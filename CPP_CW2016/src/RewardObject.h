#pragma once
#include "DisplayableObject.h"
#include "Psybd1TileManager.h"
#include "Role.h"
#include "JPGImage.h"
class RewardObject :
	public DisplayableObject
{
public:
	RewardObject(BaseEngine* pEngine, Psybd1TileManager* pTileManager, Role* protagonist, int iCurrentScreenX, int iCurrentScreenY);
	~RewardObject();
	void Draw();
	void DoUpdate(int intiCurrentTime);
	void CheckEat();
	void Move();
	//void Animation_Idle();
	//void Animation_Disappear();

	// Sprite
	ImageData m_oIdleSprite[2];
	ImageData m_oDisappearSprite[4];

protected:
	int iRefreshRate = 0;
	int iRefreshDisappearRate = 0;
	bool isEat = false;
	Psybd1TileManager* m_pTileManager;
	Role* m_Protagonist;
};

