<?php
$conn=oci_connect('username','password', '//dbserver.engr.scu.edu/db11g');
if($conn) {
        print "<br> Connection to the database successful";
} else {
        $e = oci_error;
        print "<br> connection failed:";
        print htmlentities($e['message']);
        exit;
}

echo "<BR/>";
//Open and read contents of the text file, staff.txt
$handle = fopen('./staff.txt', "r");
for($i =1;($data = fgetcsv($handle, 10000)) !== FALSE; $i++) {
//	Prepare the SQL statement to insert values 		
$sql = "INSERT INTO Staff_2010(Last,First,status,salary,salary_type,title)          VALUES('".$data[0]."','".$data[1]."','".$data[2]."',".$data[3].",'".$data[4]."','".$data[5]."')";
$stid = oci_parse($conn, $sql);
// Execute the statement
oci_execute($stid);
}
oci_free_statement($stid);
oci_close($conn);
fclose($handle);
?>
