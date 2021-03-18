/*Mandeep Singh Extra Credit*/
Select * From Book;
Select * From Applicant;
Select * From BooksRead;
Select A.ANAME
From Applicant A, BooksRead R
Where A.applicantid = R.applicantid
Group By ANAME
Having count(R.BookID)= (select count(B.BookID) From Book B);