#pragma once
#include "GameObject.h"
#include "define.h"
#include "Items.h"
#include "Brick.h"
#include "LimitTransparent.h"

#define ZOMBIE_WALKING_SPEED	0.1f 
#define ZOMBIE_GRAVITY			0.001f


class Zombie :public CGameObject
{

	Items *item;
	bool isGround = true;
	bool isLeft = true;
	float limx, limy;
	float Slimx;

public:

	Zombie();
	~Zombie();

	virtual void LoadResource();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);

	void SetItem(Items *_item) { this->item = _item; }
	Items* GetItem() { return this->item; }
	void is_Item();

	void UpdateLimit();

	void SetlimX(float _limx) { this->limx = _limx; }
	void SetlimY(float _limy) { this->limy = _limy; }
	void SetSlimX(float _Slimx) { this->Slimx = _Slimx; }
	float GetlimX() { return this->limx; }
	float GetlimY() { return this->limy; }
	float GetSlimX() { return this->Slimx; }

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};