#pragma once


typedef struct
{
	unsigned short x; 
	unsigned short y; 
} USHORT;

typedef struct
{
	unsigned int TileCountX;
	unsigned int TileCountY;
} UINT;

//출력하기 원하는 타일인덱스 담아두는
class CameraFindTile
{
protected:

	USHORT StartIndex;			// 시작 지점    카메라의 Left, Top
	USHORT EndIndex;			// 끝나는 지점  Right, Bottom
	USHORT Range;				// 출력 범위   레탑에서 끝 까지 보이는 타일 개수를 담는것 

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
	}

	// 찾아야 하는 타일의 범위 
	void FIndRange()
	{
		Range.x = unsigned short(EndIndex.x - StartIndex.x); 
		Range.y = unsigned short(EndIndex.y - StartIndex.y);
	}
	
	USHORT GetStartIndex() { return StartIndex; }
	USHORT GetEndIndex() { return EndIndex; }
	USHORT GetRangeIndex() { return Range; }
};


// 카메라의 변수 모음 
struct CameraInfo
{

};