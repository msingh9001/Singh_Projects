select last || first AS fullname, salary from Staff_2010 where salary = (select MAX(salary) from Staff_2010);
select last, salary from Staff_2010 where salary = (select salary from Staff_2010 where last = 'Zichal') OR salary = (select salary from Staff_2010 where last = 'zichal') OR salary = (select salary from Staff_2010 where last = 'ZICHAL');
select last, salary from Staff_2010 where salary IN (select salary from Staff_2010 where last = 'Young') OR salary IN (select salary from Staff_2010 where last = 'young') OR salary IN (select salary from Staff_2010 where last = 'YOUNG');
select Count(salary) AS Salaries_100k_Above from Staff_2010 where salary >= 100000;
select salary, Count(salary) AS Salaries_100k_Above from Staff_2010 where salary >= 100000 GROUP BY salary;
select salary, Count(salary) AS Salaries_100k_Above from Staff_2010 where salary >= 100000 GROUP BY salary HAVING Count(salary)>=10;
select last from Staff_2010 where REGEXP_LIKE (last, '([aeiou])\1', 'i');
