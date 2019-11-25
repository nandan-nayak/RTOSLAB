// Load the AWS SDK for Node.js
var AWS = require('aws-sdk');
/**
* Don't hard-code your credentials!
* Create an IAM role for your EC2 instance instead.
*/
// Set your region
AWS.config.region = 'ap-south-1';
var db = new AWS.DynamoDB({apiVersion: '2012-08-10'});


// Call DynamoDB to retrieve the list of tables
db.listTables({Limit: 10}, function(err, data) {
  if (err) {
    console.log("Error", err.code);
  } else {
    console.log("Table names are ", data.TableNames);
  }
});

