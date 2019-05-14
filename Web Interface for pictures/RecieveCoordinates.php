<?php
$latitude = "";
$longitude = "";
if(isset($_POST["latitude"]) && isset($_POST["longitude"])){

  $latitude = $_POST["latitude"];
  $longitude = $_POST["longitude"];
	//----------------------------
  $file = fopen("C:/wamp/www/RecieveCoordinates.txt", "w") or die ("Unable to open file!");
  
  
  fwrite($file, $latitude);
  fwrite($file, PHP_EOL);
  fwrite($file, $longitude);
  fclose($file);
  	//-----------------------------
  echo "Updates Recieved";
}
else{
	echo "No Updates";
}

$longitude= rand(670000000,671234567 )/10000000;
  $latitude= rand(240000000, 241234567)/10000000;
//----------------------------------------------------------mywork----------------------------------------------------
require("header.php");
$path = "pics/";
$files = array_map('mysql_real_escape_string',array_map('basename',array_filter(glob("{$path}*.*"),'is_file')));

if(empty($files)){
	echo "There were no matching files to insert into the database.";
} else {	

	$query = "INSERT INTO mytable (image,longitude,latitude) VALUES ('$files[0]','$longitude','$latitude')";
	if(!mysql_query($query)){
		echo "There was a problem inserting the data.";
		trigger_error("Query failed: $query<br />Error: " . mysql_error());
	} else {
		echo "The data was inserted successfully.";
	}



	
	if(file_exists('pics/'.$files[0].''))
{
    rename('pics/'.$files[0].'' , 'fpics/'.$files[0].'');
    echo "success";
} 
//----




	
}




?>