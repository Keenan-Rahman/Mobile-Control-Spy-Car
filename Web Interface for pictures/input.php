<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Untitled Document</title>
</head>

<body background="maps.jpeg">
<form method="post" action="actions.php" >
<fieldset>
  <h1><strong>Enter Longitude</strong> :
  <input type="text" name="text1" />
  </h1>
  <h1><strong>Enter Latitude :</strong>
    <input type="text" name="text2" />
  </h1>
  <p>&nbsp;</p>
  <input type="submit" value="Submit Location" />

</fieldset>

</form>
<form action="RecieveCoordinates.php" method="post">
<input type="submit" value="update" />

</fieldset> 
</form>
</body>
</html>