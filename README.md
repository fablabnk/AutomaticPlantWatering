# Introduction

Welcome to the wonderful world of automatic plant watering and home automation!  :palm_tree:  :palm_tree:  :palm_tree:

This repo provides concise instructions and code for the simple no-pump automatic plant watering system [described here](https://www.printables.com/model/43718-automatic-plant-watering-system-ultra-cheap)

<img src="https://media.printables.com/media/prints/43718/images/434527_67eb3612-adee-4225-bf60-efe7ccbdb286/thumbs/inside/1280x960/jpg/large_display_img_20201017_125324_43718.webp" alt="Simple No-pump Automatic Plant-Watering System" width="300"/>

It is worth saying upfront that there are lower-tech and more sustainable solutions out there for plant watering. As programmers, we're primarily doing this as a fun introduction to embedded systems and automation.

<img src="https://i.redd.it/d1gjdqbtxdb51.jpg" alt="A simpler low-tech solution" width="300"/>

TL;DR: Coders gonna code :)

# Materials

- An Arduino (we will start by using an Uno, though eventually you might want to go Nano)
- A micro-servo motor
- A screw-cap PET bottle
- A short length of silicone fish-task hose (6mm outer diameter / 4mm inner diameter)
- A set of 3D printed parts
	1. Bottle cap with hose attachment
	2. Bottle holder/irrigation spike
	3. Cam
	4. Cam follower
- 2 x M2 screws (to attach servo to spike)
- A capacitative soil sensor (optional)

# Goals

Our baseline goal for the workshop is to get our motor running and write code to time-release water from an upright bottle. If we all get there, then great!

Where you take the project after reaching the baseline is up to you. Some ideas include:
- Using a capacitive soil sensor to release the water only when the soil is dry
- Optimising the project for minimal power usage (e.g. powering down when not in use)
- Exploring solar power
- Collecting and/or serving plant-watering statistics

Don't worry if you don't get there today - there will be more time to work on the project in next Friday's open session.

# Safety Points

- No water in the clean lab! When you get to the stage of filling the bottles, move your setup to the dirt lab
- When water is used, your project should not be connected to mains electricity - use batteries/power banks!

# The Basics: How It Works

When all the parts are assembled correctly, the following should happen:

0. The motor starts in the closed position (pinching the hose)
1. The Arduino tells the servo motor to turn the cam
2. The cam moves a cam-follower, which un-pinches our silicon hose to the 'open-position' to release water from the upright bottle
3. The water flows down to the plant roots and the plant is happy (maybe!)
4. After a set amount of time, the Arduino tells the servo (and therefore cam) to move back to the closed position

# Wiring the Servo

When wiring a servo motor to an Arduino, the connections should be made as follows:
- The red wire of the servo goes to the 5V pin on the Arduino.
- The black or brown wire of the servo connects to the GND (ground) pin on the Arduino.
- The orange or yellow wire (signal wire) of the servo connects to digital pin 9 on the Arduino.

See the [Arduino Basic Servo Control](https://docs.arduino.cc/tutorials/generic/basic-servo-control/) article for more details...

# Calibrating the Servo

To
we need to first ensure the servo is set to the 0 degree position and make sure this corresponds to our value being fully closed (i.e. the hose is pinched tight)

1. Wire the arduino to the servo
2. Run the provided sample sketch ([described here](./code/servo_reset/servo_reset.ino)) to move the servo to 0 degrees, then remove the power
3. Screw the cam so that it is at its widest and pushed the cam follow to pin the tubing

# Timed-Watering Code Example

In our simplest use-case, to release water we move the servo from the 0 degree position to the 120 degree position for a set amount of time.

- You will need to experiment to see how much water you think it is necessary to release
- Then we set a delay until the next time we want water to be released

A commented code example can be found [here](./code/watering/watering.ino)

# Notes on Power

- The original project powers the device with block of 4 AA rechargable batteries connected to Vin and Ground
- I also tried with a USB: it works!
- The code example attempts to reduce power consumption by disconnecting the servo when the system is in the valve closed state
- An improved version would completely cut the power to the servo during wait periods instead of just disconnecting the control 

# Adding the Capacitative Soil Sensor

See [here](https://makersportal.com/blog/2020/5/26/capacitive-soil-moisture-calibration-with-arduino) for some background.

Wiring of the sensor should be as follows:
- Black GND cable goes to GND
- Red VCC cable goes to 3.3V and AREF (in parallel)
- Yellow AOUT cable goes to Analog in Pin A0

<img src="https://images.squarespace-cdn.com/content/v1/59b037304c0dbfb092fbe894/1590622711213-VD9LBEVQMX3CFYBCR0GG/cap_soil_sensor_arduino_wiring.png?format=2500w" alt="Soil Sensor Arduino Wiring" width="300"/>