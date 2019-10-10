<h1>Introduction</h1>
This is python code which is made for the IOT Client for the IBM IOT. In this i used the Paho-mqtt library for this.
<br>
1. install dependency: pip install paho-mqtt or you can use pip3 too.<br>
2. Create a device in IBM IOT and note down the required information like : ORG-ID,DEVICE-TYPE,DEVICE-ID,TOKEN, iot-2/evt/test/fmt/json and fill all the details inside the code. Template code is given below in a comment inside IOTPUB.py.
3. Run the script using :  python IOTPUB.py
<br/>
For more details: https://github.com/cgqspider/IOT-Internet-of-Things-
 
<br />

<p>NOTE:From IBM IOT security -> connection security -> TLS Optional.</p>
<p>From APPS create api : note down api key and auth token which will be used as username and password for Cloud function for HTTP request to IBM IOT. (BASIC AUTHENTICATION)</p>


<h3>Ref :</h3>
<p>Watch other required files for more other details<p>
https://stackoverflow.com/questions/46664862/python-paho-mqtt-og-ibm-watson-iot
