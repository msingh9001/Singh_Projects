/*Mandeep Singh Number 8*/
Select * From Emp_Office;
Select * From Emp_Phone;
Select EO.OfficeNo From Emp_Office EO, Emp_Phone EP
WHERE EO.EmpNo = EP.EmpNo
GROUP BY OfficeNo
HAVING count(DISTINCT EP.PhoneNo)>1;