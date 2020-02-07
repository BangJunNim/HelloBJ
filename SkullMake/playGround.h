#pragma once
#include "gameNode.h"
#include "Scene.h"
#include "ImageBox.h"

//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif

class playGround : public gameNode
{
private:
	
	AddImageBox AddImage;

	Scene* SSin;
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};
