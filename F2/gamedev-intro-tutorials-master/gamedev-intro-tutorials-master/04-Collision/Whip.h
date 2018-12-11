#pragma once
#include "GameObject.h"
#include "define.h"
#include "Candle.h"
#include "CandleSmall.h"
#include "Zombie.h"
#include "Panther.h"



class Whip : public CGameObject
{
	float curX;
	float curY;
	bool isLeft = false;
	bool isStand = true;
	int currentAni = 0;
	int timeDelay = 0;
	bool oneHIT = false;

public:
	Whip();
	~Whip();
	
	virtual void LoadResource();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects , vector<LPGAMEOBJECT> *coObjectStatic , vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);

	void SetPositionLR(float _x, float _y, bool _isStand, bool _isLeft);
};