#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>

using namespace std;
// TileNode - stdafx - CameraBox

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "utils.h"
#include "imageManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "txtData.h"
#include "soundManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"

using namespace SEVENTEEN_UTIL;

//=========================================
// ## 19.10.30 ## - 디파인문 -
//=========================================

#define WINNAME (LPCTSTR)(TEXT("SevenTeen Class"))
#define WINSTARTX 50
#define WINSTARTY 50
#define WINSIZEX 1600
#define WINSIZEY 900
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()


#define SAFE_DELETE(p) {if(p) {delete(p); (p)=NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

//==========================================
// ## 19.10.31 ## Extern
//==========================================
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;
extern BOOL			_leftButtonDown;

//#include "TileNode.h"
//#include "CameraBox.h"

// 카메라 좌표 
typedef struct
{
	unsigned short x;
	unsigned short y;
} UCAMERA;

// 카메라 연산 
typedef struct
{
	unsigned int TileCountX;
	unsigned int TileCountY;
} UCOUNT;


// 타일 사이즈 
#define TILESIZEX 64
#define TILESIZEY 64
// 타일 갯수 
#define TileX 60
#define TileY 60
// 타일을 그릴 화면 사이즈  1440 * 1440
#define WinTileSizeX TILESIZE * TileX
#define WInTileSizeY TILESIZE * TileY
// 바닥 타일 범위  
#define FloorTileX 9
#define FloorTileY 5
// 성 바닥 타일 범위
#define CastieTileX 8
#define CastieTileY 2


