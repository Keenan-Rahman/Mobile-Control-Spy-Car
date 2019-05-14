
<?php
require("header.php");
$path = "pics/";
$files = array_map('mysql_real_escape_string',array_map('basename',array_filter(glob("{$path}*.*"),'is_file')));
if(empty($files)){
	echo "There were no matching files to insert into the database.";
} else {	

	$query = "INSERT INTO mytable (image) VALUES ('" . implode("'),('",$files) . "')";
	
	if(!mysql_query($query)){
		echo "There was a problem inserting the data.";
		trigger_error("Query failed: $query<br />Error: " . mysql_error());
	} else {
		echo "The data was inserted successfully.";
	}
	

	
	

}

?>
