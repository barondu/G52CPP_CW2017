#include "header.h"
#include "templates.h"
#include "RewardObject.h"
#include "Role.h"
#include "JPGImage.h"

RewardObject::RewardObject(BaseEngine* pEngine, Psybd1TileManager* pTileManager, Role* protagonist, int iCurrentScreenX, int iCurrentScreenY)
	: DisplayableObject(pEngine), m_pTileManager(pTileManager), m_Protagonist(protagonist)
{
	// Current and previous coordinates for the object - set them the same initially
	m_iCurrentScreenX = m_iPreviousScreenX = iCurrentScreenX;
	m_iCurrentScreenY = m_iPreviousScreenY = iCurrentScreenY;
	//m_iCurrentScreenX = iCurrentScreenX;
	//m_iCurrentScreenY = iCurrentScreenY;
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = -16;
	m_iStartDrawPosY = -16;
	// Record the ball size as both height and width
	m_iDrawWidth = 32;
	m_iDrawHeight = 32;
	// And make it visible
	SetVisible(true);
}


RewardObject::~RewardObject()
{
}


void RewardObject::Draw()
{
	if (IsVisible() == false)
		return;

	if (isEat == false)
	{
		int sprite_index = (iRefreshRate / 8) % 2;
		switch (sprite_index)
		{
		case 0:
			m_oIdleSprite[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 1:
			m_oIdleSprite[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		}
	}
	else
	{
		iRefreshDisappearRate += 1;
		int sprite_index = (iRefreshDisappearRate / 8) % 4;
		switch (sprite_index)
		{
		case 0:
			m_oDisappearSprite[0].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 1:
			m_oDisappearSprite[1].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 2:
			m_oDisappearSprite[2].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			break;
		case 3:
		{
			m_oDisappearSprite[3].RenderImageWithMask(GetEngine()->GetForeground(), 0, 0,
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
			SetVisible(false);
			break;
		}
		}
	}
}


void RewardObject::DoUpdate(int intiCurrentTime)
{
	iRefreshRate += 1;
	//CheckEat();
	//Move();
	// Ensure that the object gets redrawn on the display, if something changed
	RedrawObjects();
}


void RewardObject::CheckEat()
{
	int protagonist_X = m_Protagonist->GetXCentre();
	int protagonist_Y = m_Protagonist->GetYCentre();
	int distance_X = protagonist_X - m_iCurrentScreenX;
	int distance_Y = protagonist_Y - m_iCurrentScreenY;
	if (distance_X < (29 + m_iDrawWidth) || distance_X > (- 29 - m_iDrawWidth)
		|| distance_Y < (50 + m_iDrawHeight) || distance_Y > (- 50 - m_iDrawHeight))
	{
		isEat = true;
	}
}


void RewardObject::Move()
{

}
//void RewardObject::Animation_Idle()
//{
//
//}
//void RewardObject::Animation_Disappear()
//{
//
//}
