#pragma once
#include "gameNode.h"
#include "TileNode.h"

class TileMap : public gameNode
{
private:
	RECT RC;
	TileInfo Tiles[TileX * TileY];     // 그리는 곳 타일 설정
	DWORD	 Attribute[TileX * TileY]; // 타일의 속정

	int pos[2];



public:
	TileMap();
	~TileMap();

	HRESULT init();
	void Release();
	void Update();
	void Render();

	void Load();

	DWORD * GetAttribute() { return Attribute; }
	
	int GetPosFirst() { return pos[0]; }
	int GetPosSecond() { return pos[1]; }
};

