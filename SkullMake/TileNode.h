#pragma once
//展析 奄沙 舛税 h



// 展析税 曽嫌 c
enum class Tile_Type
{
	//	因拷 ,   郊韓 ,  汽坪展析  , 採辞走澗展析, 巴傾戚嬢   , 旋		  ,敗舛 展析 , 庚,		焼戚奴 
	Empty, FloorTile, ObjectTile, BrokenTile, PlayerTile, EnemyTile, TrapTile, DoorTile, ItemTile
};

// 郊韓 展析 雌室 
enum class Floor_Tile
{
	Empty, DevilCastle, Stage1, Stage2, Stage3
};
// 神崎詮闘 
enum class Object_Tile
{
	//混,探舌,奄逆,貝娃,炎降,腎疎, 
	Empty, Wall, BrokenWall, Ceiling, BrokenCeiling, Pillar, BrokenPillar, Handrail, BrokenHandrail, Flag, BrokenFlag, Throne, BrokenThrone, Tree, Grass, 
};
// 採辞走澗 展析
enum class BrokenTile
{
	// 展趨 , 炎降 , 度闘
	Empty, Towar, BrokenTowar, Flag, BrokenFlag, Tent, BrokenTent
};

enum class EnemyTile
{
	// 奄紫, 叡紫, 諺帖, 析鋼 蟹巷, 遭廃蟹巷, 舌稽蟹巷, 耕艦左什(亀旋)
	Empty, Soldier, Archer, Hammer, Tree, Tree2, ElderTree, MiniBoss
};

enum class PlayerTile
{
	// 巴傾戚嬢 什展闘 走繊 
	Empty, StarPoint
};

enum class TrapTile
{
	// 亜獣帰悌
	Empty, Bush
};

enum class DoorTile
{
	// 雌繊 , 左弘, 陥製什砺戚走, 左什 , 原走厳 左什 
	Empty, Shop, Treasure, NextStage, Boss, FinalBoss
};

enum class ItemTile
{
	// 疑穿, 噺差姥十, 舛呪, 什鎮 巾壕奄 
	Empty, Coin, HpBead, AbilityBead, Skull
};

//  壕井 戚耕走 朝錘闘
enum class BackGroundCount
{
	Empty, One, two, three
};

enum class MapToolUI
{
	None, Save, Load, Ground, Eraser
};



//展析 独型闘 戚疑精 蓄板 蟹掻拭  拝 呪 亀 照 拝呪亀 赤製. 

// 唖 展析( 児巴 ) 舛左研 眼澗陥 . 
// 戚掘辞 害税 坪球 益撹 薪奄檎 照鞠澗暗醤..益竹び...,.,ばばばばばばばばばば
// 悦汽 煽 UCAMERA研 瓜戚 食奄辞 床澗 戚政亜 赤澗暗醤? 
// 嬢託杷 袷 情紫昔球 儒 痕呪 砧鯵 促軒 床澗闇汽 益竹... 製.... 悦汽 嬢胸惟 企端
struct TileSetInfo
{
	RECT rc;
	UCAMERA Frame;  // CameraBox  朝五虞税 x ,y 疎妊 
	Floor_Tile floortile;  // 競 展析 

	// 展析 段奄鉢 拝 凶 紫遂 馬形壱 幻給
	void TypeReSet()
	{
		floortile = Floor_Tile::Empty;
	}
};

// 展析(児巴) 鯉系 
struct TileSetKind
{
	TileSetInfo Ground_TileSet[FloorTileX * FloorTileY];
	//TileSetInfo 
	// 蓄板 食奄拭 神崎詮闘 / 焼戚奴 / 督雨 神崎詮闘 / 去去 幻級檎 喫. 

};
// 杭叶税 姥繕端亜 戚係惟 弦嬢 せせせせ 焼戚壱 せせせ...ばばばば
// 析追掬檎.. 伯希亜 何析 呪鉱拭 蒸走 莫 薦亜 廃腰 達焼瑳惟推 ..
// 展析 覗傾績 戚耕走研 眼聖 姥繕端級 
struct TileFrameImage
{
	UCAMERA  GroundFrameImage;  // 走莫 戚耕走 覗傾績 
};


// 展析 舛左研 煽舌 拝 姥繕端 
struct TileSave
{
	POINTFLOAT		Center;		// 展析税 掻繊聖 眼澗陥.
	RECT			rc;			// 展析 刑闘 
	UCAMERA			Index;		// 展析税 昔畿什研 眼澗陥 . 

	Tile_Type		Tiletype;	// 乞窮 展析税  展脊 ! ! ! 
	Floor_Tile		Floortype;	// 郊韓 展析 ! ! ! 

	TileFrameImage	Frame;		// 戚耕走 覗傾績 
	
	// 展析 段奄鉢 
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
	Tile_Type	TileList;					// 乞窮 展析 軒什闘 / 鯉系  旭精 糎仙
	Floor_Tile	FloorTileList;				// 郊韓
	Object_Tile ObjTileList;				// 神崎詮闘
	BrokenTile	BrokenTileList;				// 督雨亜管廃
	EnemyTile	EnemyTileList;				// 旋
	PlayerTile	PlayerTileList;				// 爽昔因 
	TrapTile	TrapTileList;				// 敗舛
	DoorTile	DoorTileList;				// 庚 / 陥製 什砺戚走 
	ItemTile	ItemTileList;				// 焼戚奴 
	RECT		rc;
	int IndexX, IndexY;

} TileInfo;

typedef struct 
{
	RECT rcTile;
	int FloorFrameX, FloorFrameY;

} SampleFloorTile;
