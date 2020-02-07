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
	SSin->init();
	return S_OK;
}


void playGround::release()
{
	gameNode::release();
	SSin->release();
}


void playGround::update()
{
	gameNode::update();
	SSin->update();
}

void playGround::render()
{
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==========================================================	
	SSin->render();

	//===========================================================
	_backBuffer->render(getHDC(), 0, 0);
}