#include "StateManager.h"

MState::MState()
{

}

MState::~MState()
{

}

void MState::Init()
{

}

void MState::LoadState(int _stateID)
{
	switch (_stateID)
	{
		case STATE_MAP_MENU:
		{
			delete(gamestate);
			break;
		}

		case STATE_MAP_INTRO:
		{
			delete(gamestate);			
			break;
		}

		case STATE_MAP_START:
		{
			delete(gamestate);
			gamestate = new StateOne();
			gamestate->tilemap = new TileMap(L"textures\\mapR.png");
			gamestate->tilemap->SetSettingMap(MAPWIDTH_1, MAPHEIGHT_1);
			gamestate->tilemap->LoadMapCSV(L"mapR.csv");
			gamestate->LoadState();
			gamestate->simon->SetPosition(this->pointSimonX, this->pointSimonY);
			this->stateID = _stateID;
			break;
		}

		case STATE_MAP_1:
		{
			delete(gamestate);
			gamestate = new StateTwo();
			gamestate->tilemap = new TileMap(L"textures\\map1A.png");
			gamestate->tilemap->SetSettingMap(MAPWIDTH_2, MAPHEIGHT_2);
			gamestate->tilemap->LoadMapCSV(L"map1A.csv");
			gamestate->LoadState();
			this->stateID = _stateID;
			break;
		}

		case STATE_MAP_2:
		{
			delete(gamestate);
			gamestate = new StateThree();
			gamestate->tilemap = new TileMap(L"textures\\map1B.png");
			gamestate->tilemap->SetSettingMap(MAPWIDTH_3, MAPHEIGHT_3);
			gamestate->tilemap->LoadMapCSV(L"map1B.csv");
			gamestate->LoadState();
			gamestate->simon->SetPosition(this->pointSimonX, this->pointSimonY);
			this->stateID = _stateID;
			break;
		}
	}
}

void MState::Render(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler)
{
	gamestate->RenderState(d3ddv, bb, spriteHandler);
}

void MState::Update(DWORD dt)
{
	gamestate->UpdateState(dt);
	this->SetChangeGameState();
}

void MState::ChangeState(DWORD dt)
{
	if (Change)
	{
		LoadState(this->stateID);
		this->Change = false;
	}
	//this->SetChangeGameState();
}

void MState::SetChangeGameState()
{
	if (gamestate->simonChangeMap())
	{
		
		//this->stateID = STATE_MAP_1;
		this->stateID = gamestate->simon->GetMap();

		switch (this->stateID)
		{
			case BOX_CHANGE_MAP2:
			{
				
				if (IsKeyDown(DIK_DOWN))
				{
					Change = true;
				}
				break;
			}
			//Neu nhu la BOX undo
			//Thi moi set position simon lai
			default:
			{
				Change = true;
				break;
			}
		}
	}
}
