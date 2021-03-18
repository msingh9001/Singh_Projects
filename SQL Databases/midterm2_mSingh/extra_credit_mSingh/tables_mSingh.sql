/*Mandeep Singh Extra Credit*/
create table Book(
bookid char(2),
title varchar(20),
author varchar(20),
PRIMARY KEY(bookid)
);
create table Applicant(
applicantid char(2),
aname varchar(10),
PRIMARY KEY(applicantid)
);
create table BooksRead(
applicantid char(2),
bookid char(2),
FOREIGN KEY(applicantid) REFERENCES Applicant,
FOREIGN KEY(bookid) REFERENCES Book,
PRIMARY Key(applicantid, bookid)
);