#include "BossBat.h"
#include <ctime>


void BossBat::LoadResource()
{
	//Load Item
	this->item = new Items();
	this->item->LoadResource();
	this->item->SetState(I_BOSS_BAT);
	this->item->SetInvisible(true);

	//load resource zombie
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_BOSSBAT, L"Resource\\sprites\\Bosses\\VAMPIRE_BAT.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_DEAD, L"Resource\\sprites\\Effect\\DEAD.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texBoss = textures->Get(ID_TEX_BOSSBAT);


	sprites->Add(301, 0, 0, 100, 46, texBoss);		//boss static


	sprites->Add(302, 100, 0, 200, 46, texBoss);		//boss fly
	sprites->Add(303, 200, 0, 300, 46, texBoss);


	LPDIRECT3DTEXTURE9 texdead = textures->Get(ID_TEX_DEAD);
	//dead object
	sprites->Add(6000, 0, 0, 42, 44, texdead);
	sprites->Add(6001, 42, 0, 84, 44, texdead);
	sprites->Add(6002, 84, 0, 128, 44, texdead);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);		//boss static
	ani->Add(301);
	animations->Add(BOSSBAT_STATIC, ani);


	ani = new CAnimation(100);		//boss fly
	ani->Add(302);
	ani->Add(303);
	animations->Add(BOSSBAT_FLY, ani);

	ani = new CAnimation(100);		//Dead
	ani->Add(6000);
	ani->Add(6001);
	ani->Add(6002);
	animations->Add(BOSSBAT_DIE, ani);

	this->AddAnimation(BOSSBAT_STATIC);
	this->AddAnimation(BOSSBAT_FLY);
	this->AddAnimation(BOSSBAT_DIE);

	//Vector v random
	vRandom.push_back(0.05);
	vRandom.push_back(0.08);
	vRandom.push_back(0.07);
	vRandom.push_back(0.1);
}

void BossBat::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects, vector<LPGAMEOBJECT>* coObjectStatic, vector<LPGAMEOBJECT>* coObjectEnemy)
{
	CGameObject::Update(dt);

	if (isAction)
	{
		if (isAttack)
		{
			this->TestA(dt);
		}
		else if (!isAttack)
		{
			x += dx;
			y += dy;
			deplayAttack -= 10;
		}
	}

}

void BossBat::Render(float xViewport, float yViewport)
{
	//Update action
	this->Action(xViewport, yViewport);

	//Update state
	this->SetState(this->state);

	//Update limit
	this->UpdateLimit(xViewport, yViewport);

	int alpha = 255;
	this->isLeft = this->nx == 1 ? true : false;

	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	if (!(isDead && isvisible))
	{
		animations[ani]->Render(x - xViewport, y - yViewport, alpha, this->isLeft);
		RenderBoundingBox();
	}
}

void BossBat::SetState(int state)
{
	CGameObject::SetState(state);

	switch (this->state)
	{
		case BOSSBAT_STATIC:
		{
			ani = BOSSBAT_STATIC;
			if (isAction)
			{
				this->state = BOSSBAT_FLY;
				vx = vRandom[1];
				vy = vRandom[1];
				//break;
			}
			break;
		}
		case BOSSBAT_FLY:
		{			
			ani = BOSSBAT_FLY;
			if (deplayAttack == 0)
			{
				this->state = BOSSBAT_ATTACK;
				isAttack = true;
			}
			break;
		}

		case BOSSBAT_ATTACK:
		{
			//ani = BOSSBAT_STATIC;
			this->vx = 0.2f;
			this->vy = 0.2f;
			if (!isAttack)
			{
				this->state = BOSSBAT_FLY;
				this->deplayAttack = 5000;
			}
			break;
		}
	}
}

void BossBat::is_Item()
{
	//whip collision vs candlesmall
	item->SetPosition(this->x, this->y);
	item->SetInvisible(false);

	//update y = x for equation sin
	item->Setcurrent_Oy(this->x);
}

void BossBat::not_Item()
{
	//simon eat item
	item->SetDead(true);
}

void BossBat::UpdateLimit(float xViewport, float yViewport)
{
	r.left = xViewport;
	r.top = yViewport + 100;
	r.right = r.left + SCREEN_WIDTH;
	r.bottom = r.top + SCREEN_HEIGHT - 170;

	if (this->x + 100 >= r.right)
	{
		srand(time(0));
		int b = 0 + rand() % (4);
		vx = -vRandom[b];
	}

	else if (this->x <= r.left)
	{
		srand(time(0));
		int b = 0 + rand() % (4);
		vx = vRandom[b];
		
	}

	else if(this->y <= r.top)
	{
		srand(time(0));
		int b = 0 + rand() % (4);
		vy = vRandom[b];
		
	}

	else if (this->y + 46 >= r.bottom)
	{
		srand(time(0));
		int b = 0 + rand() % (4);
		vy = -vRandom[b];
	}
}

void BossBat::RandomPos()
{

}

void BossBat::RandomFly()
{

}

void BossBat::Action(float xViewport, float yViewport)
{
	if ((this->x - (xViewport + SCREEN_WIDTH / 2)) <= DIS_BOSSBAT_ATTACK)
	{
		this->isAction = true;
	}
}

void BossBat::UpdatePosSimon(float _simonX, float _simonY)
{
	if (this->isAction && !isDead)
	{
		this->simonX = _simonX;
		this->simonY = _simonY;

	}
}

void BossBat::AttackSimon()
{

}

void BossBat::TestXY(float & x, float & y)
{

}

void BossBat::TestA(DWORD dt)
{


	//position target
	//float xA = 345.0f;
	//float yA = 350.0f;
	float xA = this->simonX;
	float yA = this->simonY;

	//boss -> target
	distance = std::sqrt(
		std::pow(xA - this->x, 2) +
		std::pow(yA - this->y, 2));

	//vector PT
	float ax, ay;
	ax = (xA - this->x) / distance;
	ay = (yA - this->y) / distance;

	//position Boss temp
	float posX , posY;

	posX = this->x;
	posY = this->y;
	posX += ax * vx *dt;
	posY += ay * vy *dt;

	if (std::sqrt(std::pow(xA - posX, 2) + std::pow(yA - posY, 2)) >= distance)
	{
		posX = xA;
		posY = yA;
		isAttack = false;
	}

	if (isAttack)
	{
		this->x = posX;
		this->y = posY;
	}
}

void BossBat::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (!isDead)
	{
		left = x;
		top = y;
		right = left + BOSSBAT_BBOX_WIDTH;
		bottom = top + BOSSBAT_BBOX_HEIGHT;
	}
}
