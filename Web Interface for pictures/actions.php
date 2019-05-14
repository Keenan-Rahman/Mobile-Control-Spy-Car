<body background="maps-local-search1-ss-1920-800x450.jpg" style="background-size:cover"></body>

<div align="center">
  <h1><strong><font color="#000066">Longitude is :</font></strong> <?php echo $_POST["text1"]; ?></h1>
</div><br>
<div align="center">
  <h1><strong><font color="#000066">Latitude is :</font></strong> <?php echo $_POST["text2"]; ?></h1>
</div>
<br>
<div align="center">
  <strong><font color="#000066">Image is :</font></strong> 
</div>
<br>

<?php 

$username = "root";
$password = "";
$hostname = "localhost"; 

//connection to the database
$con = mysql_connect($hostname, $username, $password) 
 or die("Unable to connect to MySQL");

//select a database to work with
$selected = mysql_select_db("cpictures",$con) 
  or die("Could not select examples");

 
$t1=$_POST["text1"];
$t2=$_POST["text2"];


$result = mysql_query("SELECT image FROM mytable WHERE longitude='$t1' AND latitude ='$t2' ");		

  $row = mysql_fetch_row($result); // get the single row.

		
	echo '<div align="center"><img src="fpics/'.$row[0].'" alt="random image" height="300px" width="300px" ></div>'; 
		 
		 echo '<div align="center">'.$row[0].'</div>'; 
		 ?>
	