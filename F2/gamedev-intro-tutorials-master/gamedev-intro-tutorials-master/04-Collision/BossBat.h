#pragma once
#include "GameObject.h"
#include "Items.h"

class BossBat :public CGameObject
{
	Items *item;
	bool isLeft = true;
	vector <float> vRandom;

	float simonX;
	float simonY;
	RECT r;

	int ani = BAT_RED_STATIC;

	bool isAction = false;
	bool isAttack = false;
	bool isRandomFly = false;
	bool isHIT = false;
	int	deplayAttack = 5000;

	float distance;


public:

	virtual void LoadResource();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);
	void SetState(int state);

	void SetItem(Items *_item) { this->item = _item; }
	void is_Item();
	void not_Item();
	Items* GetItem() { return this->item; }

	void UpdateLimit(float xViewport, float yViewport);
	void RandomPos();
	void RandomFly();
	void Action(float xViewport, float yViewport);
	void SetAction(bool _isAction) { this->isAction = _isAction; }
	bool GetAction() { return this->isAction; }
	void UpdatePosSimon(float _simonX, float _simonY);
	void AttackSimon();

	void TestXY(float &x, float &y);
	void TestA(DWORD dt);

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};