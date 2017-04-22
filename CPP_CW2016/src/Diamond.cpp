#include "header.h"
#include "templates.h"
#include "Diamond.h"
#include "JPGImage.h"


Diamond::Diamond(BaseEngine* pEngine, Psybd1TileManager* pTileManager, Role* protagonist, int iCurrentScreenX, int iCurrentScreenY)
	: RewardObject(pEngine, pTileManager, protagonist, iCurrentScreenX, iCurrentScreenY)
{
	m_oIdleSprite[0].LoadImage("diamond.png");
	m_oIdleSprite[1].LoadImage("diamond.png");

	m_oDisappearSprite[0].LoadImage("diamond.png");
	m_oDisappearSprite[1].LoadImage("diamond.png");
	m_oDisappearSprite[2].LoadImage("diamond.png");
	m_oDisappearSprite[3].LoadImage("diamond.png");
}


Diamond::~Diamond()
{
}
