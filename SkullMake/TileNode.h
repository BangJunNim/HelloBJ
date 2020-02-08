#pragma once
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
enum BackGroundCount
{
	Empty, One, two, three
};
// ���� UI ��ư 
enum class MapToolUI
{
	None, Save, Load, Ground, Eraser
};

// ��׶��� ��� �̹��� ī��Ʈ 
enum class BackGroundImageCount
{
	NONE,ONE,TWO,THREE 
};

//Ÿ�� �ȷ�Ʈ �̵��� ���� ���߿� �� �� �� �� �Ҽ��� ����. 



// �� Ÿ��( ���� ) ������ ��´� . 
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

// Ÿ��(����) ��� , �ȿ�Ʈ ������ 
struct TileSetKind
{
	TileSetInfo Ground_TileSet[FloorTileX * FloorTileY];
	//TileSetInfo 
	// ���� ���⿡ ������Ʈ / ������ / �ı� ������Ʈ / ��� ����� ��. 

};

// ���������� ���� ����ü (���) ���� ��ȣ���� ���� �ڿ� �򸮴� ��� 
struct LoopRenderVariable
{
	short LoopImage0;
	short LoopImage1;
	short LoopImage2;

	void ResetLoopImage()
	{
		LoopImage0 = LoopImage1 = LoopImage2 = 0;
	}
};

// �� ���� ���⼭ ���� Ÿ���� ���� ������ �ϰ� Ű�� �ҷ���  �� ����� �� �ְ� . 
struct Mapmanger
{
	//ī�޶� 
	string MapName;
	UCAMERA	 TileSize;
	UCAMERA  TileCount;

	POINTFLOAT Center;
	RECT rc;;


	// ��� ���� 
	char BackGroundCount; 
	string BackImage;
	string MiddleImage;
	string FrontImage;

	LoopRenderVariable* Loop;
	
	// �� �Ŵ��� �ʱ�ȭ 
	void MapManagerReSet()
	{
		MapName = {};
		TileSize.x = TileSize.y = 0;
		TileCount.x = TileCount.y = 0;

		Center.x = Center.y = 0;
		rc.left = rc.top = rc.right = rc.bottom = 0;

		BackGroundCount = 0;
		BackImage = {};
		MiddleImage = {};
		FrontImage = {};
		Loop = new LoopRenderVariable;
		Loop->ResetLoopImage();
	}
	// �ǵ� / �߰� / �Ǿ� �̹��� �߰� 
	void AddBackGroundImage(string MapName)
	{
		// ���� �̻��� �� ������������ ���� 
		if (BackGroundCount == 4) return;
		BackGroundCount++;

		if (BackGroundCount == 1)
		{
			BackImage = MapName;
		}

		if (BackGroundCount == 2)
		{
			MiddleImage = MapName;
		}
		if (BackGroundCount == 3)
		{
			FrontImage == MapName;
		}
	}
	// ��� �� ��ü �ϱ� ����.  ��ġ�� ��ü �Ϸ��� �� �̸� 
	void ChangeBackGround(string MapName, signed short Num)
	{
		if (Num > 0 && Num <= 3)
		{
			switch (Num)
			{
			case(One):
				BackImage = MapName;
			break;
				
			case(two):
				MiddleImage = MapName;
			break;
			
			case(three):
				FrontImage = MapName;
			break;
			}
		}
	}
};

// Ÿ�� ����� �� ������ �̹��� ����ؼ� �����
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
		Index.x = Index.y = 0;
		Frame.GroundFrameImage.x = Frame.GroundFrameImage.y = 0;
		Tiletype = Tile_Type::Empty;
		Floortype = Floor_Tile::Empty;
	}
};

// ��� Ÿ���� ���� �̰��� ������.  ���⼭ ���� �ٽ� �غ��� 
struct TileBox
{
	TileSetKind			Tile;				//���� Ÿ�� 
	TileSetInfo			TileCurrent;		//������Ÿ���� ���� 

	// 
	void Setting()
	{

	}
};