#!/usr/bin/env python

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

"""
Wireshark extcap wrapper for the nRF Sniffer by Nordic Semiconductor.

Place this script and the SnifferAPI folder into Wireshark extcap folder.
Install all needed python packages.

NOTE:
To use this script on Windows, please generate an nrf_sniffer.bat inside
the extcap folder, with the following content:

    @echo off
    <Path to python interpreter> "%~dp0nrf_sniffer.py" %*

Windows is not able to execute Python scripts directly.
"""

from __future__ import print_function
import os
import sys
import argparse
import re
import time
import struct
import serial
import logging
from SnifferAPI import Sniffer, myVersion, Logger, UART

ERROR_USAGE = 0
ERROR_ARG = 1
ERROR_INTERFACE = 2
ERROR_FIFO = 3
ERROR_INTERNAL = 4

CTRL_CMD_INIT = 0
CTRL_CMD_SET = 1
CTRL_CMD_ADD = 2
CTRL_CMD_REMOVE = 3
CTRL_CMD_ENABLE = 4
CTRL_CMD_DISABLE = 5
CTRL_CMD_STATUSBAR = 6
CTRL_CMD_INFO_MSG = 7
CTRL_CMD_WARN_MSG = 8
CTRL_CMD_ERROR_MSG = 9

CTRL_ARG_DEVICE = 0
CTRL_ARG_KEY = 1
CTRL_ARG_ADVHOP = 2
CTRL_ARG_HELP = 3
CTRL_ARG_RESTORE = 4
CTRL_ARG_LOG = 5
CTRL_ARG_NONE = 255

fn_capture = None
fn_ctrl_in = None
fn_ctrl_out = None

# Wireshark nRF Sniffer Toolbar will always cache the last used key and adv hop and send
# this when starting a capture. To ensure that the key and adv hop is always shown correctly
# in the Toolbar, even if the user has changed it but not applied it, we send the last used
# key and adv hop back as a default value.
last_used_key = ""
last_used_advhop = "37,38,39"

# While searching for a selected Device we must not write packets to the pipe until
# the device is found to avoid getting advertising packets from other devices.
write_new_packets = False

# The RSSI capture filter value given from Wireshark.
rssi_filter = 0

# The RSSI filtering is not on when in follow mode.
in_follow_mode = False


def extcap_config(interface):
    """List configuration for the given interface"""
    pass


def extcap_dlts(interface):
    """List DLTs for the given interface"""
    print("dlt {number=272}{name=NORDIC_BLE}{display=Nordic BLE Sniffer}")


def get_interfaces():
    if not hasattr(serial, "__version__") or not serial.__version__.startswith('3.'):
        raise RuntimeError("Too old version of python 'serial' Library. Version 3 required.")

    devices = UART.find_sniffer(write_data=False)  # Try non-intrusive search first

    if len(devices) == 0:
        devices = UART.find_sniffer(write_data=True)

    return devices


def extcap_interfaces():
    """List available interfaces to capture from"""
    print(
        "extcap {version=%s}{display=nRF Sniffer}{help=http://www.nordicsemi.com/eng/Products/Bluetooth-low-energy/nRF-Sniffer#Downloads}" % myVersion.versionString)

    for interface_port in get_interfaces():
        if sys.platform == 'win32':
            print("interface {value=%s}{display=nRF Sniffer %s}" % (interface_port, interface_port))
        else:
            print("interface {value=%s}{display=nRF Sniffer}" % interface_port)

    print("control {number=%d}{type=selector}{display=Device}{tooltip=Device list}" % CTRL_ARG_DEVICE)
    print("control {number=%d}{type=string}{display=Passkey / OOB key}{tooltip=6 digit temporary key or 16 byte Out-of-band (OOB) key in hexadecimal starting with '0x', big endian format. If the entered key is shorter than 16 bytes, it will be zero-padded in front'}{validation=\\b^(([0-9]{6})|(0x[0-9a-fA-F]{1,32}))$\\b}" % CTRL_ARG_KEY)
    print("control {number=%d}{type=string}{display=Adv Hop}{default=37,38,39}{tooltip=Advertising channel hop sequence. Change the order in which the siffer switches advertising channels. Valid channels are 37, 38 and 39 separated by comma.}{validation=^\s*((37|38|39)\s*,\s*){0,2}(37|38|39){1}\s*$}{required=true}" % CTRL_ARG_ADVHOP)
    print("control {number=%d}{type=button}{role=help}{display=Help}{tooltip=Access user guide (launches browser)}" % CTRL_ARG_HELP)
    print(
        "control {number=%d}{type=button}{role=restore}{display=Defaults}{tooltip=Resets the user interface and clears the log file}" % CTRL_ARG_RESTORE)
    print("control {number=%d}{type=button}{role=logger}{display=Log}{tooltip=Log per interface}" % CTRL_ARG_LOG)
    print("value {control=%d}{value= }{display=All advertising devices}{default=true}" % CTRL_ARG_DEVICE)


