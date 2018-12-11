#include "StateOne.h"

StateOne::StateOne()
{

}

StateOne::~StateOne()
{

}

void StateOne::InitState(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb)
{

}

void StateOne::LoadState()
{
	CGameState::LoadState();

	//Simon
	//simon = new CMario();
	//simon->LoadResource();
	//simon->SetPosition(50.0f, 0);
	//simon->SetState(SM_STAND_STATIC);
	//objects.push_back(simon);
	//isInitSimon = true;


	//Groud
	BOXStair *box_dl = new BOXStair();
	box_dl->LoadResource();
	box_dl->SetPosition(1300.0f, 380.0f);
	box_dl->SetState(BOX_LEFT);
	objecttsStatic.push_back(box_dl);

	//Box Map
	BoxMap *map13 = new BoxMap();
	map13->LoadResource();
	map13->SetPosition(200.0f, 380.0f);
	map13->SetAniBoxMap(BOX_CHANGE_MAP1);
	objecttsStatic.push_back(map13);

	//Ground
	CLimit *limG1 = new CLimit();
	limG1->SetwidthBBox(3.072f);
	limG1->SetPosition(0.0f, 390.0f);
	limG1->SetState(LIMIT_GROUND);
	objects.push_back(limG1);

	//Candle
	Candle *candle = new Candle();
	candle->LoadResource();
	candle->SetPosition(200.0f, 330);
	objects.push_back(candle->GetItem());
	objecttsStatic.push_back(candle);

	Candle *candle1 = new Candle();
	candle1->LoadResource();
	candle1->SetPosition(450.0f, 330);
	objects.push_back(candle1->GetItem());
	objecttsStatic.push_back(candle1);

	Candle *candle2 = new Candle();
	candle2->LoadResource();
	candle2->SetPosition(700.0f, 330);
	objects.push_back(candle2->GetItem());
	objecttsStatic.push_back(candle2);

	Candle *candle3 = new Candle();
	candle3->LoadResource();
	candle3->SetPosition(950.0f, 330);
	objects.push_back(candle3->GetItem());
	objecttsStatic.push_back(candle3);

	//Limit map
	CLimit *lim = new CLimit();
	lim->SetPosition(0.0f, 0.0f);
	objects.push_back(lim);

	CLimit *lim1 = new CLimit();
	lim1->SetPosition(1504, 0.0f);
	objects.push_back(lim1);
}

void StateOne::UpdateState(DWORD dt)
{
	CGameState::UpdateState(dt);
}

void StateOne::RenderState(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler)
{
	//Update viewport
	tilemap->UpdateScrollPosition();
	CGameState::RenderState(d3ddv, bb, spriteHandler);

}
