#include "StateThree.h"

StateThree::StateThree()
{

}

StateThree::~StateThree()
{

}

void StateThree::InitState(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb)
{

}

void StateThree::LoadState()
{
	CGameState::LoadState();

	//r1
	r1.left = 0;
	r1.top = 200;
	r1.right = 160;
	r1.bottom = 400;

	//r2
	r2.left = 254;
	r2.top = 200;
	r2.right = 420;
	r2.bottom = 400;

	//Box Map
	BoxMap *map13 = new BoxMap();
	map13->LoadResource();
	map13->SetPosition(200.0f, 250.0f);
	map13->SetAniBoxMap(BOX_CHANGE_MAP1);
	objecttsStatic.push_back(map13);

	//Simon
	//simon = new CMario();
	//simon->LoadResource();
	////simon->SetPosition(20.0f,0);
	//simon->SetPosition(260.0f, 0);
	//simon->SetState(SM_STAND_STATIC);
	//objects.push_back(simon);


	//effect water
	//CEffect *e1 = new CEffect();
	//e1->LoadResource();
	//e1->SetPosition(300.0f, 300.0f);
	//e1->SetState(EFFECT_WATER);
	//e1->SetNX(0);
	//objectsEnemy.push_back(e1);

	//CEffect *e2 = new CEffect();
	//e2->LoadResource();
	//e2->SetPosition(300.0f, 300.0f);
	//e2->SetState(EFFECT_WATER);
	//e2->SetNX(1);
	//objectsEnemy.push_back(e2);

	//CEffect *e3 = new CEffect();
	//e3->LoadResource();
	//e3->SetPosition(300.0f, 300.0f);
	//e3->SetState(EFFECT_WATER);
	//e3->SetNX(-1);
	//objectsEnemy.push_back(e3);

	//merman
	//this->createEnemy();
	//Merman *mer1 = new Merman();
	//mer1->LoadResource();
	//mer1->SetPosition(280.0f, 400.0f);
	//mer1->SetState(MERMAN_JUMP);
	//mer1->Set_Rlim(r2);
	//objectsEnemy.push_back(mer1->GetFireball());
	//objectsEnemy.push_back(mer1);

	//Merman *mer2 = new Merman();
	//mer2->LoadResource();
	//mer2->SetPosition(150.0f, 400.0f);
	//mer2->SetState(MERMAN_JUMP);
	//mer2->Set_Rlim(r1);
	//objectsEnemy.push_back(mer2->GetFireball());
	//objectsEnemy.push_back(mer2);

	//merA = new Merman();
	//merA->LoadResource();
	//merA->SetPosition(r1.left + 100.0f, 400.0f);
	//merA->SetState(MERMAN_JUMP);
	//merA->Set_Rlim(r1);
	//objectsEnemy.push_back(merA->GetFireball());
	//objectsEnemy.push_back(merA);

	//merB = new Merman();
	//merB->LoadResource();
	//merB->SetPosition(r2.left + 100.0f, 400.0f);
	//merB->SetState(MERMAN_JUMP);
	//merB->Set_Rlim(r2);
	//merB->SetDead(true);
	//objectsEnemy.push_back(merB->GetFireball());
	//objectsEnemy.push_back(merB);


	//GLimit merman jump
	CLimit *limJump = new CLimit();
	limJump->LoadResource();
	limJump->SetwidthBBox(1.856f);
	limJump->SetPosition(70.0f, 220.0f);//130
	limJump->SetState(LIMIT_GROUND);
	objecttsStatic.push_back(limJump);
	

	//G1
	CLimit *limG1 = new CLimit();
	limG1->SetwidthBBox(1.856f);
	limG1->SetPosition(0.0f, 290.0f);
	limG1->SetState(LIMIT_GROUND);
	objects.push_back(limG1);

	//G21
	CLimit *limG21 = new CLimit();
	limG21->SetwidthBBox(0.128f);
	limG21->SetPosition(190.0f, 230.0f);
	limG21->SetState(LIMIT_GROUND);
	objects.push_back(limG21);

	//G22
	CLimit *limG22 = new CLimit();
	limG22->SetwidthBBox(0.128f);
	limG22->SetPosition(960.0f, 354.0f);
	limG22->SetState(LIMIT_GROUND);
	objects.push_back(limG22);

	//G23
	CLimit *limG23 = new CLimit();
	limG23->SetwidthBBox(0.128f);
	limG23->SetPosition(896.0f, 418.0f);
	limG23->SetState(LIMIT_GROUND);
	objects.push_back(limG23);
}

void StateThree::UpdateState(DWORD dt)
{
	this->createEnemy();
	CGameState::UpdateState(dt);
}

void StateThree::RenderState(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler)
{
	//Update viewport
	tilemap->UpdateScrollPosition();
	CGameState::RenderState(d3ddv, bb, spriteHandler);
}

void StateThree::createEnemy()
{
	//simon thuoc RECT?
	RECT temp = r1;
	if (simon->x >= r2.left)
	{
		temp = r2;
	}

	//so luong merman con tren map
	//if (merA->isDead || merB->isDead)
	//{
	//	numMerman--;
	//}


	if (numMerman < 2)
	{
		//create merman khung thich hop
		//if (merA->isDead)
		{
			merA = new Merman();
			merA->LoadResource();
			merA->SetPosition(temp.left + 100.0f, 400.0f);
			merA->SetState(MERMAN_JUMP);
			merA->Set_Rlim(temp);
			objectsEnemy.push_back(merA->GetFireball());
			objectsEnemy.push_back(merA);
			numMerman++;
		}

		//if (merB->isDead)
		{
			merB = new Merman();
			merB->LoadResource();
			merB->SetPosition(temp.left + 150.0f, 400.0f);
			merB->SetState(MERMAN_JUMP);
			merB->Set_Rlim(temp);
			objectsEnemy.push_back(merB->GetFireball());
			objectsEnemy.push_back(merB);
			numMerman++;
		}

	}
	
}
