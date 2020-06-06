/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*PHP updateGold*/
<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // collect input data from the form
    $custid = $_POST['custid'];
    
    if (!empty($custid)){
       $custid = prepareInput($custid);
    }

    updateGold($custid);
    
}

function prepareInput($inputData){
    $inputData = trim($inputData);
      $inputData  = htmlspecialchars($inputData);
      return $inputData;
}

function updateGold($custid){
    $conn = oci_connect('username', 'password', '//dbserver.engr.scu.edu/db11g');
    
    if (!$conn) {
        $e = oci_error();
        trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
    }
    if(!$conn) {
         print "<br> connection failed:";
        exit;
    }
    // Updating in Customers
    $sql = oci_parse($conn, "Update Customers SET custtype = 'gold' where custid = :cust");
    
    oci_bind_by_name($sql, ':cust', $custid);
    
    //Inserting into GoldCustomer
    $sql = oci_parse($conn, "Insert into GoldCustomer values(:id, sysdate)");
    
    oci_bind_by_name($sql2, ':id', $custid);
    
    // Execute the query
    $res = oci_execute($sql);
    $res2 = oci_execute($sql2);
    
    if ($res){
        echo '<br><br> <p style="color:green;font-size:20px">';
        echo "Updated in Customer </p>";
    }
    else{
        $e = oci_error($query);
            echo $e['message'];
    }
    if ($res2){
        echo '<br><br> <p style="color:green;font-size:20px">';
        echo "Inserted into GoldCustomers</p>";
    }
    else{
        $e = oci_error($query);
            echo $e['message'];
    }
    oci_free_statement($sql);
    oci_free_statement($sql2);
    OCILogoff($conn);
}
?>
