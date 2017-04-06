#include "header.h"
#include "templates.h"
#include "Role.h"
//#include "Psybd1Engine.h"
#include "JPGImage.h"


Role::Role(BaseEngine* pEngine, Psybd1TileManager* pTileManager)
	: DisplayableObject(pEngine), m_pTileManager(pTileManager)
{
	// Current and previous coordinates for the object - set them the same initially
	m_iCurrentScreenX = m_iPreviousScreenX = 200;
	m_iCurrentScreenY = m_iPreviousScreenY = 200;
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = -30;
	m_iStartDrawPosY = -50;
	// Record the ball size as both height and width
	m_iDrawWidth = 58;
	m_iDrawHeight = 100;
	// And make it visible

	// Load image
	m_oIdleSpriteL.LoadImage("idleL.png");
	m_oIdleSpriteR.LoadImage("idleR.png");

	m_oRunSpriteL[0].LoadImage("1walk.png");
	m_oRunSpriteL[1].LoadImage("2walk.png");
	m_oRunSpriteL[2].LoadImage("3walk.png");
	m_oRunSpriteL[3].LoadImage("4walk.png");
	m_oRunSpriteL[4].LoadImage("idleL.png");

	m_oRunSpriteR[0].LoadImage("walk1.png");
	m_oRunSpriteR[1].LoadImage("walk2.png");
	m_oRunSpriteR[2].LoadImage("walk3.png");
	m_oRunSpriteR[3].LoadImage("walk4.png");
	m_oRunSpriteR[4].LoadImage("idleR.png");

	m_oJumpSpriteL[0].LoadImage("idleL.png");
	m_oJumpSpriteL[1].LoadImage("jumpL.png");
	m_oJumpSpriteR[0].LoadImage("idleR.png");
	m_oJumpSpriteR[1].LoadImage("jumpR.png");
	SetVisible(true);
}


Role::~Role()
{
}


