/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*updateGold Trigger*/
CREATE OR REPLACE trigger updateGold
after update on customers
for each row
begin
	/*If custtype is being changed to gold from regular*/
	if :new.custtype = 'gold' and :old.custtype = 'regular'
    then
	/*Shipping Fee is now 0 since gold for customer who's custtype is being changed*/
	update itemorder
	set shippingfee = 0 
    where custid = :new.custid and (shippeddate is null or shippeddate >sysdate);
	end if;
end;
/
show error;