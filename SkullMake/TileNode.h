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
//Ÿ�� �̵� �ϴ� �� 
struct SampleTileBar
{
	RECT GroundTileBar;						//  �켱�� �� Ÿ�� �� ���� .


	void MoveBar()
	{

	}

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
	SampleTileBar		TileBar;			// Ÿ�� �� 
	TileSetKind			Tile;				//���� Ÿ�� 
	TileSetInfo			TileCurrent;		//������Ÿ���� ���� 

	// ���� Ÿ�� �⺻ ���� 
	void Setting()
	{
		TileBar.GroundTileBar = RectMake(WINSIZEX - IMAGEMANAGER->findImage("TutorialTile")->getWidth(),10,
			IMAGEMANAGER->findImage("TutorialTile")->getWidth(), 20);

		//����Ÿ�� ������ ������ ��Ʈ�� �׸���. 
		for (int y = 0; y < FloorTileY; ++y)
		{
			for (int x = 0; x < FloorTileX; ++x)
			{
				//�����Ӱ� �־��ֱ� 
				Tile.Ground_TileSet[x + y * FloorTileX].Frame.x = 0;
				Tile.Ground_TileSet[x + y * FloorTileX].Frame.y = 0;
				// ���� �����ʿ� ���� Ÿ�� �׸��� 
				Tile.Ground_TileSet[x + y * FloorTileX].rc =
					RectMake(TileBar.GroundTileBar.top + x * TILESIZEX, TileBar.GroundTileBar.right + y * TILESIZEY, TILESIZEX, TILESIZEY);
		
				Tile.Ground_TileSet->floortile = Floor_Tile::Stage1;
			}
		}
		// Ŭ���� Ÿ�������� ��� ���� ���� 
		TileCurrent.Frame.x = TileCurrent.Frame.y = 0;
	}
	// Ÿ�� ����/ �·� ���� �ϱ� ���� 
	void TileUpdate()
	{
		//����Ÿ�� ������ ������ ��Ʈ�� �׸���. 
		for (int y = 0; y < FloorTileY; ++y)
		{
			for (int x = 0; x < FloorTileX; ++x)
			{
				// ���� �����ʿ� ���� Ÿ�� �׸��� 
				Tile.Ground_TileSet[x + y * FloorTileX].rc =
					RectMake(TileBar.GroundTileBar.top + x * TILESIZEX, TileBar.GroundTileBar.right + y * TILESIZEY, TILESIZEX, TILESIZEY);
			}
		}
	}
	// Ÿ�� ��� �Լ� 
	void  ShowTile(HDC getMem, MapToolUI Botton)
	{
		//��ư Ÿ�Կ� ���� �ٸ� Ÿ�� ��� 
		switch (Botton)
		{
		case MapToolUI::Ground:
			Rectangle(getMem, TileBar.GroundTileBar);

			break;
		}
	}

	void TileInfoSave(MapToolUI Botton)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			switch (Botton)
			{
			case MapToolUI::Ground:
				for (int i = 0; i < FloorTileX * FloorTileY; ++i)
				{
					// ���콺 �����Ͱ� �� Ÿ�� ���ÿ� ���� ��Ʈ �Ǿ��� �� ; 
					if (PtInRect(&Tile.Ground_TileSet[i].rc, _ptMouse))
					{
						TileCurrent.Frame.x = Tile.Ground_TileSet[i].Frame.x;
						TileCurrent.Frame.y = Tile.Ground_TileSet[i].Frame.y;
						TileCurrent.TypeReSet(); // Ÿ�� ���� �ϱ� ���� ���� ������ ����

						TileCurrent.floortile = Floor_Tile::Stage1; 
					}
				}
				break;
			}
			KEYMANAGER->setKeyDown(VK_LBUTTON, false); // ���콺 Ŭ�� ��ġ�� �ʰ� �ϱ� ���� �� 
		}
	}
};
// ��ư ���� 
struct UiButtonInfo
{
	// ���� UI ��ư  
	RECT SaveButton;
	RECT LoadButton;
	RECT EraserButton;
	
	// Ÿ�� ���� ��ư 
	RECT GroundButton;

	////��ư Ÿ�� 
	//enum class MapToolUI
	//{
	//	None, Save, Load, Ground, Eraser
	//};

	MapToolUI MapUi;

	// ��ư �������� üũ
	bool bMapUi; 

	//�� �� ȣ ��
	void Reset()
	{
		bMapUi = false;

		MapUi = MapToolUI::None;

		SaveButton = RectMake(0, 0, 52, 52);
		LoadButton = RectMake(62, 0, 52, 52);
		GroundButton = RectMake(0, 52, 52, 52);
	}
	
	void ButtonImage(HDC getDC)
	{
		// ���� ���� �� �ʿ��� ��Ʈ ��¿� 
		if (KEYMANAGER->isToggleKey(VK_NUMPAD9))
		{
			Rectangle(getDC, SaveButton);
			Rectangle(getDC, LoadButton);
			Rectangle(getDC, GroundButton);

		}
		// ��ư �̹��� ���� �ϴ°�
		IMAGEMANAGER->findImage("Save")->render(getDC, SaveButton.left, SaveButton.top);
		IMAGEMANAGER->findImage("Load")->render(getDC, SaveButton.left, SaveButton.top);
		IMAGEMANAGER->findImage("Ground")->render(getDC, SaveButton.left, SaveButton.top);
	}
	// ��ư Ŭ������ ��
	void ClickButton()
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&SaveButton, _ptMouse)) MapUi = MapToolUI::Save;
			if (PtInRect(&SaveButton, _ptMouse)) MapUi = MapToolUI::Load;
			if (PtInRect(&SaveButton, _ptMouse)) MapUi = MapToolUI::Ground;

			KEYMANAGER->setKeyDown(VK_LBUTTON, false);
		}
	}
};
// �� ��Ŭ���� 
class MapClass
{
public:

	//�׸��� Ÿ�� ����� 
	void BaseTileList(vector<TileSave*>* TileList)
	{
		for (int y = 0; y < TileY; ++y)
		{
			for (int x = 0; x < TileX; ++x)
			{
				TileSave* NewTile = new TileSave;
				NewTile->ResetTile();
				NewTile->Index.x = x;
				NewTile->Index.y = y;
				NewTile->rc = RectMake(NewTile->Index.x * TILESIZEX, NewTile->Index.y * TILESIZEY, TILESIZEX, TILESIZEY);
				NewTile->Center.x = (NewTile->rc.left + NewTile->rc.right) / 2.f;
				NewTile->Center.y = (NewTile->rc.top + NewTile->rc.bottom) / 2.f;

				(*TileList).push_back(NewTile);
			}
		}
	}

	// ī�޶�ȿ� �ִ� Ÿ�� ã�Ƽ� ���� 
	void CameraTileSave()
	{
		CAMERAMANAGER->CameraFunc()->FINDTile(CAMERAMANAGER->CameraFunc()->GetCameraOperation().TileCountX, CAMERAMANAGER->CameraFunc()->GetCameraOperation().TileCountY);
	}



private:

};