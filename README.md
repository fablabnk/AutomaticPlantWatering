A repo for turning (this automatic plant watering project)[https://www.printables.com/model/43718-automatic-plant-watering-system-ultra-cheap] into a workshop

# How It Works

The servo turns a cam, which moves a cam follower, which un-pinches a silicon hose to release water.

To note:
- The release of the water is simply timed
- We will add a soil sensor to the project

# Components / BOM

- Arduino (Uno)
- 9g RC servo e.g. tower pro SG90
- silicone fish tank air hose, 6mm OD / 4mm ID
- two M2 or 2/56 screws to attach RC servo to device
- 20 ounce or 500mL soda / water bottle


# Wiring

## Servo

When wiring a servo motor to an Arduino, the connections should be made as follows:
- The red wire of the servo goes to the 5V pin on the Arduino.
- The black or brown wire of the servo connects to the GND (ground) pin on the Arduino.
- The orange or yellow wire (signal wire) of the servo connects to digital pin 9 on the Arduino.

## Soil Sensor (not yet implemented)

- Black GND cable goes to GND
- Red VCC cable goes to 3.3V and AREF (in parallel)
- Yellow AOUT cable goes to Analog in Pin A0

## Parts and Construction



### Calibration

0 degrees on the servo corresponds to the valve fully closed. 

1. Wire the arduino to the servo
2. Run the provided sample sketch (`servo_reset.ino`) to move the servo to 0 degrees, then remove the power
3. Screw the cam so that it is at its widest and pushed the cam follow to pin the tubing

# Code Example (watering.ino)

In the code example

# Power

- The original project powers the device with block of 4 AA rechargable batteries connected to Vin and ground
- I also tried with a power bank: works
- The code example attempts to reduce power consumption by disconnecting the servo when the system is in the valve closed state
- An improved version would completely cut the power to the servo during wait periods instead of just disconnecting the control. 

# Addition of Soil Sensor

See photo (here)[https://makersportal.com/blog/2020/5/26/capacitive-soil-moisture-calibration-with-arduino]

![Soil Sensor Arduino Wiring](https://images.squarespace-cdn.com/content/v1/59b037304c0dbfb092fbe894/1590622711213-VD9LBEVQMX3CFYBCR0GG/cap_soil_sensor_arduino_wiring.png?format=2500w)

# Make it More Power Efficient