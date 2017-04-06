#include "header.h"
#include "templates.h"
#include "Enemy.h"
#include "JPGImage.h"

Enemy::Enemy(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
{
	// Current and previous coordinates for the object - set them the same initially
	m_iCurrentScreenX = m_iPreviousScreenX = 100;
	m_iCurrentScreenY = m_iPreviousScreenY = 300;
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = -18;
	m_iStartDrawPosY = -16;
	// Record the ball size as both height and width
	m_iDrawWidth = 36;
	m_iDrawHeight = 32;
	// And make it visible

	// Load image
	m_oEnemyIdle1.LoadImage("enemy1.png");
	m_oEnemyIdle2.LoadImage("enemy2.png");
	SetVisible(true);
}


Enemy::~Enemy()
{
}


void Enemy::Draw()
{
	int sprite_index = (iRefreshRate / 60) % 2;
	//printf("index: %d",sprite_index);
	switch (sprite_index)
	{
	case 0:
		m_oEnemyIdle1.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			m_iDrawWidth, m_iDrawHeight);
		break;
	case 1:
		m_oEnemyIdle2.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			m_iDrawWidth, m_iDrawHeight);
		break;
		}

	// This will store the position at which the object was drawn
	// so that the background can be drawn over the top.
	// This will then remove the object from the screen.
	StoreLastScreenPositionForUndraw();
}


void Enemy::DoUpdate(int intiCurrentTime)
{
	iRefreshRate += 1;
	// Change position if player presses a key
	if (GetEngine()->IsKeyPressed(SDLK_w))
	{
		m_iCurrentScreenY -= 2;
	}
	else if (GetEngine()->IsKeyPressed(SDLK_s))
	{
		m_iCurrentScreenY += 2;
	}
	else if (GetEngine()->IsKeyPressed(SDLK_a))
	{
		m_iCurrentScreenX -= 2;
		isRight = 0;
	}
	else if (GetEngine()->IsKeyPressed(SDLK_d))
	{
		m_iCurrentScreenX += 2;
		isRight = 1;
	}
	else if (isRight)
	{
		m_iCurrentScreenX += 2;
	}
	else if (!isRight)
	{
		m_iCurrentScreenX -= 2;
	}


	if (m_iCurrentScreenX < m_iDrawWidth / 2)
	{
		m_iCurrentScreenX = m_iDrawWidth / 2;
		isRight = 1;
	}
	if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth / 2)
	{
		m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth / 2;
		isRight = 0;
	}
	if (m_iCurrentScreenY < m_iDrawHeight / 2)
		m_iCurrentScreenY = m_iDrawHeight / 2;
	if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - 192 - m_iDrawHeight / 2)
		m_iCurrentScreenY = GetEngine()->GetScreenHeight() - 192 - m_iDrawHeight / 2;

	//if (m_iCurrentScreenX < m_iDrawWidth / 2)
	//	m_iCurrentScreenX = m_iDrawWidth / 2;
	//if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth / 2)
	//	m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth / 2;
	//if (m_iCurrentScreenY < m_iDrawHeight / 2)
	//	m_iCurrentScreenY = m_iDrawHeight / 2;
	//if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - 192 - m_iDrawHeight / 2)
	//	m_iCurrentScreenY = GetEngine()->GetScreenHeight() - 192 - m_iDrawHeight / 2;

	// Ensure that the object gets redrawn on the display, if something changed
	RedrawObjects();
}
