<h1>Introduction</h1>
In this IBM IOT services are used.
You can find installation instructions here: https://ibm-watson-iot.github.io/iot-python/

below is a sample code on how you can connect and publish events

https://ibm-watson-iot.github.io/iot-python/device/#sample-code
<h2>Code:</h2>
import wiotp.sdk.device

def myCommandCallback(cmd):<br>
    print("Command received: %s" % cmd.data)<br>

# Configure
myConfig = wiotp.sdk.device.parseConfigFile("device.yaml")<br>
client = wiotp.sdk.device.DeviceClient(config=myConfig, logHandlers=None)<br>
client.commandCallback = myCommandCallback<br>

# Connect
client.connect()<br>

# Send Data
myData={'name' : 'foo', 'cpu' : 60, 'mem' : 50}<br>
client.publishEvent(eventId="status", msgFormat="json", data=myData, qos=0, onPublish=None)<br>

# Disconnect
client.disconnect()<br>
<br />
and example of the device.yaml is<br/>
myConfig = { <br>
    "identity": {<br>
        "orgId": "org1id",<br>
        "typeId": "raspberry-pi-3"<br>
        "deviceId": "00ef08ac05"<br>
    }.<br>
    "auth" {<br>
        "token": "Ab$76s)asj8_s5"<br>
    }<br>
}<br>
client = wiotp.sdk.device.DeviceClient(config=myConfig)<br>
<br/>
The above information can be obtained from the IoT Platform interface
