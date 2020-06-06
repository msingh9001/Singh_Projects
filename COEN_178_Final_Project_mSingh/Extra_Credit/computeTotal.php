/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*PHP computeTotal*/

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8"/>
      <title>Compute Total</title>
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
         $total = getTotalFromDB($orderid);
         echo "Order ID: $orderid <br>";
         echo "Total: $total <br>";
     }
}

function getTotalFromDB($orderid){
    $conn=oci_connect('username','password', '//dbserver.engr.scu.edu/db11g');
    if(!$conn) {
        print "<br> connection failed:";
        exit;
    }
    $query = oci_parse($conn, "select computeTotal(orderid) from itemorder where orderid = :bv");
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
