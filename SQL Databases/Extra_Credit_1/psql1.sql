Create or Replace FUNCTION Something (v_sno IN Supplier.SNO%TYPE) 
RETURN NUMBER IS l_cnt NUMBER;
BEGIN
    Select count(city) into l_cnt
    From Supplier
    Where city = (Select city From Supplier where v_sno = sno);
    return l_cnt;
END;
/
show errors;