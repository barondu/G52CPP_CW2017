#include "header.h"
#include "templates.h"
#include "Psybd1Engine.h"


Psybd1Engine::Psybd1Engine()
{
}


Psybd1Engine::~Psybd1Engine()
{
}

void Psybd1Engine::SetupBackgroundBuffer()
{
	FillBackground(0xe3f2fd);
	//FillBackground(0xffffff);
	int ground_Rows = 4;
	int ground_Columns = 27;

	// a--tile1.png b--tile2.png c--tile3.png
	char* data[] = {
		"aaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"bbbccbbbbcbbbcbcccbbccbbbcc",
		"cbccccbbcccbcccbcccbcccbbcc",
		"ccccccccccccccccccccccccccc"
		 };

	// Specify how many tiles wide and high
	m_oTiles.SetSize(ground_Columns, ground_Rows);
	// Set up the tiles
	for (int x = 0; x < ground_Columns; x++)
		for (int y = 0; y < ground_Rows; y++)
			m_oTiles.SetValue(x, y, data[y][x]-'a');


	// Specify the screen x,y of top left corner
	m_oTiles.SetBaseTilesPositionOnScreen(0, 528);

	// Tell it to draw tiles from x1,y1 to x2,y2 in tile array,
	// to the background of this screen
	m_oTiles.DrawAllTiles(this,
		this->GetBackground(),
		0, 0, ground_Columns - 1, ground_Rows- 1);
}

//void Psybd1Engine::DrawStringsOnTop()
//{
//	// Build the string to print
//	char buf[128];
//	sprintf(buf, "Time %6d", rand(), rand());
//	DrawScreenString(150, 40, buf, 0xff00ff, NULL);
//	DrawScreenString(450, 40, "On top of the objects", 0x00ff00, NULL);
//}

void Psybd1Engine::MouseDown(int iButton, int iX, int iY)
{
	printf("%d %d\n", iX, iY);
	//if (iButton == SDL_BUTTON_LEFT)
	//{
	//	DrawBackgroundTriangle(iX - 10, iY - 10, iX + 10, iY + 10, iX+20, iY, 0xffff00);
	//	//DrawRectangle(iX - 10, iY - 10, iX + 10, iY + 10, 0xffff00);
	//	Redraw(true);
	//}
	//else if (iButton == SDL_BUTTON_RIGHT)
	//{
	//	DrawBackgroundOval(iX - 10, iY - 10, iX + 10, iY + 10, 0xff0000);
	//	//DrawOval(iX - 10, iY - 10, iX + 10, iY + 10, 0xff0000);
	//	Redraw(true);
	//}
}

void Psybd1Engine::KeyDown(int iKeyCode)
{
	//switch (iKeyCode)
	//{
	//case ' ':
	//	SetupBackgroundBuffer();
	//	Redraw(true);
	//	break;
	//}

	// NEW SWITCH on current state
	switch (iKeyCode)
	{
	case SDLK_ESCAPE: // End program when escape is pressed
		SetExitWithCode(0);
		break;
	case SDLK_SPACE: // SPACE Pauses
		protagonist->Jump();
		break;

	}
}


int Psybd1Engine::InitialiseObjects()
{
	// Record the fact that we are about to change the array - so it doesn't get
	// used elsewhere without reloading it
	DrawableObjectsChanged();
	// Destroy any existing objects
	DestroyOldObjects();
	// Creates an array to store the objects
	// Needs to have room for the NULL at the end
	CreateObjectArray(3);
	// You MUST set the array entry after the last one that you create to NULL, so 
	// that the system knows when to stop.
	// i.e. The LAST entry has to be NULL. The fact that it is NULL is used in
	//order to work out where the end of the array is.
	StoreObjectInArray(0, protagonist);
	StoreObjectInArray(1, enemy1);
	StoreObjectInArray(2, NULL);
	return 0;
}


void Psybd1Engine::UnDrawStrings()
{
	// Clear the top of the screen, since we about to draw text on it.
	CopyBackgroundPixels(0, 0, GetScreenWidth(), 70);
}


void Psybd1Engine::DrawStringsOnTop()
{
	// Build the string to print
	char buf[128];
	sprintf(buf, "CurrentMouseX %d", GetCurrentMouseX());
	DrawScreenString(150, 40, buf, 0xef5350, NULL);
	DrawScreenString(450, 40, "PSYBD1", 0xef5350, NULL);
}


void Psybd1Engine::DrawStringsUnderneath()
{
	// Build the string to print

	/*char buf[128];
	sprintf(buf, "Changing random %6d", rand());
	DrawScreenString(50, 10, buf, 0x00ffff, NULL);
	DrawScreenString(450, 10, "Underneath the objects", 0xff0000, NULL);*/
}


/* Overridden GameAction which can be modified */
void Psybd1Engine::GameAction()
{
	// If too early to act then do nothing
	if (!IsTimeToActWithSleep())
		return;

	// Don't act for another 15 ticks
	SetTimeToAct(10);

	// Tell all objects to update themselves
	UpdateAllObjects(GetTime());
}



