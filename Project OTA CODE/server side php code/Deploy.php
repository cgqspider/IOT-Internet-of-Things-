<!DOCTYPE html>
<html lang="en">
<head>
  <title>Bootstrap Example</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/paho-mqtt/1.0.1/mqttws31.js" type="text/javascript"></script>
</head>
<body>

<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">OTA UPLOADER DEMO V1.0</a>
      <a class="navbar-brand" href="./index.php">Upload Bins</a>
    </div>
   
  </div>
</nav>


<?php
// Define a function to output files in a directory
function outputFiles($path){
    // Check directory exists or not
    if(file_exists($path) && is_dir($path)){
        // Search the files in this directory
        $files = glob($path ."/*");
        if(count($files) > 0){
            // Loop through retuned array
            foreach($files as $file){
                if(is_file("$file")){
                    // Display only filename
                    echo "<div class='well well-lg'><h3 id='demo'>MQTT Server Status : Connected</h3><br/><h5> ".basename($file) . "</h5><br> ";
                    echo "<button class='btn btn-success' id='deploy' onclick='Deploy();'>Deploy</button></div><br>";
                } else if(is_dir("$file")){
                    // Recursively call the function if directories found
                    outputFiles("$file");
                }
            }
        } else{
            echo "<div class='well well-lg'>No! Binaries Found Please <a href='./index.php'>Add Binaries</a> </div>";
        }
    } else {
        echo "<div class='well well-lg'>Sorry No Such Directory Found!</div>";
    }
}
 
// Call the function
outputFiles("upload");
?>
 
</body>
</html>

<script>


  // Create a client instance
            client = new Paho.MQTT.Client("soldier.cloudmqtt.com", 38269, "web_" + parseInt(Math.random() * 100, 10));
            //Example client = new Paho.MQTT.Client("m11.cloudmqtt.com", 32903, "web_" + parseInt(Math.random() * 100, 10));

            // set callback handlers
            client.onConnectionLost = onConnectionLost;
            client.onMessageArrived = onMessageArrived;
            var options = {
                useSSL: true,
                userName: "nrfmmlmy",
                password: "N9vGWSSTpTxp",
                onSuccess:onConnect,
                onFailure:doFail
            }

            // connect the client
            client.connect(options);

            // called when the client connects
            function onConnect() {
                // Once a connection has been made, make a subscription and send a message.
                console.log("onConnect");
                var x = document.getElementById("demo");   // Get the element with id="demo"
                x.style.color = "green";                     // Change the color of the element
                alert("Mqtt Connection Success!");
                var sbs="/cloudmqtt";
                client.subscribe(sbs);
                message = new Paho.MQTT.Message("Hello CloudMQTT");
                message.destinationName = "/cloudmqtt";
                //client.send(message);
            }

            function doFail(e){
                console.log(e);
                var x = document.getElementById("demo");   // Get the element with id="demo"
                x.style.color = "red";                     // Change the color of the element
            }

            // called when the client loses its connection
            function onConnectionLost(responseObject) {
                if (responseObject.errorCode !== 0) {
                    console.log("onConnectionLost:"+responseObject.errorMessage);
                }
            }

            // called when a message arrives
            function onMessageArrived(message) {
                console.log("onMessageArrived:" + message.payloadString);
                alert(message.payloadString);
            }

            function Deploy()
            {
               
                var sbs="/OTA";
                client.subscribe(sbs);
                message = new Paho.MQTT.Message("Ota message to Esp8266");
                message.destinationName = "/OTA";
                client.send(message);
                alert("Deployment Message sent to ESP8266...");
                document.getElementById("deploy").disabled = true;
                setTimeout(function(){
                    document.getElementById("deploy").disabled = false;
                    },10000);
                
            }

            

        </script>

