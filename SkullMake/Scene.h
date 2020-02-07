#pragma once
#include "gameNode.h"
#include "SceneBox.h"

class Scene:public gameNode
{
private:
	//¾À ÇÔ¼ö ¼ÒÈ¯ ! 
	SceneBox SBox;

public:
	Scene();
	~Scene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

