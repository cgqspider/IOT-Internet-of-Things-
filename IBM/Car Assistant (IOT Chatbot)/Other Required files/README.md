
Basic Authentication with URL:
Inside IOT Cloud Function create a APP inside that api key and authentication token: Note that:
Username = apikey
Password = Authentication token
https://USERNAME:PASSWORD@openwhisk.ng.bluemix.net/api/v1/namespaces.
Basic Authentication using Node.js Request api
Tutorial: https://www.haykranen.nl/2011/06/21/basic-http-authentication-in-node-js-using-the-request-module/
HOW TO MAKE WEBPACK:
Dependencies
npm install –g webpack
npm install webpack --save

webpack.js
var path = require('path');module.exports = {  entry: './index.js',  output: {    path: path.resolve(__dirname, 'dist'),    filename: 'bundle.js'  },  target: 'node'};

add build key in the scripts of package.json:
"scripts": {   "build": "webpack --config webpack.config.js" }
 
Build:
npm run build
 
 
Deploy this function to IBM FUNCTIONS:
 
ibmcloud wsk action update GrenerateJWT dist/bundle.js --kind nodejs:8
 
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




