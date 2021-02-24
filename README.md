# Esp8266_NTP

This is my ESP8266 project to retrieve date and time from an NTP server.
I used a MacBook and the Arduino IDE to program directly the ESP8266-01 module.

## Hardware and Connections

#### Hardware

- ESP8266-01
- USB to Serial adapter with the FT232RL (FTDI) chip
- 3.3V power supply
- Breadboard and some jumper wires
- 2 10KΩ resistors

*I also tried to use a Serial adapter with CH340 chip but it didn't work for me.*

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
*The GPIO0 needs to be connected to GND when you're uploading something to the board and NC when you want to run normally

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
!!!It's important to have a common GND, so connect both GNDs to the power supply.

## Software



## Serial Communication

To communicate with the ESP8266 you have to connect the FTDI adapter to your pc and from the Arduino IDE select open the right port Serial Monitor. The default baud of the ESP8266 is 115200, so you have to select *115200 baud* and *Both (NL and CR)*
