<?php 
if(isset($_POST['submit'])){

$folder_path = "upload"; 
   
// List of name of files inside 
// specified folder 
$files = glob($folder_path.'/*');  
   
// Deleting all the files in the list 
foreach($files as $file) { 
   
    if(is_file($file))  
    
        // Delete the given file 
        unlink($file);  
} 
 
 // Count total files
 $countfiles = count($_FILES['file']['name']);

 // Looping all files
 for($i=0;$i<$countfiles;$i++){
  $filename = $_FILES['file']['name'][$i];
 
  // Upload file
  move_uploaded_file($_FILES['file']['tmp_name'][$i],'upload/'.$filename);
 
 }

 echo "<script>alert('Binaries Uploading Success!');</script>";
 header( "refresh:1;url=Deploy.php" );
} 
?>




<!DOCTYPE html>
<html lang="en">
<head>
  <title>Bootstrap Example</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
</head>
<body>

<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">OTA UPLOADER DEMO V1.0</a>
      <a class="navbar-brand" href="./Deploy.php">Deploy</a>
    </div>
   
  </div>
</nav>


<form method='post' action='' enctype='multipart/form-data'>
<div class="container">
  <div class="jumbotron">
  <h2>Add Your Files Here...</h2>
 
    <div class="form-group">
     
      <input type="file" class="" name="file[]" id="file" multiple>
      
    </div>
    <input type='submit' class="btn btn-default" name='submit' value='Upload'>
   
  </form>
</div>
</div>

</body>
</html>
