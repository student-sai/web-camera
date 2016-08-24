1 import webiopi
2 from RPIO import PWM
3 #import datetime
4
5 GPIO = webiopi.GPIO
6 servo = PWM.Servo()
7 portR1 = 18
8 portR2 = 23
9 portL1 = 24
10 portL2 = 25
11 YAW = 17
12 PIT = 27
13 #HOUR_ON = 14 # Turn Light ON at 8:00
14 #HOUR_OFF = 18 # Turn Light OFF at 18:00
15
16 # setup function is automatically called at WebIOPi startup
17 def setup():
18      # set the GPIO used by the motors to output
19      GPIO.setFunction(portR1, GPIO.OUT)
20      GPIO.setFunction(portR2, GPIO.OUT)
21      GPIO.setFunction(portL1, GPIO.OUT)
22      GPIO.setFunction(portL2, GPIO.OUT)
23      #set the GPIO used by the servos to output
24      GPIO.setFunction(YAW, GPIO.OUT)
25      GPIO.setFunction(PIT, GPIO.OUT)
26      GPIO.output(YAW, GPIO.LOW)
27      GPIO.output(PIT, GPIO.LOW)
28      # retrieve current datetime
29      #now = datetime.datetime.now()
30
31      # test if we are between ON time and tun the light ON
32      #if ((now.hour >= HOUR_ON)  and (now.hour < HOUR_OFF)):
33      #     GPIO.digitalWrite(LIGHT, GPIO.HIGH)
34
35 # loop function is repeatedly called by WebIOPi
36 #def loop():
37     # retrieve current datetime
38     #now = datetime.datetime.now()
39
40     # toggle light ON all days at the correct time
41     #if ((now.hour == HOUR_ON) and (now.minute == 0) and ( now.second == 0)):
42     #     if (GPIO.digitalRead(LIGHT) == GPIO.HIGH):
43     #GPIO.digitalWrite(LIGHT, GPIO.LOW)
44
45     # toggle light OFF
46     #if ((now.hour == HOUR_OFF) and (now.minute == 0) and (now.second == 0)):
47     #     if (GPIO.digitalRead(LIGHT) == GPIO.HIGH):
48     #         GPIO.digitalWrite(LIGHT, GPIO.LOW)
49
50     # gives CPU some time before looping again
51     #webiopi.sleep(1)
52
1,1          先頭

