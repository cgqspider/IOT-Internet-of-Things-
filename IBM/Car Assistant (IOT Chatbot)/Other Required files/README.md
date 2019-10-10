
<h1>Basic Authentication with URL:</h1>
Inside IOT Cloud Function create a APP inside that api key and authentication token: Note that: <br>
Username = apikey<br>
Password = Authentication token<br>
https://USERNAME:PASSWORD@openwhisk.ng.bluemix.net/api/v1/namespaces. <br>
Basic Authentication using Node.js Request api<br>
Tutorial: https://www.haykranen.nl/2011/06/21/basic-http-authentication-in-node-js-using-the-request-module/<br>
<h1>HOW TO MAKE WEBPACK:</h1>
<h2>Dependencies</h2>
npm install –g webpack<br>
npm install webpack --save<br>

<h3>webpack.js</h3>
var path = require('path'); <br>
module.exports = {  entry: './index.js', <br>
  output: {  <br>
  path: path.resolve(__dirname, 'dist'), <br>
    filename: 'bundle.js'  },  target: 'node'};<br>

<h2>add build key in the scripts of package.json:</h2>
"scripts": {   "build": "webpack --config webpack.config.js" }<br>
 
<h3>Build:</h3>
npm run build<br>
 
 
<h1>Deploy this function to IBM FUNCTIONS:</h1>
 
ibmcloud wsk action update GrenerateJWT dist/bundle.js --kind nodejs:8<br>
 
Tutorial for IBM Cloud Functions: https://medium.com/@yunyuenchan/how-to-use-npm-module-in-ibm-cloud-functions-a0c76154e85









#Note: if you are using get post service dont forget to send the promise otherwise not result will be shown
Tutorial: https://stackoverflow.com/questions/51943158/calling-http-get-requests-from-ibm-cloud-functions-using-nodejs

   /*

const request = require('request-promise');

function main(params) {
    return request("https://jsonplaceholder.typicode.com/todos/1").then(response => {
        process.stdout.write(response);
    });
}*/

const https = require('https');

function main(params) {
 return new Promise((resolve, reject) => {
        https.get('https://jsonplaceholder.typicode.com/todos/1', (resp) => {
        resp.on('data', (d) => {
            process.stdout.write(d);
            resolve({})
        });
    });
  })        
}




