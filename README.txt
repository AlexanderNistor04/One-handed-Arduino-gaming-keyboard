This repository is for a 3D printed one handed gaming keyboard with a thumbstick and a small display. The keyboard has 36 keys (the button inside the thumbstick is the 36th key) and isn't meant to be used for typing but rather for gaming or other programs which don't require a full keyboard. 
The keyboard is built off of an Arduino pro micro with a micro usb port and has a male micro usb to female usb c internal adapter to allow the user to connect the keyboard to their computer with a usb c cable. The program for the Arduino is written in c++ and is included in this repository. 
The thumbstick functions as a mouse by default, moving the stick moves the cursor and clicking on the stick corresponds to a left click. Holding shift and clicking corresponds to a right click. 
All of the circuit boards are custom and their Gerber files are included. The circuits don't have any components on them, but were designed to have the user hand solder each component. The keyboard uses smd neopixel leds, which are the most difficult component to hand solder. The keyboard is designed to fit 3 pin mechanical keyboard switches and is made for hotswap switch sockets.
The previous iterations of the design are included as well, though many are not entirely complete and some files have been lost. 

This link leads to a thingiverse item with the stl files of the latest version of the 3d models: https://www.thingiverse.com/thing:6422238

Parts:
- arduino pro micro (https://www.amazon.com/gp/product/B01MTU9GOB/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- male micro usb to female usb c adapter (https://www.amazon.com/Adapter-KUXIYAN-Connector-Compatible-Devices-Black/dp/B07VBV1PY5/ref=rvi_d_sccl_10/147-5259136-8825426?pd_rd_w=iCySJ&content-id=amzn1.sym.f5690a4d-f2bb-45d9-9d1b-736fee412437&pf_rd_p=f5690a4d-f2bb-45d9-9d1b-736fee412437&pf_rd_r=ZH9G5PDKC799G8YT5HKT&pd_rd_wg=0rtzB&pd_rd_r=36694f2f-eb38-40d5-a16a-09adfaf040f5&pd_rd_i=B07VBV1PY5&psc=1)
- monochrome oled 12c display (https://www.amazon.com/gp/product/B08KLMJDGH/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 35 * 0.1uF ceramic capacitor (https://www.amazon.com/gp/product/B00RT02YIU/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 35 * WS2812B neopixel LED (https://www.amazon.com/gp/product/B00YC7ZXRM/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 36 * through-hole rectifier diode (https://www.amazon.com/gp/product/B071YWNBVM/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 470 ohm through hole resistor
- 36 * gateron yellow mechanical keyboard switche (you can use any full size 3-pin mechanical keyboard switch) (https://www.amazon.com/gp/product/B08JPJX296/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 35 * gateron mechanical switch hot-swap socket (https://www.amazon.com/gp/product/B0972HB9GY/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- mechanical keyboard keycap set (I used a hyperx pudding keycap set but you can use any mechanical keyboard keycap set) (https://www.amazon.com/gp/product/B087QTR4CT/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- screw-in keyboard stabilizer kit (https://www.amazon.com/gp/product/B08MWDGBJ8/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- dual potentiometer analog thumbstick w/ button (https://www.amazon.com/gp/product/B06XH1NTFY/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- thumbstick cap (https://www.amazon.com/gp/product/B083P4K9YR/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- male pin headers (https://www.amazon.com/gp/product/B074HVBTZ4/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 9 * m3 nuts and bolts (https://www.amazon.com/Socket-Screws-Assortment-Button-Assorted/dp/B0BMQGV4SW/ref=sr_1_5?crid=2MHPP35RS5O8X&keywords=m3+screws&qid=1704772159&sprefix=m3%2Caps%2C129&sr=8-5)

Building Instructions:
1. Solder the neopixel LEDs onto the primary circuit board. It's easiest to solder the neopixels first because they're the most dificult component to solder and should be done on a flat pcb, though this is not strictly necessary. The neopixels need to be oriented such that the small triangle indent on each neopixel is on the bottom right corner. 
2. Solder the diodes to the primary and secondary pcbs. The annode (negative side) (the side with the silver making) should be facing downwards for each diode. The diodes can be on either the front or the back of the pcb, except for the diode next to the shift key and the diode on the secondary pcb, which must be facing the backside of the board to avoid interference with other components.
3. Solder the hotswap sockets to the back of the primary pcb. The sockets should only be able to fit in one way, so there's no need to worry about soldering them backwards.
4. Solder the capacitors onto the back of the primary board. The capacitors must be on the backside of the board to not interfere with the keys. Most small, ceramic capaitors are not polar, so the capacitors can be soldered either way.
5. Solder the arduino to the back of the primary pcb. When looking at the back of the primary pcb, the port of the arduino should be facing right.
6. Solder the resistor to the back of the primary pcb.
7. Solder the display to the front of the primary pcb. Place the screen spacer 3d printed piece underneath the display while soldering to help keep the display level. Keep the spacer underneath the display to ensure it stays in place while in use. 
8. Solder the thumbstick to the secondary pcb. 
9. Solder the secondary pcb to the main pcb using some pin headers.
10. Attach the shift key stabilizer to the pcb.
11. Insert the female usb c end of the adapter into the main body of the keyboard such that the rest of the adapter lays on the inside of the body and the female end is flush with the outside of the body. It helps to heat the inside of the hole with a soldering iron to assist this process. It should be a very stiff fit and can be difficult to insert. 
12. Plug the male micro usb end of the adapter into the arduino and place the pcb into the main body.
13. Place the thumbstick cap onto the thumbstick. The thumbstick may be too wide to fit, in which case it can be trimmed and sanded down to fit. 
14. Place the spacer plate on top of the pcb.
15. Place the main plate on top of the spacer plate and insert the switches into the main plate and pcb. Be careful to keep the swiches completely vertical when pressing them in as it is easy to bend the pins. 
16. Optionally attach the wrist rest and stand and secure the keyboard shut with 9 screws.
17. Install the keycaps and finish. 

