Create or Replace FUNCTION getEmpSalary(p_name in VARCHAR)
Return NUMBER IS
/* Define the local variables you need */
    l_salary  AlphaCoEmp.salary%type;
BEGIN
    Select salary 
    INTO l_salary
    FROM AlphaCoEmp
    where name = p_name;
    return l_salary;
END;
/
show errors;