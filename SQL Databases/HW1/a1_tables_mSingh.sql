create table Student(
studentId char(3),
name varchar(20),
city varchar(15),
PRIMARY KEY(studentID)
);
create table SummerJob(
jobId char(5),
jobTitle varchar(25),
company varchar(20),
city varchar(20),
hrlyPay decimal(4,2),
PRIMARY KEY(jobId)
);
create table Student_Work(
studentId char(3),
jobId char(5),
hrsWorked INT,
StartDate DATE,
EndDate DATE,
PRIMARY KEY(studentId, jobId),
FOREIGN KEY(studentId) REFERENCES Student(studentId),
FOREIGN KEY(jobId) REFERENCES SummerJob(jobId)
);
