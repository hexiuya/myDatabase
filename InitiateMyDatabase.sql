create database if not exists myDatabase;
USE myDatabase

drop table if exists users;
create table users(user_id int auto_increment not null primary key, user_name varchar(15) not null, password nvarchar(15));

create unique index comp on users (`user_id`,`user_name`);

insert into users (user_name, password) values ("hexiuya01","G012#you"),("jennybay02","H2$9heBv"),("adazhao33","V90(Tbo1"),("ailenzeng00","Ww7&rue0"),("katedeng09","3$5(12Hi"),("markning20","7^012!Lo"),("jacksonyuan01","i<3%09Fw"),("jasonwang1","wir7^0qA"),("helenliu10","jq1@?098"),("michaellin05","sue&Mcve");

drop procedure if exists compare_passwords;

delimiter //

create procedure compare_passwords (IN local_usrname varchar(15), IN local_pswd nvarchar(15))

BEGIN
IF (select count(*) from users where user_name=local_usrname and password=local_pswd) >0 THEN
select 'Match';

ELSEIF (select count(*) from users where user_name=local_usrname and password <> local_pswd) >0 THEN
select 'Not Match';

ELSE
select 'Not exists';

END IF;

END //

delimiter ;

drop procedure if exists NEW_A_USER;

delimiter //

create procedure New_A_USER (IN local_usrname varchar(15), IN local_pswd nvarchar(15))

BEGIN

IF (select count(*) from users where user_name=local_usrname) >0 THEN
select 'Username already exists, please try another one.';

ELSEIF (select count(*) from users where user_name=local_usrname)=0 THEN
insert into users (user_name, password) values (local_usrname, local_pswd);

END IF;

END //

delimiter ; 
 

