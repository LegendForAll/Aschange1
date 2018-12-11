#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"
#include "Goomba.h"
#include "Candle.h"
#include "Items.h"
#include "Brick.h"
#include "BoxStair.h"
#include "BoxChangeMap.h"
#include "LimitTransparent.h"


bool douKey = false;

void CMario::LoadAnimation()
{
	//Load animation SIMON

	//Load texture of Animation SIMON


	//SM STAND STATIC

	//SM SIT

	//SM NOVE

	//SM JUMP

	//SM HURTED

	//SM THROW WEAPON

	//SM DEAD

	//SM INVISIBLE

	//SM EAT ITEM

	//SM FALL DOWN

	//SM STAND ATTACK

	//SM SIT ATTACK

	//SM STAND_UP_STAIR

	//SM STAND_DOWN_STAIR

	//SM ATTACK UP_STAIR

	//SM ATTACK DOWN_STAIR

	//SM MOVE UP_STAIR

	//SM MOVE DOWN_STAIR
}

void CMario::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_SIMON, L"Resource\\sprites\\Simon\\Simon_ver_editted.png", D3DCOLOR_XRGB(255, 0, 255));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texMario = textures->Get(ID_TEX_SIMON);

	//load sprite stand and static
	sprites->Add(101, 0, 0, 60, 64, texMario);
	sprites->Add(102, 60, 0, 120, 64, texMario);
	sprites->Add(103, 120, 0, 180, 64, texMario);
	sprites->Add(104, 180, 0, 240, 64, texMario);
	//load sprite sit
	sprites->Add(105, 240, 0, 300, 64, texMario);
	//load sprite jump
	sprites->Add(106, 240, 0, 300, 64, texMario);
	//load sprite stand attack
	sprites->Add(107, 300, 0, 360, 64, texMario);
	sprites->Add(108, 360, 0, 420, 64, texMario);
	sprites->Add(109, 420, 0, 480, 64, texMario);
	//load sptite sit attack
	sprites->Add(110, 420, 66, 480, 132, texMario);
	sprites->Add(111, 0, 132, 60, 198, texMario);
	sprites->Add(112, 60, 132, 120, 198, texMario);
	//load sprite stand up_stair
	sprites->Add(113, 240, 66, 300, 132, texMario);
	//load sprite stand down_stair
	sprites->Add(114, 120, 66, 180, 132, texMario);
	//load sprite go up_stair
	sprites->Add(115, 240, 66, 300, 132, texMario);
	sprites->Add(116, 300, 66, 360, 132, texMario);
	//load sprite go down_stair
	sprites->Add(117, 120, 66, 180, 132, texMario);
	sprites->Add(118, 180, 66, 240, 132, texMario);
	//load sprite attack up_stair
	sprites->Add(119, 300, 132, 360, 198, texMario);
	sprites->Add(120, 360, 132, 420, 198, texMario);
	sprites->Add(121, 420, 132, 480, 198, texMario);
	//load sprite attack down_stair
	sprites->Add(122, 120, 132, 180, 198, texMario);
	sprites->Add(123, 180, 132, 240, 198, texMario);
	sprites->Add(124, 240, 132, 300, 198, texMario);
	//load sprite hurted
	sprites->Add(125, 0, 66, 60, 132, texMario);
	//load sprite invisible
	sprites->Add(126, 180, 198, 240, 264, texMario);
	sprites->Add(127, 0, 0, 60, 64, texMario);
	//load sprite eatItem
	sprites->Add(128, 0, 198, 60, 264, texMario);
	sprites->Add(129, 60, 198, 120, 264, texMario);
	sprites->Add(130, 120, 198, 180, 264, texMario);
	//load sprite die
	sprites->Add(131, 240, 198, 300, 264, texMario);
	//load stand back
	sprites->Add(132, 60, 66, 120, 132, texMario);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	ani = new CAnimation(100);		// simon stand static
	ani->Add(101, 100);
	animations->Add(SM_STAND_STATIC, ani);

	ani = new CAnimation(100);		// simon move left
	ani->Add(101, 150);
	ani->Add(102, 150);
	ani->Add(103, 150);
	ani->Add(104, 150);
	animations->Add(SM_MOVE_LEFT, ani);

	ani = new CAnimation(100);		// simon sit
	ani->Add(105);
	animations->Add(SM_SIT, ani);

	ani = new CAnimation(100);		// simon jump
	ani->Add(106);
	animations->Add(SM_JUMP, ani);

	ani = new CAnimation(100);		// simon stand attack (whip)
	ani->Add(101, 90);	//ani important
	ani->Add(107, 90);
	ani->Add(108, 90);
	ani->Add(109, 90);
	animations->Add(SM_STAND_ATTACK, ani);

	ani = new CAnimation(100);		// simon stand attack (weapon)
	ani->Add(107, 170);
	ani->Add(108, 170);
	ani->Add(109, 170);
	animations->Add(SM_THROW_WEAPON, ani);

	ani = new CAnimation(100);		// simon sit attack (whip)
	ani->Add(105, 90);
	ani->Add(110, 90);
	ani->Add(111, 90);
	ani->Add(112, 90);
	animations->Add(SM_SIT_ATTACK, ani);

	ani = new CAnimation(100);		// simon stand up_stair
	ani->Add(113);
	animations->Add(SM_STAND_UP_STAIR, ani);

	ani = new CAnimation(100);		// simon stand down_stair
	ani->Add(114);
	animations->Add(SM_STAND_DOWN_STAIR, ani);

	ani = new CAnimation(100);		// simon go up_stair
	ani->Add(115, 170);
	ani->Add(116, 170);
	animations->Add(SM_MOVE_UP_STAIR, ani);

	ani = new CAnimation(100);		// simon go down stair
	ani->Add(117, 170);
	ani->Add(118, 170);
	animations->Add(SM_MOVE_DOWN_STAIR, ani);

	ani = new CAnimation(100);		// simon attack up_stair
	ani->Add(119, 170);
	ani->Add(120, 170);
	ani->Add(121, 170);
	animations->Add(SM_ATTACK_UP_STAIR, ani);

	ani = new CAnimation(100);		// simon attack down_stair
	ani->Add(122, 170);
	ani->Add(123, 170);
	ani->Add(124, 170);
	animations->Add(SM_ATTACK_DOWN_STAIR, ani);

	ani = new CAnimation(100);		// simon hurted
	ani->Add(125);
	animations->Add(SM_HURTED, ani);

	ani = new CAnimation(100);		// simon Invisible
	ani->Add(126, 200);
	ani->Add(127, 200);
	animations->Add(SM_INVISIBLE, ani);

	ani = new CAnimation(100);		// simon eat Item
	ani->Add(128);
	ani->Add(129);
	ani->Add(130);
	animations->Add(SM_EAT_ITEM, ani);

	ani = new CAnimation(100);		// fall down
	ani->Add(101);
	animations->Add(SM_FALL_DOWN, ani);

	ani = new CAnimation(100);		// throw weapon
	ani->Add(107, 170);
	ani->Add(108, 170);
	ani->Add(109, 170);
	animations->Add(SM_THROW_WEAPON, ani);

	ani = new CAnimation(100);		// die
	ani->Add(131);
	animations->Add(SM_DEAD, ani);

	ani = new CAnimation(100);		// stand back
	ani->Add(132);
	animations->Add(SM_STAND_BACK, ani);

	ani = new CAnimation(100);		// simon fly attack (whip)
	ani->Add(105, 200);
	ani->Add(110, 200);
	ani->Add(111, 200);
	ani->Add(112, 200);
	animations->Add(SM_FLY_ATTACK, ani);



	this->AddAnimation(SM_STAND_STATIC);		//simon stand static
	this->AddAnimation(SM_MOVE_LEFT);			//simon move left
	this->AddAnimation(SM_SIT);					//simon sit
	this->AddAnimation(SM_JUMP);				//simon jump
	this->AddAnimation(SM_STAND_ATTACK);		//simon stand attack
	this->AddAnimation(SM_SIT_ATTACK);			//simon sit attack
	this->AddAnimation(SM_STAND_UP_STAIR);		//simon stand up stair
	this->AddAnimation(SM_STAND_DOWN_STAIR);	//simon stand down stair
	this->AddAnimation(SM_MOVE_UP_STAIR);		//simon move up_stair
	this->AddAnimation(SM_MOVE_DOWN_STAIR);		//simon move down_stair
	this->AddAnimation(SM_ATTACK_UP_STAIR);		//simon attack up_stair
	this->AddAnimation(SM_ATTACK_DOWN_STAIR);	//simon attack down_stair
	this->AddAnimation(SM_HURTED);				//simon hurted
	this->AddAnimation(SM_INVISIBLE);			//simon invisible
	this->AddAnimation(SM_EAT_ITEM);			//simon eatItem
	this->AddAnimation(SM_FALL_DOWN);			//simon fall down
	this->AddAnimation(SM_THROW_WEAPON);		//simon throw weapon
	this->AddAnimation(SM_DEAD);				//simon die
	this->AddAnimation(SM_STAND_BACK);			//simon stand back
	this->AddAnimation(SM_FLY_ATTACK);			//simon fly attack
}

