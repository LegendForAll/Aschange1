#include "SoundManager.h"

Sound::Sound() {}
Sound::~Sound() {}

Sound* Sound::instance;

Sound* Sound::GetInstance()
{
	if (instance == nullptr)
		instance = new Sound();
	return instance;
}

void Sound::loadSound(HWND hwnd)
{
	InitDirectSound(hwnd);

	CSound* sound = NULL;

	sound = LoadSound(L"Resource//sound//usingwhip.wav");
	listSound[eSoundID::USING_WHIP] = sound;

	sound = LoadSound(L"Resource//sound//splashwater.wav");
	listSound[eSoundID::SLASH_WATER] = sound;

	sound = LoadSound(L"Resource//sound//select.wav");
	listSound[eSoundID::SELECT] = sound;

	sound = LoadSound(L"Resource//sound//pause.wav");
	listSound[eSoundID::PAUSE] = sound;

	sound = LoadSound(L"Resource//sound//opendoor.wav");
	listSound[eSoundID::OPEN_DOOR] = sound;

	sound = LoadSound(L"Resource//sound//holywater.wav");
	listSound[eSoundID::HOLY_WATER] = sound;

	sound = LoadSound(L"Resource//sound//holycross.wav");
	listSound[eSoundID::HOLY_CROSS] = sound;

	sound = LoadSound(L"Resource//sound//hitcannon.wav");
	listSound[eSoundID::HIT_CANNON] = sound;

	sound = LoadSound(L"Resource//sound//hit.wav");
	listSound[eSoundID::HIT_SOUND] = sound;

	sound = LoadSound(L"Resource//sound//fallingdownwatersurface.wav");
	listSound[eSoundID::FALLING_DOWN_WATER_SUFACE] = sound;

	sound = LoadSound(L"Resource//sound//falling.wav");
	listSound[eSoundID::FALLING] = sound;

	sound = LoadSound(L"Resource//sound//decreaseweaponusepoint.wav");
	listSound[eSoundID::DECREASE_WEAPON_USE_POINT] = sound;

	sound = LoadSound(L"Resource//sound//collectweapon.wav");
	listSound[eSoundID::COLLECT_WEAPON] = sound;

	sound = LoadSound(L"Resource//sound//collectitem.wav");
	listSound[eSoundID::COLLECT_ITEM] = sound;

	sound = LoadSound(L"Resource//sound//gointocastle.wav");
	listSound[eSoundID::GO_INTO_CASTLE] = sound;

	sound = LoadSound(L"Resource//sound//hurted.wav");
	listSound[eSoundID::SIMON_HURTED] = sound;

	sound = LoadSound(L"Resource//music//Boss_Battle_Poison_Mind.wav");
	listSound[eSoundID::BOSS_BATTLE_POISON_MIND] = sound;

	sound = LoadSound(L"Resource//music//Game_Over.wav");
	listSound[eSoundID::GAME_OVER] = sound;

	sound = LoadSound(L"Resource//music//Game_Start_Prologue.wav");
	listSound[eSoundID::GAME_START_PROLOGUE] = sound;

	sound = LoadSound(L"Resource//music//Life_Lost.wav");
	listSound[eSoundID::LIFE_LOST] = sound;

	sound = LoadSound(L"Resource//music//Stage_01_Vampire_Killer.wav");
	listSound[eSoundID::STAGE_01_VAMPIRE_KILLER] = sound;

	sound = LoadSound(L"Resource//music//Stage_04_Stalker.wav");
	listSound[eSoundID::STAGE_04_STALKER] = sound;

	sound = LoadSound(L"Resource//music//Stage_Clear.wav");
	listSound[eSoundID::STAGE_CLEAR] = sound;

	sound = LoadSound(L"Resource//music//Title_Theme_Prelude.wav");
	listSound[eSoundID::TITLE_THEME_PRELUDE] = sound;

	sound = LoadSound(L"Resource//sound//eat_change_state_ball.wav");
	listSound[eSoundID::EAT_CHANGE_STATE_BALL] = sound;

	sound = LoadSound(L"Resource//sound//collectmoney.wav");
	listSound[eSoundID::MONEY] = sound;
}

void Sound::Play(eSoundID id)
{
	auto sound = listSound[id];
	if (sound != NULL)
		PlaySound(sound);
}

void Sound::PlayLoop(eSoundID id)
{
	auto sound = listSound[id];
	if (sound != NULL)
		LoopSound(sound);
}

void Sound::Stop(eSoundID id)
{
	auto sound = listSound[id];
	if (sound != NULL)
		StopSound(sound);
}

bool Sound::IsPLaying(eSoundID id)
{
	auto sound = listSound[id];
	if (sound != NULL)
		return sound->IsSoundPlaying();
	return false;
}