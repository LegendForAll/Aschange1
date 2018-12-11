#include "Input.h"

//doi tuong DirectInput
LPDIRECTINPUT8 dinput;
//kieu device cua Object DirectInput
LPDIRECTINPUTDEVICE8 dkeyboard;

char keys[256];
char keysBuffer[256]; // luu trang thai cac phim vao mang nay => xet KEYPRESS

int InitDirectInput()
{
	// khoi tao doi tuong DirectInput
	HRESULT result = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&dinput,
		NULL);

	if (result != DI_OK)
		return 0;

	// khoi tao keyBoard
	result = dinput->CreateDevice(GUID_SysKeyboard, &dkeyboard, NULL);

	if (result != DI_OK)
		return 0;

	return 1;
}

int InitKeyboard(HWND hwnd)
{
	// Thiet lap dinh dang du lieu
	HRESULT result = dkeyboard->SetDataFormat(&c_dfDIKeyboard);

	if (result != DI_OK)
		return 0;

	// Thiet lap muc do hop tac thiet bi ban phim
	// Chi ra muc do ban phim direct input theo muc do uu tiên
	result = dkeyboard->SetCooperativeLevel(hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

	if (result != DI_OK)
		return 0;

	// Gianh kiem soat keyBoard de co the tien hanh kiem tra nut nhan
	result = dkeyboard->Acquire();

	if (result != DI_OK)
		return 0;

	return 1;
}

void PollKeyboard()
{
	//doc du lieu ban phim
	for (int i = 0;i < 256;i++)
		keysBuffer[i] = keys[i];

	dkeyboard->GetDeviceState(sizeof(keys), (LPVOID)&keys);
}

int IsKeyDown(int key)
{
	return (keys[key] & 0x80);
}

int IsKeyPress(int key)
{
	return (IsKeyDown(key) && !(keysBuffer[key] & 0x80));
}

int IsKeyRelease(int key)
{
	return (!IsKeyDown(key) && (keysBuffer[key] & 0x80));
}

void KillKeyboard()
{
	if (dkeyboard != NULL)
	{
		dkeyboard->Unacquire();
		dkeyboard->Release();
		dkeyboard = NULL;
	}
}