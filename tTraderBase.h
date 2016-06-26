//#include "tDBSnap.h"
//#include "tTraderMeter.h"
//#include "tTraderUnitMeter.h"
//#include "tCapAccountMeter.h"
#include "tMyDataBase.h"
//#include <cstdint>
#include <stdint.h>
#include <stddef.h>

#pragma once

#define ISONDB			(*(LRS::tTraderBase::tObject()))
#define FREE_ISONDB		LRS::tTraderBase::tByeBye()


//  Singleton 
namespace LRS
{
	class tTraderBase
	{
	public:
		
		// set up those values
		//static uint32_t	traderId;		
		//static uint64_t	innerCode;
		//static uint32_t	tradeUnitId;

		static tTraderBase* tObject();
		static tTraderBase* tObject(std::string url, std::string usr, std::string passwd, std::string database);
		static void tByeBye(void);

		void operator<<(std::string str);
			

		// those are the parameters i need to check
		//tTraderMeter		tdr_m;			// trader parameters
		//tTraderUnitMeter	tdru_m;			// traderUnit parameters
		//tCapAccountMeter	cap_m;			// capital account parameters

		//void tTakeSnap(void); // the Snap variables, 
		//tDBSnap& tGetSnapDB(void);
		
		// Reset OMS to Zero State
		//void tResetOMS(void);

		// Reset ISONDB to be Zero State
		//void tResetISONDB(void);

	
	protected:

		double		SnapTime;	// will implement in the future
//		tDBSnap		SnapBase;	// this has got 9 tables
		
	private:
		// block to use
		tTraderBase();
		~tTraderBase();
		tTraderBase(tTraderBase const& obj);
		
		//*  *//
		static tTraderBase*		m_pInstance;
		static tMyDataBase*		isonDB;		// how to destruct the data base

	};
}

