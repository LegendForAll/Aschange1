#include "Items.h"

Items::Items()
{

}

Items::~Items()
{

}

void Items::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_ITEM_HEART_BIG, L"Resource\\sprites\\Items\\BIG_HEART.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_ITEM_MORNING_STAR, L"Resource\\sprites\\Items\\MORNING_STAR.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_ITEM_MONEY_BLUE, L"Resource\\sprites\\Items\\Money_bag_blue.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_ITEM_ROSARY, L"Resource\\sprites\\Items\\ROSARY.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_ITEM_ROSACT, L"Resource\\sprites\\Items\\ROAST.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_ITEM_STOPWATCH, L"Resource\\sprites\\Items\\STOP_WATCH.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_ITEM_DOUBLE_SHOT, L"Resource\\sprites\\Items\\DOUBLE_SHOT.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_ITEM_BALL, L"Resource\\sprites\\Items\\13.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texHeart = textures->Get(ID_ITEM_HEART_BIG);
	sprites->Add(2000, 0, 0, 24, 20, texHeart);

	LPDIRECT3DTEXTURE9 texMoring = textures->Get(ID_ITEM_MORNING_STAR);
	sprites->Add(2001, 0, 0, 32, 32, texMoring);

	LPDIRECT3DTEXTURE9 texMoney = textures->Get(ID_ITEM_MONEY_BLUE);
	sprites->Add(2002, 0, 0, 32, 32, texMoney);

	LPDIRECT3DTEXTURE9 texRosary = textures->Get(ID_ITEM_ROSARY);
	sprites->Add(2003, 0, 0, 32, 32, texRosary);

	LPDIRECT3DTEXTURE9 texRosact = textures->Get(ID_ITEM_ROSACT);
	sprites->Add(2004, 0, 0, 32, 32, texRosact);

	LPDIRECT3DTEXTURE9 texWatch = textures->Get(ID_ITEM_STOPWATCH);
	sprites->Add(2005, 0, 0, 32, 32, texWatch);

	LPDIRECT3DTEXTURE9 texShot = textures->Get(ID_ITEM_DOUBLE_SHOT);
	sprites->Add(2006, 0, 0, 32, 32, texShot);

	LPDIRECT3DTEXTURE9 texBall = textures->Get(ID_ITEM_BALL);
	sprites->Add(2007, 0, 0, 32, 32, texBall);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);
	ani->Add(2000);
	animations->Add(I_HEART_BIG, ani);

	ani = new CAnimation(100);
	ani->Add(2001);
	animations->Add(I_MORNING_STAR, ani);

	ani = new CAnimation(100);
	ani->Add(2002);
	animations->Add(I_MONEY_BLUE, ani);

	ani = new CAnimation(100);
	ani->Add(2003);
	animations->Add(I_ROSARY, ani);

	ani = new CAnimation(100);
	ani->Add(2004);
	animations->Add(I_ROSACT, ani);

	ani = new CAnimation(100);
	ani->Add(2005);
	animations->Add(I_STOPWATCH, ani);

	ani = new CAnimation(100);
	ani->Add(2006);
	animations->Add(I_DOUBLE_SHOT, ani);

	ani = new CAnimation(100);
	ani->Add(2007);
	animations->Add(I_BOSS_BAT, ani);

	this->AddAnimation(I_HEART_BIG);
	this->AddAnimation(I_MORNING_STAR);
	this->AddAnimation(I_MONEY_BLUE);
	this->AddAnimation(I_ROSARY);
	this->AddAnimation(I_ROSACT);
	this->AddAnimation(I_STOPWATCH);
	this->AddAnimation(I_DOUBLE_SHOT);
	this->AddAnimation(I_BOSS_BAT);

	this->SetState(I_HEART_BIG);
}

void Items::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;



	switch (this->state)
	{
		case I_HEART_BIG:
		{
			currentAni = I_HEART_BIG;
			break;
		}
		case I_MORNING_STAR:
		{
			currentAni = I_MORNING_STAR;
			break;
		}
		case I_MONEY_BLUE:
		{
			currentAni = I_MONEY_BLUE;
			break;
		}
		case I_ROSARY:
		{
			currentAni = I_ROSARY;
			break;
		}
		case I_ROSACT:
		{
			currentAni = I_ROSACT;
			break;
		}
		case I_STOPWATCH:
		{
			currentAni = I_STOPWATCH;
			break;
		}
		case I_DOUBLE_SHOT:
		{
			currentAni = I_DOUBLE_SHOT;
			break;
		}
		case I_BOSS_BAT:
		{
			currentAni = I_BOSS_BAT;
			break;
		}
	}

	if (!isvisible)
	{
		animations[currentAni]->Render(x - xViewport, y - yViewport);
		//animations[typeItem]->Render(x - xViewport, y - yViewport);
		RenderBoundingBox();
	}
}

void Items::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	if (!(isvisible && isDead))
	{
		l = x;
		t = y;
		r = x + ITEM_BBOX_WIDTH;
		b = y+ ITEM_BBOX_HEIGHT;
	}
}

void Items::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy)
{
	// Calculate dx, dy 
	if (!isvisible)
	{
		CGameObject::Update(dt);
		vy += ITEM_GRAVITY * dt;

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();


		CalcPotentialCollisions(coObjects, coEvents); //tao ra danh sach cac doi tuong co kha nang va cham


		// No collision occured, proceed normally
		if (coEvents.size() == 0) //danh sach kha nang va cham rong  x, y mario cap nhat binh thuong
		{
			y += dy;
			
			if (this->equation_Fly == EQUATION_SIN)
			{
				x = AMx * cos(((2 * CONST_PI * CURRENT_TIME) / double(Tms)) + ((2 * CONST_PI * y) / double(LAMDA_Ox))) + this->current_Oy;
			}
			else
			{
				x += dx;
			}	

		}
		else	//co doi tuong co kha nang va cham voi mario
		{
			float min_tx, min_ty, nx = 0, ny;

			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			// block 
			x += min_tx * dx + nx * 0.1f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
			y += min_ty * dy + ny * 0.1f;

			if (nx != 0) vx = 0; //khi mario co va cham theo huong RIGHT-> nx = 1/LEFT->ny = -1
			if (ny != 0) vy = 0; //khi mario co va cham theo huong DOWN-> ny = -1/UP->ny = 1 cho vy = 0 de khong bi roi tu do

			// Collision logic with Object after collision vs mario
			for (UINT i = 0; i < coEventsResult.size(); i++)//UNIT
			{
				LPCOLLISIONEVENT e = coEventsResult[i];
				//xu ly sau va cham voi Candle => collision whip vs candle
				if (dynamic_cast<CBrick *>(e->obj))
				{
					//Candle *_candle = dynamic_cast<Candle *>(e->obj);
					//if (e->nx != 0)
					//{
					//	//Xu ly sau va cham
					//	_candle->SetDead(true);
					//	_candle->SetInvisible(true);
					//	_candle->SetState(CANDLE_STATE_DIE);
					//}
				}
			}
		}
		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}


}

void Items::Set_positionSimon(float _xSimon, float _ySimon)
{
	this->SetPosition(_xSimon, _ySimon);
}

void Items::Random_pre()
{
	this->typeItem = rand() % 7;
	this->currentAni = this->typeItem;
}
