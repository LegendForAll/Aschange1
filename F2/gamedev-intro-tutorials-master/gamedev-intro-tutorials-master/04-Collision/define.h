#pragma once
//Window
#define WINDOW_CLASS_NAME					L"SampleWindow"
#define MAIN_WINDOW_TITLE					L"Castlevania"
#define BACKGROUND_COLOR D3DCOLOR_XRGB		(0, 0, 0)
#define MAX_FRAME_RATE						90

//Map state
#define FULLSCREEN							false
#define SCREEN_WIDTH						640
#define SCREEN_HEIGHT						480
#define TILE_WIDTH							64
#define TILE_HEIGHT							64

#define ID_TEX_MAP1							100
#define MAPWIDTH_1							24
#define MAPHEIGHT_1							6

#define ID_TEX_MAP2							200
#define MAPWIDTH_2							88
#define MAPHEIGHT_2							6

#define ID_TEX_MAP3							300
#define MAPWIDTH_3							16
#define MAPHEIGHT_3							6

#define BOX_MAP_NEXT						0

#define SAFE_DELETE(p) \
if(p) \
{\
	delete (p); \
	p = nullptr; \
} \

//Flight equation
#define EQUATION_NORMAL		1
#define EQUATION_SIN		2
#define EQUATION_PARAPOL	3
#define CONST_PI			3.14159265359f
#define AMx					25.0f
#define Tms					0.5f
#define LAMDA_Ox			90.0f
#define CURRENT_TIME		5.0f
#define MARGIN_TOP			200.0f

enum eSoundID
{
	USING_WHIP,
	SLASH_WATER,
	SELECT,
	PAUSE,
	OPEN_DOOR,
	HOLY_WATER,
	HOLY_CROSS,
	HIT_CANNON,
	HIT_SOUND,
	FALLING_DOWN_WATER_SUFACE,
	FALLING,
	DECREASE_WEAPON_USE_POINT,
	COLLECT_WEAPON,
	COLLECT_ITEM,
	BOSS_BATTLE_POISON_MIND,
	GAME_OVER,
	GAME_START_PROLOGUE,
	LIFE_LOST,
	STAGE_01_VAMPIRE_KILLER,
	STAGE_04_STALKER,
	STAGE_CLEAR,
	TITLE_THEME_PRELUDE,
	GO_INTO_CASTLE,
	SIMON_HURTED,
	EAT_CHANGE_STATE_BALL,
	MONEY
};

//Map state

#define STATE_MAP_MENU						-2
#define STATE_MAP_INTRO						-1
#define STATE_MAP_START						0
#define STATE_MAP_1							1
#define STATE_MAP_2							2
#define STATE_MAP_3							3

#define BOX_CHANGE_MAP0					0
#define BOX_CHANGE_MAP1					1
#define BOX_CHANGE_MAP2					2
#define BOX_CHANGE_MAP3					3

//Texture
#define ID_TEX_BBOX				-100
#define ID_TEX_MISC				10
#define ID_LEVEL_ONE_BG			20
#define ID_TEX_SIMON			30
#define ID_TEX_WHIP				40
#define ID_TEX_CANDLE			50
#define ID_TEX_DEAD				60
#define ID_TEX_GROUND			70
#define ID_TEX_ZOMBIE			80
#define ID_TEX_PANTHER			90
#define ID_TEX_CANDLE_SMALL		100
#define ID_TEX_KNIFE			110
#define ID_TEX_KNIFE			110
#define ID_TEX_BAT_RED			120
#define ID_TEX_BOSSBAT			130
#define ID_TEX_STAIR_LEFT		140
#define ID_TEX_STAIR_RIGHT		150
#define ID_TEX_BOX_STAIR		160
#define ID_TEX_AXE				170
#define ID_TEX_MERMAN			180
#define ID_TEX_WATER			220
#define ID_TEX_FIREBALL			230
#define ID_TEX_MAPSET			240
#define ID_TEX_BOXMAP			250

#define ID_ITEM_HEART_BIG		61
#define ID_ITEM_MORNING_STAR	62
#define ID_ITEM_MONEY_BLUE		63
#define ID_ITEM_ROSARY			64
#define ID_ITEM_ROSACT			65
#define ID_ITEM_STOPWATCH		66
#define ID_ITEM_DOUBLE_SHOT		67
#define ID_ITEM_BALL			68

//status effect
#define EFFECT_WATER			0


//Status SIMON
#define SM_STAND_STATIC			0
#define SM_MOVE_LEFT			1
#define SM_SIT					2
#define SM_JUMP					3
#define SM_STAND_ATTACK			4
#define SM_SIT_ATTACK			5
#define SM_STAND_UP_STAIR		6
#define SM_STAND_DOWN_STAIR		7
#define SM_MOVE_UP_STAIR		8
#define SM_MOVE_DOWN_STAIR		9
#define SM_ATTACK_UP_STAIR		10
#define SM_ATTACK_DOWN_STAIR	11
#define SM_HURTED				12
#define SM_INVISIBLE			13
#define SM_EAT_ITEM				14
#define SM_FALL_DOWN			15
#define SM_THROW_WEAPON			16
#define SM_DEAD					17
#define SM_STAND_BACK			18
#define SM_FLY_ATTACK			19
#define SM_AUTO_DOOR			20

