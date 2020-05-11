CREATE or REPLACE TRIGGER display_customer_trig
AFTER  INSERT ON BankCust_6
FOR EACH ROW
BEGIN
DBMS_OUTPUT.PUT_LINE('From Trigger '||'Customer NO: '||:new.custno||' Customer Name: '||:new.custname);
END;
/
show errors;