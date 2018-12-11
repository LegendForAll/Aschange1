#pragma once
#include "GameState.h"
#include "StateOne.h"
#include "StateTwo.h"
#include "StateThree.h"


class MState 
{
	CGameState *gamestate;
	int stateID;
	bool Change = true;
	float pointSimonX, pointSimonY;

public:

	MState();
	~MState();

	void Init();
	void LoadState(int _stateID);
	void NextState();
	void Render(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler);
	void Update(DWORD dt);
	void ChangeState(DWORD dt);
	void SetChangeGameState();

	void SetStateID(int _IDstate) { this->stateID = _IDstate; }

};
