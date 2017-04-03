#include "header.h"
#include "templates.h"
#include "Role.h"
#include "JPGImage.h"


Role::Role(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
{
	// Current and previous coordinates for the object - set them the same initially
	m_iCurrentScreenX = m_iPreviousScreenX = 200;
	m_iCurrentScreenY = m_iPreviousScreenY = 540;
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = -30;
	m_iStartDrawPosY = -50;
	// Record the ball size as both height and width
	m_iDrawWidth = 60;
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
	int sprite_index = (iRefreshRate / 6) % 5;

	if (!isGround)
	{
		// Jump sprite
		if (m_iDir == 0)
		{
			if (m_dSpeedY > 8)
				m_oJumpSpriteL[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
					m_iCurrentScreenX + m_iStartDrawPosX,
					m_iCurrentScreenY + m_iStartDrawPosY,
					60, 100);
			else
				m_oJumpSpriteL[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
					m_iCurrentScreenX + m_iStartDrawPosX,
					m_iCurrentScreenY + m_iStartDrawPosY,
					60, 100);
			}
		else
		{
			if (m_dSpeedY > 8)
				m_oJumpSpriteR[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			else
				m_oJumpSpriteR[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
		}

	}
	else if (isIdle)
	{
		// If direction is left
		if (m_iDir == 0)
			m_oIdleSpriteL.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
		else
			m_oIdleSpriteR.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
	}
	else if (m_iDir == 0)
	{
		switch (sprite_index)
		{
		case 0:
			m_oRunSpriteL[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			break;
		case 1:
			m_oRunSpriteL[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			break;
		case 2:
			m_oRunSpriteL[2].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			break;
		case 3:
			m_oRunSpriteL[3].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			break;
		case 4:
			m_oRunSpriteL[4].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
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
				60, 100);
			break;
		case 1:
			m_oRunSpriteR[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			break;
		case 2:
			m_oRunSpriteR[2].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			break;
		case 3:
			m_oRunSpriteR[3].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
			break;
		case 4:
			m_oRunSpriteR[4].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				60, 100);
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
		m_dSpeedY -= m_dAccelerateY;


	if (m_iCurrentScreenX < m_iDrawWidth / 2)
		m_iCurrentScreenX = m_iDrawWidth / 2;
	if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth / 2)
		m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth / 2;
	if (m_iCurrentScreenY < m_iDrawHeight / 2)
		m_iCurrentScreenY = m_iDrawHeight / 2;
	if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - 180 - m_iDrawHeight / 2)
	{
		isGround = true;
		m_dSpeedY = 0;
		m_iCurrentScreenY = GetEngine()->GetScreenHeight() - 180 - m_iDrawHeight / 2;
	}


	// Ensure that the object gets redrawn on the display, if something changed
		RedrawObjects();
}

void Role::Jump()
{
	if (isGround)
	{
		printf("jump!");
		m_dSpeedY = -15;
		isGround = false;
		canDoubleJump = true;
	}
	else if (!isGround && canDoubleJump)
	{
		printf("doubleJump!/n");
		m_dSpeedY = -15;
		canDoubleJump = false;
	}
}
