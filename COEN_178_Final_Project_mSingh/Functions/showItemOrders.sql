/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*showItemOrders Function*/
CREATE OR REPLACE procedure showItemOrders(l_cust in varchar, l_date in date)
is
	/*Defining*/
	l_name customers.name%type;
	l_phone customers.phone%type;
	l_address customers.address%type;
	cursor c_order is 
/*Select all the information needed to be displayed from all tables where the orderid is of the customer provided*/
select a.orderid, a.itemid, b.title, c.price, a.dateoforder, a.shippeddate, a.noofitems 
from itemorder a, storeItems c, comicbook b 
where a.custid = l_cust and a.itemid = b.itemid and a.itemid = c.itemid and a.dateoforder > l_date; 
	/*Defining types*/
	l_order itemorder.orderid%type;
	l_item itemorder.itemid%type;
	l_title comicbook.title%type;
	l_price storeItems.price%type;
	l_orderdate itemorder.dateoforder%type;
	l_shipdate itemorder.shippeddate%type;
	l_totalitem storeItems.price%type;
	l_tax storeItems.price%type;
	l_fee storeItems.price%type;
	l_discount storeItems.price%type;
	l_total storeItems.price%type;
	l_no int;
	l_type customers.custtype%type;

begin 
	/*Get customer type, name, phone, and address where custid is the customer provided*/
	select custtype into l_type from customers where custid = l_cust;
	select name into l_name from customers where custid = l_cust;
	select phone into l_phone from customers where custid = l_cust;
	select address into l_address from customers where custid = l_cust;
	/*Formatting*/
	dbms_output.put_line('Customer Information:');
	dbms_output.put_line('id: ' || l_cust);
	dbms_output.put_line('name: ' || l_name);
	dbms_output.put_line('phone: ' || l_phone);
	dbms_output.put_line('address: ' || l_address);

	open c_order;
	/*Looping to get information for all orders for a customer*/
	loop
	/*Retrieve information*/
	fetch c_order into l_order, l_item, l_title, l_price, l_orderdate, l_shipdate, l_no;
	EXIT WHEN c_order%notfound;
	/*Formatting*/ 
	dbms_output.put_line('Order Information:');
	dbms_output.put_line('Order id: ' || l_order || ', item id: ' ||l_item || ', title: '||l_title||', price: ' || l_price || ', Order date: '||l_orderdate||', shipping date: ' ||l_shipdate);
    /*Calculating some outputs*/
	/*If regular then calculate the regular customer price level*/
	if l_type = 'regular' then
		l_totalitem := l_price*l_no;
		l_tax := l_totalitem*0.05;
		l_fee := 10;
		l_discount:= 0;
    	l_total := 10 + l_price*l_no*1.05; 
	else
	/*If gold, then calculate the gold customer price level*/
		l_fee := 0;
		l_totalitem := l_price*l_no;
		if l_price*l_no < 100 then
			l_tax := l_totalitem*0.05;
			l_discount := 0;
			l_total := l_totalitem*1.05;
		else
		/*If gold and > 100 copies 10% discount*/
			l_tax := l_totalitem*0.9*0.05;
			l_discount := l_totalitem*0.1;
			l_total := l_totalitem*0.9*1.05;
		end if;
	end if;
	/*Formatting*/
	dbms_output.put_line('Payment Details:');
	dbms_output.put_line('Item(s) Total: '||l_totalitem||', Tax: '||l_tax||', Discount: '||l_discount||', Shipping Fee: '||l_fee||', Total: '||l_total);
	end loop;
	close c_order;
end;
/
show error;  