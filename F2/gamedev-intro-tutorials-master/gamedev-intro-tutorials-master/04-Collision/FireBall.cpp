#include "FireBall.h"

FireBall::FireBall()
{

}

FireBall::~FireBall()
{

}

void FireBall::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_FIREBALL, L"Resource\\sprites\\Enemies\\FIREBALL.png", D3DCOLOR_XRGB(255, 0, 255));

	LPDIRECT3DTEXTURE9 texfireball = textures->Get(ID_TEX_FIREBALL);

	CSprites * sprites = CSprites::GetInstance();
	sprites->Add(300, 0, 0, 14, 12, texfireball);


	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);		//fireball
	ani->Add(300, 90);
	animations->Add(600, ani);

	this->AddAnimation(600);
}

void FireBall::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	if (!isDead)
	{
		l = x;
		t = y;
		r = l + FIREBALL_BBOX_WIDTH;
		b = t + FIREBALL_BBOX_HEIGHT;
	}
}

void FireBall::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects, vector<LPGAMEOBJECT>* coObjectStatic, vector<LPGAMEOBJECT>* coObjectEnemy)
{
	CGameObject::Update(dt);
	x += dx;
	this->SetState(NULL);
}

void FireBall::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;
	int alpha = 255;

	//animation whip left or right
	this->isLeft = nx < 0 ? false : true;

	if (!isDead)
	{
		animations[0]->Render(x - xViewport, y - yViewport, alpha, isLeft);
		//Render boundingBox at end frame of currentAnimation
		RenderBoundingBox();
	}
}

void FireBall::SetCurrentMerman(float _xSimon, float _ySimon, int _nx, bool _isStand)
{
	this->x = _xSimon + 20.0f;
	this->y = _ySimon + 15.0f;
	this->nx = _nx;
	this->isStand = _isStand;
	this->SetDead(false);
}

void FireBall::SetState(int state)
{
	this->vx = this->GetNX() == 1 ? 0.1f : -0.1f;
}
