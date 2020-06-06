/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*addItemOrder Function*/
CREATE OR REPLACE procedure addItemOrder(l_item in varchar, l_cust in varchar, l_order in varchar, l_no in int, l_orderdate in date, l_shippeddate in date)
IS
    /*Defining*/
	l_bookno int;
    l_fee itemorder.shippingfee%type;
	l_type customers.custtype%type;
    comic int;
begin
    /*Find out customer type*/
	select custtype into l_type 
    from customers 
    where custid = l_cust;
    /*Load number ordered into variable*/
    select noofcopies 
    into l_bookno 
    from comicbook 
    where itemid = l_item;
    /*Set shipping fee based on customer type*/
    if l_type = 'regular' then
		l_fee := 10;
	else
		l_fee := 0;
	end if;
    /*Find out how many copies of each comicbook there are*/
	select count(*) into comic from comicbook group by itemid having itemid = l_item;
	if comic = 1 
    then
        /*If the number ordered is less than number available*/
        if l_no <= l_bookno 
        then
            /*Update value of comicbook*/
            update comicbook
                set noofcopies = noofcopies - l_no 
                where itemid = l_item;
        /*There are not enough comicbooks for order*/
        else
            dbms_output.put_line('Not enough comic books');
            return;
        end if;
	end if;
    /*After all is run, insert into values*/
    insert into itemorder values (l_order, l_item, l_cust, l_orderdate, l_no, null, l_fee);
end;
/
show error;