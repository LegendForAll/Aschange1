#include "Axe.h"

void Axe::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_AXE, L"Resource\\sprites\\Sub_weapons\\AXE_ACTION.png", D3DCOLOR_XRGB(255, 0, 255));

	LPDIRECT3DTEXTURE9 texAXE = textures->Get(ID_TEX_AXE);

	CSprites * sprites = CSprites::GetInstance();
	sprites->Add(300, 0, 0, 30, 28, texAXE);
	sprites->Add(301, 30, 0, 60, 28, texAXE);
	sprites->Add(302, 60, 0, 90, 28, texAXE);
	sprites->Add(303, 90, 0, 120, 28, texAXE);


	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);		//Axe
	ani->Add(300, 90);
	ani->Add(301, 90);
	ani->Add(302, 90);
	ani->Add(303, 90);
	animations->Add(WP_AXE_STAND, ani);

	this->AddAnimation(WP_AXE_STAND);

}

void Axe::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	if (!isDead)
	{
		l = x;
		t = y;
		r = l + AXE_BBOX_WIDTH;
		b = t + AXE_BBOX_HEIGHT;
	}
}

void Axe::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects, vector<LPGAMEOBJECT>* coObjectStatic, vector<LPGAMEOBJECT>* coObjectEnemy)
{
	CGameObject::Update(dt);
	vy += 0.001 * dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	CalcPotentialCollisions(coObjects, coEvents);


	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		y += dy;
		x += dx;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx * dx + nx * 0.1f;
		y += min_ty * dy + ny * 0.1f;

		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;

		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			if (dynamic_cast<CandleSmall *>(e->obj))
			{
				CandleSmall *_canM = dynamic_cast<CandleSmall *>(e->obj);
				if (e->nx != 0)
				{
					_canM->SetState(CANDLESMALL_STATE_DIE);
					_canM->SetDead(true);
					_canM->SetInvisible(true);
					_canM->is_Item();
				}
			}

			if (dynamic_cast<CLimit *> (e->obj))
			{
				this->isDead = true;
				vy = 0;
				vx = 0;
			}
		}
	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Axe::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;
	int alpha = 255;

	//this->SetState(this->state);

	//animation axe left or right
	this->isLeft = nx > 0 ? false : true;

	//choose animation axe stand or sit
	this->ani = isStand ? 0 : 1;
	if (!isDead)
	{
		animations[ani]->Render(x - xViewport, y - yViewport, alpha, isLeft);
		//Render boundingBox at end frame of currentAnimation
		RenderBoundingBox();
	}
	

}

void Axe::SetCurrentPosSimon(float _xSimon, float _ySimon, int _nx, bool _isStand)
{
	this->x = _xSimon + 20.0f;
	this->y = _ySimon + 15.0f;
	this->nx = _nx;
	this->isStand = _isStand;
	this->AxeFly();
	this->SetDead(false);
}

void Axe::SetState(int state)
{
	CGameObject::SetState(state);

}
