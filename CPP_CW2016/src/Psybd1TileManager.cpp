#include "header.h"
#include "templates.h"
#include "Psybd1TileManager.h"
#include "JPGImage.h"

Psybd1TileManager::Psybd1TileManager()
	: TileManager(48, 48)
{
	m_tFloor1.LoadImage("floor1.png");
	m_tFloor2.LoadImage("floor2.png");
	m_tFloor3.LoadImage("floor3.png");
}


Psybd1TileManager::~Psybd1TileManager()
{
}


void Psybd1TileManager::DrawTileAt(
	BaseEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	switch (GetValue(iMapX, iMapY))
	{
	case 0:
		m_tFloor1.RenderImage(pEngine->GetBackground(),
			0, 0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			48, 48);
		break;
	case 1:
		m_tFloor2.RenderImage(pEngine->GetBackground(),
			0,0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			48,48);
		break;
	case 2:
		m_tFloor3.RenderImage(pEngine->GetBackground(),
			0, 0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			48, 48);
		break;
	case 3:break;
	case 4:break;
	case 5:break;
	case 6:break;
	case 7:break;
	case 8:break;
	}
}