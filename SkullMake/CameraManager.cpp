#include "stdafx.h"
#include "CameraManager.h"


CameraManager::CameraManager()
{
}


CameraManager::~CameraManager()
{
}

HRESULT CameraManager::init()
{
	Camera = new CameraInfo;
	Camera->BaseSetting();
	return S_OK;
}

void CameraManager::release()
{
}

void CameraManager::update()
{
}

void CameraManager::render()
{
}
