#pragma once
//Ÿ�� �⺻ ���� h



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
	//��,õ��,���,����,���,����, 
	Empty, Wall, BrokenWall, Ceiling, BrokenCeiling, Pillar, BrokenPillar, Handrail, BrokenHandrail, Flag, BrokenFlag, Throne, BrokenThrone, Tree, Grass, 
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

//  ��� �̹��� ī��Ʈ
enum class BackGroundCount
{
	Empty, One, two, three
};

enum class MapToolUI
{
	None, Save, Load, Ground, Eraser
};



//Ÿ�� �ȷ�Ʈ �̵��� ���� ���߿�  �� �� �� �� �Ҽ��� ����. 

// �� Ÿ��( ���� ) ������ ��´� . 
// �̷��� ���� �ڵ� �׳� �ű�� �ȵǴ°ž�..���ݤ�...,.,�ФФФФФФФФФ�
// �ٵ� �� UCAMERA�� ���� ���⼭ ���� ������ �ִ°ž�? 
// ������ �� ����ε� �� ���� �ΰ� ¥�� ���°ǵ� ����... ��.... �ٵ� ��� ��ü
struct TileSetInfo
{
	RECT rc;
	UCAMERA Frame;  // CameraBox  ī�޶��� x ,y ��ǥ 
	Floor_Tile floortile;  // �� Ÿ�� 

	// Ÿ�� �ʱ�ȭ �� �� ��� �Ϸ��� ����
	void TypeReSet()
	{
		floortile = Floor_Tile::Empty;
	}
};

// Ÿ��(����) ��� 
struct TileSetKind
{
	TileSetInfo Ground_TileSet[FloorTileX * FloorTileY];
	//TileSetInfo 
	// ���� ���⿡ ������Ʈ / ������ / �ı� ������Ʈ / ��� ����� ��. 

};
// ������ ����ü�� �̷��� ���� �������� ���̰� ������...�ФФФ�
// ���ɵŸ�.. ����� ���� ���ۿ� ���� �� ���� �ѹ� ã�ƺ��Կ� ..
// Ÿ�� ������ �̹����� ���� ����ü�� 
struct TileFrameImage
{
	UCAMERA  GroundFrameImage;  // ���� �̹��� ������ 
};


// Ÿ�� ������ ���� �� ����ü 
struct TileSave
{
	POINTFLOAT		Center;		// Ÿ���� ������ ��´�.
	RECT			rc;			// Ÿ�� ��Ʈ 
	UCAMERA			Index;		// Ÿ���� �ε����� ��´� . 

	Tile_Type		Tiletype;	// ��� Ÿ����  Ÿ�� ! ! ! 
	Floor_Tile		Floortype;	// �ٴ� Ÿ�� ! ! ! 

	TileFrameImage	Frame;		// �̹��� ������ 
	
	// Ÿ�� �ʱ�ȭ 
	void ResetTile()
	{
		Center.x = Center.y = 0;
		
		Frame.GroundFrameImage.x = Frame.GroundFrameImage.y = 0;
		Tiletype = Tile_Type::Empty;
		Floortype = Floor_Tile::Empty;
		
	}

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
