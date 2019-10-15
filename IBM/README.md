<h1>Introduction</h1>
In this IBM IOT services are used.
You can find installation instructions here: https://ibm-watson-iot.github.io/iot-python/

below is a sample code on how you can connect and publish events

https://ibm-watson-iot.github.io/iot-python/device/#sample-code
<h2>Code:</h2>
import wiotp.sdk.device

def myCommandCallback(cmd):
    print("Command received: %s" % cmd.data)

# Configure
myConfig = wiotp.sdk.device.parseConfigFile("device.yaml")
client = wiotp.sdk.device.DeviceClient(config=myConfig, logHandlers=None)
client.commandCallback = myCommandCallback

# Connect
client.connect()

# Send Data
myData={'name' : 'foo', 'cpu' : 60, 'mem' : 50}
client.publishEvent(eventId="status", msgFormat="json", data=myData, qos=0, onPublish=None)

# Disconnect
client.disconnect()
<br />
and example of the device.yaml is<br/>
myConfig = { 
    "identity": {
        "orgId": "org1id",
        "typeId": "raspberry-pi-3"
        "deviceId": "00ef08ac05"
    }.
    "auth" {
        "token": "Ab$76s)asj8_s5"
    }
}
client = wiotp.sdk.device.DeviceClient(config=myConfig)
<br/>
The above information can be obtained from the IoT Platform interface
