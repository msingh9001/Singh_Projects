/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*setShippingDate Function*/
CREATE OR REPLACE procedure setShippingDate (l_order in varchar, l_date in date)
is
/*Update the shipping date where the orderid is the one provided in function call*/
begin
	update itemorder
		set shippeddate = l_date where orderid = l_order;
end;
/
show errors;