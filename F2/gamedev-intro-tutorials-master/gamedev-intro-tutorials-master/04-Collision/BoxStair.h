#pragma once
#include "GameObject.h"
#include "define.h"

class BOXStair : public CGameObject
{
	int currentBOX;

public:

	BOXStair();
	~BOXStair();

	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);

	void SetcurrentBox(int _here) { this->currentBOX = _here; }
	int GetcurrentBox() { return this->currentBOX; }
};