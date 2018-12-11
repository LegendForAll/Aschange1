#pragma once
#include "dsutil.h"


int InitDirectSound(HWND);
CSound* LoadSound(LPTSTR filename);
void PlaySound(CSound*);
void LoopSound(CSound*);
void StopSound(CSound*);