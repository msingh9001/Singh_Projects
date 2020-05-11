select custid, city, firstname||lastname AS fullname from cust;
select * from cust ORDER BY lastname;
select * from schedule ORDER BY serviceid, custid desc;
select serviceid from deliveryservice MINUS select serviceid from schedule;
select firstname||lastname AS fullname from cust, schedule where day = 'm';
select lastname from cust, schedule where cust.custid = schedule.custid;
select MAX(servicefee) as highestServiceFee from deliveryservice;
select count(day) from schedule GROUP BY day;
select A.custid,B.custid,A.city from Cust A, Cust B where A.city = B.city;
select custid from cust, deliveryservice where cust.city = deliveryservice.location;
select MIN(salary) as MinimumSalary from staff_2010;
select MAX(salary) as MaximumSalary from staff_2010;
