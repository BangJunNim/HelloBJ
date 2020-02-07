#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

HRESULT Scene::init()
{
	SBox.AddScene();
	SBox.ChangeScene("TileMap");
	return S_OK;
}

void Scene::release()
{
	SCENEMANAGER->release();
}

void Scene::update()
{
	SCENEMANAGER->update();
}

void Scene::render()
{
	SCENEMANAGER->render();
}
