#pragma once
#include "GameObject.h"
#include "OStatis.h"
#include "Items.h"

class CandleSmall : public COStatic
{
	int ani = CANDLESMALL_STATE_NO;
	Items *_item;

public:

	CandleSmall();
	~CandleSmall();

	void is_Item();
	void not_Item();
	Items* GetItem() { return this->_item; }

	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL, vector<LPGAMEOBJECT> *coObjectStatic = NULL, vector<LPGAMEOBJECT> *coObjectEnemy = NULL);
};