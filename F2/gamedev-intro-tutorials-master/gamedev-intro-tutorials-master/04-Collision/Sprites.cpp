#include "Sprites.h"
#include "Game.h"
#include "debug.h"

CSprite::CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;
	
	//width, height of sprite
	this->width = right;
	this->height = bottom;
}

CSprites * CSprites::__instance = NULL;

CSprites *CSprites::GetInstance()
{
	if (__instance == NULL) __instance = new CSprites();
	return __instance;
}

void CSprite::Draw(float x, float y, int alpha, bool isleft)
{
	CGame * game = CGame::GetInstance();
	game->Draw(x, y, texture, left, top, right, bottom, alpha, isleft);
}

void CSprite::Render(D3DXVECTOR3 pos, RECT rect , LPDIRECT3DTEXTURE9 tex)
{
	CGame *game = CGame::GetInstance();
	game->Render(pos, rect, tex);
}

void CSprite::Render(ViewPort * viewPort, LPDIRECT3DTEXTURE9 tex)
{
	CGame *game = CGame::GetInstance();
	D3DXVECTOR3 pos;
	pos.x = 50;
	pos.y = 50;
	pos.z = 0;

	pos = viewPort->SetPositionInViewPort(pos);
	game->Render(pos, tex);
}


void CSprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	LPSPRITE s = new CSprite(id, left, top, right, bottom, tex);
	sprites[id] = s;
}

LPSPRITE CSprites::Get(int id)
{
	return sprites[id];
}



CAnimation::CAnimation()
{
	this->isDoAllFrame = false;
}

CAnimation::CAnimation(int defaultTime)
{
	this->defaultTime = defaultTime; 
	lastFrameTime = -1; 
	currentFrame = -1; 
	isDoAllFrame = false;
	timeDeplay = 0.0f;
}

void CAnimation::Add(int spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t=this->defaultTime;

	LPSPRITE sprite = CSprites::GetInstance()->Get(spriteId);
	LPANIMATION_FRAME frame = new CAnimationFrame(sprite, t);
	frames.push_back(frame);
}

void CAnimation::Render(float x, float y, int alpha, bool isleft)
{
	DWORD now = GetTickCount();
	if (currentFrame == -1) 
	{
		currentFrame = 0; 
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size())
			{
				isDoAllFrame = true; // Flag ve het frame
				currentFrame = 0;
			}
				
		}
		
	}

	//	Do khi ve het frame cua 1 animation 
	//	CURRENT FRAME => currentFrame = 0
	//	frames[currentFrame]->GetSprite()->Draw(x, y, alpha, isleft); 
	//	Auto render frames[0] cua animation => Load them 1 Frame cua NEW animation ma CURRENT ANIMATION nay chuyen den
	frames[currentFrame]->GetSprite()->Draw(x, y, alpha, isleft);
}

CAnimations * CAnimations::__instance = NULL;

CAnimations * CAnimations::GetInstance()
{
	if (__instance == NULL) __instance = new CAnimations();
	return __instance;
}

void CAnimations::Add(int id, LPANIMATION ani)
{
	animations[id] = ani;
}

LPANIMATION CAnimations::Get(int id)
{
	return animations[id];
}