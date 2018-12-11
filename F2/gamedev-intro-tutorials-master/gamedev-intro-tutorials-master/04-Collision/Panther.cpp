#include "Panther.h"

void Panther::LoadResource()
{
	//Load Item
	this->item = new Items();
	this->item->LoadResource();
	this->item->SetState(I_HEART_BIG);
	this->item->SetInvisible(true);

	//load resource zombie
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_PANTHER, L"Resource\\sprites\\Enemies\\PANTHER.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_DEAD, L"Resource\\sprites\\Effect\\DEAD.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texPan = textures->Get(ID_TEX_PANTHER);


	sprites->Add(301, 0, 0, 64, 32, texPan);		//panther static

	sprites->Add(302, 192, 0, 256, 32, texPan);		//panther jump

	sprites->Add(303, 64, 0, 128, 32, texPan);		//panther move
	sprites->Add(304, 128, 0, 192, 32, texPan);
	sprites->Add(305, 192, 0, 256, 32, texPan);


	LPDIRECT3DTEXTURE9 texdead = textures->Get(ID_TEX_DEAD);
	//dead object
	sprites->Add(6000, 0, 0, 42, 44, texdead);
	sprites->Add(6001, 42, 0, 84, 44, texdead);
	sprites->Add(6002, 84, 0, 128, 44, texdead);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);		//panther static
	ani->Add(301);
	animations->Add(PANTHER_STATIC, ani);

	ani = new CAnimation(100);		//panther jump
	ani->Add(302);
	animations->Add(PANTHER_JUMP, ani);

	ani = new CAnimation(100);		//panther move
	ani->Add(303);
	ani->Add(304);
	ani->Add(305);
	animations->Add(PANTHER_MOVE, ani);

	ani = new CAnimation(100);		//Dead
	ani->Add(6000);
	ani->Add(6001);
	ani->Add(6002);
	animations->Add(PANTHER_DIE, ani);

	this->AddAnimation(PANTHER_STATIC);
	this->AddAnimation(PANTHER_JUMP);
	this->AddAnimation(PANTHER_MOVE);
	this->AddAnimation(PANTHER_DIE);
}

void Panther::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects, vector<LPGAMEOBJECT>* coObjectStatic, vector<LPGAMEOBJECT>* coObjectEnemy)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);
	vy += PANTHER_GRAVITY * dt;


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();


	CalcPotentialCollisions(coObjects, coEvents); //tao ra danh sach cac doi tuong co kha nang va cham

	// No collision occured, proceed normally
	if (coEvents.size() == 0) //danh sach kha nang va cham rong  x, y mario cap nhat binh thuong
	{
		if (!isDead)
		{
			x += dx;
			y += dy;
		}
	}
	else	//co doi tuong co kha nang va cham voi mario
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += dx;						// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty * dy + ny * 0.4f;

		//if (nx != 0) vx = 0; //khi mario co va cham theo huong RIGHT-> nx = 1/LEFT->ny = -1
		if (ny != 0) vy = 0; //khi mario co va cham theo huong DOWN-> ny = -1/UP->ny = 1 cho vy = 0 de khong bi roi tu do

		// Collision logic with Object after collision vs panther
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{

		}
	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Panther::Render(float xViewport, float yViewport)
{
	CGameObject::SetState(state);

	//Update limit
	this->UpdateLimit(xViewport, yViewport);

	//Update action
	this->Action(xViewport, yViewport);
	
	//Update state of panther
	this->SetState(state);

	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	int alpha = 255;
	this->isLeft = this->nx == 1 ? true : false;

	if (!(isDead && isvisible))
	{
		animations[ani]->Render(x - xViewport, y - yViewport, alpha, this->isLeft);
		RenderBoundingBox();
	}
	else if (isDead)
	{
		if(this->state == PANTHER_DIE)
		{
			animations[ani]->Render(x - xViewport, y - yViewport, alpha, this->isLeft);
			RenderBoundingBox();
			//animations[PANTHER_DIE]->Render(x - xViewport, y - yViewport);

			//if (animations[PANTHER_DIE]->CheckDoAllFrame())
			//{
			//	this->SetState(PANTHER_STATIC);
			//	animations[PANTHER_DIE]->SetDoAllFrame(false);
			//}
		}
	}
}

void Panther::SetState(int state)
{
	CGameObject::SetState(state);

	switch (this->state)
	{
		case PANTHER_STATIC:
		{
			this->vx = 0;

			if (isAction)
			{
				this->state = PANTHER_JUMP;
				ani = PANTHER_JUMP;
				vx = -PANTHER_WALKING_SPEED;
				vy = -PANTHER_JUMP_SPEED;
				break;
			}
			break;
		}
		case PANTHER_JUMP:
		{
			if (animations[PANTHER_JUMP]->CheckDoAllFrame())
			{
				this->state = PANTHER_MOVE;
				ani = PANTHER_MOVE;
				break;
			}
			break;
		}
		case PANTHER_MOVE:
		{
			ani = PANTHER_MOVE;
			break;
		}

		case PANTHER_DIE:
		{
			ani = PANTHER_DIE;
			if (animations[PANTHER_DIE]->CheckDoAllFrame())
			{
				animations[PANTHER_DIE]->SetDoAllFrame(false);
				this->state = PANTHER_STATIC;
				ani = PANTHER_STATIC;
				break;
			}
			break;
		}
	}
}

void Panther::is_Item()
{
	item->SetPosition(this->x, this->y);
	item->SetInvisible(false);
}

void Panther::UpdateLimit(float xViewport, float yViewport)
{
	if (this->x - xViewport < 0.0f)
	{
		this->SetInvisible(true);
		this->SetDead(true);
	}
}

void Panther::Action(float xViewport, float yViewport)
{
	if ((this->x - (xViewport + SCREEN_WIDTH/2)) <= DIS_PANTHER_ATTACK)
	{
		this->isAction = true;
	}
}

void Panther::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (!isDead)
	{
		left = x;
		top = y;
		right = left + PANTHER_BBOX_WIDTH;
		bottom = top + PANTHER_BBOX_HEIGHT;
	}
}
