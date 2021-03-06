#include <QPainter>
#include <QHash>
#include <QDebug>

#include "War3MapLibrary\include\War3MapEnvironment.h"
#include "War3MapLibrary\include\War3DataFormat.h"

#define WAR3MAPENVIRONMENT_HEADER 4
#define WAR3MAPENVIRONMENT_VERSION 4
#define WAR3MAPENVIRONMENT_TILESET 1
#define WAR3MAPENVIRONMENT_CUSTOMTILESET 4
#define WAR3MAPENVIRONMENT_TILETYPECOUNT 4
#define WAR3MAPENVIRONMENT_TILETYPE 4
#define WAR3MAPENVIRONMENT_CLIFFTYPECOUNT 4
#define WAR3MAPENVIRONMENT_CLIFFTYPE 4
#define WAR3MAPENVIRONMENT_SIZE 4
#define WAR3MAPENVIRONMENT_CENTER 4
#define WAR3MAPENVIRONMENT_TILEPOINT 7

#define WAR3MAPENVIRONMENT_TILEPOINT_SHADOWFLAG 0x0004
#define WAR3MAPENVIRONMENT_TILEPOINT_HEIGHT 0x003F
#define WAR3MAPENVIRONMENT_TILEPOINT_HEIGHTBASE 0x2000
#define WAR3MAPENVIRONMENT_TILEPOINT_WATERDEEPFLAG 0x0004
#define WAR3MAPENVIRONMENT_TILEPOINT_WATER 0x003F
#define WAR3MAPENVIRONMENT_TILEPOINT_WATERBASE 0x2000
#define WAR3MAPENVIRONMENT_TILEPOINT_CAMERAFLAG 0x0800
#define WAR3MAPENVIRONMENT_TILEPOINT_WATERSHALLOWFLAG 0x0400
#define WAR3MAPENVIRONMENT_TILEPOINT_BLIGHTFLAG 0x0200
#define WAR3MAPENVIRONMENT_TILEPOINT_RAMPFLAG 0x0100
#define WAR3MAPENVIRONMENT_TILEPOINT_TILETYPE 0x000F
#define WAR3MAPENVIRONMENT_TILEPOINT_CILFFTYPE 4
#define WAR3MAPENVIRONMENT_TILEPOINT_CILFFLEVEL 0x000F