def string_address(address):
    """Make a string representation of the address"""
    if len(address) < 7:
        return None

    addr_string = ''

    for i in range(5):
        addr_string += (format(address[i], '02x') + ':')
    addr_string += format(address[5], '02x') + ' '

    if address[6]:
        addr_string += ' random '
    else:
        addr_string += ' public '

    return addr_string


def control_read():
    """Read a message from the control channel"""
    try:
        header = fn_ctrl_in.read(6)
        payload = bytearray()
        sp, _, length, arg, typ = struct.unpack('>sBHBB', header)

        if length > 2:
            payload = fn_ctrl_in.read(length - 2)

        return arg, typ, payload

    except:
        return None, None, None


def control_write(arg, typ, message):
    """Write the message to the control channel"""
    packet = bytearray()

    packet += struct.pack('>sBHBB', 'T', 0, len(message) + 2, arg, typ)
    packet += message

    fn_ctrl_out.write(packet)


def capture_write(message):
    """Write the message to the capture pipe"""
    try:
        fn_capture.write(message)
        fn_capture.flush()
    except:
        pass


def make_pcap_header():
    """Make a PCAP header"""
    LINKTYPE_NORDIC_BLE = 272

    header = bytearray()
    header += struct.pack('<L', int('a1b2c3d4', 16))  # Pcap Magic Number
    header += struct.pack('<H', int(2))  # Pcap Major Version
    header += struct.pack('<H', int(4))  # Pcap Minor Version
    header += struct.pack('<I', int(0))  # Timezone
    header += struct.pack('<I', int(0))  # Accurancy of timestamps
    header += struct.pack('<L', int('0000ffff', 16))  # Max Length of capture frame
    header += struct.pack('<L', int(LINKTYPE_NORDIC_BLE))  # Nordic BLE DLT

    return header


def make_packet_header(length):
    """Make a PCAP packet header"""
    if os.name == 'posix':
        time_now = time.time()
    else:
        time_now = time.clock()

    header = bytearray()
    header += struct.pack('<L', int(time_now))  # Seconds
    header += struct.pack('<L', int((time_now - int(time_now)) * 1000000))  # Microseconds
    header += struct.pack('<L', int(length))  # Captured Length
    header += struct.pack('<L', int(length))  # Packet Length

    return header


def new_packet(notification):
    """A new BLE packet has arrived"""
    if write_new_packets == True:
        packet = notification.msg["packet"]

        if rssi_filter == 0 or in_follow_mode == True or packet.RSSI > rssi_filter:
            capture_write(make_packet_header(len(packet.getList()) + 1))
            capture_write(chr(packet.boardId) + packet.asString())


def device_added(notification):
    """A device is added or updated"""
    device = notification.msg

    # Only add devices matching RSSI filter
    if rssi_filter == 0 or device.RSSI > rssi_filter:
        display = device.name + "  " + str(device.RSSI) + " dBm  " + string_address(device.address)

        message = bytearray()
        message += str(device.address) + '\0' + display

        control_write(CTRL_ARG_DEVICE, CTRL_CMD_ADD, message)


def device_removed(notification):
    """A device is removed"""
    device = notification.msg
    display = device.name + "  " + string_address(device.address)

    message = bytearray()
    message += str(device.address)

    control_write(CTRL_ARG_DEVICE, CTRL_CMD_ADD, message)
    logging.info("Removed: " + display)


def handle_control_command(sniffer, arg, typ, payload):
    """Handle command from control channel"""
    if arg == CTRL_ARG_DEVICE:
        if payload == " ":
            scan_for_devices(sniffer)
        else:
            follow_device(sniffer, payload)

    elif arg == CTRL_ARG_KEY:
        set_passkey_or_OOB(sniffer, payload)

    elif arg == CTRL_ARG_ADVHOP:
        set_advhop(sniffer, payload)


def control_read_initial_values(sniffer):
    """Read initial control values"""
    initialized = False

    while not initialized:
        arg, typ, payload = control_read()
        if typ == CTRL_CMD_INIT:
            initialized = True
        else:
            handle_control_command(sniffer, arg, typ, payload)


def control_write_defaults():
    """Write default control values"""
    control_write(CTRL_ARG_KEY, CTRL_CMD_SET, last_used_key)
    control_write(CTRL_ARG_ADVHOP, CTRL_CMD_SET, last_used_advhop)


def scan_for_devices(sniffer):
    """Start scanning for advertising devices"""
    global in_follow_mode
    if sniffer.state == 2:
        log = "Scanning all advertising devices"
        logging.info(log)
        sniffer.scan()

    in_follow_mode = False


