# ACS712-v1.0-beta
Current-Sensor-Lib for Arduino (tested with UNO &amp; pro mini 5V )  

![ACS712](http://www.bilder-upload.eu/thumb/9b920f-1466532639.jpg)  

Only for 5V (ADC) Controller.  

I write a small lib to simplify the conversion with the different modules 5/20/30 A.  
I tried to find out a way for the smallest calculation-error.  


###Following commands are possible:    

- uint16_t Set_ADC(byte bit);        // set the ADC-solution - default 10 bit  
                                                       // get digi middle 10 bit -> 512  

- long Get_vcc_analog();        // get µC - vcc in mV  
- double  Get_current(uint8_t port, int version);       // get current in A  
                                                                                   // port , version - default A0, 5A  
