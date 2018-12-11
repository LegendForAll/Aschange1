#pragma once
#include "GameObject.h"
#include "OStatis.h"


class Candle : public COStatic
{

	Items *_item;
	
public:

	Candle();
	~Candle();

	void is_Item();
	void not_Item();
	Items* GetItem() { return this->_item; }

	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL, vector<LPGAMEOBJECT> *coObjectStatic = NULL, vector<LPGAMEOBJECT> *coObjectEnemy = NULL);
};