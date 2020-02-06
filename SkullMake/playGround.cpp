#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}

playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);

	TMap = new TileMap;
	TMap->init();

	/*bg[0] = IMAGEMANAGER->addImage("tutorial_BG_0", "./image/tutorial/backGround/tutorial_BG_0.bmp", 2160, 1800, false, RGB(0, 0, 0));
	bg[1] = IMAGEMANAGER->addImage("tutorial_BG_1", "./image/tutorial/backGround/tutorial_BG_1.bmp", 2160, 1800, true, RGB(255, 0, 255));
	bg[2] = IMAGEMANAGER->addImage("tutorial_BG_2", "./image/tutorial/backGround/tutorial_BG_2.bmp", 2160, 1800, true, RGB(255, 0, 255));
	bg[0] = new image;
	bg[0] = IMAGEMANAGER->findImage("tutorial_BG_0");
	bg[1] = new image;
	bg[1] = IMAGEMANAGER->findImage("tutorial_BG_1");
	bg[2] = new image;
	bg[2] = IMAGEMANAGER->findImage("tutorial_BG_2");

	_worImg = new image;
	_worImg = IMAGEMANAGER->addImage("worldMap", 2160, 1800);
	_worDC = _worImg->getMemDC();

	_player.center.x = WINSIZEX / 2;
	_player.center.y = WINSIZEY / 2;

	_player.rc = RectMake(_player.center.x - 25, _player.center.y - 25, 50, 50);

	cameraX = cameraY = 0;

	worSizeX = worSizeY = 0;

	worSizeX = 2160;
	worSizeY = 1800;*/

	return S_OK;
}


void playGround::release()
{
	gameNode::release();
}


void playGround::update()
{
	gameNode::update();

	//if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	//{
	//	_player.center.x -= 10;
	//}
	//
	//if (KEYMANAGER->isStayKeyDown(VK_UP))
	//{
	//	_player.center.y -= 10;
	//}
	//
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	//{
	//	_player.center.x += 10;
	//}
	//
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	//{
	//	_player.center.y += 10;
	//}
	//
	//_player.rc = RectMakeCenter(_player.center.x, _player.center.y, 50, 50);
	//
	//cameraX = _player.center.x - WINSIZEX / 2;
	//cameraY = _player.center.y - WINSIZEY / 2;
	//
	//if (cameraX < 0) cameraX = 0;
	//if (cameraY < 0) cameraY = 0;
	//if (cameraX + WINSIZEX > worSizeX) cameraX = worSizeX - WINSIZEX;
	//if (cameraY + WINSIZEY > worSizeY) cameraY = worSizeY - WINSIZEY;
}

void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==========================================================	
	
	TMap->Render();

	//for (int i = 0; i < 3; ++i)
	//{
	//	bg[i]->render(_worDC, 0, 0);
	//}
	//Rectangle(_worDC, _player.rc);
	//
	//_worImg->render(getMemDC(), 0, 0, cameraX, cameraY, WINSIZEX, WINSIZEY);



	//===========================================================
	_backBuffer->render(getHDC(), 0, 0);
}