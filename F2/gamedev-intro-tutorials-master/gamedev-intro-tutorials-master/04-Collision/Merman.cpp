#include "Merman.h"

Merman::Merman()
{

}

Merman::~Merman()
{

}

void Merman::LoadResource()
{
	//Load Item
	this->item = new Items();
	this->item->LoadResource();
	this->item->SetState(I_HEART_BIG);
	this->item->SetInvisible(true);


	//Load effect
	_w1->LoadResource();
	_w1->SetState(EFFECT_WATER);
	_w1->SetNX(0);
	_w2->LoadResource();
	_w2->SetState(EFFECT_WATER);
	_w2->SetNX(-1);
	_w3->LoadResource();
	_w3->SetState(EFFECT_WATER);
	_w3->SetNX(1);

	//Load fireball
	_fireball->LoadResource();
	//_fireball->SetSpeed(0.05f, 0.0f);

	//load resource zombie
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_MERMAN, L"Resource\\sprites\\Enemies\\MERMAN.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_DEAD, L"Resource\\sprites\\Effect\\DEAD.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texMer = textures->Get(ID_TEX_MERMAN);


	sprites->Add(301, 32, 0, 64, 64, texMer);		//merman move
	sprites->Add(302, 64, 0, 96, 64, texMer);		

	sprites->Add(303, 64, 0, 96, 64, texMer);		//merman jump

	sprites->Add(304, 64, 0, 96, 64, texMer);		//merman attack
	sprites->Add(305, 0, 0, 32, 64, texMer);


	LPDIRECT3DTEXTURE9 texdead = textures->Get(ID_TEX_DEAD);
	//dead object
	sprites->Add(6000, 0, 0, 42, 44, texdead);
	sprites->Add(6001, 42, 0, 84, 44, texdead);
	sprites->Add(6002, 84, 0, 128, 44, texdead);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);		//merman move
	ani->Add(301,180);
	ani->Add(302,180);
	animations->Add(MERMAN_MOVE, ani);

	ani = new CAnimation(100);		//merman attack
	ani->Add(304,400);
	ani->Add(305,400);
	animations->Add(MERMAN_ATTACK, ani);

	ani = new CAnimation(100);		//merman jump
	ani->Add(303);
	animations->Add(MERMAN_JUMP, ani);

	ani = new CAnimation(100);		//Dead
	ani->Add(6000);
	ani->Add(6001);
	ani->Add(6002);
	animations->Add(MERMAN_DIE, ani);

	this->AddAnimation(MERMAN_MOVE);
	this->AddAnimation(MERMAN_ATTACK);
	this->AddAnimation(MERMAN_JUMP);
	this->AddAnimation(MERMAN_DIE);
}

void Merman::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects, vector<LPGAMEOBJECT>* coObjectStatic, vector<LPGAMEOBJECT>* coObjectEnemy)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);
	


	if (!isDead)
	{
		x += dx;
		y += dy;
	}

	if (!isGround)
	{
		//vy += MERMAN_GRAVITY * dt;
		vy += 0.0005 * dt;
	}
	

	vector<LPGAMEOBJECT> coEventStair;

	for (UINT i = 0; i < coObjectStatic->size(); i++)
	{
		if (this->AABB_BOX(this, coObjectStatic->at(i)))
		{
			coEventStair.push_back(coObjectStatic->at(i));
		}
	}

	if (coEventStair.size() == 0)
	{

	}

	else
	{
		for (int i = 0; i < coEventStair.size(); i++)
		{
			if (dynamic_cast<CLimit *>(coEventStair[i]))
			{
				isJumpLimit = true;
				isEffect = true;
			}
		}
	}
	if (isJumpLimit)
	{
		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();


		CalcPotentialCollisions(coObjects, coEvents);

		// No collision occured, proceed normally
		if (coEvents.size() == 0)
		{
			
		}
		else
		{

			float min_tx, min_ty, nx = 0, ny;

			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			// block 
			x += min_tx * dx + nx * 0.4f;	// nx*0.4f : need to push out a bit to avoid overlapping next frame
			y += min_ty * dy + ny * 0.4f;

			if (nx != 0) vx = 0;
			if (ny != 0) vy = 0;

			// Collision logic with Object after collision vs panther
			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];
				if (dynamic_cast<CLimit *>(e->obj))
				{
					isGround = true;
					isEffect = false;
				}
			}
		}
		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}


	//Update effect water
	_w1->Update(dt, coObjects, coObjectStatic, coObjectEnemy);
	_w2->Update(dt, coObjects, coObjectStatic, coObjectEnemy);
	_w3->Update(dt, coObjects, coObjectStatic, coObjectEnemy);

	//fireball
	//_fireball->Update(dt, coObjects, coObjectStatic, coObjectEnemy);
}

