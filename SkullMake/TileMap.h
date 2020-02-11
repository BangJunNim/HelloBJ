#pragma once
#include "gameNode.h"
#include "TileNode.h"

class TileMap : public gameNode
{
private:
	RECT RC;
	//TileInfo Tiles[TileX * TileY];     // �׸��� �� Ÿ�� ����
	DWORD	 Attribute[TileX * TileY]; // Ÿ���� ����

	int pos[2];



public:
	TileMap();
	~TileMap();

	HRESULT init();
	void release();
	void update();
	void render();

	void Load();

	DWORD * GetAttribute() { return Attribute; }
	
	int GetPosFirst() { return pos[0]; }
	int GetPosSecond() { return pos[1]; }
};

