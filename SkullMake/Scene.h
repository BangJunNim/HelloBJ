#pragma once
#include "gameNode.h"
#include "SceneBox.h"

class Scene
{
private:
	//�� �Լ� ��ȯ ! 
	SceneBox SBox;

public:
	Scene();
	~Scene();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();
};

