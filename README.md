![*SA-ECG*](https://github.com/Mic-Tsai/SA-ECG_AD8233_Single-Arm_ECG/blob/main/res/SA-ECG_Single%20Arm_ECG-1.png)

# SA-ECG | Single-Arm ECG

   [![Donate](https://img.shields.io/badge/paypal-donate-yellow.svg)](https://paypal.me/mictsai?locale.x=zh_TW)

According to previous project experience that board-level noise coming from the power source (USB cable). This application follows the wireless way to transfer data by esp-8266 micro-control, with ADI AD8232/AD8233 analog ADC board catch bio-signal.

 *Add additional OPA for reference electrodes.
 *SA-ECG results showing R-R interval.

##

Reference project:

* [Sensor_ECG_PPG_MAX86150_Dev-Board](https://github.com/Mic-Tsai/Sensor_ECG_PPG_MAX86150_Dev-Board)
* [Sensor_ECG_MAX86150_Patch](https://github.com/Mic-Tsai/Sensor_ECG_MAX86150_Patch)


##

This application support WiFi transmission via ESPNOW (ESP8266 Broadcast), and need power by battery. You need 2x esp8266 board.

1) Read receiver esp8266's mac address.
2) Fill it into the transmitter sketch. "broadcastAddress"


```
Arduino tool kit, and require the following material:
- MCU: ESP8266 
- Sensor: ADI AD8232/AD8233
```

## 

Any question or need technical support:

* Contact me via mail (xbcke12345@gmail.com)

   [![Donate](https://img.shields.io/badge/paypal-donate-yellow.svg)](https://paypal.me/mictsai?locale.x=zh_TW)


## 


>### License Information
>>This product is open source! Both, our hardware and software are open source and licensed under the following:
>>#### Hardware
>>>All hardware is released under [Creative Commons Share-alike 4.0 International](http://creativecommons.org/licenses/by-sa/4.0/)
>>#### Software 
>>>All software is released under the MIT License [http://opensource.org/licenses/MIT](http://opensource.org/licenses/MIT)
>>#### Documentation
>>>The documentation on this page is released under [Creative Commons Share-alike 4.0 International](http://creativecommons.org/licenses/by-sa/4.0/)
