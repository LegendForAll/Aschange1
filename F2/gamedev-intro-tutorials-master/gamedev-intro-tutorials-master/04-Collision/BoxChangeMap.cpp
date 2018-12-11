#include "BoxChangeMap.h"

BoxMap::BoxMap()
{

}

BoxMap::~BoxMap()
{

}

void BoxMap::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_BOXMAP, L"Resource\\sprites\\Ground\\13.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texBox = textures->Get(ID_TEX_BOXMAP);


	sprites->Add(20001, 0, 0, 32, 16, texBox);


	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	//Animation ground
	ani = new CAnimation(100);		// box
	ani->Add(20001);
	animations->Add(BOX_MAP_NEXT, ani);

	this->AddAnimation(BOX_MAP_NEXT);
}

void BoxMap::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	animations[BOX_MAP_NEXT]->Render(x - xViewport, y - yViewport);
}

void BoxMap::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x;
	t = y;
	r = l + BOXMAP_BBOX_WIDTH;
	b = t + BOXMAP_BBOX_HEIGHT;
}
