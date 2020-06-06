/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*PHP getOrderInfo*/
<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // collect input data from the form
    $itemid = $_POST['itemid'];
    $custid = $_POST['custid'];
    $orderid = $_POST['orderid'];
    $noofcopies = $_POST['noofcopies'];
    
    if (!empty($itemid)){
       $itemid = prepareInput($itemid);
    }
    if (!empty($custid)){
       $custid = prepareInput($custid);
    }
    if (!empty($orderid)){
       $orderid = prepareInput($orderid);
    }
    if (!empty($noofcopies)){
       $noofcopies = prepareInput($noofcopies);
    }

    insertItemOrderIntoDB($itemid,$custid, $orderid, $noofcopies);
    
}

function prepareInput($inputData){
    $inputData = trim($inputData);
      $inputData  = htmlspecialchars($inputData);
      return $inputData;
}

function insertItemOrderIntoDB($itemid,$custid, $orderid, $noofcopies){
    $conn = oci_connect('username', 'password', '//dbserver.engr.scu.edu/db11g');
    
    if (!$conn) {
        $e = oci_error();
        trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
    }
    if(!$conn) {
         print "<br> connection failed:";
        exit;
    }
    // Calling the PLSQL procedure, addItemOrder
    $sql = oci_parse($conn, 'begin addItemOrder(:item, :cust, :order, :no, sysdate, NULL); end;');

    oci_bind_by_name($sql, ':item', $itemid);
    oci_bind_by_name($sql, ':cust', $custid);
    oci_bind_by_name($sql, ':order', $orderid);
    oci_bind_by_name($sql, ':no', $noofcopies);

    // Execute the query
    $res = oci_execute($sql);
    
    if ($res){
        echo '<br><br> <p style="color:green;font-size:20px">';
        echo "Item Order Inserted </p>";
    }
    else{
        $e = oci_error($query);
            echo $e['message'];
    }
    oci_free_statement($sql);
    OCILogoff($conn);
}
?>
