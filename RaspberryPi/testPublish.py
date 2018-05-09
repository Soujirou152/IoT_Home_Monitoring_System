#!/usr/bin/python
import sys
try:
        import paho.mqtt.publish as publish
except ImportError:
        print 'No known paho'
        print 'sys path is'
        print sys.path
import time

print("Sending to MQTT  Broker...")
publish.single("Camera", "Camera Sensed Motion", hostname="XXX.XXX.X.XXX")
time.sleep(1)
#print("Sending 1...")
#publish.single("ledStatus", "1", hostname="XXX.XXX.X.XXX")
