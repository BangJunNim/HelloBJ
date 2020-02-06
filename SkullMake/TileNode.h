#pragma once
//Ÿ�� �⺻ ���� h

// Ÿ�� ������ 
#define TILESIZE 64
// Ÿ�� ���� 
#define TileX 60
#define TileY 60
// Ÿ���� �׸� ȭ�� ������  1440 * 1440
#define TileSizeX TILESIZE * TileX
#define TileSizeY TILESIZE * TileY
// �ٴ� Ÿ�� ����  
#define FloorTileX 9
#define FloorTileY 5
// �� �ٴ� Ÿ�� ����
#define CastieTileX 8
#define CastieTileY 2


// Ÿ���� ���� c
enum class Tile_Type
{
	//	���� ,   �ٴ� ,  ����Ÿ��  , �μ�����Ÿ��, �÷��̾�   , ��		  ,���� Ÿ�� , ��,		������ 
	Empty, FloorTile, ObjectTile, BrokenTile, PlayerTile, EnemyTile, TrapTile, DoorTile, ItemTile
};

// �ٴ� Ÿ�� �� 
enum class Floor_Tile
{
	Empty, DevilCastle, Stage1, Stage2, Stage3
};
// ������Ʈ 
enum class Object_Tile
{
	//��,õ��,���,����,���,����, Į���¼���
	Empty, Wall, BrokenWall, Ceiling, BrokenCeiling, Pillar, BrokenPillar, Handrail, BrokenHandrail, Flag, BrokenFlag, Throne, BrokenThrone, Tree, Grass, CastieGate
};
// �μ����� Ÿ��
enum class BrokenTile
{
	// Ÿ�� , ��� , ��Ʈ
	Empty, Towar, BrokenTowar, Flag, BrokenFlag, Tent, BrokenTent
};

enum class EnemyTile
{
	// ���, �û�, ��ġ, �Ϲ� ����, ���ѳ���, ��γ���, �̴Ϻ���(����)
	Empty, Soldier, Archer, Hammer, Tree, Tree2, ElderTree, MiniBoss
};

enum class PlayerTile
{
	// �÷��̾� ��ŸƮ ���� 
	Empty, StarPoint
};

enum class TrapTile
{
	// ���õ���
	Empty, Bush
};

enum class DoorTile
{
	// ���� , ����, ������������, ���� , ������ ���� 
	Empty, Shop, Treasure, NextStage, Boss, FinalBoss
};

enum class ItemTile
{
	// ����, ȸ������, ����, ���� �ҹ�� 
	Empty, Coin, HpBead, AbilityBead, Skull
};


typedef struct 
{
	Tile_Type	TileList;					// ��� Ÿ�� ����Ʈ / ���  ���� ����
	Floor_Tile	FloorTileList;				// �ٴ�
	Object_Tile ObjTileList;				// ������Ʈ
	BrokenTile	BrokenTileList;				// �ı�������
	EnemyTile	EnemyTileList;				// ��
	PlayerTile	PlayerTileList;				// ���ΰ� 
	TrapTile	TrapTileList;				// ����
	DoorTile	DoorTileList;				// �� / ���� �������� 
	ItemTile	ItemTileList;				// ������ 
	RECT		rc;
	int IndexX, IndexY;
} TileInfo;

typedef struct 
{
	RECT rcTile;
	int FloorFrameX, FloorFrameY;
} SampleFloorTile;
