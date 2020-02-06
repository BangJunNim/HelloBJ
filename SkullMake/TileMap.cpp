#include "stdafx.h"
#include "TileMap.h"


TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

HRESULT TileMap::init()
{
	//렉트로 그릴곳 초기화  // 속성 값 초기화 
	for (int Y = 0; Y < TileY; Y++)
	{
		for (int X = 0; X < TileX; X++)
		{
			Tiles[X + Y * TileX].IndexX = X; 
			Tiles[X + Y * TileY].IndexY = Y;
			Tiles[X + Y * TileX].rc = RectMake(X * TileX ,Y * TileY, 64, 64);
			Tiles[X + Y * TileX].BrokenTileList = BrokenTile::Empty;  
			Tiles[X + Y * TileX].DoorTileList = DoorTile::Empty;
			Tiles[X + Y * TileX].EnemyTileList = EnemyTile::Empty;
			Tiles[X + Y * TileX].TrapTileList = TrapTile::Empty;
			Tiles[X + Y * TileX].PlayerTileList = PlayerTile::Empty;
			Tiles[X + Y * TileX].ItemTileList = ItemTile::Empty;
			Tiles[X + Y * TileX].TileList = Tile_Type::Empty;
			Tiles[X + Y * TileX].FloorTileList = Floor_Tile::Empty;
			Tiles[X + Y * TileX].ObjTileList = Object_Tile::Empty;
		}
	}

	return S_OK;
}

void TileMap::Release()
{
}

void TileMap::Update()
{
}

void TileMap::Render()
{
	//렉트를 그려보자 
	for (int i = 0; i < TileX * TileY; ++i)
	{
		Rectangle(getMemDC(), Tiles[i].rc);
	}
}

void TileMap::Load()
{
}
