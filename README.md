
# SFP_Util
Simple tool allowing for easy interaction with SFP modules trough a serial port

## How to use:

Connect the device to the computer and open a terminal of your choosing eg. TeraTerm, PuTTy. The device listens for commands. Everything that's sent not longer than 5ms apart is considered to be one command.

## List of commands
- help - Prints available commands
- read8(addres)  - Reads 8bytes and returns the result
- read16(addres) - Reads 8bytes and returns the result
- write8(addres, value)  - Writes 8bits to the given adress
- write16(addres, value) - Writes 16bits to the given adress
- readASCII(startADD, endADD) - Tries to decode a string of ASCII characters located from "startADD" to "endADD"
- tryWriting - Checks to which adresses you are able to write
- setDeviceAddres - Sets the I2C addres of the device we are reading/writing from (default 0xA0(160))
- getInfo - Prints basic information about the inserted device
- getRaw(startAdd,stopAdd) - Prints the contents of the entire memory from addres startAdd to addres stopAdd
- getEncoding - Prints the encoding type
- getIdentifier - Prints the Identifier of the device
- getExtIdentifier - Prints the Extended Identifier of the device
- getConnector - Prints the Connector Type of the device
- getSignalingRate - Prints the signaling rate of the device
- getRateIdentifier - Prints the Rate Identifier


### Additional information
##### All input arguments are to be in decimal format without any spacing for example write8(3,56)

