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

import os, sys, traceback
import time
import logging
from SnifferAPI import Sniffer, Logger

def setup():
    sniffer = Sniffer.Sniffer("/dev/ttyACM0")
    sniffer.start()

    tls_dev_addr = [0xde, 0xde, 0x96, 0xdf, 0x92, 0x4a, True]

    for _ in range(10):
        time.sleep(1)
        devlist = sniffer.getDevices()
        found_dev = [dev for dev in devlist.devices if dev.address == tls_dev_addr]
        if found_dev:
            follow(sniffer, found_dev[0])
            break

def follow(sniffer, dev):
    pipeFilePath = os.path.join(Logger.logFilePath, "nordic_ble.pipe")
    logging.info('###### Found dev %s. Start wireshark with -Y btle -k -i %s', dev, os.path.abspath(pipeFilePath))

    myPipe = PcapPipe()
    myPipe.open_and_init(pipeFilePath)
    sniffer.follow(dev)
    sniffer.subscribe("NEW_BLE_PACKET", myPipe.newBlePacket)

    try:
        loop(sniffer)
    except:
        pass

    myPipe.close()

def loop(sniffer):
    nLoops = 0
    nPackets = 0
    connected = False
    while True:
        time.sleep(0.1)

        packets   = sniffer.getPackets()
        nLoops   += 1
        nPackets += len(packets)

        if connected != sniffer.inConnection or nLoops % 20 == 0
            connected = sniffer.inConnection
            logging.info("connected %s, nPackets %s", sniffer.inConnection, nPackets)

class PcapPipe(object):
    def open_and_init(self, pipeFilePath):
        try:
            os.mkfifo(pipeFilePath)
        except OSError:
            logging.warn("fifo already exists?")
            raise SystemExit(1)
        self._pipe = open(pipeFilePath, 'w')
        self.write(self.makeGlobalHeader())

    def write(self, message):
        if not self._pipe: return
        try:
            self._pipe.write(''.join(map(chr, message)))
            self._pipe.flush()
        except IOError:
            exc_type, exc_value, exc_tb = sys.exc_info()
            logger.error('Got exception trying to write to pipe: %s', exc_value)
            self.close()

    def close(self):
        logging.debug("closing pipe")
        if not self._pipe: return
        self._pipe.close()
        self._pipe = None

    def newBlePacket(self, notification):
        packet      = notification.msg["packet"]
        packetList  = packet.getList()
        snifferList = self.makePacketHeader(len(packetList) + 1) + [packet.boardId] + packetList
        self.write(snifferList)

    def makeGlobalHeader(self):
        LINKTYPE_BLUETOOTH_LE_LL    = 251
        LINKTYPE_NORDIC_BLE         = 157

        MAGIC_NUMBER                = 0xa1b2c3d4
        VERSION_MAJOR               = 2
        VERSION_MINOR               = 4
        THISZONE                    = 0
        SIGFIGS                     = 0
        SNAPLEN                     = 0xFFFF
        NETWORK                     = LINKTYPE_NORDIC_BLE

        headerString = [
                            ((MAGIC_NUMBER  >>  0) & 0xFF),
                            ((MAGIC_NUMBER  >>  8) & 0xFF),
                            ((MAGIC_NUMBER  >> 16) & 0xFF),
                            ((MAGIC_NUMBER  >> 24) & 0xFF),
                            ((VERSION_MAJOR >>  0) & 0xFF),
                            ((VERSION_MAJOR >>  8) & 0xFF),
                            ((VERSION_MINOR >>  0) & 0xFF),
                            ((VERSION_MINOR >>  8) & 0xFF),
                            ((THISZONE      >>  0) & 0xFF),
                            ((THISZONE      >>  8) & 0xFF),
                            ((THISZONE      >> 16) & 0xFF),
                            ((THISZONE      >> 24) & 0xFF),
                            ((SIGFIGS       >>  0) & 0xFF),
                            ((SIGFIGS       >>  8) & 0xFF),
                            ((SIGFIGS       >> 16) & 0xFF),
                            ((SIGFIGS       >> 24) & 0xFF),
                            ((SNAPLEN       >>  0) & 0xFF),
                            ((SNAPLEN       >>  8) & 0xFF),
                            ((SNAPLEN       >> 16) & 0xFF),
                            ((SNAPLEN       >> 24) & 0xFF),
                            ((NETWORK       >>  0) & 0xFF),
                            ((NETWORK       >>  8) & 0xFF),
                            ((NETWORK       >> 16) & 0xFF),
                            ((NETWORK       >> 24) & 0xFF)
                        ]

        return headerString

    def makePacketHeader(self, length):

        timeNow = time.clock()

        TS_SEC      = int(timeNow)
        TS_USEC     = int((timeNow-TS_SEC)*1000000)
        INCL_LENGTH = length
        ORIG_LENGTH = length

        headerString = [
                            ((TS_SEC        >>  0) & 0xFF),
                            ((TS_SEC        >>  8) & 0xFF),
                            ((TS_SEC        >> 16) & 0xFF),
                            ((TS_SEC        >> 24) & 0xFF),
                            ((TS_USEC       >>  0) & 0xFF),
                            ((TS_USEC       >>  8) & 0xFF),
                            ((TS_USEC       >> 16) & 0xFF),
                            ((TS_USEC       >> 24) & 0xFF),
                            ((INCL_LENGTH   >>  0) & 0xFF),
                            ((INCL_LENGTH   >>  8) & 0xFF),
                            ((INCL_LENGTH   >> 16) & 0xFF),
                            ((INCL_LENGTH   >> 24) & 0xFF),
                            ((ORIG_LENGTH   >>  0) & 0xFF),
                            ((ORIG_LENGTH   >>  8) & 0xFF),
                            ((ORIG_LENGTH   >> 16) & 0xFF),
                            ((ORIG_LENGTH   >> 24) & 0xFF)
                        ]
        return headerString

if __name__ == '__main__':
    logger = logging.getLogger()
    logger.addHandler(logging.StreamHandler())
    logger.setLevel(logging.INFO)
    setup()
