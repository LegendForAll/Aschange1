#include "BoxStair.h"

BOXStair::BOXStair()
{

}

BOXStair::~BOXStair()
{

}

void BOXStair::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_BOX_STAIR, L"Resource\\sprites\\Ground\\13.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texBox = textures->Get(ID_TEX_BOX_STAIR);


	sprites->Add(20001, 0, 0, 32, 32, texBox);


	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	//Animation ground
	ani = new CAnimation(100);		// box top
	ani->Add(20001);
	animations->Add(BOX_STAIR_TOP, ani);


	ani = new CAnimation(100);		// box bottom
	ani->Add(20001);
	animations->Add(BOX_STAIR_BOTTOM, ani);

	this->AddAnimation(BOX_STAIR_TOP);
	this->AddAnimation(BOX_STAIR_BOTTOM);
}

void BOXStair::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	switch (this->state)
	{
		case BOX_STAIR_TOP:
		{
			animations[BOX_STAIR_TOP]->Render(x - xViewport, y - yViewport);
			break;
		}
		case BOX_STAIR_BOTTOM:
		{
			animations[BOX_STAIR_BOTTOM]->Render(x - xViewport, y - yViewport);
			break;
		}

		case BOX_LEFT:
		{
			animations[BOX_STAIR_BOTTOM]->Render(x - xViewport, y - yViewport);
			break;
		}
		case BOX_RIGHT:
		{
			animations[BOX_STAIR_BOTTOM]->Render(x - xViewport, y - yViewport);
			break;
		}
	}

	RenderBoundingBox();
}

void BOXStair::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x;
	t = y;
	r = l + BOX_STAIR_WIDTH;
	b = t + BOX_STAIR_HEIGHT;
}
