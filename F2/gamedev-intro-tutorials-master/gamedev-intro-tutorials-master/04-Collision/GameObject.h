#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Game.h"
#include "Sprites.h"
#include "Input.h"


using namespace std;

#define ID_TEX_BBOX -100		// special texture to draw object bounding box

class CGameObject; 
typedef CGameObject * LPGAMEOBJECT;

struct CCollisionEvent;
typedef CCollisionEvent * LPCOLLISIONEVENT;
struct CCollisionEvent
{

	LPGAMEOBJECT obj;
	float t, nx, ny;
	CCollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL) { this->t = t; this->nx = nx; this->ny = ny; this->obj = obj; }

	static bool compare(const LPCOLLISIONEVENT &a, LPCOLLISIONEVENT &b)
	{
		return a->t < b->t;
	}
};



class CGameObject
{
public:

	float x; 
	float y;

	float dx;	// dx = vx*dt
	float dy;	// dy = vy*dt

	float vx;
	float vy;

	int nx;		// xac dinh huong cua doi tuong

	int state;	// trang thai cua doi tuong

	bool isDead;
	bool isvisible;
	bool isCollisonBox;

	DWORD dt; 

	vector<LPANIMATION> animations;

	//them vao
	float X_view = 0;
	float Y_view = 0;

public: 

	
	float GetX() { return this->x; }
	float GetY() { return this->y; }

	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }
	void GetPosition(float &x, float &y) { x = this->x; y = this->y; }
	void GetSpeed(float &vx, float &vy) { vx = this->vx; vy = this->vy; }

	int GetState() { return this->state; }

	void SetNX(int nX) { this->nx = nX; }
	int GetNX() { return this->nx; }

	void RenderBoundingBox();

	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);

	//collision 2 object static
	bool AABB_BOX(LPGAMEOBJECT coO_1, LPGAMEOBJECT coO_2);

	void CalcPotentialCollisions(vector<LPGAMEOBJECT> *coObjects, vector<LPCOLLISIONEVENT> &coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents, 
		vector<LPCOLLISIONEVENT> &coEventsResult, 
		float &min_tx, 
		float &min_ty, 
		float &nx, 
		float &ny);

	void AddAnimation(int aniId);

	CGameObject();

	virtual void LoadResource() = 0;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) = 0;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL, vector<LPGAMEOBJECT> *coObjectStatic = NULL, vector<LPGAMEOBJECT> *coObjectEnemy = NULL);
	virtual void Render(float xViewport, float yViewport) = 0;
	virtual void SetState(int state) { this->state = state; }
	virtual void SetDead(bool _isDead) { this->isDead = _isDead; }
	virtual void SetInvisible(bool _isvisible) { this->isvisible = _isvisible; }

	~CGameObject();
};