//Weapons
#define WP_WHIP_STAND_LEFT		19
#define WP_WHIP_SIT_LEFT		20
#define WP_KNIFE_STAND			0
#define WP_KNIFE_SIT			1
#define WP_AXE_STAND			0
#define WP_AXE_FLY				1

//Speed weapons
#define KNIFE_SPEED				0.2f
#define AXE_SPEED_X				0.15f
#define AXE_SPEED_Y				0.6f

//Items

#define I_HEART_BIG				0
#define I_MORNING_STAR			1
#define I_MONEY_BLUE			2
#define I_ROSARY				3
#define I_ROSACT				4
#define I_STOPWATCH				5
#define I_DOUBLE_SHOT			6
#define I_BOSS_BAT				7

//ALL BOX
#define CANDLE_BBOX_WIDTH		32
#define CANDLE_BBOX_HEIGHT		64
#define PROP_BBOX_WIDTH			35
#define PROP_BBOX_HEIGHT		35
#define PROP_BBOX_CHANGE		100
#define GROUND_BBOX_WIDTH		32
#define GROUND_BBOX_HEIGHT		32
#define BRICK_BBOX_WIDTH		760
#define BRICK_BBOX_HEIGHT		32
#define LIMITCAM_BBOX_WIDTH		20
#define LIMITCAM_BBOX_HEIGHT	480
#define LIMIT_GROUND_WIDTH		500
#define LIMIT_GROUND_HEIGHT		32
#define LIMIT_GROUND_H2			400
#define ZOMBIE_BBOX_WIDTH		34
#define ZOMBIE_BBOX_HEIGHT		64
#define ITEM_BBOX_WIDTH			32
#define ITEM_BBOX_HEIGHT		32
#define PANTHER_BBOX_WIDTH		64
#define PANTHER_BBOX_HEIGHT		32
#define CANDLESMALL_BBOX_WIDTH	16
#define CANDLESMALL_BBOX_HEIGHT 16
#define KNIFE_BBOX_WIDTH		32
#define KNIFE_BBOX_HEIGHT		18
#define BAT_RED_BBOX_WIDTH		32
#define BAT_RED_BBOX_HEIGHT		32
#define BOSSBAT_BBOX_WIDTH		100
#define BOSSBAT_BBOX_HEIGHT		46
#define BOX_STAIR_WIDTH			32
#define BOX_STAIR_HEIGHT		32
#define AXE_BBOX_WIDTH			30
#define AXE_BBOX_HEIGHT			28
#define MERMAN_BBOX_HEIGHT		64
#define MERMAN_BBOX_WIGHT		32
#define FIREBALL_BBOX_WIDTH		14
#define FIREBALL_BBOX_HEIGHT	12
#define BOXMAP_BBOX_WIDTH		32
#define BOXMAP_BBOX_HEIGHT		16


//Status candle
#define CANDLE_STATE_NO			100
#define CANDLE_STATE_DIE		200
#define CANDLESMALL_STATE_NO	0
#define CANDLESMALL_STATE_DIE	1

//Ground
#define BRICK					0
#define GROUND					1
#define STAIR_LEFT				2
#define STAIR_RIGHT				3

//Box stair
#define BOX_STAIR_TOP			0
#define BOX_STAIR_BOTTOM		1
#define BOX_LEFT				2
#define BOX_RIGHT				3
#define BOX_CHANGE_MAPNEXT		4

//Transparent object
#define LIMIT_CAMERA			0
#define LIMIT_GROUND			1

//Enemy
#define ZOMBIE_MOVE_LEFT		0
#define ZOMBIE_DIE				1
#define PANTHER_STATIC			0
#define PANTHER_JUMP			1
#define PANTHER_MOVE			2
#define PANTHER_DIE				3
#define BAT_RED_STATIC			0
#define BAT_RED_FLY				1
#define BAT_RED_DIE				2
#define BOSSBAT_STATIC			0
#define BOSSBAT_FLY				1
#define BOSSBAT_DIE				2
#define BOSSBAT_ATTACK			3
#define MERMAN_MOVE				0
#define MERMAN_ATTACK			1
#define MERMAN_JUMP				2
#define MERMAN_DIE				3

//Enemy speed
#define BAT_FLY_SPEED			0.045f
#define BOSSBAT_SPEED_X			0.05f
#define BOSSBAT_SPEED_Y			0.05f

//Distance enemy attack
#define DIS_PANTHER_ATTACK		200.0f
#define DIS_BAT_ATTACK			150.0f
#define DIS_BOSSBAT_ATTACK		-100.0f
