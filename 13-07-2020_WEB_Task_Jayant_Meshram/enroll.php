<?php
include('db.php');
    if(isset($_POST['submit_data']))
    {
        $stud_name = $_POST['name'];
        $branch = $_POST['branch'];
        $cgpa = $_POST['cgpa'];
        $query = "INSERT INTO `students`(`stud_name`, `branch`, `cgpa`) VALUES ('$stud_name', '$branch','$cgpa')";
        $run = mysqli_query($con,$query);
        $new_query = "SELECT * FROM `students`";
        $result = mysqli_query($con,$new_query);
        $index = mysqli_num_rows($result);
    }
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Database</title>
        <link rel="stylesheet" href="css/enroll.css">
        <link rel="icon" href="images/webicon.png">
    </head>

    <body>
        <div class="data_box">
            <h2><?php if (!$run==0 )
                {
                    echo "Student data Strored. Your Student ID no is : " .$index;
                }?> </h2>
            <p class="search"><a href="enroll.html">Return</a></p>
        </div>
    </body>
</html>