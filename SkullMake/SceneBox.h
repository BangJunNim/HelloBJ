#pragma once
#include "stdafx.h"
#include "TileMap.h"

class SceneBox
{
public:
	// �� �߰�  ���ִ� �Լ� addScene(string sceneName, gameNode * scene)
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