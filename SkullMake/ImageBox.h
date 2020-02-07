#pragma once
#include "stdafx.h"

//여기서 모든 이미지를 관리할 예정

struct AddImageBox
{
	void ImageSave()
	{
		// BackGround Image 
		IMAGEMANAGER->addImage("Tutorial0", " ./image/Stage/backGround/Tutorial0.bmp", 2160, 1800, false, RGB(0, 0, 0));
		IMAGEMANAGER->addImage("Tutorial1", " ./image/Stage/backGround/Tutorial1.bmp", 2160, 1800, false, RGB(0, 0, 0));
		IMAGEMANAGER->addImage("Tutoria12", " ./image/Stage/backGround/Tutorial2.bmp", 2160, 1800, false, RGB(0, 0, 0));

		// Tile Image
		IMAGEMANAGER->addFrameImage("TutorialTile", "./image/Tile/Tutorial_Tile.bmp", 576, 256, 9, 4, true, RGB(255, 0, 255));
			
		// MapTool Icon
		IMAGEMANAGER->addImage("Save", "./image/Icon/Save.bmp", 52, 52, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("Load", "./image/Icon/Load.bmp", 52, 52, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("Ground", "./image/Icon/Ground.bmp", 52, 52, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("DleratGround", "./image/Icon/DleratGround.bmp", 52, 52, true, RGB(255, 0, 255));

	}





};