void Role::Draw()
{
	int sprite_index = (iRefreshRate / 15) % 5;

	if (!isGround)
	{
		// Jump sprite
		if (m_iDir == 0)
		{
			if (m_dSpeedY < -6 &&m_dSpeedY > 6)
				m_oJumpSpriteL[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
					m_iCurrentScreenX + m_iStartDrawPosX,
					m_iCurrentScreenY + m_iStartDrawPosY,
					m_iDrawWidth, m_iDrawHeight);
			else
				m_oJumpSpriteL[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
					m_iCurrentScreenX + m_iStartDrawPosX,
					m_iCurrentScreenY + m_iStartDrawPosY,
					m_iDrawWidth, m_iDrawHeight);
			}
		else
		{
			if (m_dSpeedY < -6 && m_dSpeedY > 6)
				m_oJumpSpriteR[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			else
				m_oJumpSpriteR[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
		}

	}
	else if (isIdle)
	{
		// If direction is left
		if (m_iDir == 0)
			m_oIdleSpriteL.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
		else
			m_oIdleSpriteR.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
	}
	else if (m_iDir == 0)
	{
		switch (sprite_index)
		{
		case 0:
			m_oRunSpriteL[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 1:
			m_oRunSpriteL[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 2:
			m_oRunSpriteL[2].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 3:
			m_oRunSpriteL[3].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 4:
			m_oRunSpriteL[4].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		}
	}
	else if (m_iDir == 1)
	{
		switch (sprite_index)
		{
		case 0:
			m_oRunSpriteR[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 1:
			m_oRunSpriteR[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 2:
			m_oRunSpriteR[2].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 3:
			m_oRunSpriteR[3].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 4:
			m_oRunSpriteR[4].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		}
	}


	// This will store the position at which the object was drawn
	// so that the background can be drawn over the top.
	// This will then remove the object from the screen.
	StoreLastScreenPositionForUndraw();
}


void Role::DoUpdate(int intiCurrentTime)
{
	isIdle = false;
	iRefreshRate += 1;

	// Change position if player presses a key

	if (GetEngine()->IsKeyPressed(SDLK_LEFT))
	{
		m_iCurrentScreenX -= m_dSpeedX;
		m_iDir = 0;
	}
	else if (GetEngine()->IsKeyPressed(SDLK_RIGHT))
	{
		m_iCurrentScreenX += m_dSpeedX;
		m_iDir = 1;
	}
	else if (isGround)
	{
		iRefreshRate = 0;
		isIdle = true;
	}

	m_iCurrentScreenY += m_dSpeedY;
	if (!isGround)
	{
		m_dSpeedY -= m_dAccelerateY;
	}

	

	// Collision of ground
	if (m_pTileManager->IsValidTilePosition(m_iCurrentScreenX - m_iDrawWidth / 2 + 5, m_iCurrentScreenY + m_iDrawHeight / 2)
		&& m_pTileManager->IsValidTilePosition(m_iCurrentScreenX + m_iDrawWidth / 2 - 5, m_iCurrentScreenY + m_iDrawHeight / 2))
	{
		int iTileX1 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX - m_iDrawWidth / 2 + 5);
		int iTileY1 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY + m_iDrawHeight / 2);
		int iCurrentTile1 = m_pTileManager->GetValue(iTileX1, iTileY1);
		int iTileX2 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX + m_iDrawWidth / 2 - 5);
		int iTileY2 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY + m_iDrawHeight / 2);
		int iCurrentTile2 = m_pTileManager->GetValue(iTileX2, iTileY2);
		// If there is not a wall or block under the foot
		if (iCurrentTile1 == 3 && iCurrentTile2 == 3)
			isGround = false;
		else
		{ 
			isGround = true;
			m_dSpeedY = 0;

			if ((m_iCurrentScreenY+ m_iDrawHeight / 2) > iTileY1 *60)
			{
				m_iCurrentScreenY = iTileY1 * 60 - m_iDrawHeight / 2;
			}
		}	
	}

	// Conllision of the bottom of wall
	if (m_pTileManager->IsValidTilePosition(m_iCurrentScreenX - m_iDrawWidth / 2, m_iCurrentScreenY - m_iDrawHeight / 2)
		&& m_pTileManager->IsValidTilePosition(m_iCurrentScreenX + m_iDrawWidth / 2, m_iCurrentScreenY - m_iDrawHeight / 2))
	{
		int iTileX1 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX - m_iDrawWidth / 2);
		int iTileY1 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY - m_iDrawHeight / 2);
		int iCurrentTile1 = m_pTileManager->GetValue(iTileX1, iTileY1);
		int iTileX2 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX + m_iDrawWidth / 2);
		int iTileY2 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY - m_iDrawHeight / 2 );
		int iCurrentTile2 = m_pTileManager->GetValue(iTileX2, iTileY2);
		// If there is a wall over head
		if (iCurrentTile1 != 3 || iCurrentTile2 != 3)
			m_dSpeedY = -m_dSpeedY;
	}

	// Conllision of the flank of wall(left side of role)
	if (m_pTileManager->IsValidTilePosition(m_iCurrentScreenX - m_iDrawWidth / 2, m_iCurrentScreenY + m_iDrawHeight / 2 - 1)
		&& m_pTileManager->IsValidTilePosition(m_iCurrentScreenX - m_iDrawWidth / 2, m_iCurrentScreenY - m_iDrawHeight / 2 + 1)
		&& m_pTileManager->IsValidTilePosition(m_iCurrentScreenX - m_iDrawWidth / 2, m_iCurrentScreenY))
	{
		int iTileX1 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX - m_iDrawWidth / 2);
		int iTileY1 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY + m_iDrawHeight / 2 - 1);
		int iCurrentTile1 = m_pTileManager->GetValue(iTileX1, iTileY1);
		int iTileX2 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX - m_iDrawWidth / 2);
		int iTileY2 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY - m_iDrawHeight / 2 + 1);
		int iCurrentTile2 = m_pTileManager->GetValue(iTileX2, iTileY2);
		int iTileX3 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX - m_iDrawWidth / 2);
		int iTileY3 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY);
		int iCurrentTile3 = m_pTileManager->GetValue(iTileX3, iTileY3);
		// If there is not a wall or block under the foot
		if (iCurrentTile1 != 3 || iCurrentTile2 != 3 || iCurrentTile3 != 3)
			m_iCurrentScreenX = (iTileX1 +1) * 60 + m_iDrawWidth / 2;
	}

	// Conllision of the flank of wall(right side of role)
	if (m_pTileManager->IsValidTilePosition(m_iCurrentScreenX + m_iDrawWidth / 2, m_iCurrentScreenY + m_iDrawHeight / 2 - 1)
		&& m_pTileManager->IsValidTilePosition(m_iCurrentScreenX + m_iDrawWidth / 2, m_iCurrentScreenY - m_iDrawHeight / 2 + 1)
		&& m_pTileManager->IsValidTilePosition(m_iCurrentScreenX + m_iDrawWidth / 2, m_iCurrentScreenY))
	{
		int iTileX1 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX + m_iDrawWidth / 2);
		int iTileY1 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY + m_iDrawHeight / 2 - 1);
		int iCurrentTile1 = m_pTileManager->GetValue(iTileX1, iTileY1);
		int iTileX2 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX + m_iDrawWidth / 2);
		int iTileY2 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY - m_iDrawHeight / 2 + 1);
		int iCurrentTile2 = m_pTileManager->GetValue(iTileX2, iTileY2);
		int iTileX3 = m_pTileManager->GetTileXForPositionOnScreen(m_iCurrentScreenX + m_iDrawWidth / 2);
		int iTileY3 = m_pTileManager->GetTileYForPositionOnScreen(m_iCurrentScreenY);
		int iCurrentTile3 = m_pTileManager->GetValue(iTileX3, iTileY3);
		// If there is not a wall or block under the foot
		if (iCurrentTile1 != 3 || iCurrentTile2 != 3 || iCurrentTile3 != 3)
			m_iCurrentScreenX = iTileX1 * 60 - m_iDrawWidth / 2;
	}

	// Bound of screen
	if (m_iCurrentScreenX < m_iDrawWidth / 2)
		m_iCurrentScreenX = m_iDrawWidth / 2;
	if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth / 2)
		m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth / 2;
	if (m_iCurrentScreenY < m_iDrawHeight / 2)
	{
		m_iCurrentScreenY = m_iDrawHeight / 2;
		m_dSpeedY = 0;
	}
	if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight / 2)
	{
		m_dSpeedY = 0;
		m_iCurrentScreenY = GetEngine()->GetScreenHeight() - m_iDrawHeight / 2;
	}

	// Ensure that the object gets redrawn on the display, if something changed
		RedrawObjects();
}

void Role::Jump()
{
	if (isGround)
	{
		printf("jump\n!");
		m_dSpeedY = -15;
		isGround = false;
		canDoubleJump = true;
	}
	else if (!isGround && canDoubleJump)
	{
		printf("doubleJump!\n");
		m_dSpeedY = -15;
		canDoubleJump = false;
	}
}
