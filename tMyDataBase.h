#pragma once
//#define _WIN32
#include <iostream>
#include <string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class tMyDataBase
{
private:

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement *stmt;
	sql::ResultSet *res;

	std::string name;
	std::string url;
	std::string usr;
	std::string passwd;
	std::string database;
	FILE* tlogF;

//	class tRecord{
//	public:
//		static void pVerbose(FILE* stream, int vb, const char* format, ...);
//	};

public:

	tMyDataBase();
	~tMyDataBase();
	int OpenDB(std::string url, std::string usr, std::string passwd, std::string database);

	int DBExec(std::string sql);
	int DBExecQuary(std::string sql);
	
/*
	int GetResInt(int i);
	int GetResInt(std::string str);
	double GetResDouble(int i);
	double GetResDouble(std::string str);

	std::string GetResStr(int i);
	std::string GetResStr(std::string str);

	bool GetNext(void);

	static int tCount;	// the number of databases created 
*/

};



