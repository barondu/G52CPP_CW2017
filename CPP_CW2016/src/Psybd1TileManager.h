#pragma once
#include "TileManager.h"
#include "JPGImage.h"

class Psybd1TileManager :
	public TileManager
{
public:
	Psybd1TileManager();
	~Psybd1TileManager();
	// Draw a tile at a location on the screen determined by the tile
	// position and the base X and Y co-ordinates
	// OVERRIDE THIS TO DRAW YOUR TILE!!!
	// Draw a tile
	virtual void DrawTileAt(
		BaseEngine* pEngine,
		SDL_Surface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const;
	// floor
	ImageData m_tFloor1;
	ImageData m_tFloor2;
	ImageData m_tFloor3;
};

