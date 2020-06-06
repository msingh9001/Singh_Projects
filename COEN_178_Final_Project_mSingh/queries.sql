spool COEN178Project.txt
/*Dropping old tables from previous queries.sql execution for fresh spool*/
drop table goldcustomer;
drop table itemorder;
drop table comicbook;
drop table tshirt;
drop table storeItems;
drop table customers;
set serveroutput on;
/*Create the tables*/
start tables.sql
/*Insert the values into tables*/
start values.sql
/*Create the triggers and functions*/
start addItemOrder.sql
start updateGold.sql
start setShippingDate.sql
start computeTotal.sql
start showItemOrders.sql
/*Display tables and respective values*/
select * from storeItems;
select * from comicbook;
select * from tshirt;
select * from customers;
select * from goldcustomer;
/*Show original itemorder table*/
select * from itemorder;
/*Run addItemOrder function*/
execute addItemOrder('item1', 'c001', 'o001', 1, '1-jun-2020', '8-jun-2020');
execute addItemOrder('item2', 'c002', 'o002', 2, '2-jun-2020', '9-jun-2020');
execute addItemOrder('item6', 'c003', 'o003', 4, '2-jun-2020', '9-jun-2020');
execute addItemOrder('item9', 'c001', 'o004', 3, '3-jun-2020', '10-jun-2020');
/*Display table and respective values to show addItemOrder functions worked*/
select * from itemorder;
/*Display original comicbook table*/
select * from comicbook;
/*Update customer type*/
update customers set custtype = 'gold' where custid = 'c001';
/*Display table and respective values to show trigger updateGold worked*/
select * from customers;
/*Display original itemorder table*/
select * from itemorder;
/*Run setShippingDate function*/
execute setShippingDate('o001', '5-jun-2020');
/*Display tables and respective values to show setShippingDate function worked*/
select * from itemorder;
/*Display computed total value where orderid is o001 to show computeTotal function works*/
select computeTotal(orderid) from itemorder where orderid = 'o001';
/*Run showItemOrders function to show showItemOrders function works*/
execute showItemOrders('c001', '1-jan-2015');
spool off;