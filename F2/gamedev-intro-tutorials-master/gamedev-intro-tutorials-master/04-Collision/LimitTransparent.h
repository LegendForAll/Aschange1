#pragma once
#include "GameObject.h"



class CLimit : public CGameObject
{
	float widthBBox = 1.0f;
	float heightBBox = 1.0f;

public:
	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);

	float GetwidthBBox() { return this->widthBBox; }
	void SetwidthBBox(float _widthBBox) { this->widthBBox = _widthBBox; }
	float GetheightBBox() { return this->heightBBox; }
	void SetheightBBox(float _heightBBox) { this->heightBBox = _heightBBox; }
};