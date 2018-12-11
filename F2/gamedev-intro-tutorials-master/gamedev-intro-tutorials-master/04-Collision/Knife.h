#pragma once
#include "GameObject.h"
#include "define.h"
#include "CandleSmall.h"
#include "Candle.h"
#include "Zombie.h"
#include "Panther.h"

class Knife : public CGameObject
{
	float curX;
	float curY;

	bool isLeft = false;
	bool isStand = true;

	int ani = WP_KNIFE_STAND;

public:

	virtual void LoadResource();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);

	void SetCurrentPosSimon(float _xSimon, float _ySimon, int _nx, bool _isStand = true);
	void SetPositionLR(float _x, float _y, bool _isStand, int _isLeft);
	void UpdateLimit(float xViewport, float yViewport);
	void SetState(int state);

	float GetcurX() { return this->curX; }
	float GetcurY() { return this->curY; }
	float GetX() { return this->x; }
};