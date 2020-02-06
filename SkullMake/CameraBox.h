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

//����ϱ� ���ϴ� Ÿ���ε��� ��Ƶδ�
class CameraFindTile
{
protected:

	USHORT StartIndex;			// ���� ����    ī�޶��� Left, Top
	USHORT EndIndex;			// ������ ����  Right, Bottom
	USHORT Range;				// ��� ����   ��ž���� �� ���� ���̴� Ÿ�� ������ ��°� 

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

		StartIndex.x < 0 ? StartIndex.x = 0 : StartIndex.x;   // ������ x / left�� 0���� ���� �� �� ��������  
		StartIndex.y < 0 ? StartIndex.y = 0 : StartIndex.y;
	}

	void FindEnd(float x, float y, unsigned short TileCountX, unsigned short TileCountY)
	{
		EndIndex.x = unsigned short((x + WINSIZEX) / TILESIZEX);
		EndIndex.y = unsigned short((y + WINSIZEY) / TILESIZEY);
	}

	// ã�ƾ� �ϴ� Ÿ���� ���� 
	void FIndRange()
	{
		Range.x = unsigned short(EndIndex.x - StartIndex.x); 
		Range.y = unsigned short(EndIndex.y - StartIndex.y);
	}
	
	USHORT GetStartIndex() { return StartIndex; }
	USHORT GetEndIndex() { return EndIndex; }
	USHORT GetRangeIndex() { return Range; }
};


// ī�޶��� ���� ���� 
struct CameraInfo
{

};