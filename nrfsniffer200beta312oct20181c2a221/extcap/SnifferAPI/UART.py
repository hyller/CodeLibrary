# Copyright (c) 2017, Nordic Semiconductor ASA
# 
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 
#    1. Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
# 
#    2. Redistributions in binary form must reproduce the above
#       copyright notice, this list of conditions and the following
#       disclaimer in the documentation and/or other materials provided
#       with the distribution.
# 
#    3. Neither the name of Nordic Semiconductor ASA nor the names of
#       its contributors may be used to endorse or promote products
#       derived from this software without specific prior written
#       permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NORDIC
# SEMICONDUCTOR ASA OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.

import logging, serial, collections
import serial.tools.list_ports as list_ports
from threading import Thread
import time

read_uart_data_queue = collections.deque()

SLIP_ENCODED_PING_REQ = [0xab, 0x06, 0x00, 0x01, 0xde, 0xad, 0x0D, 0xbc]


def find_sniffer(write_data=False):

    open_ports = list_ports.comports()

    sniffers = []
    for port in [x.device for x in open_ports]:
        try:
            ser = serial.Serial(
                port=port,
                baudrate=9600,
                timeout=0.5
            )
            ser.baudrate=460800
            if write_data:
                ping_req = ''.join([chr(b) for b in SLIP_ENCODED_PING_REQ])
                ser.write(ping_req)
                ser.write(ping_req)
            data_read = ser.read(10000)
            if len(data_read) > 0:
                byte_stream = ''.join(['%02x' % ord(x) for x in data_read])
                if 'bcab' in byte_stream:  # Will be seen for each EVENT_PACKET, IE when a BLE packet is seen.
                    sniffers.append(port.encode('ascii', 'ignore'))  # Safe to assume no non-ascii characters.
            ser.close()
        except:
            pass

    return sniffers


class Uart:
    def __init__(self, portnum=None):
        self.ser = None

        try:
            self.ser = serial.Serial(
                port=portnum,
                baudrate=9600,
                timeout=0.5
            )
            self.ser.baudrate = 460800

        except Exception as e:
            if self.ser:
                self.ser.close()
            raise

        self.worker_thread = Thread(target=self._read_worker)
        self.reading = True
        self.worker_thread.setDaemon(True)
        self.worker_thread.start()

    def _read_worker(self):
        while self.reading:
            try:
                data_read = self.ser.read()
            except serial.SerialException as e:
                logging.info("Unable to read UART: %s" % e)
                self.reading = False
                return

            if len(data_read) > 0:
                read_uart_data_queue.extend(data_read)

    def close(self):
        if self.ser:
            logging.info("closing UART")
            self.ser.close()
            self.reading = False
            self.worker_thread.join()

    def __del__(self):
        if self.ser:
            logging.info("closing UART")
            self.ser.close()
            self.reading = False
            self.worker_thread.join()

    def switchBaudRate(self, newBaudRate):
        self.ser.baudrate = newBaudRate

    def read(self, timeout=None):
        time_slept = 0

        while len(read_uart_data_queue) == 0 and (timeout is not None and time_slept < timeout):
            time_slept += 0.1
            time.sleep(0.1)

        if len(read_uart_data_queue) == 0:
            return None
        else:
            return read_uart_data_queue.popleft()

    def readByte(self, timeout = None):
        readString = ""

        readString = self.read(timeout)
            
        return readString
        
    def writeList(self, array):
        try:
            self.ser.write(array)
        except serial.SerialTimeoutException:
            logging.info("Got write timeout, ignoring error")

        except serial.SerialException as e:
            self.ser.close()
            raise e


def list_serial_ports():
    # Scan for available ports.
    return list_ports.comports()

# Convert a list of ints (bytes) into an ASCII string
def listToString(list):
    str = ""
    for i in list:
        str+=chr(i)
    return str
    
# Convert an ASCII string into a list of ints (bytes)
def stringToList(str):
    lst = []
    for c in str:
        lst += [ord(c)]
    return lst


if __name__ == "__main__":
    print find_sniffer()