def follow_device(sniffer, payload):
    """Follow the selected device"""
    global write_new_packets, in_follow_mode
    values = payload
    values = values.replace('[', '')
    values = values.replace(']', '')
    device = values.split(',')

    for i in range(6):
        device[i] = int(device[i])
    if device[6] == " True":
        device[6] = True
    else:
        device[6] = False

    # Disable setting device until found
    control_write(CTRL_ARG_DEVICE, CTRL_CMD_DISABLE, " ")

    # Hold off writing new packets until device is found
    write_new_packets = False
    scan_for_devices(sniffer)

    device_found = None
    retries = 0
    while device_found is None and retries < 100:
        device_found = sniffer.getDevices().find(device)
        if not device_found:
            time.sleep(.1)
            retries += 1

    if device_found is not None:
        sniffer.follow(device_found)
        time.sleep(.1)
        in_follow_mode = True
        log = "Following " + device_found.name + " " + string_address(device_found.address)
    else:
        # Set device back to All, remove the not found entry
        control_write(CTRL_ARG_DEVICE, CTRL_CMD_SET, " ")
        control_write(CTRL_ARG_DEVICE, CTRL_CMD_REMOVE, payload)
        in_follow_mode = False
        log = "Device not found: " + string_address(device)

    # Start writing packets
    write_new_packets = True

    control_write(CTRL_ARG_DEVICE, CTRL_CMD_ENABLE, " ")
    control_write(CTRL_ARG_NONE, CTRL_CMD_STATUSBAR, log)

    logging.info(log)


def set_passkey_or_OOB(sniffer, payload):
    """Send passkey or OOB to device"""
    global last_used_key
    last_used_key = payload

    if re.match("^[0-9]{6}$", payload):
        set_passkey(sniffer, payload)
    elif re.match("^0[xX][0-9A-Za-z]{1,32}$", payload):
        set_OOB(sniffer, payload[2:])
    else:
        logging.info("Remove Passkey/OOB key")
        sniffer.sendTK([])


def set_passkey(sniffer, payload):
    """Send passkey to device"""
    passkey = []
    logging.info("Setting Passkey: " + payload)
    init_payload = int(payload, 10)
    if len(payload) >= 6:
        passkey = []
        passkey += [(init_payload >> 16) & 0xFF]
        passkey += [(init_payload >> 8) & 0xFF]
        passkey += [(init_payload >> 0) & 0xFF]

    sniffer.sendTK(passkey)


def set_OOB(sniffer, payload):
    """Send OOB to device"""
    oob = []
    current_hex = ""
    logging.info("Setting OOB: " + payload)
    payload = list(payload)
    while len(payload):
        current_hex += payload.pop(0)
        if len(current_hex) >= 2:
            oob += [int(current_hex, 16)]
            current_hex = ""
        elif len(current_hex) == 1 and len(payload) == 0:
            current_hex = "0" + current_hex
            oob += [int(current_hex, 16)]
            current_hex = ""

    sniffer.sendTK(oob)


def set_advhop(sniffer, payload):
    """Set advertising channel hop sequence"""
    global last_used_advhop
    last_used_advhop = payload

    hops = [int(channel) for channel in payload.split(',')]

    sniffer.setAdvHopSequence(hops)

    log = "AdvHopSequence: " + str(hops)
    logging.info(log)


def control_loop(sniffer):
    """Main loop reading control messages"""
    arg_read = CTRL_ARG_NONE
    while arg_read is not None:
        arg_read, typ, payload = control_read()
        handle_control_command(sniffer, arg_read, typ, payload)


def validate_interface(interface, fifo):
    """Check if interface exists"""
    if sys.platform != 'win32' and not os.path.exists(interface):
        log = "nRF Sniffer could not find interface: " + interface
        control_write(CTRL_ARG_NONE, CTRL_CMD_ERROR_MSG, log)
        extcap_close_fifo(fifo)
        sys.exit(ERROR_INTERFACE)


def sniffer_capture(interface, fifo, control_in, control_out):
    """Start the sniffer to capture packets"""
    global fn_capture, fn_ctrl_in, fn_ctrl_out, write_new_packets

    with open(fifo, 'wb', 0) as fn_capture:
        capture_write(make_pcap_header())

        with open(control_out, 'wb', 0) as fn_ctrl_out:
            control_write(CTRL_ARG_LOG, CTRL_CMD_SET, "")
            logging.info("Log started at " + time.strftime("%c"))

            validate_interface(interface, fifo)

            # Initialize the sniffer and discover devices.
            sniffer = Sniffer.Sniffer(interface)
            sniffer.subscribe("NEW_BLE_PACKET", new_packet)
            sniffer.subscribe("DEVICE_ADDED", device_added)
            sniffer.subscribe("DEVICE_UPDATED", device_added)
            sniffer.subscribe("DEVICE_REMOVED", device_removed)
            sniffer.setAdvHopSequence([37,38,39])

            sniffer.start()
            sniffer.scan()

            with open(control_in, 'rb', 0) as fn_ctrl_in:
                # First read initial control values
                control_read_initial_values(sniffer)

                # Then write default values
                control_write_defaults()

                # Start receiving packets
                write_new_packets = True

                # Start the control loop
                control_loop(sniffer)


