<?php 
$files = glob("pics/*.*"); 
for ($i=1; $i<count($files); $i++) 
	{ 
		$num = $files[$i]; 
		
		echo '<img src="'.$num.'" alt="random image height="100px" width="100px"">'."&nbsp;&nbsp;"; 
	}
?>