/*Mandeep Singh*/
/*COEN 178 Final Project*/
/*createTables*/
/*Create storeItems table*/
Create table storeItems(
	Itemid varchar(10) primary key,
	Price number(10, 2)
);
/*Create comicBook table*/
Create table comicbook(
	Itemid varchar(10),
	ISBN varchar(10) primary key,
	Title varchar(20),
	Publisheddate date,
	Noofcopies int check (Noofcopies >= 0),
	Foreign key (Itemid) References storeItems(Itemid)
);
/*Create Tshirt table*/
Create table Tshirt(
	Itemid varchar(10),
	Sizes int,
	Foreign key(Itemid) References storeItems(Itemid)
);
/*Create Customers table*/
Create table Customers(
	Custid varchar(10) primary key,
	custtype varchar(10) check(custtype in ('regular', 'gold')),
	phone varchar(10) unique not null,
	name varchar(20),
	address varchar(50)
);
/*Create Goldcustomer table*/
Create table Goldcustomer(
	Custid varchar(20),
	Datejoined date,
	Foreign key (custid) references customers (custid)
);
/*Create Itemorder table*/
Create table Itemorder(
	Orderid varchar (10) primary key,
	Itemid varchar (10),
	Custid varchar (10),
	DateOfOrder date,
	NoofItems int,
	Shippeddate date,
	ShippingFee number(10, 2),
	check (shippeddate >= dateoforder),
	Foreign key(custid) references customers(custid),
	Foreign key(itemid) references storeItems(itemid)
);