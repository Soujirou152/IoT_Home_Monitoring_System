 // This #include statement was automatically added by the Particle IDE. #include "MQTT/MQTT.h"
// This #include statement was automatically added by the Particle IDE.
#include "MQTT/MQTT.h"
#include "MQTT/MQTT.h"
 String sensor;
 bool onConnect = false;
 byte server[] = { 192,168,1,50 };//the IP of broker
 void callback(char* topic, byte* payload, unsigned int length);
 MQTT client(server, 1883, callback);
void callback(char* topic, byte* payload, unsigned int length) {
     char p[length + 1];
     memcpy(p, payload, length);
     p[length] = NULL;
     String message(p);
    if (message.equals("Camera Sensed Motion"))
         Particle.publish("pushbulletHOME", "Check AMP App, Motion Detected!", 60, PRIVATE);
         client.publish("TestPX", "Message Sent to PushBullet");
     delay(1000);
 }
void setup() {
     RGB.control(true);
     client.connect(System.deviceID());
     if (client.isConnected()) {
         client.subscribe("Camera");//color is the topic that photon is subscribed
         client.publish("TestPX", "hello this is particle");//publishing a data "hello" to the topic "fun"
     }
 }
void loop() {
     //int sensor_value =analogRead(A0);
     //sensor =String (sensor_value);
     sensor = "This Is your particle, PX, I have connected";
     if (client.isConnected())
         client.loop();
         if(!onConnect){
            client.publish("TestPX", sensor);//publishing a sensor data  to the topic "value"
            onConnect = true;
         }
 } 