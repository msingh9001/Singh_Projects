/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*computeTotal Function*/
create or replace function computeTotal (l_order in varchar)
return number is
	/*Defining*/
	total number(10,2);
    ctype customers.custtype%type;
    copies itemorder.noofitems%type;
    l_price storeItems.price%type;
begin
	total := 0;
	/*Finding out customer type, number of items they ordered, and the price of the items*/
    select custtype into ctype from customers where custid = (select custid from itemorder where orderid = l_order);
    select noofitems into copies from itemorder where orderid = l_order;
    select price into l_price from storeItems where itemid = (select itemid from itemorder where orderid = l_order);
    /*If the customer type is regular, then total is order total + $10 shipping fee + 5% tax*/
	if ctype = 'regular' then
    	total := total + 10 + l_price*copies*1.05; 
	else
	/*If the customer type is gold and the order is less than 100 copies, then total is order total + 5% tax*/
		if l_price*copies < 100 then
			total := total + l_price*copies*1.05;
		else
		/*If the customer type is gold and the order is more than 99 copies, then total is order total with 10% discount + 5% tax*/
			total := total + l_price*copies*0.9*1.05;
		end if;
	end if;
	return total;
end;
/
show error;