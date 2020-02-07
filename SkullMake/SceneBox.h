#pragma once
#include "stdafx.h"
#include "TileMap.h"

class SceneBox
{
public:
	// 씬 추가  해주는 함수 addScene(string sceneName, gameNode * scene)
	void AddScene()
	{
		SCENEMANAGER->addScene("TileMap", new TileMap);
	}

	void ChangeScene(string sceneName)
	{
		SCENEMANAGER->changeScene(sceneName);
	}

	void TestSceneChange()
	{
		if (KEYMANAGER->isOnceKeyDown(VK_F1))
		{
			SCENEMANAGER->changeScene("TileMap");
		}
	}
};