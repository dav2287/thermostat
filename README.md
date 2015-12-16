## Current Wiring:

### Thermostat:

| Wire 	| Port on Existing 	| Function 	|
| ---- 	| ---------------- 	| -------- 	|
| Brown | W2 				| Heat2		|
| Green | G  				| Fan		|
| White | W  				| Heat		|
| Black | C  				| 24V common|
| Blue  | Y  				| Cool 		|
| Red   | R + Rc 			| Power		|

### Photon:

| Photon Pin | Connected  |
| ---------- | ---------  |
| D0         | SDA bus    |
| D1         | SCL bus    |
| D2         | AC Relay   |
| D3         | Heat Relay |
| D4         | Fan Relay  |
| GND        | i2c + relay GND |
| Vcc        | i2c + relay Vcc |

Reference: [Thermostat Wiring](http://www.behvac.com/troubleshooter41.htm)

## Packages:
https://github.com/adafruit/Adafruit_HTU21DF_Library
https://github.com/romainmp/HTU21D

