
# SFP_Util
Simple tool allowing for easy interaction with SFP modules trough a serial port.

It's meant to be used on the [SATA_SFP](https://github.com/sinara-hw/SATA_SFP) board

## How to use:

Connect the device to the computer and open a terminal of your choosing eg. TeraTerm, PuTTy. The device listens for commands. Everything that's sent not longer than 5ms apart is considered as one command.

## List of commands
- help - Prints available commands
- read8(address)  - Reads 8bytes and returns the result
- read16(address) - Reads 8bytes and returns the result
- write8(address, value)  - Writes 8bits to the given adress
- write16(address, value) - Writes 16bits to the given adress
- getRaw(startAdd,stopAdd) - Prints the contents of the entire memory from address startAdd to address stopAdd in a .csv friendly format (read values are in hexadecimal)
- readASCII(startADD, endADD) - Tries to decode a string of ASCII characters located from "startADD" to "endADD"
- tryWriting - Checks to which adresses you are able to write
- setDeviceAddress - Sets the I2C address of the device we are reading from / writing to (default 0xA0(160))
- getInfo - Prints basic information about the inserted device
- getEncoding - Prints the encoding type
- getIdentifier - Prints the Identifier of the device
- getExtIdentifier - Prints the Extended Identifier of the device
- getConnector - Prints the Connector Type of the device
- getSignalingRate - Prints the signaling rate of the device
- getRateIdentifier - Prints the Rate Identifier
- getVendorSpecificInformation - Tries to interpret data saved in a memory region reserved to the manufacturer
- getLinkLength - Prints supported link lengths
- getVendorDate - Prints vendor specified manufacturing date
- tryAddressChange(interfae) - In some SFP's it is necessary to preform this operation to have acces to the diagnostic interface. Arguments are: 0 for 2-wire interface ID memory page, 1 for Digital Diagnostic memory page
- readTemperature - Reads Internally measured module temperature
- readVoltage - Reads Internally measured supply voltage in transceiver
- readTxBias - Reads Internally measured TX Bias Current
- readTxOut - Reads Measured TX output power
- readRxIn - Reads Measured RX input power
- readLasTemp - Reads Measured laser temperature or wavelength
- getDiagnostics - Prints available diagnostic information

### Additional information
##### All input arguments are to be in decimal format without any spacing for example write8(3,56).
##### All output data is to be read as decimal if not stated otherwise.