void Merman::Render(float xViewport, float yViewport)
{


	//Update state of merman
	this->SetState(state);

	//Update rect
	//this->Set_Rlim(xViewport, yViewport);

	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	int alpha = 255;
	this->isLeft = this->nx == 1 ? true : false;

	//render
	if (!(isDead && isvisible))
	{
		animations[ani]->Render(x - xViewport, y - yViewport, alpha, this->isLeft);
		RenderBoundingBox();
	}

	if (isEffect)
	{
		_w1->Render(xViewport, yViewport);
		_w2->Render(xViewport, yViewport);
		_w3->Render(xViewport, yViewport);
	}

	switch (this->typeUse)
	{
		case 1:
		{
			_fireball->Render(xViewport, yViewport);
			break;
		}
	}
}

void Merman::SetState(int state)
{
	CGameObject::SetState(state);

	switch (this->state)
	{
		case MERMAN_MOVE:
		{
			//nx = -1;
			vx = 0;

			if (isGround)
			{
				//update limit
				this->UpdateLimit();
				vy = 0;
				ani = MERMAN_MOVE;
				vx = nx * MERMAN_WALKING_SPEED;
			}

			if (this->isAttack)
			{
				vx = 0;
				this->state = MERMAN_ATTACK;
				ani = MERMAN_ATTACK;
				//------------------------------------------------
				_fireball->SetCurrentMerman(this->x, this->y, this->nx);
				this->typeUse = 1;
				//------------------------------------------------
				break;
			}
			break;
		}

		case MERMAN_ATTACK:
		{

			if (animations[MERMAN_ATTACK]->CheckDoAllFrame())
			{
				this->state = MERMAN_MOVE;
				animations[MERMAN_ATTACK]->SetDoAllFrame(false);
				isAttack = false;
				break;
			}
			break;
		}

		case MERMAN_JUMP:
		{
			this->state = MERMAN_JUMP;
			ani = MERMAN_JUMP;
			vy = -MERMAN_JUMP_SPEED;
			nx = -1;

			_w1->SetCurrentMerman(this->x, 310.0f, 0);
			_w2->SetCurrentMerman(this->x, 310.0f, -1);
			_w3->SetCurrentMerman(this->x, 310.0f, 1);

			if (isJumpLimit)
			{
				this->state = MERMAN_MOVE;
				break;
			}
			break;
		}

		case MERMAN_DIE:
		{

			break;
		}
	}

}

void Merman::is_Item()
{
	item->SetPosition(this->x, this->y);
	item->SetInvisible(false);
}

//void Merman::Set_Rlim(float _x, float _y)
//{
//	//rlim.left = _x + 200;
//	//rlim.top = _y;
//	//rlim.right = rlim.left + 400;
//	//rlim.bottom = _y + 200;
//	rlim.left = 254;
//	rlim.top = 200;
//	rlim.right = 420;
//	rlim.bottom = _y + 200;
//}

void Merman::UpdatePosSimon(float _simonX, float _simonY)
{
	this->x = _simonX;
}

void Merman::Set_Rlim(RECT _r)
{
	rlim.left = _r.left;
	rlim.top = _r.top;
	rlim.right = _r.right;
	rlim.bottom = _r.bottom;
}

void Merman::UpdateLimit()
{
	if (this->x >= rlim.right)
	{
		nx = (-1)*nx;
		this->x = rlim.right-5;
		isAttack = true;
	}

	else if (this->x <= rlim.left)
	{
		nx = (-1)*nx;
		this->x = rlim.left+5;
		isAttack = true;
	}
}

void Merman::InitEffectWater()
{

}

void Merman::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (!isDead)
	{
		left = x;
		top = y;
		right = left + MERMAN_BBOX_WIGHT;
		bottom = top + MERMAN_BBOX_HEIGHT;
	}
}
