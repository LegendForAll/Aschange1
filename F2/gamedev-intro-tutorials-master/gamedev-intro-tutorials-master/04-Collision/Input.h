#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#define KEYBOARD_BUFFER_SIZE 1024

int InitDirectInput();			// Direct Input
int InitKeyboard(HWND hwnd);	// Setting and using keyboard
void PollKeyboard();			// Read data of keyboard

int IsKeyDown(int key);			// kiem tra trang thai phim dang duoc an hay khong
int IsKeyRelease(int key);		// kiem tra phim co dang o trang thai tren khong
int IsKeyPress(int key);		// kiem tra phim co vua chuyen tu up sang down khong

void KillKeyboard();			// Release DirectInput