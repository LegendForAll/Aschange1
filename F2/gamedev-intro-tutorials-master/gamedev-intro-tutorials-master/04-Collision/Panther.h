#pragma once
#include "GameObject.h"
#include "Items.h"
#include "LimitTransparent.h"
#include "Brick.h"


#define PANTHER_WALKING_SPEED		0.2f 
#define PANTHER_JUMP_SPEED			0.5f
#define PANTHER_GRAVITY				0.002f

class Panther : public CGameObject
{
	Items *item;
	bool isGround = true;
	bool isLeft = true;
	float limx, limy;
	float Slimx;

	int ani = PANTHER_STATIC;
	bool isAction = false;

public:
	virtual void LoadResource();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);
	void SetState(int state);

	void SetItem(Items *_item) { this->item = _item; }
	Items* GetItem() { return this->item; }
	void is_Item();

	void UpdateLimit(float xViewport, float yViewport);
	void Action(float xViewport, float yViewport);
	void SetAction(bool _isAction) { this->isAction = _isAction; }
	bool GetAction() { return this->isAction; }

	void SetlimX(float _limx) { this->limx = _limx; }
	void SetlimY(float _limy) { this->limy = _limy; }
	void SetSlimX(float _Slimx) { this->Slimx = _Slimx; }
	float GetlimX() { return this->limx; }
	float GetlimY() { return this->limy; }
	float GetSlimX() { return this->Slimx; }

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};