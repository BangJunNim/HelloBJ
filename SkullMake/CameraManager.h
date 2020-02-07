#pragma once
#include "singletonBase.h" 
#include "CameraBox.h"

class CameraManager : public singletonBase<CameraManager>
{
private:
	CameraInfo* Camera;

public:
	CameraManager();
	~CameraManager();

	HRESULT init();
	void release();
	void update();
	void render();

	CameraInfo* CameraFunc() { return Camera; }
};

