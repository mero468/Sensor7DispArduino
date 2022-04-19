# Sensor7DispArduino

Code for arduino uno connected to HC-Sr501 movement sensor, 14mm 7 segment display and an LED.

Lab's goal is to to create a light (represented via a LED) using “HC-SR501
Integrated Motion Sensor” as activation key and using “14 mm Seven Segment Display”
to display remaining time until turning out the light.

Compare this system to motion sensor lights or lamps that you have seen in buildings.
When motion sensor detects a movement, it turns the light on and waits a previously
determined time before it turns the light off and returns to its initial state, waiting for
activation again.

While using “HC-SR501 Integrated Motion Sensor”, you may require to set certain
variables concerning activation distance, location or speed. Try to declare these values as
global variables so that we can input different values in lab hour to see their effect on the
sensor.

You can use a single LED to represent light in this experiment. Just turn it on when
motion sensor activated and turn it off when the wait time has passed.

“14 mm Seven Segment Display” is used to show the remaining time until light is turned
off. As you know, it can be used to represent decimal or hexadecimal values. However,
showing larger values may not be possible. Assuming we choose a larger wait time, we
can create a circle animation through “a” to “f” segments, similar to busy mouse pointer
animation in operating systems. If you have alternative animation idea to represent larger
values, in place of suggested circle one, you can use it and show them in lab hour.
However, it must be an animation, not a static image like an integer.

Try to make your circuit elements as distant as possible from each other and make sure
there are no jumper wires over circuit elements that prevent the correct working of
sensors or other input devices.
