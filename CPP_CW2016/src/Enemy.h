#pragma once
#include "DisplayableObject.h"
#include "JPGImage.h"
class Enemy :
	public DisplayableObject
{
public:
	Enemy(BaseEngine* pEngine);
	~Enemy();

	void Draw();
	void DoUpdate(int intiCurrentTime);

	// Sprite
	ImageData m_oEnemyIdle1;
	ImageData m_oEnemyIdle2;

	int iRefreshRate = 0;

	bool isRight = 1;
};

