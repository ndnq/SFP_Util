
# SFP_Util
Simple tool allowing for easy interaction with SFP modules through a serial port. It's made to be easily interacted with by programs and by people through the use of a CLI

Hardware: [SATA_SFP](https://github.com/sinara-hw/SATA_SFP) board

## How to use:

Connect the device to the computer and open a terminal of your choosing (eg. PuTTy, TeraTerm) then open a COM port to the device using 9600 baudrate. The device listens for commands.  Entered commands should be followed by a EOL character ('\r\n') to be handled, or the device must not have received any data in 500ms.

## List of commands
- `help` - Prints available commands
- `read8(address)`  - Reads 8bytes and returns the result in hexadecimal format
- `read16(address)` - Reads 8bytes and returns the result in hexadecimal format
- `write8(address, value)`  - Writes 8bits to the given address
- `write16(address, value)` - Writes 16bits to the given address
- `getRaw(startAdd,stopAdd)` - Prints the contents of the entire memory from address startAdd to address stopAdd in a .csv friendly format (read values are in hexadecimal)
- `readASCII(startADD, endADD)` - Tries to decode a string of ASCII characters located from "startADD" to "endADD"
- `getDiagnostics` - Prints available diagnostic information
- `monitor(mode)` - Sets diagnostic data to be monitored (0=Internal Device Temperature, 1=Internal Supply Voltage, 2=TxBias, 3=TxPower, 4=RxPower, 5=Laser Temperature, 6=TEC Current)
- `monitor` - Constantly transmits set diagnostic information (order of the data is as above 0->6)
- `escape` - Stops the monitoring command
- `tryWriting` - Checks to which addresses you are able to write. Many sectors of data are write protected this allows you to check which ones aren't
- `setDeviceAddress` - Sets the I2C address of the device we are reading from / writing to (default 0xA0(160))
- `getInfo` - Prints basic information about the inserted device
- `getEncoding` - Prints the encoding type
- `getIdentifier` - Prints the Identifier of the device
- `getExtIdentifier` - Prints the Extended Identifier of the device
- `getConnector` - Prints the Connector Type of the device
- `getSignalingRate` - Prints the signaling rate of the device
- `getRateIdentifier` - Prints the Rate Identifier
- `getVendorSpecificInformation` - Tries to interpret data saved in a memory region reserved to the manufacturer
- `getLinkLength` - Prints supported link lengths
- `getVendorDate` - Prints vendor specified manufacturing date
- `tryAddressChange(interface)` - In some SFP's it is necessary to preform this operation to have access to the diagnostic interface. Arguments are: 0 for 2-wire interface ID memory page, 1 for Digital Diagnostic memory page
- `readTemperature` - Reads Internally measured module temperature [C]
- `readVoltage` - Reads Internally measured supply voltage in transceiver [mV]
- `readTxBias` - Reads Internally measured TX Bias Current [mA]
- `readTxOut` - Reads Measured TX output power [mW]
- `readRxIn` - Reads Measured RX input power [mW]
- `readLasTemp` - Reads Measured laser temperature or wavelength [C]
- `readTECCurrent` - Reads measured TEC current [mA]



### Additional information
##### All input arguments are to be in decimal format without any spacing for example write8(3,56).
##### All output data is to be read as decimal if not stated otherwise.
##### Unsuccessful reads result in 0xFF and not implemented diagnostic features read 0

