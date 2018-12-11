#pragma once
#include "GameObject.h"
#include "Items.h"

class BatRed :public CGameObject
{
	Items *item;
	bool isLeft = true;

	int ani = BAT_RED_STATIC;
	bool isAction = false;

public:
	virtual void LoadResource();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);
	void SetState(int state);
	void SetItem(Items *_item) { this->item = _item; }

	void UpdateLimit(float xViewport, float yViewport);
	void Action(float xViewport, float yViewport);
	void SetAction(bool _isAction) { this->isAction = _isAction; }
	bool GetAction() { return this->isAction; }

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};