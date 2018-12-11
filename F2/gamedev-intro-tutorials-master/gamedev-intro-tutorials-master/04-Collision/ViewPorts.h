#pragma once
#include <d3dx9.h>
#include "define.h"

class CView
{
	D3DXVECTOR3 pos_cam;
	float Width_cam = SCREEN_WIDTH;
	float Height_cam = SCREEN_HEIGHT;

public:
	CView(float x_cam, float y_cam);
	~CView();

	// position_W => position_VP
	D3DXVECTOR3 SetPositionInCamera(D3DXVECTOR3 pos_W);

	// set position camera in W
	void SetPositionCamera(float x, float y);

	// get position camera in W
	D3DXVECTOR3 GetPositionCamera();
};