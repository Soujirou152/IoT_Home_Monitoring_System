# IoT_Home_Monitoring_System
SEIS 744 - proj

This project uses a private Mosquitto broker on my Home network to handle messages between 
a Rapsberry Pi that has a camera module connected to it as well as a Particle Photon 
subscribed to the topic the Raspberry Pi is publising too whenever the camera senses motion.

Once the Particle Photon receives the message on the topic, it activates a webhook to 
Pushbullet, which then sends a push notification to my phone to open up the App My Product 
mobile app.

App My Product is a software service that allows 1 year free service for up to 99 devices that 
uses their nabto tunneling to connect devices. My phone is paired with the Raspberry Pi that 
is running the nabto tunneling service. This allows video to be streamed securely through the 
web.

This project is also intended to be scalable so that any device can be added to publish to the 
home broker and any functionality can be added without much change in infrastructure.

Repository----

The repository contains the Particle Photon firmware code that is loaded unto my Photon. It is 
inside the ParticleCode directory. You have to change the IP from "XXX,XXX,X,XXX" to what is 
desired.

Inside RasperryPi directory is a python script that publishes to my home broker. You have to 
switch the IP like above. The motion.conf that the motion software uses to control the camera is also 
included in the directory.

Configuration ----

Please follow these tutorials in order to set up a Mosquitto broker and install the App My 
Product software to enable nabto tunneling

https://blog.nabto.com/2017/09/11/raspberry-pi-webcam-with-secure-remote-access/
https://www.networkworld.com/article/3160055/internet-of-things/internet-of-things-messaging-part-2-the-mosquitto-mqtt-broker.html

