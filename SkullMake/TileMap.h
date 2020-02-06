#pragma once
#include "gameNode.h"
#include "TileNode.h"

class TileMap : public gameNode
{
private:
	RECT RC;
	TileInfo Tiles[TileX * TileY];     // �׸��� �� Ÿ�� ����
	DWORD	 Attribute[TileX * TileY]; // Ÿ���� ����

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

