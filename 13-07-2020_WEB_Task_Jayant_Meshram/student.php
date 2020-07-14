<?php
include('db.php');
    if(isset($_POST['search']))
    {
        $stud_id = $_POST['id'];
        $new_query = "SELECT * FROM `students`";
        $result = mysqli_query($con,$new_query);
        $index = mysqli_num_rows($result);

        $query = "SELECT * FROM `students` WHERE `stud_id`='$stud_id'";
        $run = mysqli_query($con,$query);
        $row = mysqli_num_rows($run);
        $arr = mysqli_fetch_assoc($run);
        $keys= array_keys($arr);
        if($row==1)
        {
            echo "Found!";
        }
        else
        {
            echo "Last ID is " .$index ." Please enter equal or low value than that" ."<br>";
            die("Error-No such id found!");
        }
    }
?>
<html>
    <head>
        <title>Display Data</title>
        <link rel="stylesheet" href="css/enroll.css">
        <link rel="icon" href="images/webicon.png">
        <!--Fontawesome CDN Link-->
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    </head>
    <body> 
        <div class="data_box">
            <div class="form_input">
                <i class="fa fa-id-card-o" aria-hidden="true"></i>
                Student ID : <?php echo $arr[$keys[0]]."<br>";?>
            </div>
            <div class="form_input">
                <i class="fa fa-id-card-o" aria-hidden="true"></i>
                Name : <?php echo $arr[$keys[1]]."<br>";?>
            </div>
            <div class="form_input">
                <i class="fa fa-book" aria-hidden="true"></i>
                Branch : <?php echo $arr[$keys[2]]."<br>";?>
            </div>
            <div class="form_input">
                <i class="fa fa-percent" aria-hidden="true"></i>
                CGPA : <?php echo $arr[$keys[3]]."<br>";?>
            </div>
            <p class="search"><a href="student.html">Return</a></p>
        </div>
    </body>
<html>
   