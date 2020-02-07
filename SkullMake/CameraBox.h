#pragma once
#include "stdafx.h"
//??.. TileSave 여기 있다고? UCAMERA 요 친굽ㄴ다
//카메라의 좌표 


//출력하기 원하는 타일인덱스 담아두는
class CameraFindTile
{
protected:

	UCAMERA StartIndex;			// 시작 지점    카메라의 Left, Top
	UCAMERA EndIndex;			// 끝나는 지점  Right, Bottom
	UCAMERA Range;				// 출력 범위   레탑에서 끝 까지 보이는 타일 개수를 담는것 

public:

	CameraFindTile() {}
	~CameraFindTile() {}

	
	void ReSet()
	{
		StartIndex.x = StartIndex.y = 0;
		EndIndex.x = EndIndex.y = 0;
		Range.x = Range.y = 0;
	}

	void FindStart(float x, float y)
	{
		StartIndex.x = unsigned short(x / TILESIZEX);
		StartIndex.y = unsigned short(y / TILESIZEY);

		StartIndex.x < 0 ? StartIndex.x = 0 : StartIndex.x;   // 시작점 x / left가 0보다 작을 때 를 조건으로  
		StartIndex.y < 0 ? StartIndex.y = 0 : StartIndex.y;
	}

	void FindEnd(float x, float y, unsigned short TileCountX, unsigned short TileCountY)
	{
		EndIndex.x = unsigned short((x + WINSIZEX) / TILESIZEX);
		EndIndex.y = unsigned short((y + WINSIZEY) / TILESIZEY);

		EndIndex.x > TileCountX ? EndIndex.x = TileCountX : EndIndex.x;
		EndIndex.y > TileCountY ? EndIndex.y = TileCountY : EndIndex.y;
	}

	// 찾아야 하는 타일의 범위 
	void FIndRange()
	{
		Range.x = unsigned short(EndIndex.x - StartIndex.x); 
		Range.y = unsigned short(EndIndex.y - StartIndex.y);
	}
	
	UCAMERA GetStartIndex() { return StartIndex; }
	UCAMERA GetEndIndex() { return EndIndex; }
	UCAMERA GetRangeIndex() { return Range; }
};


// 카메라의 변수 모음 
struct CameraInfo
{
	UCAMERA WorldSize;								// 월드 사이즈 
	UCAMERA CameraSize;								// 카메라 사이즈 
													
	POINTFLOAT CameraXY;							// 카메라의 X, Y 좌표
	UCOUNT  CameraOperator;							// 카메라 연산
													
	CameraFindTile* FindTile;						// 출력해야 할 타입 찾아주는 


	void BaseSetting()
	{
		//초기 셋팅 
		SetCameraXY(WINSIZEX / 2.f, WINSIZEY / 2.f, true);

		//카메라 범위 내 타일 찾는 클래스 
		FindTile = new CameraFindTile;
		FindTile->ReSet();

		// 월드 사이즈 저장 
		WorldSize.x = TileX * TILESIZEX;
		WorldSize.y = TileY * TILESIZEY;

		//카메라 사이즈 
		CameraSize.x = WINSIZEX;
		CameraSize.y = WINSIZEY;

		//그려져있는 타일의 갯수를 저장 
		CameraOperator.TileCountX = TileX;
		CameraOperator.TileCountY = TileY;
	}

	void SetWorldSize(unsigned short x, unsigned short y) { WorldSize.x = x; WorldSize.y; }			// 월드 사이즈 저장 
	void SetCameraSize(unsigned short x, unsigned short y) { CameraSize.x = x; CameraSize.y; }		// 카메라 사이즈 저장 
	void SetCameraX(float x) { CameraXY.x; CameraCorrection(); }									// 카메라 x 값 수정 
	void SetCameraY(float y) { CameraXY.y; CameraCorrection(); }									// 카메라 y  값 수정 
	void SetCameraXY(float x, float y, bool noCorrenction)											// true를 넣으면 예외처리를 제외하고 세팅 
	{
		CameraXY.x = x - (CameraSize.x / 2);
		CameraXY.y = y - (CameraSize.y / 2);

		// true 예외처리
		if (noCorrenction) CameraCorrection();
	};
	
	UCAMERA GetWorldSize() { return WorldSize; }
	UCAMERA GetCameraSize() { return CameraSize; }
	POINTFLOAT GetCameraXY() { return CameraXY; }
	CameraFindTile* GetFindTile() { return FindTile; }
	UCOUNT GetCameraOperation() { return CameraOperator; }
	
	void CameraCorrection()
	{
		// 카메라좌표가 맵을 넘어갔을때 보정 
		if (CameraXY.x < 0) CameraXY.x = 0;
		if (CameraXY.y < 0) CameraXY.y = 0;
		if (CameraXY.x + CameraSize.x > WorldSize.x) CameraXY.x = WorldSize.x - CameraSize.x;
		if (CameraXY.y + CameraSize.y > WorldSize.y) CameraXY.y = WorldSize.y - CameraSize.y;
	}

	void FINDTile(unsigned short TileCountX, unsigned short TileCountY)
	{
		FindTile->FindStart(CameraXY.x, CameraXY.y);
		FindTile->FindEnd(CameraXY.x, CameraXY.y, TileCountX, TileCountY);
		FindTile->FIndRange();
	}

};