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
	ImageData m_oBaseSprite;
	ImageData m_oIdleSprite;
	//ImageData m_oAttackSprite;
	ImageData m_oLeftRun1Sprite;
	ImageData m_oRightRun1Sprite;
	ImageData m_oRightRun2Sprite;
	ImageData m_oRightRun3Sprite;
	ImageData m_oRightRun4Sprite;
	ImageData m_oLeftMoveSprite;

	
protected:
	int iRefreshRate = 0;
	bool isIdle = true;
	bool isGround = true;
	bool canDoubleJump = false;

	double m_dSpeedX = 4;
	double m_dSpeedY = 0;
	double m_dAccelerateX = 0.2;
	// Because the drop speed is positive
	double m_dAccelerateY = -0.6;
};