namespace LibraryWar3Map
{
	TilePointStruct::TilePointStruct(char *bytes, War3MapEnvironment *enviroment)
	{
		//uint datas[7];
		//char chars[7];
		//chars[0] = bytes[0];
		//datas[0] = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[0]);
		//chars[1] = bytes[1];
		//datas[1] = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[1]);
		//chars[2] = bytes[2];
		//datas[2] = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[2]);
		//chars[3] = bytes[3];
		//datas[3] = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[3]);
		//chars[4] = bytes[4];
		//datas[4] = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[4]);
		//chars[5] = bytes[5];
		//datas[5] = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[5]);
		//chars[6] = bytes[6];
		//datas[6] = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[6]);
		shadowFlag = (WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[1]) & WAR3MAPENVIRONMENT_TILEPOINT_SHADOWFLAG) != 0;
		groundHeight = (((int)(WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[1]) & WAR3MAPENVIRONMENT_TILEPOINT_HEIGHT)) << 8) + (int)(WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[0])) - WAR3MAPENVIRONMENT_TILEPOINT_HEIGHTBASE;
		waterDeepFlag = (WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[3]) & WAR3MAPENVIRONMENT_TILEPOINT_WATERDEEPFLAG) != 0;
		waterHeight = (((int)(WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[3]) & WAR3MAPENVIRONMENT_TILEPOINT_WATER)) << 8) + (int)(WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[3])) - WAR3MAPENVIRONMENT_TILEPOINT_WATERBASE;
		cameraFlag = (WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[4]) & WAR3MAPENVIRONMENT_TILEPOINT_CAMERAFLAG) != 0;
		waterShallowFlag = (WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[4]) & WAR3MAPENVIRONMENT_TILEPOINT_WATERSHALLOWFLAG) != 0;
		blightFlag = (WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[4]) & WAR3MAPENVIRONMENT_TILEPOINT_BLIGHTFLAG) != 0;
		rampFlag = (WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[4]) & WAR3MAPENVIRONMENT_TILEPOINT_RAMPFLAG) != 0; 
		tileTypeIndex = WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[4]) & WAR3MAPENVIRONMENT_TILEPOINT_TILETYPE;
		tileTypeID = enviroment->GetTileType(tileTypeIndex);
		textureDetails = (int)(WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[5]));
		cliffTypeID = enviroment->GetCilffType(WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[6]) >> WAR3MAPENVIRONMENT_TILEPOINT_CILFFTYPE);
		cliffLevel = (short)(WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[6]) & WAR3MAPENVIRONMENT_TILEPOINT_CILFFLEVEL);
	}

	TilePointStruct::~TilePointStruct()
	{
	}

	int TilePointStruct::GetGroundHeight()
	{
		return groundHeight;
	}

	bool TilePointStruct::GetShadowFlag()
	{
		return shadowFlag;
	}

	int TilePointStruct::GetWaterHeight()
	{
		return waterHeight;
	}

	bool TilePointStruct::GetWaterDeepFlag()
	{
		return waterDeepFlag;
	}

	bool TilePointStruct::GetCameraFlag()
	{
		return cameraFlag;
	}

	bool TilePointStruct::GetWaterShallowFlag()
	{
		return waterShallowFlag;
	}

	bool TilePointStruct::GetBlightFlag()
	{
		return blightFlag;
	}

	bool TilePointStruct::GetRampFlag()
	{
		return rampFlag;
	}

	int TilePointStruct::GetTileTypeIndex()
	{
		return tileTypeIndex;
	}

	QString TilePointStruct::GetTileTypeID()
	{
		return tileTypeID;
	}

	short TilePointStruct::GetTextureDetails()
	{
		return textureDetails;
	}

	QString TilePointStruct::GetCliffTypeID()
	{
		return cliffTypeID;
	}

	short TilePointStruct::GetCliffLevel()
	{
		return cliffLevel;
	}

	War3MapEnvironment::War3MapEnvironment() : isValid(false)
	{
	}

	War3MapEnvironment::War3MapEnvironment(QString path) : isValid(false)
	{
		Load(path);
	}

	War3MapEnvironment::~War3MapEnvironment()
	{
	}

	void War3MapEnvironment::Load(QString path)
	{
		fileClass.setFileName(path);
		Q_ASSERT_X(fileClass.open(QIODevice::ReadOnly), "War3MapEnvironment::War3MapEnvironment", "Error path!");
		QDataStream stream(&fileClass);
		char *buffer = new char[];

		//文件头
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_HEADER);
		fileHeader.append(buffer);
		fileHeader.resize(WAR3MAPENVIRONMENT_HEADER);
		Q_ASSERT_X(fileHeader == "W3E!", "War3MapEnvironment::War3MapEnvironment", "Error file header!");

		//版本号
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_VERSION);
		fileVersion = War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_VERSION);

		//纹理集
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_TILESET);
		tilesetMainType = (TileSetType)War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_TILESET);

		//纹理集为自定义
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_CUSTOMTILESET);
		useCustom = War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_CUSTOMTILESET) == 1;

		//地面纹理数量
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_TILETYPECOUNT);
		tileTypeCount = War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_TILETYPECOUNT);

		//地面纹理列表
		for (size_t i = 0; i < tileTypeCount; i++)
		{
			Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
			stream.readRawData(buffer, WAR3MAPENVIRONMENT_TILETYPE);
			tileTypeID[i].append(buffer);
			tileTypeID[i].resize(WAR3MAPENVIRONMENT_TILETYPE);
		}

		//悬崖纹理数量
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_CLIFFTYPECOUNT);
		cliffTypeCount = War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_CLIFFTYPECOUNT);

		//地面纹理列表
		for (size_t i = 0; i < cliffTypeCount; i++)
		{
			Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
			stream.readRawData(buffer, WAR3MAPENVIRONMENT_CLIFFTYPE);
			cliffTypeID[i].append(buffer);
			cliffTypeID[i].resize(WAR3MAPENVIRONMENT_CLIFFTYPE);
		}

		//地图范围
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_SIZE);
		width = War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_SIZE);
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_SIZE);
		height = War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_SIZE);

		//地图原点
		Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_CENTER);
		centerX = War3DataFormatGetFloatFromHex(War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_CENTER));
		stream.readRawData(buffer, WAR3MAPENVIRONMENT_CENTER);
		centerY = War3DataFormatGetFloatFromHex(War3DataFormatGetStoredBytesValue(buffer, WAR3MAPENVIRONMENT_CENTER));

		tilePointTable.clear();
		for (size_t k = 0; k < height; k++)
		{
			for (size_t l = 0; l < width; l++)
			{
				Q_ASSERT_X(!stream.atEnd(), "War3MapEnvironment::War3MapEnvironment", "Error file is not complete!");
				stream.readRawData(buffer, WAR3MAPENVIRONMENT_TILEPOINT);
				tilePointTable.push_back(TilePointStruct(buffer, this));
			}
		}

		fileClass.close();
		isValid = true;
	}

	bool War3MapEnvironment::IsValid()
	{
		return isValid;
	}

	QString War3MapEnvironment::GetTileType(int index)
	{
		if (index < tileTypeCount)
		{
			return tileTypeID[index];
		}
		else
		{
			if (index <= 0xF)
			{
				return WAR3SLKTERRAIN_TYPE_NOTHINGTYPE;
			}
			Q_ASSERT_X(false, "War3MapEnvironment::GetTileType", "Error index!");
			return "";
		}
	}

	QString War3MapEnvironment::GetCilffType(int index)
	{
		if (index < cliffTypeCount)
		{
			return cliffTypeID[index];
		}
		else
		{
			if (index <= 0xF)
			{
				return "";
			}
			Q_ASSERT_X(false, "War3MapEnvironment::GetCilffType", "Error index!");
			return "";
		}
	}

	int War3MapEnvironment::GetWidth()
	{
		return width;
	}

	int War3MapEnvironment::GetHeight()
	{
		return height;
	}

	int War3MapEnvironment::GetMapWidth()
	{
		return (width - 1) * WAR3DEFINE_TERRAIN_TILESIZE;
	}

	int War3MapEnvironment::GetMapHeight()
	{
		return (height - 1) * WAR3DEFINE_TERRAIN_TILESIZE;
	}

	TilePointStruct * War3MapEnvironment::GetTilePointStruct(int x, int y)
	{
		Q_ASSERT_X(x + y * width < tilePointTable.count(), "War3MapEnvironment::GetTilePointStruct", "Error out of size!");
		return &tilePointTable[x + y * width];
	}

	//采用的随机纹理由地形贴图左下角Tile的随机样式决定，随机样式的值为16位无符号整数,对应为随机部分贴图（右半侧）序号，特别的，0x10代表左侧0x0F号贴图，0x11代表左侧0x00号贴图，其它取对16的模。生成时先铺四个Tile中序号（地图采用的纹理的序号）最小的一个的0x00位置贴图，再按照合并后的四角样式添加。
	QImage War3MapEnvironment::GetGridTerrainImage(int x, int y, War3SLK<War3SLKterrainStruct> &terrainSLK)
	{
		Q_ASSERT_X(isValid, "War3MapEnvironment::GetGridTerrainImage", "Error not valid!");
		Q_ASSERT_X(x >= 0 && y >= 0 && x < width && y < height, "War3MapEnvironment::GetGridTerrainImage", "Error out map!");
		QImage gridTerrainImage(WAR3DEFINE_TERRAIN_TILESIZE, WAR3DEFINE_TERRAIN_TILESIZE, QImage::Format_ARGB32);
		QPainter painter(&gridTerrainImage);
		QMap<int, int> terrainTypes;
		int baseType = tilePointTable[x + y * width].GetTileTypeIndex();
		int details = tilePointTable[x + y * width].GetTextureDetails(); 
		bool haveDetails = terrainSLK.GetTileStruct(GetTypeIDbyIndex(baseType))->IsExistRandomDetails();
		terrainTypes[baseType] = 8;

		int terrainType = tilePointTable[x + 1 + (y + 1) * width].GetTileTypeIndex();
		if (terrainTypes.contains(terrainType))
		{
			terrainTypes[terrainType] += 1;
		}
		else
		{
			terrainTypes[terrainType] = 1;
		}
		terrainType = tilePointTable[x + (y + 1) * width].GetTileTypeIndex();
		if (terrainTypes.contains(terrainType))
		{
			terrainTypes[terrainType] += 2;
		}
		else
		{
			terrainTypes[terrainType] = 2;
		}
		terrainType = tilePointTable[x + 1 + y * width].GetTileTypeIndex();
		if (terrainTypes.contains(terrainType))
		{
			terrainTypes[terrainType] += 4;
		}
		else
		{
			terrainTypes[terrainType] = 4;
		}
		painter.drawImage(gridTerrainImage.rect(), terrainSLK.GetTileStruct(GetTypeIDbyIndex(terrainTypes.begin().key()))->GetGridTerrainTexture(0));
		if (terrainTypes.size() == 1 && haveDetails)
		{
			painter.drawImage(gridTerrainImage.rect(), terrainSLK.GetTileStruct(GetTypeIDbyIndex(baseType))->GetGridTerrainTextureRandomDetails(details));
		}
		else
		{
			painter.drawImage(gridTerrainImage.rect(), terrainSLK.GetTileStruct(GetTypeIDbyIndex(baseType))->GetGridTerrainTextureRandomDetails(details));
			for (QMap<int, int>::const_iterator iterator = terrainTypes.begin(); iterator != terrainTypes.end(); iterator++)
			{
				painter.drawImage(gridTerrainImage.rect(), terrainSLK.GetTileStruct(GetTypeIDbyIndex(iterator.key()))->GetGridTerrainTexture(iterator.value()));
			}
		}
		Q_ASSERT_X(terrainTypes.size(), "War3MapEnvironment::GetGridTerrainImage", "Error not draw any texture!");
		return gridTerrainImage;
	}

	QString War3MapEnvironment::GetTypeIDbyIndex(int index)
	{
		return tileTypeID[index];
	}
}