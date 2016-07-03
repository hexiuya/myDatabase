#include <iostream>
#include "tTraderBase.h"
#include "tMyDataBase.h"

void testdb(void);
void testbase(void);

int main()
{
	LRS::tTraderBase::tObject("127.0.0.1:3306","root","123456","myDatabase");
//	ISONDB<<"INSERT INTO usertable (usrname, passwd) VALUES(222, 222);";
	ISONDB<<"call compare_passwords('hexiuya01','G012#you', @status);";
	ISONDB>>"select @status;";

	int tmp = ISONDB.tGetDB()->GetResInt("@status");

	std::cout<<"####"<<tmp<<std::endl;

	return 0;
}


void testdb(void)
{
	tMyDataBase* mdb = new tMyDataBase();
//	std::cout<<"0 helloworld"<<std::endl;
	mdb->OpenDB("127.0.0.1:3306","root","123456","testdb");
//	std::cout<<"1 helloworld"<<std::endl;
	mdb->DBExec("INSERT INTO usertable (usrname, passwd) VALUES(111, 11);");
//	std::cout<<"2 helloworld"<<std::endl;
	delete mdb;				
}


void testbase(void)
{
	
}


