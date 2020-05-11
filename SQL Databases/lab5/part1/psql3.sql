Create or Replace Function countByTitle(p_title in AlphaCoEmp.title%type) 
RETURN NUMBER 
IS 
l_cnt Integer; 
BEGIN
	/* Complete the query below */ 
Select count(p_title) into l_cnt from AlphaCoEmp 
Group by title
Having 
title = p_title;
return l_cnt; 
END; 
/ 
Show Errors;