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

import Notifications
import logging

class DeviceList(Notifications.Notifier):
    def __init__(self, *args, **kwargs):
        Notifications.Notifier.__init__(self, *args, **kwargs)
        logging.info("args: " + str(args))
        logging.info("kwargs: " + str(kwargs))
        self.devices = []
    
    def __len__(self):
        return len(self.devices)
        
    def __repr__(self):
        return "Sniffer Device List: "+str(self.asList())
        
    def clear(self):
        self.devices = []
    
    def appendOrUpdate(self, newDevice):
        existingDevice = self.find(newDevice)
        
        # logging.info("appendOrUpdate")
        
        # Add device to the list of devices being displayed, but only if CRC is OK
        if existingDevice == None:
            self.append(newDevice)
        else:
            updated = False
            if (newDevice.name != "") and (existingDevice.name == ""):
                existingDevice.name = newDevice.name
                updated = True
                
            if (existingDevice.RSSI < (newDevice.RSSI - 5)) or (existingDevice.RSSI > (newDevice.RSSI+2)):
                existingDevice.RSSI = newDevice.RSSI
                updated = True
                
            if updated:
                self.notify("DEVICE_UPDATED", existingDevice)
                # self.updateDeviceDisplay()
    
    def append(self, device):
        # self.devices[listToString(device.addr)] = device
        self.devices.append(device)
        # if len(self.devices) ==  1:
            # self.devices[0].selected = True
        
        self.notify("DEVICE_ADDED", device)
        
    def find(self, id):
        # logging.info("find type: %s" % str(id.__class__.__name__))
        if type(id) == list:
            for dev in self.devices:
                if dev.address == id:
                    return dev
        elif type(id) == int:
            return self.devices[id]
        elif type(id) == str:
            for dev in self.devices:
                if dev.name in [id, '"'+id+'"']:
                    return dev
        elif id.__class__.__name__ == "Device":
            # logging.info("find Device")
            return self.find(id.address)
        return None

    def remove(self, id):
        if type(id) == list: #address
            device = self.devices.pop(self.devices.index(self.find(id)))
        elif type(id) == int:
            device = self.devices.pop(id)
        elif type(id) == Device:
            device = self.devices.pop(self.devices.index(self.find(id.address)))
        self.notify("DEVICE_REMOVED", device)
        # self.updateDeviceDisplay()
        
    # def getSelected(self):
        # for dev in self.devices:
            # if dev.selected:
                # return dev
        # if len(self.devices) ==  1:
            # self.devices[0].selected = True
        # else:
            # return None
            
    def index(self, device):
        index = 0
        for dev in self.devices:
            if dev.address == device.address:
                return index
            index += 1
        return None
        
    # def setSelected(self, device):
        # if device in self.devices:
            # for dev in self.devices:
                # dev.selected = False
        # device.selected = True
        # self.notify("DEVICE_SELECTED", device)
            
    def setFollowed(self, device):
        if device in self.devices:
            for dev in self.devices:
                dev.followed = False
            device.followed = True
        self.notify("DEVICE_FOLLOWED", device)
        
    # def incrementSelected(self, step = 1):
        # if len(self.devices) > 0:
            # self.setSelected(self.find((self.index(self.getSelected())+step)%len(self.devices)))
            
    def asList(self):
        return self.devices[:]
        


class Device:
    def __init__(self, address, name, RSSI, txAdd = 1):
        self.address = address
        self.txAdd = txAdd
        self.name = name
        self.RSSI = RSSI
        # self.selected = selected
        self.followed = False
    
    def __repr__(self):
        return 'BLE device "'+self.name+'" ('+str(self.address)+')'
            
def listToString(list):
    str = ""
    for i in list:
        str+=chr(i)
    return str
