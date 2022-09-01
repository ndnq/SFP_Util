#include "cmds.h"

void getIdentifier(){
        Serial.print(F("Identifier: "));
        switch (read8B(0))
        {
        case 0:
            Serial.println(F("Unknown or unspecified"));
            break;
        case 1:
            Serial.println(F("GBIC"));
            break;
        case 2:
            Serial.println(F("Module soldered to motherboard (ex: SFF)"));
            break;
        case 3:
            Serial.println(F("SFP or SFP+"));
            break;
                                    
        default:
        Serial.print(F("Other, raw data is :"));
        Serial.println(read8B(0));
            break;
        }
        

}

void getExtIdentifier(){

        Serial.print(F("ExtIdentifier: "));
        switch (read8B(1))
        {
        case 0:
            Serial.println(F("00h GBIC definition is not specified or the GBIC definition is not compliant with a defined MOD_DEF. See product specification for details"));
            break;
        case 1:
            Serial.println(F("01h GBIC is compliant with MOD_DEF 1"));
            break;
        case 2:
            Serial.println(F("02h GBIC is compliant with MOD_DEF 2"));
            break;
        case 3:
            Serial.println(F("03h GBIC is compliant with MOD_DEF 3"));
            break;
        case 4:
            Serial.println(F("04h GBIC/SFP function is defined by 2-wire interface ID only"));
            break;
        case 5:
            Serial.println(F("05h GBIC is compliant with MOD_DEF 5"));
            break;
        case 6:
            Serial.println(F("06h GBIC is compliant with MOD_DEF 6"));
            break;
        case 7:
            Serial.println(F("07h GBIC is compliant with MOD_DEF 7"));
            break;                                                
                                    
        default:
        Serial.print(F("Other, raw data is :"));
        Serial.println(read8B(1));
            break;
        }
        

}

void getConnector(){
        Serial.print("Connector: ");
        switch (read8B(2))
        {
        case 0:
            Serial.println(F("00h Unknown or unspecified"));
            break;
        case 1:
            Serial.println(F("01h SC (Subscriber Connector)"));
            break;
        case 2:
            Serial.println(F("02h Fibre Channel Style 1 copper connector"));
            break;
        case 3:
            Serial.println(F("03h Fibre Channel Style 2 copper connector"));
            break;
        case 4:
            Serial.println(F("04h BNC/TNC (Bayonet/Threaded Neill-Concelman)"));
            break;
        case 5:
            Serial.println(F("05h Fibre Channel coax headers"));
            break;
        case 6:
            Serial.println(F("06h Fiber Jack"));
            break;
        case 7:
            Serial.println(F("07h LC (Lucent Connector)"));
            break;             
        case 8:
            Serial.println(F("08h MT-RJ (Mechanical Transfer – Registered Jack)"));
            break;  
        case 9:
            Serial.println(F("09h MU (Multiple Optical)"));
            break;  
        case 0xA:
            Serial.println(F("0Ah SG"));
            break;
        case 0xB:
            Serial.println(F("0Bh Optical Pigtail"));
            break;    
        case 0xC:
            Serial.println(F("0Ch MPO 1x12 (Multifiber Parallel Optic)"));
            break;    
        case 0xD:
            Serial.println(F("0Dh MPO 2x16"));
            break;    
        case 0x20:
            Serial.println(F("20h HSSDC II (High Speed Serial Data Connector)"));
            break;    
        case 0x21:
            Serial.println(F("21h Copper pigtail"));
            break;    
        case 0x22:
            Serial.println(F("22h RJ45 (Registered Jack)"));
            break;    
        case 0x23:
            Serial.println(F("23h No separable connector"));
            break;    
        case 0x24:
            Serial.println(F("24h MXC 2x16"));
            break;    
        case 0x25:
            Serial.println(F("25h CS optical connector"));
            break;    
        case 0x26:
            Serial.println(F("26h SN (previously Mini CS) optical connector"));
            break;      
        case 0x27:
            Serial.println(F("27h MPO 2x12"));
            break;  
        case 0x28:
            Serial.println(F("28h MPO 1x16"));
            break;                                      
        default:
        Serial.print(F("Other, raw data is :"));
        Serial.println(read8B(2));
            break;
        
    }
}

