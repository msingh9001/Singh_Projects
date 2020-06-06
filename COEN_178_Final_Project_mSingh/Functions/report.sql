/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*Report*/
/*Setting restrictions for pagesize and linesize*/
SET PAGESIZE 20
SET LINESIZE 200
/*Initializing report similar to lab*/
BREAK ON TODAY
COLUMN TODAY NEW_VALUE report_date
SELECT TO_CHAR(SYSDATE, 'fmMonth DD, YYYY') TODAY
FROM DUAL;

ff

set termout off
/*Setting title*/
ttitle center "Customer Report"  report_date skip 2
btitle center "Mandeep Singh COEN 178 Project"
spool report.txt
/*Formatting Column Headers*/
column custid format a5 heading "ID"
column name format a12 heading "Name"
column phone format a10 heading "Phone"
column address format a17 heading "Address"
column orderid format a6 heading "OrderID"
column itemid format a6 heading "itemid"
column title format a13 heading "title"
column dateoforder format a10 heading "OrderDate"
column shippeddate format a10 heading "shippeddate"
column itemtotal format $99999.00 heading "ItemTotal"
column grandtotal format $99999.00 heading "GrandTotal"
column tax format $99999.00 heading "Tax"
column shippingfee format $99999.00 heading "ShippingFee"
/*Select customer id, name, phone, address, orderid, itemid, 
title of comic book, price, date of order, shipping date, 
subtotal, tax, shipping fee, and order total from the 
natural join of customers, itemorder, comicbook, storeItems 
for customer with id c001 and order date after 10 august 2007*/
select custid, name, phone, address,orderid, itemid, title, price, dateoforder, shippeddate, noofitems*price as itemtotal,  computeTotal(orderid)-noofitems*price-shippingfee as tax, shippingfee, computeTotal(orderid) as grandtotal from customers natural join itemorder natural join comicbook natural join storeItems where custid = 'c001' and dateoforder >= '10-aug-2007';
spool off;
/*End of report necessities similar to lab*/
CLEAR COLUMNS
CLEAR BREAK
TTITLE OFF 
BTITLE OFF
SET VERIFY OFF 
SET FEEDBACK OFF
SET RECSEP OFF
SET ECHO OFF