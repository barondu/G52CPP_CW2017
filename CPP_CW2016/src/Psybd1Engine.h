#pragma once
#include "BaseEngine.h"
#include "TileManager.h"
#include "Psybd1TileManager.h"
#include "Role.h"
#include "Enemy.h"
#include "Diamond.h"

class Psybd1Engine :
	public BaseEngine
{
public:
	Psybd1Engine();
	~Psybd1Engine();
	void SetupBackgroundBuffer();
	void MouseDown(int iButton, int iX, int iY);
	void KeyDown(int iKeyCode);
	//void MyProjectMain();
	int InitialiseObjects();

	/** Draw any strings */
	void UnDrawStrings();
	void DrawStringsUnderneath();
	void DrawStringsOnTop();

	/**
	The game logic - move things and change the state if necessary.
	Must call Redraw(true/false) if anything changes that shows on the screen.
	*/
	virtual void GameAction();


	// Get a reference to the current tile manager
	Psybd1TileManager& GetTileManager() { return *m_oTiles; }
private:
	Psybd1TileManager* m_oTiles = new Psybd1TileManager();
	Role* protagonist = new Role(this, m_oTiles);
	Enemy* enemy1 = new Enemy(this);
	Diamond* diamond = new Diamond(this, m_oTiles, protagonist, 500, 200);
};

