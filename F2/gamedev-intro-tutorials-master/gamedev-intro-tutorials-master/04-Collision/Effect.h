#pragma once
#include "GameObject.h"


class CEffect : public CGameObject
{
	float curX;
	float curY;


	int ani = EFFECT_WATER;

public:

	CEffect();
	~CEffect();

	virtual void LoadResource();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);

	//void AxeFly() { this->vx = this->nx*AXE_SPEED_X; this->vy = -AXE_SPEED_Y; }
	void SetCurrentMerman(float _xMerman, float _yMerman, int _nx, bool _isStand = true);
	void UpdateLimit(float xViewport, float yViewport);
	void SetState(int state);

	float GetcurX() { return this->curX; }
	float GetcurY() { return this->curY; }
	float GetX() { return this->x; }
};
