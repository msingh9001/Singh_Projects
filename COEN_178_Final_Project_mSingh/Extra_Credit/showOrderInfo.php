/*Mandeep Singh
COEN 178 Final Project
PHP showOrderInfo*/
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8"/>
      <title>Show Order Info</title>
   </head>
   <body>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
  Order ID: <input type="text" name="orderid" id="orderid">
  <input type="submit">
 </form>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    # collect input data
     $orderid = $_POST['orderid'];

     if (!empty($orderid)){
         $orderid = prepareInput($orderid);
         $itemid = getItemidFromDB($orderid);
         $custid = getCustidFromDB($orderid);
         $dateOfOrder = getDateoforderFromDB($orderid);
         $noOfItems = getNoofitemsFromDB($orderid);
         $shippingFee = getShippingfeeFromDB($orderid);
         echo "Order ID: $orderid <br>";
         echo "Item ID: $itemid <br>";
         echo "Customer ID: $custid <br>";
         echo "Date of Order: $dateOfOrder <br>";
         echo "Number of Items: $noOfItems <br>";
         echo "Shipping Fee: $shippingFee <br>";
     }
}

function getItemidFromDB($orderid){
    $conn=oci_connect('username','password', '//dbserver.engr.scu.edu/db11g');
    if(!$conn) {
        print "<br> connection failed:";
        exit;
    }
    $query = oci_parse($conn, "SELECT itemid FROM itemOrder where orderid= :bv");
    oci_bind_by_name($query,':bv',$orderid);
    oci_execute($query);

    if (($row = oci_fetch_array($query, OCI_BOTH)) != false) {
        $itemid = $row[0];
    }
    else {
        echo "Error <br>\n";
    }
    oci_free_statement($query);
    oci_close($conn);

    return $itemid;
    }

function getCustidFromDB($orderid){
    $conn=oci_connect('username','password', '//dbserver.engr.scu.edu/db11g');
    if(!$conn) {
        print "<br> connection failed:";
        exit;
    }
    $query = oci_parse($conn, "SELECT custid FROM itemOrder where orderid= $orderid");
    oci_execute($query);

    if (($row = oci_fetch_array($query, OCI_BOTH)) != false) {
        $custid = $row[0];
    }
    else {
        echo "Error <br>\n";
    }
    oci_free_statement($query);
    oci_close($conn);

    return $custid;
}

function getDateoforderFromDB($orderid){
    $conn=oci_connect('username','password', '//dbserver.engr.scu.edu/db11g');
    if(!$conn) {
        print "<br> connection failed:";
        exit;
    }
    $query = oci_parse($conn, "SELECT dateOfOrder FROM itemOrder where orderid= :bv");
    oci_bind_by_name($query,':bv',$orderid);
    oci_execute($query);

    if (($row = oci_fetch_array($query, OCI_BOTH)) != false) {
        $dateOfOrder = $row['DATEOFORDER'];
    }
    else {
        echo "Error <br>\n";
    }
    oci_free_statement($query);
    oci_close($conn);

    return $dateOfOrder;
    }

function getNoofitemsFromDB($orderid){
    $conn=oci_connect('username','password', '//dbserver.engr.scu.edu/db11g');
    if(!$conn) {
        print "<br> connection failed:";
        exit;
    }
    $query = oci_parse($conn, "SELECT noOfItems FROM itemOrder where orderid= :bv");
    oci_bind_by_name($query,':bv',$orderid);
    oci_execute($query);

    if (($row = oci_fetch_array($query, OCI_BOTH)) != false) {
        $noOfItems = $row['NOOFITEMS'];
    }
    else {
        echo "Error <br>\n";
    }
    oci_free_statement($query);
    oci_close($conn);

    return $noOfItems;
}
    
function getShippingfeeFromDB($orderid){
    $conn=oci_connect('username','password', '//dbserver.engr.scu.edu/db11g');
    if(!$conn) {
        print "<br> connection failed:";
        exit;
    }
    $query = oci_parse($conn, "SELECT shippingFee FROM itemOrder where orderid= :bv");
    oci_bind_by_name($query,':bv',$orderid);
    oci_execute($query);

    if (($row = oci_fetch_array($query, OCI_BOTH)) != false) {
        $shippingFee = $row['SHIPPINGFEE'];
    }
    else {
        echo "Error <br>\n";
    }
    oci_free_statement($query);
    oci_close($conn);

    return $shippingFee;
}
    
function prepareInput($inputData){
    // Removes any leading or trailing white space
    $inputData = trim($inputData);
    // Removes any special characters that are not allowed in the input
    $inputData  = htmlspecialchars($inputData);
    return $inputData;
}

?>
<!-- end PHP script -->
   </body>
</html>
