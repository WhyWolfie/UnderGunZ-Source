#ifndef _MMATCHMAP_H
#define _MMATCHMAP_H

#include "MMatchGlobal.h"


enum MMATCH_MAP 
{
	MMATCH_MAP_MANSION			= 0,
	MMATCH_MAP_PRISON_II		= 31,
	MMATCH_MAP_BATTLE_ARENA		= 2,
	MMATCH_MAP_TOWN				= 48,
	MMATCH_MAP_DUNGEON			= 10,
	MMATCH_MAP_RUIN				= 34,
	MMATCH_MAP_ISLAND			= 23,
	MMATCH_MAP_GARDEN			= 19,
	MMATCH_MAP_CASTLE			= 4,
	MMATCH_MAP_FACTORY			= 17,
	MMATCH_MAP_PORT				= 30,
	MMATCH_MAP_WEAPONSHOP		= 50,
	MMATCH_MAP_HIGH_HAVEN		= 22,

	// »õ¸Ê Ãß°¡´Â ÀÌ ¹Ø¿¡ ÇÏ¼¼¿ä.

	//	MMATCH_MAP_EVENT,					// ÀÌº¥Æ® Àü¿ë¸Ê
	MMATCH_MAP_RELAYMAP			= 22,

	MMATCH_MAP_HALLOWEEN_TOWN	= 23,
	MMATCH_MAP_WEAPON_SHOP		= 24,
	MMATCH_MAP_MAX              = 125,
};

#define MMATCH_MAP_COUNT	MMATCH_MAP_MAX			// ÀüÃ¼ ¸Ê °¹¼ö

#define MMATCH_MAPNAME_RELAYMAP				"RelayMap"


class MMapDesc
{
private:
	const struct MapInfo
	{
		int			nMapID;							// map id
		char		szMapName[MAPNAME_LENGTH];		// ¸Ê ÀÌ¸§
		char		szMapImageName[MAPNAME_LENGTH];	// ¸Ê ÀÌ¹ÌÁö ÀÌ¸§
		char		szBannerName[MAPNAME_LENGTH];	// º£³Ê ÀÌ¸§
		float		fExpRatio;						// °æÇèÄ¡ ½Àµæ·ü
		int			nMaxPlayers;					// ÃÖ´ë ÀÎ¿ø
		bool		bOnlyDuelMap;					// µà¾ó¸Ê Àü¿ë
		bool		bIsCTFMap;
	};


	// data
	MapInfo	m_MapVectors[MMATCH_MAP_COUNT];
	MMapDesc();
public:
	~MMapDesc() { }
	
	static MMapDesc* GetInstance();

	bool Initialize(const char* szFileName);
	bool Initialize(MZFileSystem* pfs, const char* szFileName);
	bool MIsCorrectMap(const int nMapID);
	

 
	bool IsMapOnlyDuel( const int nMapID);
	bool IsCTFMap( const int nMapID);
	int GetMapID( const int nMapID);
	const char* GetMapName(const int nMapID);
	const char* GetMapImageName(const char* szMapName);
	const char* GetBannerName(const char* szMapName);
	float GetExpRatio( const int nMapID); 
	int GetMaxPlayers( const int nMapID);

	int GetMapCount(){ return MMATCH_MAP_COUNT; }
};


inline MMapDesc* MGetMapDescMgr() 
{ 
	return MMapDesc::GetInstance();
}



#endif