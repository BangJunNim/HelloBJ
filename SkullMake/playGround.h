#pragma once
#include "gameNode.h"
#include "TileMap.h"
#include "Scene.h"

//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif

class playGround : public gameNode
{
private:
	
	TileMap* TMap;
	Scene* SSin;
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};
