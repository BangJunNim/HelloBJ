#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

HRESULT Scene::Init()
{
	SBox.AddScene();
	SBox.ChangeScene("TileMap");
	return S_OK;
}

void Scene::Release()
{
}

void Scene::Update()
{
	SCENEMANAGER->update();
}

void Scene::Render()
{
	SCENEMANAGER->render();
}
