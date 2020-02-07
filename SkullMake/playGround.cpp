#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}

playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);
	SSin = new Scene;
	SSin->Init();

	return S_OK;
}


void playGround::release()
{
	gameNode::release();
	SSin->Release();
}


void playGround::update()
{
	gameNode::update();
	SSin->Update();
}

void playGround::render()
{
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==========================================================	
	SSin->Render();


	//===========================================================
	_backBuffer->render(getHDC(), 0, 0);
}