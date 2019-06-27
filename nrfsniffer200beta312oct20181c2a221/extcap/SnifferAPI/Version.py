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

import myVersion

pdfVersion = "1.2"

def getRevision():
    return myVersion.version

def getVersionString(mRevision = getRevision()):
    # prevRev = 0
    
    # if mRevision == 0:
        # return "0.0.0"
    # for rev in versions:
        # if rev > int(mRevision):
            # return versions[prevRev]
        # prevRev = rev
    # return versions[prevRev]
    
    return myVersion.versionString + myVersion.versionNameAppendix

def getPureVersionString(mRevision = getRevision()):
    return myVersion.versionString
    
def getUserGuideFileName(version = pdfVersion, platformName = "win", deliverableName = "ble-sniffer", itemName = "User Guide.pdf"):
    return str(deliverableName) + "_" + str(platformName) + "_" + str(version) + "_" + str(itemName)
    
    
def getReadableVersionString(mRevision = getRevision()):
    return "SVN rev. "+str(mRevision) if mRevision else "version information unavailable"
            
def getFileNameVersionString(mRevision = getRevision(), itemName = "", platformName = "win", deliverableName = "ble-sniffer"):
    ver = getVersionString(mRevision)
    if itemName != "":
        return str(deliverableName)+"_"+str(platformName)+"_"+str(ver)+"_"+str(itemName)
    else:
        return str(deliverableName)+"_"+str(platformName)+"_"+str(ver)
