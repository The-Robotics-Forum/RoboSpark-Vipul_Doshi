<?php
include('db.php');
if(isset($_POST['submit']))
{
  $user_id=$_POST['user_id'];
  $query="SELECT *FROM `student` WHERE `student_id`='$user_id'";
  $run = mysqli_query($con,$query);
  $row = mysqli_num_rows($run);
  if($row==1)
  {
   echo "sucess";
   $user_row=mysqli_fetch_assoc($run);
   print_r($user_row);
  }
  else{
    echo "failed";
  }
}
?>
