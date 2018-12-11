#pragma once
#include "GameObject.h"
#include "define.h"
#include "Brick.h"

#define ITEM_GRAVITY		0.0001f

class Items : public CGameObject
{
	int currentAni = 0;
	int typeItem = I_MORNING_STAR;
	int equation_Fly = EQUATION_NORMAL;
	float current_Oy = 0.0f;

public:

	Items();
	~Items();

	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);

	void Setcurrent_Oy(float _x) { this->current_Oy = _x; }
	float Getcurrent_Oy() { return this->current_Oy; }
	void Set_positionSimon(float _xSimon, float _ySimon);
	void Random_pre();
	void Set_epuationFly(int _equa) { this->equation_Fly = _equa; }
	void Set_typeItem(int _type) { this->typeItem = _type; }
};