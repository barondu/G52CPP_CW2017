#include "header.h"
#include "templates.h"
#include "Role.h"
#include "JPGImage.h"


Role::Role(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
{
	// Current and previous coordinates for the object - set them the same initially
	m_iCurrentScreenX = m_iPreviousScreenX = 200;
	m_iCurrentScreenY = m_iPreviousScreenY = 470;
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = -34;
	m_iStartDrawPosY = -58;
	// Record the ball size as both height and width
	m_iDrawWidth = 68;
	m_iDrawHeight = 116;
	// And make it visible

	// Load image
	m_oBaseSprite.LoadImage("idle1.png");
	m_oIdleSprite;
	m_oLeftRun1Sprite;
	m_oRightRun1Sprite.LoadImage("run1.png");
	m_oRightRun2Sprite.LoadImage("run2.png");
	m_oRightRun3Sprite.LoadImage("run3.png");
	m_oRightRun4Sprite.LoadImage("run4.png");
	m_oLeftMoveSprite;
	SetVisible(true);
}


Role::~Role()
{
}


void Role::Draw()
{
	int sprite_index = (iRefreshRate / 6) % 4;
	//printf("index: %d",sprite_index);

	// Change direction of sprite
	if (m_dSpeedX > 0)
	{

	}
	else if (m_dSpeedX < 0)
	{

	}


	if (isIdle)
	{
		m_oBaseSprite.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			68, 116);
	}
	//else if (!isGround)
	//{
	//	// Jump sprite
	//}
	else switch (sprite_index)
	{
	case 0:
		m_oRightRun1Sprite.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			68, 116);
		break;
	case 1:
		m_oRightRun2Sprite.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			68, 116);
		break;
	case 2:
		m_oRightRun3Sprite.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			68, 116);
		break;
	case 3:
		m_oRightRun4Sprite.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			68, 116);
		break;
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
	}
	else if (GetEngine()->IsKeyPressed(SDLK_RIGHT))
	{
		m_iCurrentScreenX += m_dSpeedX;
	}
	else if (isGround)
	{
		iRefreshRate = 0;
		isIdle = true;
	}

	// If jump
	//if (GetEngine()->IsKeyPressed(SDLK_SPACE))
	//{
	//	if (isGround)
	//	{
	//		m_dSpeedY = -15;
	//		isGround = false;
	//		canDoubleJump = true;
	//	}
	//	else if (!isGround && canDoubleJump)
	//	{
	//		printf("aaaaaaaaa/n");
	//		m_dSpeedY = -15;
	//		canDoubleJump = false;
	//	}
	//}



	m_iCurrentScreenY += m_dSpeedY;
	if (!isGround)
		m_dSpeedY -= m_dAccelerateY;


	if (m_iCurrentScreenX < m_iDrawWidth / 2)
		m_iCurrentScreenX = m_iDrawWidth / 2;
	if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth / 2)
		m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth / 2;
	if (m_iCurrentScreenY < m_iDrawHeight / 2)
		m_iCurrentScreenY = m_iDrawHeight / 2;
	if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - 192 - m_iDrawHeight / 2)
	{
		isGround = true;
		m_dSpeedY = 0;
		m_iCurrentScreenY = GetEngine()->GetScreenHeight() - 192 - m_iDrawHeight / 2;
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