void getEncoding(){

    Serial.print(F("Encoding Type: "));
     switch (read8B(11))
        {
        case 0:
            Serial.println(F("00h Unspecified"));
            break;
        case 1:
            Serial.println(F("01h 8B/10B"));
            break;
        case 2:
            Serial.println(F("02h 4B/5B"));
            break;
        case 3:
            Serial.println(F("03h NRZ"));
            break;
        case 4:
            Serial.println(F("04h Manchester(8472) | SONET Scrambled(8436/8636)"));
            break;
        case 5:
            Serial.println(F("05h SONET Scrambled(8472) | 64B/66B(8436/8636)"));
            break;
        case 6:
            Serial.println(F("06h 64B/66B(8472) | Manchester(8436/8636)"));
            break;
        case 7:
            Serial.println(F("07h 256B/257B (transcoded FEC-enabled data)"));
            break;             
        case 8:
            Serial.println(F("08h PAM4"));
            break;  
        case 9:
            Serial.println(F("09h Other(Reserved))"));
            break;
        default:
        Serial.print(F("Other, raw data is :"));
        Serial.println(read8B(11));
            break;
    }
}

void getSignalingRate(){

    Serial.print(F("Nominal signaling rate is: "));
    Serial.print(read8B(12)*100);
    Serial.println("MBd");
}

void getRateIdentifier(){

            Serial.print(F("Rate Identifier: "));
        switch (read8B(13))
        {
        case 1:
            Serial.println(F("01h SFF-8079 (4/2/1G Rate_Select & AS0/AS1)"));
            break;
        case 2:
            Serial.println(F("02h SFF-8431 (8/4/2G Rx Rate_Select only)"));
            break;
        case 4:
            Serial.println(F("04h SFF-8431 (8/4/2G Tx Rate_Select only)"));
            break;
        case 6:
            Serial.println(F("06h SFF-8431 (8/4/2G Independent Rx & Tx Rate_select)"));
            break;         
        case 8:
            Serial.println(F("08h FC-PI-5 (16/8/4G Rx Rate_select only) High=16G only, Low=8G/4G"));
            break;  
        case 0xA:
            Serial.println(F("0Ah FC-PI-5 (16/8/4G Independent Rx, Tx Rate_select) High=16G only, Low=8G/4G"));
            break;
        case 0xC:
            Serial.println(F("0Ch FC-PI-6 (32/16/8G Independent Rx, Tx Rate_Select) High=32G only, Low = 16G/8G"));
            break;     
        case 0x10:
            Serial.println(F("10h FC-PI-7 (64/32/16G Independent Rx, Tx Rate Select)"));
            break;    
        case 0x20:
            Serial.println(F("20h Rate select based on PMDs as defined by A0h, byte 36 and A2h, byte 67 (Rx, Tx Rate Select)"));
            break;                                        
        default:
        Serial.print("Other, raw data is :");
        Serial.println(read8B(13));
            break;
        
    }
}

void getLinkLength(){
    Serial.print(F("Length (SMF): "));
    Serial.print(read8B(14));
    Serial.println(F("Km"));

    Serial.print(F("Length (SMF): "));
    Serial.print(read8B(15)*100);
    Serial.println(F("m"));

    Serial.print(F("Length (50 um, OM2): "));
    Serial.print(read8B(16)*10);
    Serial.println(F("m"));

    Serial.print(F("Length (62.5 um, OM1): "));
    Serial.print(read8B(17)*10);
    Serial.println(F("m"));

    Serial.print(F("Length (OM4 (Active Cable or Copper)): "));
    Serial.print(read8B(18)*10);
    Serial.print(F("m ("));
    Serial.print(read8B(18));
    Serial.println(F("m)"));

    Serial.print(F("Length (OM3 (Active Cable or Copper)): "));
    uint8_t raw  = read8B(19);
    uint8_t multiplier = raw & 0b00000011;
    uint8_t base = (raw & 0b11111100)>>2;
    Serial.print(raw*10);
    Serial.print(F("m ("));
    if(multiplier == 0b00){Serial.print(base*0.1f);}
    if(multiplier == 0b01){Serial.print(base);}
    if(multiplier == 0b10){Serial.print(base*10);}
    if(multiplier == 0b11){Serial.print(base*100);}
    Serial.println(F("m)"));
}