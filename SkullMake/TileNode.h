#pragma once
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
	//벽,천장,기둥,난간,깃발,왕좌, 
	Empty, Wall, BrokenWall, Ceiling, BrokenCeiling, Pillar, BrokenPillar, Handrail, BrokenHandrail, Flag, BrokenFlag, Throne, BrokenThrone, Tree, Grass, 
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

//  배경 이미지 카운트
enum BackGroundCount
{
	Empty, One, two, three
};
// 맵툴 UI 버튼 
enum class MapToolUI
{
	None, Save, Load, Ground, Eraser
};
//타일 이동 하는 바 
struct SampleTileBar
{
	RECT GroundTileBar;						//  우선은 땅 타일 만 먼저 .


	void MoveBar()
	{

	}

};

// 백그라운드 배경 이미지 카운트 
enum class BackGroundImageCount
{
	NONE,ONE,TWO,THREE 
};

//타일 팔렛트 이동은 추후 나중에 할 수 도 안 할수도 있음. 



// 각 타일( 샘플 ) 정보를 담는다 . 
struct TileSetInfo
{
	RECT rc;
	UCAMERA Frame;  // CameraBox  카메라의 x ,y 좌표 
	Floor_Tile floortile;  // 땅 타일 

	// 타일 초기화 할 때 사용 하려고 만듬
	void TypeReSet()
	{
		floortile = Floor_Tile::Empty;
	}
};

// 타일(샘플) 목록 , 팔에트 사이즈 
struct TileSetKind
{
	TileSetInfo Ground_TileSet[FloorTileX * FloorTileY];
	//TileSetInfo 
	// 추후 여기에 오브젝트 / 아이템 / 파괴 오브젝트 / 등등 만들면 됨. 

};

// 루프랜더용 변수 구조체 (배경) 빠른 번호부터 제일 뒤에 깔리는 배경 
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

// 맵 인포 여기서 배경과 타일을 같이 설정을 하고 키로 불렀을  때 사용할 수 있게 . 
struct Mapmanger
{
	//카메라 
	string MapName;
	UCAMERA	 TileSize;
	UCAMERA  TileCount;

	POINTFLOAT Center;
	RECT rc;;


	// 배경 관련 
	char BackGroundCount; 
	string BackImage;
	string MiddleImage;
	string FrontImage;

	LoopRenderVariable* Loop;
	
