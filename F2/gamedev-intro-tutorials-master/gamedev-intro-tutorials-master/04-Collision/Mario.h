#pragma once
#include "GameObject.h"
#include "Whip.h"
#include "Knife.h"
#include "Axe.h"

#define SM_WALKING_SPEED		0.1f
#define SM_WALKING_STAIR_SPEED	1.0f;
//0.1f
#define SM_JUMP_SPEED_Y			0.65f
#define SM_JUMP_DEFLECT_SPEED	0.2f
#define SM_GRAVITY				0.002f

#define SM_NOMAL				1

#define SM_BBOX_WIDTH			40
#define SM_BBOX_HEIGHT			66

#define USE_NOT					0
#define USE_WHIP				1
#define USE_KNIFE				2
#define USE_AXE					4


class CMario : public CGameObject
{
	int level;
	int untouchable;
	DWORD untouchable_start;

	//weapon
	Whip *whip = new Whip();
	Knife *kni = new Knife();
	Axe *axe = new Axe();

	//weapon
	int typeWeapon = USE_NOT;

	//Current Animation
	int ani = SM_STAND_STATIC;

	//int current nx collisionBOX;
	int curNX_BOX;

	//Type map
	int isMap;

	//Flags
	bool isIntro = false;
	bool isAttack = false;
	bool isGround = true;
	bool isLeft = true;
	bool isEatItem = false;
	bool isOnStair = false;
	bool isCollisonBox = false;
	bool isCollisonTop = false;
	bool isWhip = true;
	int isAutoBox = 0;
	D3DXVECTOR3 pos;

	//Time deplay auto
	int timeAuto = 5000;

	//Item 
	Items *item;

	//LPDIRECT3DTEXTURE9 texture;		//texture SIMON
	//CSprites * sprites;				//Manager sprite SIMON
	//CAnimations * animation;		//Manager animation SIMON

public:
	CMario() : CGameObject()
	{
		level = SM_NOMAL;
		untouchable = 0;
		whip->LoadResource();
		kni->LoadResource();
		axe->LoadResource();
	}

	void LoadAnimation();
	virtual void LoadResource();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);
	void SetState(int state);
	void SetAni(int _ani) { this->ani = _ani; }
	void SetIntro(bool _intro) { this->isIntro = true; }
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void SetItem(Items *_item) { this->item = _item; }

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckKey();
	void KeyEventHandler();

	//lay nx simon vs BOX stair
	void SetcurrentColBOX(int _nxBOX) { this->curNX_BOX = _nxBOX; }
	int GetcurrentColBOX() { return this->curNX_BOX; }

	int GetAutobox() { return this->isAutoBox; }
	void SetMap(int _isMap) { this->isMap = _isMap; }
	int GetMap() { return this->isMap; }
	void SetPosBoxUndo(float _x, float _y, float _z = 0);
	D3DXVECTOR3 GetBoxUndo() { return this->pos; }

};