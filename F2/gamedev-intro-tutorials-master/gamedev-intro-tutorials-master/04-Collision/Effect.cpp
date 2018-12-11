#include "Effect.h"

CEffect::CEffect()
{

}

CEffect::~CEffect()
{

}

void CEffect::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_WATER, L"Resource\\sprites\\Effect\\2.png", D3DCOLOR_XRGB(255, 0, 255));

	LPDIRECT3DTEXTURE9 texWater = textures->Get(ID_TEX_WATER);

	CSprites * sprites = CSprites::GetInstance();
	sprites->Add(300, 0, 0, 14, 28, texWater);



	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);		//Water
	ani->Add(300);
	animations->Add(EFFECT_WATER, ani);

	this->AddAnimation(EFFECT_WATER);
}

void CEffect::GetBoundingBox(float & l, float & t, float & r, float & b)
{

}

void CEffect::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects, vector<LPGAMEOBJECT>* coObjectStatic, vector<LPGAMEOBJECT>* coObjectEnemy)
{
	CGameObject::Update(dt);
	
	if (this->nx == 0)
	{
		vy += 0.0001 * dt;
	}
	else
	{
		vy += 0.0002 * dt;
	}

	x += dx;
	y += dy;
}

void CEffect::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;
	int alpha = 255;

	this->SetState(this->state);

	if (!isDead)
	{
		animations[ani]->Render(x - xViewport, y - yViewport);
	}
}

void CEffect::SetCurrentMerman(float _xMerman, float _yMerman, int _nx, bool _isStand)
{
	this->x = _xMerman;
	this->y = _yMerman;
}

void CEffect::SetState(int state)
{
	CGameObject::SetState(this->state);

	switch (state)
	{
		case EFFECT_WATER:
		{
			ani = EFFECT_WATER;
			vx = nx*0.03f;
			break;
		}
	}
}
