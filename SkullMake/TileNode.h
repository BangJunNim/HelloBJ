#pragma once
//타일 기본 정의 h



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
enum class BackGroundCount
{
	Empty, One, two, three
};

enum class MapToolUI
{
	None, Save, Load, Ground, Eraser
};



//타일 팔렛트 이동은 추후 나중에  할 수 도 안 할수도 있음. 

// 각 타일( 샘플 ) 정보를 담는다 . 
// 이래서 남의 코드 그냥 옮기면 안되는거야..그쵸ㅣ...,.,ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
// 근데 저 UCAMERA를 굳이 여기서 쓰는 이유가 있는거야? 
// 어차피 걍 언사인드 숏 변수 두개 짜리 쓰는건데 그쵸... 음.... 근데 어떻게 대체
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

// 타일(샘플) 목록 
struct TileSetKind
{
	TileSetInfo Ground_TileSet[FloorTileX * FloorTileY];
	//TileSetInfo 
	// 추후 여기에 오브젝트 / 아이템 / 파괴 오브젝트 / 등등 만들면 됨. 

};
// 뭔놈의 구조체가 이렇게 많어 ㅋㅋㅋㅋ 아이고 ㅋㅋㅋ...ㅠㅠㅠㅠ
// 일케돼면.. 헤더가 꼬일 수밖에 없지 형 제가 한번 찾아볼게요 ..
// 타일 프레임 이미지를 담을 구조체들 
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
		
		Frame.GroundFrameImage.x = Frame.GroundFrameImage.y = 0;
		Tiletype = Tile_Type::Empty;
		Floortype = Floor_Tile::Empty;
		
	}

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
