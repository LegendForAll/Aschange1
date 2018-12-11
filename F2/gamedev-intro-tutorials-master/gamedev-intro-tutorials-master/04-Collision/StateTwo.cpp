#include "StateTwo.h"
#include "Knife.h"
#include "Axe.h"

StateTwo::StateTwo()
{

}

StateTwo::~StateTwo()
{

}

void StateTwo::InitState(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb)
{
	tilemap = new TileMap(L"textures\\map1A.png");
	tilemap->ViewPort();
	tilemap->LoadMapCSV(NULL);
}

void StateTwo::LoadState()
{
	CGameState::LoadState();

	//Simon
	//simon = new CMario();
	//simon->LoadResource();
	//simon->SetPosition(50.0f, 0);
	//simon->SetState(SM_STAND_STATIC);
	//objects.push_back(simon);

	//Box Map
	BoxMap *map2 = new BoxMap();
	map2->LoadResource();
	map2->SetPosition(300.0f, 380.0f);
	map2->SetAniBoxMap(BOX_CHANGE_MAP2);
	objecttsStatic.push_back(map2);

	//Boss
	boss = new BossBat();
	boss->LoadResource();
	boss->SetPosition(400.0f, 150.0f);
	boss->SetState(BOSSBAT_STATIC);
	objectsEnemy.push_back(boss);
	objectsEnemy.push_back(boss->GetItem());

	//Groud
	BOXStair *box_dl = new BOXStair();
	box_dl->LoadResource();
	box_dl->SetPosition(2972.0f, 150);
	box_dl->SetState(BOX_LEFT);
	objecttsStatic.push_back(box_dl);

	BOXStair *box_dr = new BOXStair();
	box_dr->LoadResource();
	box_dr->SetPosition(3200.0f, 150);
	box_dr->SetState(BOX_RIGHT);
	objecttsStatic.push_back(box_dr);

	//Candle small H1
	for (int i = 1; i <= 4; i++)
	{
		CandleSmall *can = new CandleSmall();
		can->LoadResource();
		can->SetPosition(i * 255.0f, 280.0f);
		can->SetState(CANDLESMALL_STATE_NO);
		objects.push_back(can->GetItem());
		objecttsStatic.push_back(can);

	}

	//Candle small H2
	CandleSmall *can = new CandleSmall();
	can->LoadResource();
	can->SetPosition(345.0f, 350.0f);
	can->SetState(CANDLESMALL_STATE_NO);
	objects.push_back(can->GetItem());
	objecttsStatic.push_back(can);

	//CandleSmall *test = new CandleSmall();
	//test->LoadResource();
	//test->SetPosition(200.0f, 350.0f);
	//test->SetState(CANDLESMALL_STATE_NO);
	//objects.push_back(test->GetItem());
	//objecttsStatic.push_back(test);

	for (int i = 1; i <= 4; i++)
	{
		CandleSmall *can = new CandleSmall();
		can->LoadResource();
		can->SetPosition(i * 258.0f + 345.0f, 350.0f);
		can->SetState(CANDLESMALL_STATE_NO);
		objects.push_back(can->GetItem());
		objecttsStatic.push_back(can);

	}

	//Limit map
	CLimit *lim = new CLimit();
	lim->SetPosition(0.0f, 0.0f);
	lim->SetState(LIMIT_CAMERA);
	objects.push_back(lim);

	CLimit *lim1 = new CLimit();
	lim1->SetPosition(5600, 0.0f);
	lim->SetState(LIMIT_CAMERA);
	objects.push_back(lim1);

	//G31
	CLimit *limG3 = new CLimit();
	limG3->SetPosition(1500, 223.0f);
	limG3->SetwidthBBox(0.64f);
	limG3->SetState(LIMIT_GROUND);
	objects.push_back(limG3);

	//G21
	CLimit *limG2 = new CLimit();
	limG2->SetPosition(1373, 287.0f);
	limG2->SetwidthBBox(0.192f);
	limG2->SetState(LIMIT_GROUND);
	objects.push_back(limG2);

	//G22
	CLimit *limG22 = new CLimit();
	limG22->SetPosition(1856, 287.0f);
	limG22->SetwidthBBox(0.384f);
	limG22->SetState(LIMIT_GROUND);
	objects.push_back(limG22);

	//G32
	CLimit *limG32 = new CLimit();
	limG32->SetPosition(2780, 225.0f);
	limG32->SetwidthBBox(1.088f);
	limG32->SetState(LIMIT_GROUND);
	objects.push_back(limG32);

	//G23
	CLimit *limG23 = new CLimit();
	limG23->SetPosition(3328, 287.0f);
	limG23->SetwidthBBox(0.192f);
	limG23->SetState(LIMIT_GROUND);
	objects.push_back(limG23);

	//Ground
	CLimit *limG1 = new CLimit();
	limG1->SetwidthBBox(6.176f);
	limG1->SetPosition(0.0f, 415.0f);
	limG1->SetState(LIMIT_GROUND);
	objects.push_back(limG1);

	//G12
	CLimit *limG12 = new CLimit();
	limG12->SetwidthBBox(1.024f);
	limG12->SetPosition(3072.0f, 415.0f);
	limG12->SetState(LIMIT_GROUND);
	objects.push_back(limG12);

	//Box stair

	//left - right

	//stair1
	BOXStair *box11 = new BOXStair();
	box11->LoadResource();
	//box11->SetNX(1);
	box11->SetcurrentBox(1);
	box11->SetState(BOX_STAIR_BOTTOM);
	box11->SetPosition(1248, 408);
	objecttsStatic.push_back(box11);

	BOXStair *box12 = new BOXStair();
	box12->LoadResource();
	//box12->SetNX(1);
	box12->SetcurrentBox(1);
	box12->SetState(BOX_STAIR_TOP);
	box12->SetPosition(1376, 190.0f);
	objecttsStatic.push_back(box12);

	//stair2
	BOXStair *box13 = new BOXStair();
	box13->LoadResource();
	//box11->SetNX(1);
	box13->SetcurrentBox(1);
	box13->SetState(BOX_STAIR_BOTTOM);
	box13->SetPosition(1440, 284.0f);
	objecttsStatic.push_back(box13);

	BOXStair *box14 = new BOXStair();
	box14->LoadResource();
	//box12->SetNX(1);
	box14->SetcurrentBox(1);
	box14->SetState(BOX_STAIR_TOP);
	box14->SetPosition(1505, 125.0f);
	objecttsStatic.push_back(box14);


	//stair4
	BOXStair *box15 = new BOXStair();
	box15->LoadResource();
	box15->SetcurrentBox(1);
	box15->SetState(BOX_STAIR_BOTTOM);
	box15->SetPosition(2594.0f, 408.0f);
	objecttsStatic.push_back(box15);

	BOXStair *box16 = new BOXStair();
	box16->LoadResource();
	box16->SetcurrentBox(1);
	box16->SetState(BOX_STAIR_TOP);
	box16->SetPosition(2785.0f, 127.0f);
	objecttsStatic.push_back(box16);

	//right -left

	//stair3
	BOXStair *box21 = new BOXStair();
	box21->LoadResource();
	//box14->SetNX(-1);
	box21->SetcurrentBox(-1);
	box21->SetState(BOX_STAIR_BOTTOM);
	box21->SetPosition(1857.0f, 280.0f);
	objecttsStatic.push_back(box21);

	BOXStair *box23 = new BOXStair();
	box23->LoadResource();
	//box13->SetNX(-1);
	box23->SetcurrentBox(-1);
	box23->SetState(BOX_STAIR_TOP);
	box23->SetPosition(1792, 125.0f);
	objecttsStatic.push_back(box23);

	//stair5
	BOXStair *box51 = new BOXStair();
	box51->LoadResource();
	box51->SetcurrentBox(-1);
	box51->SetState(BOX_STAIR_BOTTOM);
	box51->SetPosition(3516.0f, 409.0f);
	objecttsStatic.push_back(box51);

	BOXStair *box52 = new BOXStair();
	box52->LoadResource();
	box52->SetcurrentBox(-1);
	box52->SetState(BOX_STAIR_TOP);
	box52->SetPosition(3390.0f, 190.0f);
	objecttsStatic.push_back(box52);

	//Zombie 3
	Zombie *zom8 = new Zombie();
	zom8->SetPosition(2940, 345.0f);
	zom8->LoadResource();
	zom8->SetNX(-1);
	zom8->SetSpeed(0.05f, 1.0f);
	zom8->SetState(ZOMBIE_MOVE_LEFT);
	zom8->SetlimX(2940);
	zom8->SetSlimX(2000);
	//objectsEnemy.push_back(zom8);

	Zombie *zom9 = new Zombie();
	zom9->SetPosition(2900, 345.0f);
	zom9->LoadResource();
	zom9->SetNX(-1);
	zom9->SetSpeed(0.05f, 1.0f);
	zom9->SetState(ZOMBIE_MOVE_LEFT);
	zom9->SetlimX(2900);
	zom9->SetSlimX(1800);
	//objectsEnemy.push_back(zom9);

	Zombie *zom10 = new Zombie();
	zom10->SetPosition(2890, 345.0f);
	zom10->LoadResource();
	zom10->SetNX(-1);
	zom10->SetSpeed(0.05f, 1.0f);
	zom10->SetState(ZOMBIE_MOVE_LEFT);
	zom10->SetlimX(2890);
	zom10->SetSlimX(2000);
	//objectsEnemy.push_back(zom10);


	//Zombie 2
	Zombie *zom5 = new Zombie();
	zom5->SetPosition(1820, 345.0f);
	zom5->LoadResource();
	zom5->SetNX(-1);
	zom5->SetSpeed(0.05f, 1.0f);
	zom5->SetState(ZOMBIE_MOVE_LEFT);
	zom5->SetlimX(1820);
	zom5->SetSlimX(1120);
	//objectsEnemy.push_back(zom5);

	Zombie *zom6 = new Zombie();
	zom6->SetPosition(1870, 345.0f);
	zom6->LoadResource();
	zom6->SetNX(-1);
	zom6->SetSpeed(0.05f, 1.0f);
	zom6->SetState(ZOMBIE_MOVE_LEFT);
	zom6->SetlimX(1870);
	zom6->SetSlimX(1120);
	//objectsEnemy.push_back(zom6);

	Zombie *zom7 = new Zombie();
	zom7->SetPosition(1910, 345.0f);
	zom7->LoadResource();
	zom7->SetNX(-1);
	zom7->SetSpeed(0.05f, 1.0f);
	zom7->SetState(ZOMBIE_MOVE_LEFT);
	zom7->SetlimX(1910);
	zom7->SetSlimX(1600);
	//objectsEnemy.push_back(zom7);

	//Zombie 1 
	Zombie *zom1 = new Zombie();
	zom1->SetPosition(600, 345.0f);
	zom1->LoadResource();
	zom1->SetNX(-1);
	zom1->SetSpeed(0.05f, 1.0f);
	zom1->SetState(ZOMBIE_MOVE_LEFT);
	zom1->SetlimX(600);
	zom1->SetSlimX(500);
	objects.push_back(zom1->GetItem());
	//objectsEnemy.push_back(zom1);

	Zombie *zom3 = new Zombie();
	zom3->SetPosition(700, 345.0f);
	zom3->LoadResource();
	zom3->SetNX(-1);
	zom3->SetSpeed(0.05f, 1.0f);
	zom3->SetState(ZOMBIE_MOVE_LEFT);
	zom3->SetlimX(700);
	zom3->SetSlimX(500);
	objects.push_back(zom3->GetItem());
	//objectsEnemy.push_back(zom3);

	//Zombie *zom4 = new Zombie();
	//zom4->SetPosition(650, 345.0f);
	//zom4->LoadResource();
	//zom4->SetNX(-1);
	//zom4->SetSpeed(0.05f, 1.0f);
	//zom4->SetState(ZOMBIE_MOVE_LEFT);
	//zom4->SetlimX(650);
	//zom4->SetSlimX(500);
	//objectsEnemy.push_back(zom4);

	Zombie *zom2 = new Zombie();
	zom2->SetPosition(900, 345.0f);
	zom2->LoadResource();
	zom2->SetNX(-1);
	zom2->SetSpeed(0.05f, 1.0f);
	zom2->SetState(ZOMBIE_MOVE_LEFT);
	zom2->SetlimX(900);
	zom2->SetSlimX(300);
	objects.push_back(zom2->GetItem());
	//objectsEnemy.push_back(zom2);

	//Panther
	Panther *pan1 = new Panther();
	pan1->LoadResource();
	pan1->SetPosition(1390, 100);//1390
	pan1->SetNX(-1);
	pan1->SetState(PANTHER_STATIC);
	objects.push_back(pan1->GetItem());
	objectsEnemy.push_back(pan1);

	Panther *pan2 = new Panther();
	pan2->LoadResource();
	pan2->SetPosition(1760, 100);
	pan2->SetNX(-1);
	pan2->SetState(PANTHER_STATIC);
	objectsEnemy.push_back(pan2);

	//Bat red
	BatRed *bat1 = new BatRed();
	bat1->LoadResource();
	bat1->SetPosition(3609.0f, 190.0f);
	bat1->SetNX(-1);
	bat1->SetState(BAT_RED_STATIC);
	objectsEnemy.push_back(bat1);
}

void StateTwo::UpdateState(DWORD dt)
{
	boss->UpdatePosSimon(simon->x, simon->y);
	CGameState::UpdateState(dt);
}

void StateTwo::RenderState(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler)
{
	//Update viewport
	tilemap->UpdateScrollPosition();
	CGameState::RenderState(d3ddv, bb, spriteHandler);
}