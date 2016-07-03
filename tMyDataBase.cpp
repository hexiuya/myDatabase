#include "tMyDataBase.h"
#include <stdio.h>
#include <string.h>
#include <stdexcept>

#include <cppconn/exception.h>

#define DB_LOG "../DataBase/"
#define M_VERBOSE			4
#define	M_INFO_LEVEL		2


//int tMyDataBase::tCount = 0;

tMyDataBase::tMyDataBase()
{
	this->driver = get_driver_instance();
	this->name = "log";
	this->url  = "";

	this->usr = "";
	this->passwd = "";
	this->database= "";

	char logname[128];
	memset(logname, 0, sizeof(logname));
//	sprintf_s(logname, "%s%d%s_my.txt", DB_LOG, tCount, this->name.c_str());
	this->tlogF = fopen(logname, "w");

//	tCount++;
//	tMyDataBase::tRecord::pVerbose(this->tlogF, M_INFO_LEVEL, "\n[SUCCESS]{DataBase}[CREATE]\t(%s)", this->name.c_str());
}

tMyDataBase::~tMyDataBase()
{
	this->name = "";
	this->url = "";

	this->usr = "";
	this->passwd = "";
	this->database = "";

	delete this->res;
	delete this->stmt;
	delete this->con;
	//delete this->driver;// special can not be deleted
	//free(this->driver);
	this->driver->threadEnd();
}

int tMyDataBase::OpenDB(std::string url, std::string usr, std::string passwd, std::string database)
{
	this->con = driver->connect(url, usr, passwd);
	// adding expection later //
	std::string str = "USE " + database;
	this->stmt = this->con->createStatement();
	std::cout << str << std::endl;
	this->stmt->execute(sql::SQLString(str));
	return 0;
}

int tMyDataBase::DBExec(std::string sql)
{ 
	try{
		this->stmt->execute(sql::SQLString(sql));
	}
	catch (sql::SQLException &e)
	{
	//	std::cout<<"error"<<std::endl;
//		tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
	}
	// adding exception
	return 0;
}

int tMyDataBase::DBExecQuary(std::string sql)
{
	try{
		this->res = this->stmt->executeQuery(sql::SQLString(sql));
	//	printf();
	}
	catch (sql::SQLException &e)
	{
	//	tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
	}
	// adding exception
	return 0;
}

int tMyDataBase::GetResInt(int i)
{
	int retcode = -1;
	sql::ResultSet * temp = this->res;
	try{
		if (temp->next())
		{
			retcode = temp->getInt(i);
			temp->previous();
			return retcode;
		}
		else
			return retcode;// and then report errors
	}
	catch (sql::SQLException &e)
	{
//		tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
		return retcode;// and then report errors
	}
}

int tMyDataBase::GetResInt(std::string str)
{
	int retcode = -1;
	sql::ResultSet * temp = this->res;
	try{
		if (temp->next())
		{
			retcode = temp->getInt(str);
			temp->previous();
			return retcode;
		}
		else
			return -1;// and then report errors
	}
	catch (sql::SQLException &e)
	{
//		tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
		return retcode;// and then report errors
	}
}

double tMyDataBase::GetResDouble(int i)
{
	double retcode = -1;
	sql::ResultSet * temp = this->res;
	try{
		if (temp->next())
		{
			retcode = temp->getDouble(i);
			temp->previous();
			return retcode;
		}
		else
			return retcode;// and then report errors
	}
	catch (sql::SQLException &e)
	{
//		tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
		return retcode;// and then report errors
	}
}

double tMyDataBase::GetResDouble(std::string str)
{
	double retcode = -1;
	sql::ResultSet * temp = this->res;
	try{
		if (temp->next())
		{
			retcode = temp->getDouble(str);
			temp->previous();
			return retcode;
		}
		else
			return retcode;// and then report errors
	}
	catch (sql::SQLException &e)
	{
//		tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
		return retcode;// and then report errors
	}
}

std::string tMyDataBase::GetResStr(int i)
{
	std::string retcode = "X";
	sql::ResultSet * temp = this->res;
	try{
		if (temp->next())
		{
			retcode = temp->getString(i);
			temp->previous();
			return retcode;
		}
		else
			return retcode;// and then report errors
	}
	catch (sql::SQLException &e)
	{
//		tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
		return retcode;// and then report errors
	}
}

std::string tMyDataBase::GetResStr(std::string str)
{
	std::string retcode = "X";
	sql::ResultSet * temp = this->res;
	try{
		if (temp->next())
		{
			retcode = temp->getString(str);
			temp->previous();
			return retcode;
		}
		else
			return retcode;// and then report errors
	}
	catch (sql::SQLException &e)
	{
//		tMyDataBase::tRecord::pVerbose(stdout, M_INFO_LEVEL, "Erro:%s(%i)[%s](#E:%i)[#S:%s]{%s}", __FILE__, __LINE__, __FUNCTION__, e.getErrorCode(), e.getSQLState().c_str(), e.what());
		return retcode;// and then report errors
	}
}

bool tMyDataBase::GetNext(void)
{
	return this->res->next();
}

/*
void tMyDataBase::tRecord::pVerbose(FILE* stream, int vb, const char* format, ...)
{
	if (vb > M_VERBOSE)
		return;
	va_list args;
	va_start(args, format);
	vfprintf(stream, format, args);
	va_end(args);
}
*/
