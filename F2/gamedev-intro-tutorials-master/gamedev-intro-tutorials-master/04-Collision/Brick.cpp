#include "Brick.h"

void CBrick::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_MISC, L"Resource\\sprites\\ground_test.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_GROUND, L"Resource\\sprites\\Ground\\Brick.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_STAIR_LEFT, L"Resource\\sprites\\Ground\\3.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_STAIR_RIGHT, L"Resource\\sprites\\Ground\\3_.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	LPDIRECT3DTEXTURE9 texGround = textures->Get(ID_TEX_GROUND);
	LPDIRECT3DTEXTURE9 texStairL = textures->Get(ID_TEX_STAIR_LEFT);
	LPDIRECT3DTEXTURE9 texStairR = textures->Get(ID_TEX_STAIR_RIGHT);

	sprites->Add(20001, 0, 0, 768, 32, texMisc);
	sprites->Add(20002, 0, 0, 32, 32, texGround);
	sprites->Add(20003, 0, 0, 32, 32, texStairL);
	sprites->Add(20004, 0, 0, 32, 32, texStairR);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	//Animation ground
	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);


	ani = new CAnimation(100);		// ground
	ani->Add(20002);
	animations->Add(602, ani);

	ani = new CAnimation(100);		// stair left
	ani->Add(20003);
	animations->Add(603, ani);

	ani = new CAnimation(100);		// strair right
	ani->Add(20004);
	animations->Add(604, ani);

	this->AddAnimation(601);
	this->AddAnimation(602);
	this->AddAnimation(603);
	this->AddAnimation(604);
}

void CBrick::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	CGameObject::SetState(this->state);

	switch (this->state)
	{
		case BRICK:
		{
			animations[BRICK]->Render(x - xViewport, y - yViewport);
			RenderBoundingBox();
			break;
		}
		case GROUND:
		{
			animations[GROUND]->Render(x - xViewport, y - yViewport);
			RenderBoundingBox();
			break;
		}
		case STAIR_LEFT:
		{
			animations[STAIR_LEFT]->Render(x - xViewport, y - yViewport);
			break;
		}
		case STAIR_RIGHT:
		{
			animations[STAIR_RIGHT]->Render(x - xViewport, y - yViewport);
			break;
		}
	}
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	CGameObject::SetState(this->state);

	if (this->state != STAIR_LEFT && this->state != STAIR_RIGHT)
	{
		l = x;
		t = y;

		switch (this->state)
		{
		case BRICK:
		{
			r = x + BRICK_BBOX_WIDTH;
			b = y + BRICK_BBOX_HEIGHT;
			break;
		}
		case GROUND:
		{
			r = x + GROUND_BBOX_WIDTH;
			b = y + GROUND_BBOX_HEIGHT;
			break;
		}
		}
	}
}