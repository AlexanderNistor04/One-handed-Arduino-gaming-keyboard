This repository is for a 3D printed one handed gaming keyboard with a thumbstick and a small display. The keyboard only has 25 keys and isn't meant to be used for typing but rather for gaming or other programs which don't require a full keyboard. 
The keyboard is built off of an Arduino pro micro with a micro usb port and has a male micro usb to female usb c internal adapter to allow the user to connect the keyboard to their computer with a usb c cable. The program for the Arduino is written in c++ and is included in this repository. 
The thumbstick functions as a mouse by default, moving the stick moves the cursor and clicking on the stick corresponds to a left click. Holding shift and clicking corresponds to a right click. 
All of the circuit boards are custom and their Gerber files are included. The circuits don't have any components on them, but were designed to have the user hand solder each component. The keyboard uses smd neopixel leds, which are the most difficult component to hand solder. The keyboard is designed to fit 3 pin mechanical keyboard switches and is made for hotswap switch sockets.
The previous iterations of the design are included as well, though many are not entirely complete and some files have been lost. 

This link leads to a thingiverse item with the stl files of the latest version of the 3d models https://www.thingiverse.com/thing:6422238

Parts:
- arduino pro micro (https://www.amazon.com/gp/product/B01MTU9GOB/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- male micro usb to female usb c adapter (https://www.amazon.com/Adapter-KUXIYAN-Connector-Compatible-Devices-Black/dp/B07VBV1PY5/ref=rvi_d_sccl_10/147-5259136-8825426?pd_rd_w=iCySJ&content-id=amzn1.sym.f5690a4d-f2bb-45d9-9d1b-736fee412437&pf_rd_p=f5690a4d-f2bb-45d9-9d1b-736fee412437&pf_rd_r=ZH9G5PDKC799G8YT5HKT&pd_rd_wg=0rtzB&pd_rd_r=36694f2f-eb38-40d5-a16a-09adfaf040f5&pd_rd_i=B07VBV1PY5&psc=1)
- monochrome oled 12c display (https://www.amazon.com/gp/product/B08KLMJDGH/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 36 * 0.1uF ceramic capacitor (https://www.amazon.com/gp/product/B00RT02YIU/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 36 * WS2812B neopixel LED (https://www.amazon.com/gp/product/B00YC7ZXRM/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 36 * through-hole rectifier diode (https://www.amazon.com/gp/product/B071YWNBVM/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 470 ohm through hole resistor
- 36 * gateron yellow mechanical keyboard switche (you can use any full size 3-pin mechanical keyboard switch) (https://www.amazon.com/gp/product/B08JPJX296/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 36 * gateron mechanical switch hot-swap socket (https://www.amazon.com/gp/product/B0972HB9GY/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- mechanical keyboard keycap set (I used a hyperx pudding keycap set but you can use any mechanical keyboard keycap set) (https://www.amazon.com/gp/product/B087QTR4CT/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- screw-in keyboard stabilizer kit (https://www.amazon.com/gp/product/B08MWDGBJ8/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- dual potentiometer analog thumbstick w/ button (https://www.amazon.com/gp/product/B06XH1NTFY/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- thumbstick cap (https://www.amazon.com/gp/product/B083P4K9YR/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- male pin headers (https://www.amazon.com/gp/product/B074HVBTZ4/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
