select deptid AS deptno, Count(deptid) AS empcount from L_EMP GROUP BY deptid;
select deptno, deptname, empcount from (select deptid AS deptno, Count(deptid) AS empcount from L_EMP GROUP BY deptid),L_DEPT where deptno = L_DEPT.deptid;
select deptno, deptname, empcount from (select deptid AS deptno, Count(deptid) AS empcount from L_EMP GROUP BY deptid),L_DEPT where deptno = L_DEPT.deptid ORDER BY empcount ASC;
Select deptid, max(count(*)) from L_EMP Group by deptid;
Select deptid from L_EMP Group by deptid Having count(*) IN (Select count(*) from L_EMP Group by deptid);
select deptname from L_DEPT where L_DEPT.deptid IN (select deptid from L_EMP Group by deptid Having count(*) IN (Select count(*) from L_EMP Group by deptid));
Select * from L_EMP NATURAL JOIN L_DEPT;
Select L_EMP.deptid, empno, empname, deptname from L_EMP, L_DEPT;

