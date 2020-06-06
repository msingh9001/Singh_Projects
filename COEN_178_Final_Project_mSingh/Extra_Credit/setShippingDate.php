/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*PHP setShippingDate*/
<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // collect input data from the form
    $orderid = $_POST['orderid'];
    $date = $_POST['date'];
    
    if (!empty($orderid)){
       $orderid = prepareInput($orderid);
    }
    
    if (!empty($date)){
       $date = prepareInput($date);
    }
    
    setShippingDate($orderid, $date);
    
}

function prepareInput($inputData){
    $inputData = trim($inputData);
      $inputData  = htmlspecialchars($inputData);
      return $inputData;
}

function setShippingDate($orderid, $date){
    $conn = oci_connect('username', 'password', '//dbserver.engr.scu.edu/db11g');
    
    if (!$conn) {
        $e = oci_error();
        trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
    }
    if(!$conn) {
         print "<br> connection failed:";
        exit;
    }
    // Running PSQL function
    $sql = oci_parse($conn, 'begin setShippingDate(:order, :date,); end;');

    oci_bind_by_name($sql, ':order', $orderid);
    oci_bind_by_name($sql, ':date', $date);
    
    // Execute the query
    $res = oci_execute($sql);
    
    if ($res){
        echo '<br><br> <p style="color:green;font-size:20px">';
        echo "Updated Date </p>";
    }
    else{
        $e = oci_error($query);
            echo $e['message'];
    }

    oci_free_statement($sql);
    OCILogoff($conn);
}
?>
