#pragma once
#include <unordered_map>
#include <d3dx9.h>

using namespace std;

#include "define.h"
/*
	Manage texture database
*/
class CTextures
{
	static CTextures * __instance;
	//chieu dai, rong cua 1 texture
	float width, height;

	unordered_map<int, LPDIRECT3DTEXTURE9> textures;

public: 
	CTextures();
	void loadResources();
	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 Get(unsigned int i);

	static CTextures * GetInstance();
};