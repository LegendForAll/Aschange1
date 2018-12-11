#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"define.h"
#include"Sprites.h"



class TileMap
{
	int SCREENW = SCREEN_WIDTH;
	int SCREENH = SCREEN_HEIGHT;

	//settings for the scroller
	const int TILEWIDTH = TILE_WIDTH;
	const int TILEHEIGHT = TILE_HEIGHT;

	int MAPWIDTH;
	int MAPHEIGHT;

	RECT **matrix;

	//scrolling window size
	const int WINDOWWIDTH = (SCREENW / TILEWIDTH) * TILEWIDTH;
	const int WINDOWHEIGHT = (SCREENH / TILEHEIGHT) * TILEHEIGHT;

	LPCWSTR filename;
	float ViewPortX, ViewPortY;
	int SpeedX, SpeedY;
	long start;

	CTextures *textures;


public:

	//Map
	TileMap();
	TileMap(LPCWSTR filename);
	~TileMap();

	void LoadMap();
	void LoadMapCSV(LPCWSTR filename);
	void Render(LPD3DXSPRITE spriteHandler);


	//Viewport
	void ViewPort() { ViewPortX = 0; ViewPortY = 0; }
	void UpdateScrollPosition();
	void SetViewPortY(float y) { ViewPortY = y; }
	void SetViewportX(float x) { ViewPortX = x; }
	void SetSettingMap(int _MAPWIDTH, int _MAPHEIGHT);
	float GetViewportX() { return ViewPortX; }
	float GetViewPortY() { return ViewPortY; }
};