void CMario::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	vy += SM_GRAVITY * dt;
	//-----------------------------------------------------
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
		this->isCollisonBox = false;
		this->isCollisonTop = false;
	}

	else
	{
		for (int i = 0; i < coEventStair.size(); i++)
		{
			if (dynamic_cast<BOXStair *>(coEventStair[i]))
			{
				BOXStair *box = dynamic_cast<BOXStair *>(coEventStair[i]);

				if (box->state == BOX_STAIR_BOTTOM)
				{
					this->isCollisonBox = true;
					this->curNX_BOX = (box->GetcurrentBox());
				}

				else if (box->state == BOX_STAIR_TOP)
				{
					this->isCollisonTop = true;
					this->curNX_BOX = (box->GetcurrentBox());
				}

				else if (box->state == BOX_LEFT)
				{
					this->isAutoBox = -1;
				}

				else if (box->state == BOX_RIGHT)
				{
					this->isAutoBox = 1;
					this->isvisible = true;
				}

				else if (box->state == BOX_CHANGE_MAPNEXT)
				{
					this->isAutoBox = 2;
				}
			}

			if (dynamic_cast<BoxMap *>(coEventStair[i]))
			{
				BoxMap *box = dynamic_cast<BoxMap *>(coEventStair[i]);
				this->isAutoBox = 2;
				this->SetMap(box->GetAniBoxMap());
				//phan biet box map ma no va cham
			}
		}
	}
	//-----------------------------------------------------

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	CalcPotentialCollisions(coObjects, coEvents); //tao ra danh sach cac doi tuong co kha nang va cham


	// No collision occured, proceed normally
	if (coEvents.size() == 0) //danh sach kha nang va cham rong  x, y mario cap nhat binh thuong
	{
		x += dx;
		y += dy;
	}
	else	//co doi tuong co kha nang va cham voi mario
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx * dx + nx * 0.1f;		//khi va cham van di chuyen theo truc Ox binh thuong
		y += min_ty * dy + ny * 0.1f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame

		if (nx != 0) vx = 0; //khi mario co va cham theo huong RIGHT-> nx = 1/LEFT->ny = -1
		if (ny != 0) vy = 0; //khi mario co va cham theo huong DOWN-> ny = -1/UP->ny = 1 cho vy = 0 de khong bi roi tu do

		// Collision logic with Object after collision vs mario
		for (UINT i = 0; i < coEventsResult.size(); i++)//UNIT
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			//xu ly sau va cham voi Candle => collision whip vs candle
			//if (dynamic_cast<BOXStair *>(e->obj))
			//{
			//	isCollisonBox = true;
			//}
			if (dynamic_cast<Items *>(e->obj))
			{
				Sound::GetInstance()->Play(COLLECT_WEAPON);
				Items *_item = dynamic_cast<Items *>(e->obj);
				if (e->nx != 0)
				{
					_item->SetDead(true);
					_item->SetInvisible(true);
					this->state = SM_EAT_ITEM;
					ani = SM_EAT_ITEM;
				}
			}

			//else if (dynamic_cast<CBrick *>(e->obj))
			//{
			//	if (e->ny == -1)
			//	{
			//		isGround = true;
			//	}
			//}

			else if (dynamic_cast<CLimit *>(e->obj))
			{
				if (e->ny == -1)
				{
					isGround = true;
				}
				else if (e->nx != 0)
				{
					vx = 0;
				}
			}
		}
	}

	whip->Update(dt, coObjects, coObjectStatic, coObjectEnemy);
	kni->Update(dt, coObjects, coObjectStatic, coObjectEnemy);
	axe->Update(dt, coObjects, coObjectStatic, coObjectEnemy);

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];


}

