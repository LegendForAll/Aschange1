#pragma once
#include "GameState.h"

class StateThree : public CGameState
{
	RECT r1;
	RECT r2;
	//RECT r3;
	//RECT r4;
	int numMerman = 0;
	Merman * merA;
	Merman * merB;

public:

	StateThree();
	~StateThree();

	virtual void InitState(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb);
	virtual void LoadState();
	virtual void UpdateState(DWORD dt);
	virtual void RenderState(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler);

	void createEnemy();
};