#pragma once
#include "DisplayableObject.h"
#include "JPGImage.h"
class Role :
	public DisplayableObject
{
public:
	Role(BaseEngine* pEngine);
	~Role();
	void Draw();
	void DoUpdate(int intiCurrentTime);
	void Jump();
	// Sprite
	//ImageData m_oAttackSprite;
	ImageData m_oIdleSpriteR;
	ImageData m_oIdleSpriteL;

	ImageData m_oRunSpriteL[5];
	ImageData m_oRunSpriteR[5];

	ImageData m_oJumpSpriteL[2];
	ImageData m_oJumpSpriteR[2];
	
protected:
	int iRefreshRate = 0;
	bool isIdle = true;
	bool isGround = true;
	bool canDoubleJump = false;

	// 0 means left
	// 1 means right

	int m_iDir;

	double m_dSpeedX = 3;
	double m_dSpeedY = 0;
	double m_dAccelerateX = 0.2;
	// Because the drop speed is positive
	double m_dAccelerateY = -0.6;
};