void CMario::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	//Set left or right weapons
	whip->SetNX(this->nx);

	//opacity of sprite
	int alpha = 255;

	bool isStand;
	bool isWP = false;
	this->isLeft = this->nx == 1 ? true : false;

	//Using State Machine to render
	//if (this->typeWeapon == USE_WHIP)
	{
		switch (state)
		{
		case SM_STAND_ATTACK:
		{
			isStand = true;
			if (this->typeWeapon == USE_WHIP)
			{
				isWP = true;
			}
			break;
		}

		case SM_SIT_ATTACK:
		{
			isStand = false;
			if (this->typeWeapon == USE_WHIP)
			{
				isWP = true;
			}
			break;
		}

		default:
		{
			break;
		}
		}
	}

	if (!isvisible)
	{
		//Render animation of simon
		animations[ani]->Render(x - xViewport, y - yViewport, alpha, this->isLeft);
		//Render boundingBox of simon
		//RenderBoundingBox();
	}


	//Render animation of weapon
	if (isWP)
	{
		//sm use whip -> whip is life
		whip->SetPositionLR(x, y, isStand, this->isLeft);
		whip->SetDead(false);
		whip->Render(xViewport, yViewport);
	}

	switch (this->typeWeapon)
	{
	case USE_NOT:
	{

		break;
	}
	case USE_AXE:
	{

		axe->Render(xViewport, yViewport);
		break;
	}
	case USE_KNIFE:
	{
		kni->Render(xViewport, yViewport);
		break;
	}
	//---------------------------------------------------------
	case USE_WHIP:
	{
		////if (isWP)
		//{
		//		//sm use whip -> whip is life
		//		whip->SetPositionLR(x, y, isStand, this->isLeft);
		//		whip->SetDead(false);
		//		whip->Render(xViewport, yViewport);
		//}
		//break;
	}
	//---------------------------------------------------------
	}
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case SM_STAND_STATIC:
	{
		if (IsKeyDown(DIK_RIGHT))								//sm move right && !douKey
		{
			this->state = SM_MOVE_LEFT;
			nx = 1;
			vx = SM_WALKING_SPEED;
			ani = SM_MOVE_LEFT;
			break;
		}
		else if (IsKeyDown(DIK_LEFT) || isIntro)							//sm move left && !douKey
		{
			this->state = SM_MOVE_LEFT;
			nx = -1;
			vx = -SM_WALKING_SPEED;
			ani = SM_MOVE_LEFT;
			break;
		}
		else if (IsKeyDown(DIK_DOWN) && isCollisonTop == false)							//sm sit
		{
			this->state = SM_SIT;
			vx = 0;
			ani = SM_SIT;
			break;
		}
		else if ((IsKeyPress(DIK_Z)) && isAttack == false)		//sm attack RIGHT/LEFT
		{
			Sound::GetInstance()->Play(USING_WHIP);
			this->isAttack = true;
			this->state = SM_STAND_ATTACK;
			vx = 0;
			this->typeWeapon = USE_WHIP;
			ani = SM_STAND_ATTACK;
			break;
		}
		//-------------------------------------------------------------------
		else if ((IsKeyPress(DIK_LCONTROL)))
		{
			this->isAttack = true;
			this->state = SM_STAND_ATTACK;
			vx = 0;
			ani = SM_STAND_ATTACK;
			//this->typeWeapon = USE_AXE;
			//axe->SetCurrentPosSimon(this->x, this->y, this->nx);
			this->typeWeapon = USE_KNIFE;
			kni->SetCurrentPosSimon(this->x, this->y, this->nx);
			break;
		}
		//-------------------------------------------------------------------
		else if (IsKeyPress(DIK_X) && isGround == true)			//sm jump
		{
			isGround = false;
			vy = -SM_JUMP_SPEED_Y;
			vx = 0;					//tam thoi = 0
			this->state = SM_JUMP;
			ani = SM_JUMP;
			break;
		}

		else if (IsKeyDown(DIK_UP) && isCollisonBox && isGround)					//sm stair left - top
		{
			this->isGround = false;
			this->isCollisonBox = false;

			this->isOnStair = true;
			this->state = SM_STAND_UP_STAIR;
			ani = SM_STAND_UP_STAIR;
			break;
		}

		else if (IsKeyDown(DIK_DOWN) && isCollisonTop && isGround)					//sm down stair
		{
			this->isGround = false;
			this->isCollisonTop = false;

			this->isOnStair = true;
			this->state = SM_STAND_DOWN_STAIR;
			ani = SM_STAND_DOWN_STAIR;
			break;
		}

	default:
	{
		vx = 0;
		break;
	}
	break;
	}

	case SM_MOVE_UP_STAIR:
	{
		this->vy = 0;
		this->x = this->x + curNX_BOX * SM_WALKING_STAIR_SPEED;
		//this->x += SM_WALKING_STAIR_SPEED;			//position x phu thuong vao nx box_stair
		this->y -= SM_WALKING_STAIR_SPEED;				//position y khong phu thuoc nx box_stair

		if (IsKeyRelease(DIK_UP))
		{
			this->state = SM_STAND_UP_STAIR;
			this->ani = SM_STAND_UP_STAIR;
			break;
		}

		//khi dang up stair
		else if (isCollisonTop)
		{
			this->state = SM_STAND_STATIC;
			this->ani = SM_STAND_STATIC;
			break;
		}

		break;
	}

	case SM_MOVE_DOWN_STAIR:
	{
		this->vy = 0;
		this->x = this->x - curNX_BOX * SM_WALKING_STAIR_SPEED;
		//this->x -= SM_WALKING_STAIR_SPEED;			//position x phu thuoc vao nx box_stair
		this->y += SM_WALKING_STAIR_SPEED;			//position y khong phu thuong nx box_stair

		if (IsKeyRelease(DIK_DOWN))
		{
			this->state = SM_STAND_DOWN_STAIR;
			this->ani = SM_STAND_DOWN_STAIR;
			break;
		}

		else if (isCollisonBox == true)
		{
			this->state = SM_SIT;
			ani = SM_SIT;
			break;
		}
		break;
	}

	case SM_STAND_DOWN_STAIR:
	{
		if (IsKeyDown(DIK_UP))
		{
			//this->SetNX(1);
			this->SetNX(1 * curNX_BOX);
			this->state = SM_MOVE_UP_STAIR;
			ani = SM_MOVE_UP_STAIR;
			break;
		}
		else if (IsKeyDown(DIK_DOWN))
		{
			//this->SetNX(-1);
			this->SetNX((-1)*curNX_BOX);
			this->state = SM_MOVE_DOWN_STAIR;
			ani = SM_MOVE_DOWN_STAIR;
			break;
		}

		vy = 0;
		x += 0;
		y += 0;
		break;
	}

	case SM_STAND_UP_STAIR:
	{
		if (IsKeyDown(DIK_UP))
		{
			//this->SetNX(1);
			this->SetNX(1 * curNX_BOX);
			this->state = SM_MOVE_UP_STAIR;
			ani = SM_MOVE_UP_STAIR;
			break;
		}
		if (IsKeyDown(DIK_DOWN))
		{
			//this->SetNX(-1);
			this->SetNX((-1)*curNX_BOX);
			this->state = SM_MOVE_DOWN_STAIR;
			ani = SM_MOVE_DOWN_STAIR;
			break;
		}
		vy = 0;
		x += 0;
		y += 0;
		break;
	}

	case SM_JUMP:
	{
		if (isGround)											//sm collision Ground
		{
			this->state = SM_STAND_STATIC;
			ani = SM_STAND_STATIC;
			isGround = true;
			break;
		}

		else if ((IsKeyPress(DIK_Z)) && isAttack == false)		//sm attack RIGHT/LEFT
		{
			Sound::GetInstance()->Play(USING_WHIP);
			this->isAttack = true;
			this->state = SM_STAND_ATTACK;
			ani = SM_STAND_ATTACK;
			this->typeWeapon = USE_WHIP;
			break;
		}

		//-------------------------------------------------------------------
		else if ((IsKeyPress(DIK_LCONTROL))) //sm use weapon in stand attack
		{
			this->isAttack = true;
			this->state = SM_STAND_ATTACK;
			vx = 0;
			ani = SM_STAND_ATTACK;
			//this->typeWeapon = USE_AXE;
			//axe->SetCurrentPosSimon(this->x, this->y, this->nx);
			typeWeapon = USE_KNIFE;
			kni->SetCurrentPosSimon(this->x, this->y, this->nx);
			break;
		}
		//-------------------------------------------------------------------
		break;
	}

	case SM_MOVE_LEFT:
	{
		if (IsKeyRelease(DIK_RIGHT))		//sm stop move right
		{
			this->state = SM_STAND_STATIC;
			vx = 0;
			ani = SM_STAND_STATIC;
			douKey = false;
			break;
		}
		else if (IsKeyRelease(DIK_LEFT))	//sm stop move left
		{
			this->state = SM_STAND_STATIC;
			vx = 0;
			ani = SM_STAND_STATIC;
			douKey = false;
			break;
		}
		//text
		//else if (IsKeyDown(DIK_LEFT) && IsKeyDown(DIK_RIGHT))
		//{
		//	this->state = SM_STAND_STATIC;
		//	vx = 0;
		//	douKey = true;
		//	ani = SM_STAND_STATIC;
		//	break;
		//}

		else if (IsKeyPress(DIK_Z) && isAttack == false)				//move - attack - stop move
		{
			Sound::GetInstance()->Play(USING_WHIP);
			vx = 0;
			this->state = SM_STAND_ATTACK;
			ani = SM_STAND_ATTACK;
			this->typeWeapon = USE_WHIP;
			isAttack = true;
			break;
		}

		//-------------------------------------------------------------------
		else if ((IsKeyPress(DIK_LCONTROL)))
		{
			this->isAttack = true;
			this->state = SM_STAND_ATTACK;
			vx = 0;
			ani = SM_STAND_ATTACK;
			//this->typeWeapon = USE_AXE;
			//axe->SetCurrentPosSimon(this->x, this->y, this->nx);
			this->typeWeapon = USE_KNIFE;
			kni->SetCurrentPosSimon(this->x, this->y, this->nx);
			break;
		}
		//-------------------------------------------------------------------
		//----------------------------
		else if (isAutoBox == -1)
		{
			this->state = SM_AUTO_DOOR;
			nx = 1;
			vx = SM_WALKING_SPEED;
			ani = SM_MOVE_LEFT;
			break;
		}
		//----------------------------
		else if (IsKeyPress(DIK_X) && isGround == true)
		{
			isGround = false;
			vy = -SM_JUMP_SPEED_Y;
			this->state = SM_JUMP;
			ani = SM_JUMP;
			break;
		}
		break;

	}
	//------------------------
	case SM_AUTO_DOOR:
	{
		if (isAutoBox == 1)
		{
			this->isAutoBox = 0;
			this->state = SM_STAND_STATIC;
			ani = SM_STAND_STATIC;
			break;
		}
		break;
	}
	//------------------------
	case SM_SIT:
	{
		if (IsKeyRelease(DIK_DOWN))			//sm stop sit and stand
		{
			this->state = SM_STAND_STATIC;
			ani = SM_STAND_STATIC;
			break;
		}
		else if (IsKeyDown(DIK_RIGHT))		//sm sit right
		{
			nx = 1;
			break;
		}
		else if (IsKeyDown(DIK_LEFT))		//sm sit left
		{
			nx = -1;
			break;
		}
		else if (IsKeyPress(DIK_Z) && isAttack == false)			//sm sit attack LEFT/RIGHT
		{
			Sound::GetInstance()->Play(USING_WHIP);
			this->state = SM_SIT_ATTACK;
			ani = SM_SIT_ATTACK;
			this->typeWeapon = USE_WHIP;
			isAttack = true;
			break;
		}

		//-------------------------------------------------------------------
		else if ((IsKeyPress(DIK_LCONTROL))) //sm use weapon in stand attack
		{
			this->isAttack = true;
			this->state = SM_STAND_ATTACK;
			vx = 0;
			ani = SM_STAND_ATTACK;
			//this->typeWeapon = USE_AXE;
			//axe->SetCurrentPosSimon(this->x, this->y, this->nx);
			typeWeapon = USE_KNIFE;
			kni->SetCurrentPosSimon(this->x, this->y, this->nx);
			break;
		}
		//-------------------------------------------------------------------
		break;
	}

	case SM_STAND_ATTACK:
	{

		if (animations[ani]->CheckDoAllFrame())//finish attack
		{
			animations[ani]->SetDoAllFrame(false);
			this->state = SM_STAND_STATIC;
			ani = SM_STAND_STATIC;
			isAttack = false;
			break;
		}
		break;
	}

	case SM_SIT_ATTACK:
	{
		if (animations[ani]->CheckDoAllFrame())		//sm finish sit attack
		{
			animations[ani]->SetDoAllFrame(false);
			this->state = SM_SIT;
			ani = SM_SIT;
			isAttack = false;
			break;
		}
		break;
	}

	case SM_EAT_ITEM:
	{
		vx = 0;
		if (animations[SM_EAT_ITEM]->CheckDoAllFrame())
		{
			animations[SM_EAT_ITEM]->SetDoAllFrame(false);
			this->state = SM_STAND_STATIC;
			isEatItem = false;
			ani = SM_STAND_STATIC;
		}
		break;
	}
	}
}

void CMario::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x + 20;
	top = y;
	right = x + SM_BBOX_WIDTH;
	bottom = y + SM_BBOX_HEIGHT;
}

void CMario::CheckKey()
{

}

void CMario::KeyEventHandler()
{
	this->SetState(this->state);
}

void CMario::SetPosBoxUndo(float _x, float _y, float _z)
{
	pos.x = _x;
	pos.y = _y;
	pos.z = _z;
}


