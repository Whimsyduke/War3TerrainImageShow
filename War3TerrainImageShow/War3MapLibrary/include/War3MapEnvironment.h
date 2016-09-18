#ifndef WAR3MAPENVIRONMENT_H
#define WAR3MAPENVIRONMENT_H
#include <QFile>
#include <QDataStream>

#include "War3MapLibrary\include\War3CommonDefines.h"
#include "War3MapLibrary\include\War3SLK.h"
#include "War3MapLibrary\include\War3SLKterrain.h"

#define CONST_WAR3MAXMAPSIDE 481
#define CONST_WAR3MAXMAPTILESETTYPE 16
#define CONST_WAR3MAXMAPCLIFFTYPE 16

namespace LibraryWar3Map
{
	class TilePointStruct;
	class War3MapEnvironment;

	class TilePointStruct
	{
	public:
		TilePointStruct(char *bytes, War3MapEnvironment *enviroment);
		~TilePointStruct();

		int GetGroundHeight();
		bool GetShadowFlag();
		int GetWaterHeight();
		bool GetWaterDeepFlag();
		bool GetCameraFlag();
		bool GetWaterShallowFlag();
		bool GetBlightFlag();
		bool GetRampFlag();
		QString GetTileTypeID();
		short GetTextureDetails();
		QString GetCliffTypeID();
		short GetCliffLevel();
	private:
		int groundHeight;// ����߶�(2B, short)
		bool shadowFlag;// ��Ӱ��Χ����(1b, bool)
		int waterHeight;// ˮ��߶�(2B-1b, short)
		bool waterDeepFlag;// ��ˮ�����(1b, bool)
		bool cameraFlag;// ��ͷ��Χ���� (1b, bool)
		bool waterShallowFlag;// ǳˮ�����(1b, bool)
		bool blightFlag;// ���ߵر����(1b, bool)
		bool rampFlag;// б�±���(1b, bool)
		QString tileTypeID; // ������������ (2b, int)
		short textureDetails;// ����ϸ��(2b, int)
		QString cliffTypeID;// ������������(2b, int)
		short cliffLevel;// ���²���(2b, int)
	};

	class War3MapEnvironment
	{
	public:
		enum TileSetType
		{
			Ashenvale = 'A',
			Barrens = 'B',
			Felwood = 'C',
			Dungeon = 'D',
			LordaeronFall = 'F',
			Underground = 'G',
			LordaeronSummer = 'L',
			Northrend = 'N',
			VillageFall = 'Q',
			Village = 'V',
			LordaeronWinter = 'W',
			Dalaran = 'X',
			Cityscape = 'Y',
			SunkenRuins = 'Z',
			Icecrown = 'I',
			DalaranRuins = 'J',
			Outland = 'O',
			BlackCitadel = 'K'
		};

	public:
		War3MapEnvironment();
		War3MapEnvironment(QString path);
		~War3MapEnvironment();

		void Load(QString path);

		QString GetTileType(int index);// ��ȡ���������б�ID
		QString GetCilffType(int index);// ��ȡ���������б�ID

		bool IsValid();

		int GetWidth();
		int GetHeight();
		int GetMapWidth();
		int GetMapHeight();
		TilePointStruct * GetTilePointStruct(int x, int y);
		QImage GetGridTerrainImage(int x, int y, War3SLK<War3SLKterrainStruct> &terrainSLK);
	private:
		bool isValid;

		QFile fileClass;// war3map.w3e�ļ�
		QString fileHeader;// ͷ��ǣ�"W3E!"(4B, char[4])
		int fileVersion;// �ļ��汾(4B, int)
		TileSetType tilesetMainType; // ��������(1B, char)
		bool useCustom;// �Զ�������(4B, int)
		short tileTypeCount;// ������������ (4B, int) (<16)
		QString tileTypeID[CONST_WAR3MAXMAPTILESETTYPE];// ���������б�(4B*tileTypeCount, char[4]*tileTypeCount)
		short cliffTypeCount;// �����������(4B, int) (<16)
		QString cliffTypeID[CONST_WAR3MAXMAPCLIFFTYPE];// ���������б�(4B*cliffTypeCount, char[4]*cliffTypeCount)
		int width;// ���ο��+1,����������(4B, int)
		int height;// ���θ߶�+1,�߷���������(4B, int)
		float centerX;// ���λ�׼����X�����������ļ�ʹ��
		float centerY;// ���λ�׼����Y�����������ļ�ʹ��
		QList<TilePointStruct> tilePointTable;// ���νڵ������б�
	};
}

#endif // WAR3MAPENVIRONMENT_H
