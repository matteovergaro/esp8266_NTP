# Esp8266_NTP

This is my ESP8266 project to retrieve date and time from an NTP server.

### Hardware and Connections

#### Hardware
ESP8266-01, USB to Serial adapter with the FT232RL (FTDI) chip, 3.3V power supply, a breadboard and some jumper wires and 10KΩ resistors.

*I also tried to use a Serial adapter with CH340 chip but it didn't work.*

#### Connections

```
ESP8266-01
--------------------------------
VCC       -> 3.3V (power supply)
CH_EN     -> 3.3V (power supply)  through 10kΩ
RST       -> 3.3V (power supply)  through 10KΩ
TX        -> RX   (FTDI)
RX        -> TX   (FTDI)
GPIO0     -> read next section*
GPIO2     -> NC
GND       -> GND  (power supply)
```
```
FTDI Adapter
-------------------------------
VCC       -> NC
GND       -> GND  (power supply)
TXD       -> RX   (ESP8266)
RXD       -> TX   (ESP8266)
RTS       -> NC
CTS       -> NC
```
NC = Not Connected

!!!It's important to have a common GND, so connect both GNDs to the power supply.

### Serial Communication

