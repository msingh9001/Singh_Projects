CREATE TABLE Course(courseNo INTEGER PRIMARY KEY, courseName VARCHAR(20));
CREATE TABLE Course_Prereq(courseNo INTEGER, prereqNo Integer, Foreign Key(prereqNo) references Course (courseNo));
insert into Course values (10,'C++');
insert into Course values (11,'Java');
insert into Course values (12,'Python');
insert into Course values (121,'Web');
insert into Course values (133,'Software Eng');