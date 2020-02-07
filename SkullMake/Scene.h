#pragma once
#include "gameNode.h"
#include "SceneBox.h"

class Scene
{
private:
	//¾À ÇÔ¼ö ¼ÒÈ¯ ! 
	SceneBox SBox;

public:
	Scene();
	~Scene();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();
};

