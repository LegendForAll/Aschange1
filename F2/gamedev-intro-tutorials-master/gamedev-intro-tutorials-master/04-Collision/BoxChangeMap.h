#pragma once
#include "GameObject.h"
#include "define.h"

class BoxMap :public CGameObject 
{
	int AniBoxMap;

public:

	BoxMap();
	~BoxMap();

	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);

	void SetAniBoxMap(int _AniBox) { this->AniBoxMap = _AniBox; }
	int GetAniBoxMap() { return this->AniBoxMap; }

};