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
		int groundHeight;// 地面高度(2B, short)
		bool shadowFlag;// 阴影范围标旗(1b, bool)
		int waterHeight;// 水面高度(2B-1b, short)
		bool waterDeepFlag;// 深水面标旗(1b, bool)
		bool cameraFlag;// 镜头范围标旗 (1b, bool)
		bool waterShallowFlag;// 浅水面标旗(1b, bool)
		bool blightFlag;// 荒芜地表标旗(1b, bool)
		bool rampFlag;// 斜坡标旗(1b, bool)
		QString tileTypeID; // 地面纹理类型 (2b, int)
		short textureDetails;// 纹理细节(2b, int)
		QString cliffTypeID;// 悬崖纹理类型(2b, int)
		short cliffLevel;// 悬崖层数(2b, int)
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

		QString GetTileType(int index);// 获取地形纹理列表ID
		QString GetCilffType(int index);// 获取悬崖纹理列表ID

		bool IsValid();

		int GetWidth();
		int GetHeight();
		int GetMapWidth();
		int GetMapHeight();
		TilePointStruct * GetTilePointStruct(int x, int y);
		QImage GetGridTerrainImage(int x, int y, War3SLK<War3SLKterrainStruct> &terrainSLK);
	private:
		bool isValid;

		QFile fileClass;// war3map.w3e文件
		QString fileHeader;// 头标记："W3E!"(4B, char[4])
		int fileVersion;// 文件版本(4B, int)
		TileSetType tilesetMainType; // 地形主题(1B, char)
		bool useCustom;// 自定义纹理集(4B, int)
		short tileTypeCount;// 地形纹理数量 (4B, int) (<16)
		QString tileTypeID[CONST_WAR3MAXMAPTILESETTYPE];// 地形纹理列表(4B*tileTypeCount, char[4]*tileTypeCount)
		short cliffTypeCount;// 悬崖纹理计数(4B, int) (<16)
		QString cliffTypeID[CONST_WAR3MAXMAPCLIFFTYPE];// 悬崖纹理列表(4B*cliffTypeCount, char[4]*cliffTypeCount)
		int width;// 地形宽度+1,宽方向结点数量(4B, int)
		int height;// 地形高度+1,高方向结点数量(4B, int)
		float centerX;// 地形基准坐标X，其他配置文件使用
		float centerY;// 地形基准坐标Y，其他配置文件使用
		QList<TilePointStruct> tilePointTable;// 地形节点数据列表
	};
}

#endif // WAR3MAPENVIRONMENT_H
