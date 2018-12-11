#pragma once
#include "GameObject.h"
#include "define.h"
#include "Items.h"
#include "Brick.h"
#include "Effect.h"
#include "FireBall.h"
#include "LimitTransparent.h"

#define MERMAN_WALKING_SPEED	0.05f 
#define MERMAN_GRAVITY			0.001f
#define MERMAN_JUMP_SPEED		0.25f

class Merman : public CGameObject
{
	Items *item;
	bool isGround = false;
	bool isLeft = true;
	bool isJumpLimit = false;
	bool isAttack = false;
	bool isEffect = false;
	int typeUse = 0;

	int ani = MERMAN_JUMP;
	bool isAction = false;
	RECT rlim;

	//Animation effect water
	CEffect *_w1 = new CEffect();
	CEffect *_w2 = new CEffect();
	CEffect *_w3 = new CEffect();

	//fireball
	FireBall *_fireball = new FireBall();

public:

	Merman();
	~Merman();

	virtual void LoadResource();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);
	void SetState(int state);

	void SetItem(Items *_item) { this->item = _item; }
	Items* GetItem() { return this->item; }
	FireBall* GetFireball() { return this->_fireball; }

	void is_Item();

	void SetJumpLimit(bool _isJumpLimit) { this->isJumpLimit = _isJumpLimit; }
	bool GetJumpLimit() { return this->isJumpLimit; }

	void Action(float xViewport, float yViewport);
	void SetAction(bool _isAction) { this->isAction = _isAction; }
	bool GetAction() { return this->isAction; }

	//get current position simon
	void UpdatePosSimon(float _simonX, float _simonY);

	//void Set_Rlim(float _x, float _y);
	void Set_Rlim(RECT _r);
	void UpdateLimit();

	//Effect water
	void InitEffectWater();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};