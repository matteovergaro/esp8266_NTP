# Esp8266_NTP

This is my ESP8266 project to retrieve date and time from an NTP server.
I worked on Mac OS and i used the Arduino IDE to program directly the ESP8266-01 module.

## Hardware and Connections

#### Hardware

- ESP8266-01
- USB to Serial adapter with the FT232RL (FTDI) chip
- 3.3V power supply
- Breadboard and some jumper wires
- 2x10KΩ resistors

*You can also use a USB to Serial adapter with CH340 chip*

#### Connections

```
ESP8266-01
------------------
VCC       -> 3.3V (power supply)
CH_EN     -> 3.3V (power supply through 10kΩ)
RST       -> 3.3V (power supply through 10KΩ)
TX        -> RX   (FTDI)
RX        -> TX   (FTDI)
GPIO0     -> *
GPIO2     -> NC
GND       -> GND  (power supply)
```
*The [GPIO0](https://github.com/espressif/esptool/wiki/ESP8266-Boot-Mode-Selection) needs to be connected to GND to enter boot mode and NC to run regularly.

NC = Not Connected

```
FTDI Adapter
-----------------
VCC       -> NC
GND       -> GND  (power supply)
TXD       -> RX   (ESP8266)
RXD       -> TX   (ESP8266)
RTS       -> NC
CTS       -> NC
```
It's important to have a common GND, so connect both GNDs to the power supply.

## Software

- [Arduino IDE](https://www.arduino.cc/en/software)
- [Esptool](https://github.com/espressif/esptool)

#### Setup Arduino IDE and Esptool

Install the Arduino IDE from the link above, then install the esp8266 board package: go to Tools -> Board -> Board Manager, search for "esp8266" and download the latest version. After installing that, select the "Generic ESP8266 Module" from Tools -> Board -> "ESP8266 Boards (version)".

For the esptool just follow the "Easy installation" from the link above, which is the official documentation.


## Serial Communication

To communicate with the ESP8266 connect the FTDI adapter to your pc and open a terminal window, then connect the GPIO0 to GND and write the following commands:
```cd <path to directory "esptool-master">```
```./esptool.py erase_flash```

now the chip can be flashed, :


and from the Arduino IDE select the right port in Tools -> Port  Serial Monitor. The default baud of the ESP8266 is 115200, so you have to select *115200 baud* and *Both (NL and CR)*.


Flash firmware "esp8266_nonos_sdk_v2.0.0_16_08_10" :
```
--port /dev/tty.usbserial... write_flash 0x00000 bin/eagle.flash.bin 0x78000 bin/blank.bin 0x7c000 bin/esp_init_data_default.bin 0x7a000 bin/blank.bin 0x7e000 bin/blank.bin 0x10000 bin/eagle.irom0text.bin -fm dout
```

Serial monitor 115200 baud

baud from 115200 to 9600:
```
AT+UART_DEF=9600,8,1,0,0
```

Serial monitor 9600 baud

Flash Arduino program

Hope...

