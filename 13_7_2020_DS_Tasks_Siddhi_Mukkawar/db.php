<?php
$con=mysqli_connect('localhost','root','','users');
if(!$con)
{
echo "Connection error".mysqli_connect_error();
}
else{
echo "<h3>database Success</h3>";
}
?>