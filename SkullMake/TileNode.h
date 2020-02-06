#pragma once
//타일 기본 정의 h

// 타일 사이즈 
#define TILESIZE 64
// 타일 갯수 
#define TileX 60
#define TileY 60
// 타일을 그릴 화면 사이즈  1440 * 1440
#define TileSizeX TILESIZE * TileX
#define TileSizeY TILESIZE * TileY
// 바닥 타일 범위  
#define FloorTileX 9
#define FloorTileY 5
// 성 바닥 타일 범위
#define CastieTileX 8
#define CastieTileY 2


// 타일의 종류 c
enum class Tile_Type
{
	//	공백 ,   바닥 ,  데코타일  , 부서지는타일, 플레이어   , 적		  ,함정 타일 , 문,		아이템 
	Empty, FloorTile, ObjectTile, BrokenTile, PlayerTile, EnemyTile, TrapTile, DoorTile, ItemTile
};

// 바닥 타일 상세 
enum class Floor_Tile
{
	Empty, DevilCastle, Stage1, Stage2, Stage3
};
// 오브젝트 
enum class Object_Tile
{
	//벽,천장,기둥,난간,깃발,왕좌, 칼레온성문
	Empty, Wall, BrokenWall, Ceiling, BrokenCeiling, Pillar, BrokenPillar, Handrail, BrokenHandrail, Flag, BrokenFlag, Throne, BrokenThrone, Tree, Grass, CastieGate
};
// 부서지는 타일
enum class BrokenTile
{
	// 타워 , 깃발 , 텐트
	Empty, Towar, BrokenTowar, Flag, BrokenFlag, Tent, BrokenTent
};

enum class EnemyTile
{
	// 기사, 궁사, 망치, 일반 나무, 진한나무, 장로나무, 미니보스(도적)
	Empty, Soldier, Archer, Hammer, Tree, Tree2, ElderTree, MiniBoss
};

enum class PlayerTile
{
	// 플레이어 스타트 지점 
	Empty, StarPoint
};

enum class TrapTile
{
	// 가시덩쿨
	Empty, Bush
};

enum class DoorTile
{
	// 상점 , 보물, 다음스테이지, 보스 , 마지막 보스 
	Empty, Shop, Treasure, NextStage, Boss, FinalBoss
};

enum class ItemTile
{
	// 동전, 회복구슬, 정수, 스컬 뚝배기 
	Empty, Coin, HpBead, AbilityBead, Skull
};


typedef struct 
{
	Tile_Type	TileList;					// 모든 타일 리스트 / 목록  같은 존재
	Floor_Tile	FloorTileList;				// 바닥
	Object_Tile ObjTileList;				// 오브젝트
	BrokenTile	BrokenTileList;				// 파괴가능한
	EnemyTile	EnemyTileList;				// 적
	PlayerTile	PlayerTileList;				// 주인공 
	TrapTile	TrapTileList;				// 함정
	DoorTile	DoorTileList;				// 문 / 다음 스테이지 
	ItemTile	ItemTileList;				// 아이템 
	RECT		rc;
	int IndexX, IndexY;
} TileInfo;

typedef struct 
{
	RECT rcTile;
	int FloorFrameX, FloorFrameY;
} SampleFloorTile;