def extcap_close_fifo(fifo):
    """"Close extcap fifo"""
    if not os.path.exists(fifo):
        print("FIFO does not exist!", file=sys.stderr)
        return

    # This is apparently needed to workaround an issue on Windows/macOS
    # where the message cannot be read. (really?)
    fh = open(fifo, 'wb', 0)
    fh.close()


class ExtcapLoggerHandler(logging.Handler):
    """Handler used to display all logging messages in extcap"""

    def emit(self, record):
        try:
            configure_extcap_logging(record.levelname + ": " + record.message + "\n")
        except:
            configure_extcap_logging("unable to log record")


def configure_extcap_logging(log_message):
    """Send log message to extcap"""
    control_write(CTRL_ARG_LOG, CTRL_CMD_ADD, log_message)


def parse_capture_filter(capture_filter):
    """"Parse given capture filter"""
    global rssi_filter
    m = re.search("^\s*((?i)(RSSI))\s*>\s*(-?[0-9]+)\s*$", capture_filter)
    if m:
        rssi_filter = int(m.group(3))
        if rssi_filter > -10 or rssi_filter < -256:
            print("Illegal RSSI value, must be between -10 and -256")
    else:
        print("Filter syntax: \"RSSI > -value\"")


if __name__ == '__main__':

    # Add extcap log handler to Logger
    extcap_log_handler = ExtcapLoggerHandler()
    Logger.addLogHandler(extcap_log_handler)

    # Capture options
    parser = argparse.ArgumentParser(description="Nordic Semiconductor nRF Sniffer extcap plugin")

    # Extcap Arguments
    parser.add_argument("--capture",
                        help="Start the capture",
                        action="store_true")

    parser.add_argument("--extcap-interfaces",
                        help="List available interfaces to capture from",
                        action="store_true")

    parser.add_argument("--extcap-interface",
                        help="The interface to capture from")

    parser.add_argument("--extcap-dlts",
                        help="List DLTs for the given interface",
                        action="store_true")

    parser.add_argument("--extcap-config",
                        help="List configurations for the given interface",
                        action="store_true")

    parser.add_argument("--extcap-capture-filter",
                        help="Used together with capture to provide a capture filter")

    parser.add_argument("--fifo",
                        help="Use together with capture to provide the fifo to dump data to")

    parser.add_argument("--extcap-control-in",
                        help="Used together with capture to get control messages from toolbar")

    parser.add_argument("--extcap-control-out",
                        help="Used together with capture to send control messages to toolbar")

    # Interface Arguments
    parser.add_argument("--device", help="Device", default="")
    parser.add_argument("--password", help="Passkey", default="")
    parser.add_argument("--oobkey", help="OOB key", default="")

    try:
        args, unknown = parser.parse_known_args()
    except argparse.ArgumentError as exc:
        print("%s" % exc, file=sys.stderr)
        fifo_found = False
        fifo = ""
        for arg in sys.argv:
            if arg == "--fifo" or arg == "--extcap-fifo":
                fifo_found = True
            elif fifo_found:
                fifo = arg
                break
        extcap_close_fifo(fifo)
        sys.exit(ERROR_ARG)

    if len(sys.argv) <= 1:
        parser.exit("No arguments given!")

    if args.extcap_capture_filter:
        parse_capture_filter(args.extcap_capture_filter)
        if args.extcap_interface and len(sys.argv) == 5:
            sys.exit(0)

    if not args.extcap_interfaces and args.extcap_interface is None:
        parser.exit("An interface must be provided or the selection must be displayed")

    if args.extcap_interfaces or args.extcap_interface is None:
        extcap_interfaces()
        sys.exit(0)

    if len(unknown) > 1:
        print("Sniffer %d unknown arguments given" % len(unknown))

    interface = args.extcap_interface

    if args.extcap_config:
        extcap_config(interface)
    elif args.extcap_dlts:
        extcap_dlts(interface)
    elif args.capture:
        if args.fifo is None:
            parser.print_help()
            sys.exit(ERROR_FIFO)
        try:
            sniffer_capture(interface, args.fifo, args.extcap_control_in, args.extcap_control_out)
        except KeyboardInterrupt:
            pass
        except:
            sys.exit(ERROR_INTERNAL)
    else:
        parser.print_help()
        sys.exit(ERROR_USAGE)
