#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>
#include "ViewPort.h"
#include "Textures.h"
using namespace std;

class CSprite
{
	int id;				// Sprite ID in the sprite database

	int left; 
	int top;
	int right;
	int bottom;
	float width = 640, height = 256;	//chieu dai, chieu rong 1 sprite (TileMap)
	D3DCOLOR color;						//Mau (TileMap)

	LPDIRECT3DTEXTURE9 texture;
public: 
	CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	void Draw(float x, float y, int alpha = 255, bool isleft = false);
	void Render(D3DXVECTOR3 pos, RECT rect , LPDIRECT3DTEXTURE9 tex);
	void Render(ViewPort *viewPort, LPDIRECT3DTEXTURE9 tex);

	float GetWidth()	{ return width; }
	float GetHeight()	{ return height; }
	void SetColor(D3DCOLOR _color) { color = _color; }
};

typedef CSprite * LPSPRITE;

/*
	Manage sprite database
*/
class CSprites
{
	static CSprites * __instance;

	unordered_map<int, LPSPRITE> sprites;

public:
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	LPSPRITE Get(int id);

	static CSprites * GetInstance();
};

/*
	Sprite animation
*/
class CAnimationFrame
{
	LPSPRITE sprite;
	DWORD time;			//thoi gian ve 1 frame trong animation

public:
	CAnimationFrame(LPSPRITE sprite, int time) { this->sprite = sprite; this->time = time; }
	DWORD GetTime() { return time; }
	LPSPRITE GetSprite() { return sprite; }
};

typedef CAnimationFrame *LPANIMATION_FRAME;

class CAnimation
{

	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;

	bool isDoAllFrame = false;		//Flag xac dinh ve het frame
	float timeDeplay;		//Thoi gian song cua 1 animation
	bool isLeft;			

	vector<LPANIMATION_FRAME> frames;

public:

	CAnimation();
	CAnimation(int defaultTime);
	void Add(int spriteId, DWORD time = 0);

	//Render tung frame 1 trong vector animation frame
	void Render(float x, float y, int alpha = 255, bool left = false);

	//kiem tra trang thai hoang thanh cua cac frame trong animation
	bool CheckDoAllFrame() { return isDoAllFrame; }
	void SetDoAllFrame(bool status) { isDoAllFrame = status; }
};

typedef CAnimation *LPANIMATION;

class CAnimations
{
	static CAnimations * __instance;

	unordered_map<int, LPANIMATION> animations;

public:
	void Add(int id, LPANIMATION ani);
	LPANIMATION Get(int id);

	static CAnimations * GetInstance();
};

