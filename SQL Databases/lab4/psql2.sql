Create or Replace Procedure setEmpSalary(p_name in VARCHAR, low in INTEGER, high in INTEGER)
AS
/* Define the local variables you need */
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
        where name = p_name;
END LOOP;
    commit;
END;
/
show errors;