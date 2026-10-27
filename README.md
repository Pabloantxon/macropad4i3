<img width="1183" height="735" alt="macropad4i3" src="https://github.com/user-attachments/assets/dfb7b441-feeb-4e7e-b245-021b6be7c649" />
# macropad4i3
This is a macro pad I've made for using the i3 desktop manager on Linux. With nine keys, a single press of each key sends you to the corresponding desktop, and a long press sends the active window to the corresponding desktop. There is also an encoder for changing the system volume.

I've used a M5StampS3. 
All keys (cherry style switches) have one pin connected to GND, and the others to GPIOs. I messed up soldering, that is why I'm using GPIOs 1, 3, 4, 5, 6, 7, 8, 9, 10 instead of 1, 2, 3...
The encoder has the middle pin connected to GND and the side pins on pins 14 and 15. I didn't wire the push button.

The box design is a bit feeble, and should be made better in case it was going to be moved constantly from one place to another. In my case it is enough, since it is going to sit on my desktop. 
Four M3 and one M2 short screws needed. The M3 screws are on the left side, the M2 is for holding the M5StampS3.
Oh and some kind of anti slip rubber thingies should be used on the legs.