	// 맵 매니저 초기화 
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
	// 맨뒤 / 중간 / 맨앞 이미지 추가 
	void AddBackGroundImage(string MapName)
	{
		// 값이 이상할 때 빠져나가도록 설정 
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
	// 배경 맵 교체 하기 위한.  위치와 교체 하려는 맵 이름 
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

// 타일 등록할 때 프레임 이미지 써야해서 등롬함
struct TileFrameImage
{
	UCAMERA  GroundFrameImage;  // 지형 이미지 프레임 
};
// 타일 정보를 저장 할 구조체 
struct TileSave
{
	POINTFLOAT		Center;		// 타일의 중점을 담는다.
	RECT			rc;			// 타일 렉트 
	UCAMERA			Index;		// 타일의 인덱스를 담는다 . 

	Tile_Type		Tiletype;	// 모든 타일의  타입 ! ! ! 
	Floor_Tile		Floortype;	// 바닥 타일 ! ! ! 

	TileFrameImage	Frame;		// 이미지 프레임 
	
	// 타일 초기화
	void ResetTile()
	{
		Center.x = Center.y = 0;
		Index.x = Index.y = 0;
		Frame.GroundFrameImage.x = Frame.GroundFrameImage.y = 0;
		Tiletype = Tile_Type::Empty;
		Floortype = Floor_Tile::Empty;
	}
};

// 모든 타일의 샘플 이곳에 잠들었다.  여기서 부터 다시 해보자 
struct TileBox
{
	SampleTileBar		TileBar;			// 타일 바 
	TileSetKind			Tile;				//샘플 타일 
	TileSetInfo			TileCurrent;		//선택한타일의 정보 

	// 샘플 타일 기본 셋팅 
	void Setting()
	{
		TileBar.GroundTileBar = RectMake(WINSIZEX - IMAGEMANAGER->findImage("TutorialTile")->getWidth(),10,
			IMAGEMANAGER->findImage("TutorialTile")->getWidth(), 20);

		//샘플타일 오른쪽 옆으로 렉트를 그린다. 
		for (int y = 0; y < FloorTileY; ++y)
		{
			for (int x = 0; x < FloorTileX; ++x)
			{
				//프레임값 넣어주기 
				Tile.Ground_TileSet[x + y * FloorTileX].Frame.x = 0;
				Tile.Ground_TileSet[x + y * FloorTileX].Frame.y = 0;
				// 바의 오른쪽에 샘플 타일 그리기 
				Tile.Ground_TileSet[x + y * FloorTileX].rc =
					RectMake(TileBar.GroundTileBar.top + x * TILESIZEX, TileBar.GroundTileBar.right + y * TILESIZEY, TILESIZEX, TILESIZEY);
		
				Tile.Ground_TileSet->floortile = Floor_Tile::Stage1;
			}
		}
		// 클릭한 타일정보를 담는 변수 비우기 
		TileCurrent.Frame.x = TileCurrent.Frame.y = 0;
	}
	// 타일 갱신/ 좌료 갱실 하기 위햇 
	void TileUpdate()
	{
		//샘플타일 오른쪽 옆으로 렉트를 그린다. 
		for (int y = 0; y < FloorTileY; ++y)
		{
			for (int x = 0; x < FloorTileX; ++x)
			{
				// 바의 오른쪽에 샘플 타일 그리기 
				Tile.Ground_TileSet[x + y * FloorTileX].rc =
					RectMake(TileBar.GroundTileBar.top + x * TILESIZEX, TileBar.GroundTileBar.right + y * TILESIZEY, TILESIZEX, TILESIZEY);
			}
		}
	}
	// 타일 출력 함수 
	void  ShowTile(HDC getMem, MapToolUI Botton)
	{
		//버튼 타입에 따라 다른 타일 출력 
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
					// 마우스 포인터가 땅 타일 샘플에 핏인 렉트 되었을 때 ; 
					if (PtInRect(&Tile.Ground_TileSet[i].rc, _ptMouse))
					{
						TileCurrent.Frame.x = Tile.Ground_TileSet[i].Frame.x;
						TileCurrent.Frame.y = Tile.Ground_TileSet[i].Frame.y;
						TileCurrent.TypeReSet(); // 타입 저장 하기 전에 이전 정보를 삭제

						TileCurrent.floortile = Floor_Tile::Stage1; 
					}
				}
				break;
			}
			KEYMANAGER->setKeyDown(VK_LBUTTON, false); // 마우스 클릭 겹치지 않게 하기 위해 서 
		}
	}
};
// 버튼 관리 
struct UiButtonInfo
{
	// 맵툴 UI 버튼  
	RECT SaveButton;
	RECT LoadButton;
	RECT EraserButton;
	
	// 타일 종류 버튼 
	RECT GroundButton;

	////버튼 타입 
	//enum class MapToolUI
	//{
	//	None, Save, Load, Ground, Eraser
	//};

	MapToolUI MapUi;

	// 버튼 눌렀는지 체크
	bool bMapUi; 

	//초 기 호 ㅏ
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
		// 영상 찍을 때 필요한 렉트 출력용 
		if (KEYMANAGER->isToggleKey(VK_NUMPAD9))
		{
			Rectangle(getDC, SaveButton);
			Rectangle(getDC, LoadButton);
			Rectangle(getDC, GroundButton);

		}
		// 버튼 이미지 관리 하는곳
		IMAGEMANAGER->findImage("Save")->render(getDC, SaveButton.left, SaveButton.top);
		IMAGEMANAGER->findImage("Load")->render(getDC, SaveButton.left, SaveButton.top);
		IMAGEMANAGER->findImage("Ground")->render(getDC, SaveButton.left, SaveButton.top);
	}
	// 버튼 클릭했을 때
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
// 맵 툴클래스 
class MapClass
{
public:

	//그리드 타이 만들기 
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

	// 카메라안에 있는 타일 찾아서 저장 
	void CameraTileSave()
	{
		CAMERAMANAGER->CameraFunc()->FINDTile(CAMERAMANAGER->CameraFunc()->GetCameraOperation().TileCountX, CAMERAMANAGER->CameraFunc()->GetCameraOperation().TileCountY);
	}



private:

};