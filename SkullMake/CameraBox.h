#pragma once
#include "stdafx.h"
//??.. TileSave ���� �ִٰ�? UCAMERA �� ģ������
//ī�޶��� ��ǥ 


//����ϱ� ���ϴ� Ÿ���ε��� ��Ƶδ�
class CameraFindTile
{
protected:

	UCAMERA StartIndex;			// ���� ����    ī�޶��� Left, Top
	UCAMERA EndIndex;			// ������ ����  Right, Bottom
	UCAMERA Range;				// ��� ����   ��ž���� �� ���� ���̴� Ÿ�� ������ ��°� 

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

		EndIndex.x > TileCountX ? EndIndex.x = TileCountX : EndIndex.x;
		EndIndex.y > TileCountY ? EndIndex.y = TileCountY : EndIndex.y;
	}

	// ã�ƾ� �ϴ� Ÿ���� ���� 
	void FIndRange()
	{
		Range.x = unsigned short(EndIndex.x - StartIndex.x); 
		Range.y = unsigned short(EndIndex.y - StartIndex.y);
	}
	
	UCAMERA GetStartIndex() { return StartIndex; }
	UCAMERA GetEndIndex() { return EndIndex; }
	UCAMERA GetRangeIndex() { return Range; }
};


// ī�޶��� ���� ���� 
struct CameraInfo
{
	UCAMERA WorldSize;								// ���� ������ 
	UCAMERA CameraSize;								// ī�޶� ������ 
													
	POINTFLOAT CameraXY;							// ī�޶��� X, Y ��ǥ
	UCOUNT  CameraOperator;							// ī�޶� ����
													
	CameraFindTile* FindTile;						// ����ؾ� �� Ÿ�� ã���ִ� 


	void BaseSetting()
	{
		//�ʱ� ���� 
		SetCameraXY(WINSIZEX / 2.f, WINSIZEY / 2.f, true);

		//ī�޶� ���� �� Ÿ�� ã�� Ŭ���� 
		FindTile = new CameraFindTile;
		FindTile->ReSet();

		// ���� ������ ���� 
		WorldSize.x = TileX * TILESIZEX;
		WorldSize.y = TileY * TILESIZEY;

		//ī�޶� ������ 
		CameraSize.x = WINSIZEX;
		CameraSize.y = WINSIZEY;

		//�׷����ִ� Ÿ���� ������ ���� 
		CameraOperator.TileCountX = TileX;
		CameraOperator.TileCountY = TileY;
	}

	void SetWorldSize(unsigned short x, unsigned short y) { WorldSize.x = x; WorldSize.y; }			// ���� ������ ���� 
	void SetCameraSize(unsigned short x, unsigned short y) { CameraSize.x = x; CameraSize.y; }		// ī�޶� ������ ���� 
	void SetCameraX(float x) { CameraXY.x; CameraCorrection(); }									// ī�޶� x �� ���� 
	void SetCameraY(float y) { CameraXY.y; CameraCorrection(); }									// ī�޶� y  �� ���� 
	void SetCameraXY(float x, float y, bool noCorrenction)											// true�� ������ ����ó���� �����ϰ� ���� 
	{
		CameraXY.x = x - (CameraSize.x / 2);
		CameraXY.y = y - (CameraSize.y / 2);

		// true ����ó��
		if (noCorrenction) CameraCorrection();
	};
	
	UCAMERA GetWorldSize() { return WorldSize; }
	UCAMERA GetCameraSize() { return CameraSize; }
	POINTFLOAT GetCameraXY() { return CameraXY; }
	CameraFindTile* GetFindTile() { return FindTile; }
	UCOUNT GetCameraOperation() { return CameraOperator; }
	
	void CameraCorrection()
	{
		// ī�޶���ǥ�� ���� �Ѿ���� ���� 
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