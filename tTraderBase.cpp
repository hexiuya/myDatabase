#include "tTraderBase.h"
using namespace LRS;

#define LRS_TRADERID		121
#define LRS_TRADERUNITID	100
#define LRS_TRADERINCODE	1153202979584158078

//std::uint32_t tTraderBase::traderId = LRS_TRADERID;
//std::uint32_t tTraderBase::tradeUnitId = LRS_TRADERUNITID;
//std::uint64_t tTraderBase::innerCode = LRS_TRADERINCODE;
tTraderBase* tTraderBase::m_pInstance = NULL;
tMyDataBase* tTraderBase::isonDB = NULL;		


tTraderBase::tTraderBase()
{
}

tTraderBase::~tTraderBase()
{}

tTraderBase* tTraderBase::tObject()
{
	if (tTraderBase::m_pInstance != NULL)
	{
		return tTraderBase::m_pInstance;
	}

	tTraderBase::m_pInstance = new tTraderBase();
	tTraderBase::isonDB = new tMyDataBase();
	tTraderBase::isonDB->OpenDB("172.24.13.5:3306","ison2","ison2","ison26" );
	
	return tTraderBase::m_pInstance;
}

tTraderBase* tTraderBase::tObject(std::string url, std::string usr, std::string passwd, std::string database)
{
	if (tTraderBase::m_pInstance != NULL)
	{
		tTraderBase::m_pInstance = new tTraderBase();
		tTraderBase::isonDB =  new tMyDataBase();
		tTraderBase::isonDB->OpenDB(url, usr, passwd, database);
	}
	return tTraderBase::m_pInstance;
}

void tTraderBase::tByeBye(void)
{
	if (tTraderBase::m_pInstance != NULL)
	{
		delete tTraderBase::m_pInstance;
		tTraderBase::m_pInstance = NULL;
		delete tTraderBase::isonDB;
		tTraderBase::isonDB = NULL;
	}

}

/*
void tTraderBase::tTakeSnap(void)
{
//	void tstrader(int id);
//	this->SnapBase.tGet_tstrader(tTraderBase::traderId, this->isonDB);
//	this->SnapBase.tGet_tstrader_sa(tTraderBase::traderId, tTraderBase::innerCode, this->isonDB);
	//this->SnapBase.tPrint_tstrader();

}

tDBSnap& tTraderBase::tGetSnapDB(void)
{
//	return this->SnapBase;
}

void tTraderBase::tResetOMS(void)
{
	std::cout <<"[RESET OMS]"<<std::endl;
	return;
}

void tTraderBase::tResetISONDB(void)
{
	std::cout << "[RESET DATABASE]" << std::endl;
	return;
}

*/
#undef LRS_TRADERID
#undef LRS_TRADERUNITID

