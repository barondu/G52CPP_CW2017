#pragma once
#include "RewardObject.h"
#include "Role.h"
class Diamond :
	public RewardObject
{
public:
	Diamond(BaseEngine* pEngine, Psybd1TileManager* pTileManager, Role* protagonist, int iCurrentScreenX, int iCurrentScreenY);
	~Diamond();

};

