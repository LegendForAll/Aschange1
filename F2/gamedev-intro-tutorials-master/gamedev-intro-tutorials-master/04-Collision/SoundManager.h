#pragma once
#include <map>
#include "define.h"
#include "dxaudio.h"

class Sound
{
private:
	std::map<eSoundID, CSound*> listSound;
	Sound();
	static Sound* instance;
public:

	~Sound();
	static Sound* GetInstance();
	void loadSound(HWND hwnd);
	void Play(eSoundID);
	void Stop(eSoundID);
	void PlayLoop(eSoundID);
	bool IsPLaying(eSoundID);
};