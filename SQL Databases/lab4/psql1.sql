Create or Replace Procedure setSalaries(low in INTEGER, high in INTEGER)
AS
Cursor Emp_cur IS
    Select * from AlphaCoEmp;
    l_emprec Emp_cur%rowtype;
    l_salary AlphaCoEmp.salary%type;
BEGIN
    for l_emprec IN Emp_cur
    loop
        l_salary := ROUND(dbms_random.value(low,high)); 
        update AlphaCoEmp 
        set salary = l_salary 
        where name = l_emprec.name;   
END LOOP;
    commit;
END;
/
show errors;