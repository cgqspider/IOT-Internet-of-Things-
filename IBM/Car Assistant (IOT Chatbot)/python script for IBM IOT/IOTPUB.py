import json
import paho.mqtt.client as mqtt
import time
import random 

client = mqtt.Client('d:0wfml2:Nodemcu:7897654')

client.username_pw_set('use-token-auth', '12345678')
client.connect('0wfml2.messaging.internetofthings.ibmcloud.com', 1883, 60)

while True:
        time.sleep(4)
        payload = { 'temperature': float(random.random()) }
        client.publish('iot-2/evt/test/fmt/json', json.dumps(payload))
        print("sent : "+str(payload))
client.loop()

client.disconnect()


'''
# REFERECE: https://stackoverflow.com/questions/46664862/python-paho-mqtt-og-ibm-watson-iot
You need to run the MQTT network loop to make sure that the data is sent after the publish and before you disconnect. There are a couple of ways to do this.

The simplest is just to add the client.loop() call between the publish and disconnect calls:

import json
import paho.mqtt.client as mqtt

client = mqtt.Client('d:ORG-ID:DEVICE-TYPE:DEVICE-ID')

client.username_pw_set('use-token-auth', 'TOKEN')
client.connect('ORG-ID.messaging.internetofthings.ibmcloud.com', 1883, 60)

payload = { 'temperature': 20 }
client.publish('iot-2/evt/test/fmt/json', json.dumps(payload))

client.loop()

client.disconnect()

The other is to use the single shot publish call that does the connect, publish and disconnect all in one go.

single(topic, payload=None, qos=0, retain=False, hostname="localhost",
port=1883, client_id="", keepalive=60, will=None, auth=None, tls=None,
protocol=mqtt.MQTTv311)
Full details about the single shot method are in the docs here:
'''
