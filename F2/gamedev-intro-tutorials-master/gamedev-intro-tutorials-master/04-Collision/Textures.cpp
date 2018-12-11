#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "textures.h"

CTextures * CTextures::__instance = NULL;

CTextures::CTextures()
{

}

void CTextures::loadResources()
{
	this->Add(ID_TEX_MISC, L"Resource\\sprites\\ground_test.png", D3DCOLOR_XRGB(176, 224, 248));
	this->Add(ID_TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 0, 255));
	this->Add(ID_LEVEL_ONE_BG, L"Resource\\sprites\\lv1.s", D3DCOLOR_XRGB(255, 0, 255));
	this->Add(ID_TEX_SIMON, L"Resource\\sprites\\Simon\\Simon_ver_editted.png", D3DCOLOR_XRGB(255, 0, 255));
	this->Add(ID_TEX_WHIP, L"Resource\\sprites\\Weapons\\WHIP.png", D3DCOLOR_XRGB(255, 0, 255));
	this->Add(ID_TEX_CANDLE, L"Resource\\sprites\\Ground\\0.png", D3DCOLOR_XRGB(255, 0, 255));
}

CTextures *CTextures::GetInstance()
{
	if (__instance == NULL) __instance = new CTextures();
	return __instance;
}

void CTextures::Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);
	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] GetImageInfoFromFile failed: %s\n", filePath);
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3DDevice();
	LPDIRECT3DTEXTURE9 texture;

	width = info.Width;
	height = info.Height;

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,			
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
		return;
	}

	textures[id] = texture;

	DebugOut(L"[INFO] Texture loaded Ok: id=%d, %s \n", id, filePath);
}

LPDIRECT3DTEXTURE9 CTextures::Get(unsigned int i) 
{
	return textures[i];
}



