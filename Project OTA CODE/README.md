# Introduction
This is a special project which can be used to deploy the code over the air using HTTPS and this can be used with mqtt also by using Switch we can decide when to upload the code in the hardware.

# How to use?

1. Inside server side php code folder php script is there which can be hosted to any server and we can send the bin files to the server. This bin file can be fetched by the Nodemcu or any OTA supported controller.
<br/>
2.Inside OTA using https folder normal code of http is there which is used to fetch the code form the server and deploy itself inside the nodemcu or ota based controller.<br/>
Note: Please note it requires restart after the code is being deployed.
<br/>
3. Inside MQTT folder there is MQTT version of OTA is avaible.
<br>
NOTE: Dont forget to give the fingerprint cause it uses the HTTPS for secured service we have to use fingerprinting.<br />

# Demo
https://www.linkedin.com/posts/narayan-jha-aa3b2b13a_everything-is-over-the-air-and-cloud-why-activity-6565851476726513664-TV4d
 
