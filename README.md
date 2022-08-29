
# SFP_Util
Simple tool allowing for easy interaction with SFP modules trough a serial port

## How to use:

Connect the device to the computer and open a terminal of your choosing eg. TeraTerm, PuTTy. The device listens for commands. Everything that's sent not longer than 5ms apart is considered to be one command.

## List of commands
- help - Prints available commands
- read8(address)  - Reads 8bytes and returns the result
- read16(address) - Reads 8bytes and returns the result
- write8(address, value)  - Writes 8bits to the given adress
- write16(address, value) - Writes 16bits to the given adress
- getRaw(startAdd,stopAdd) - Prints the contents of the entire memory from address startAdd to address stopAdd in a .csv friendly format (read values are in hexadecimal)
- readASCII(startADD, endADD) - Tries to decode a string of ASCII characters located from "startADD" to "endADD"
- tryWriting - Checks to which adresses you are able to write
- setDeviceAddres - Sets the I2C address of the device we are reading/writing from (default 0xA0(160))
- getInfo - Prints basic information about the inserted device
- getEncoding - Prints the encoding type
- getIdentifier - Prints the Identifier of the device
- getExtIdentifier - Prints the Extended Identifier of the device
- getConnector - Prints the Connector Type of the device
- getSignalingRate - Prints the signaling rate of the device
- getRateIdentifier - Prints the Rate Identifier
- getVendorSpecificInformation - Tries to interpret data saved in a memory region reserved to the manufacturer


### Additional information
##### All input arguments are to be in decimal format without any spacing for example write8(3,56).
##### All output data is to be read as decimal if not stated otherwise.

