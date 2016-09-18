#include "War3MapLibrary\include\War3SLKterrain.h"
namespace LibraryWar3Map
{
	War3SLKterrainStruct::War3SLKterrainStruct() : notLoadPixMap(true)
	{
	}

	War3SLKterrainStruct::War3SLKterrainStruct(int StructIndex, QString StructTileID)
	{
		if (StructTileID == WAR3SLKTERRAIN_QPIXMAP_NOTHINGTYPE)
		{
			SetIndex(StructIndex);
			tileID = WAR3SLKTERRAIN_QPIXMAP_NOTHINGTYPE;
			cliffSet = -1;
			dir = "TerrainArt\\Nothing";
			file = "nothing";
			path = WAR3SLKTERRAIN_QPIXMAP_BASEPATH + dir + "\\" + file + WAR3SLKTERRAIN_QPIXMAP_EXTENSION;
			//pixmap.load(path);
			comment = "Nothing";
			name = "WESTRING_TILE_NOTHING";
			buildable = false;
			footprints = false;
			walkable = false;
			flyable = false;
			blightPri = 0;
			inBeta = false;
			version = false;
			notLoadPixMap = true;
		}
	}

	War3SLKterrainStruct::War3SLKterrainStruct(
		int StructIndex,
		QString StructTileID,
		int StructCliffSet,
		QString StructDir,
		QString StructFile,
		QString StructPath,
		QString StructComment,
		QString StructName,
		bool StructBuildable,
		bool StructFootprints,
		bool StructWalkable,
		bool StructFlyable,
		int StructBlightPri,
		QString StructConvertTo,
		bool StructInBeta,
		int StructVersion
		) : notLoadPixMap(true)
	{
		SetIndex(StructIndex);
		tileID = StructTileID;
		cliffSet = StructCliffSet;
		dir = StructDir;
		file = StructFile;
		path = WAR3SLKTERRAIN_QPIXMAP_BASEPATH + dir + "\\" + file + WAR3SLKTERRAIN_QPIXMAP_EXTENSION;
		//pixmap.load(path);
		comment = StructComment;
		name = StructName;
		buildable = StructBuildable;
		footprints = StructFootprints;
		walkable = StructWalkable;
		flyable = StructFlyable;
		blightPri = StructBlightPri;
		convertTo = StructConvertTo.split(',', QString::SkipEmptyParts);
		inBeta = StructInBeta;
		version = StructVersion;
		notLoadPixMap = true;
	}

	War3SLKterrainStruct::~War3SLKterrainStruct()
	{
	}

	void War3SLKterrainStruct::ReadDatas(int structIndex, QStringList datas)
	{
		bool tranOK;
		SetIndex(structIndex);
		tileID = datas[0];
		cliffSet = datas[1].toInt(&tranOK);
		Q_ASSERT_X(tranOK, "War3SLKterrainStruct::ReadDatas", "Error data!");
		dir = datas[2];
		file = datas[3];
		path = WAR3SLKTERRAIN_QPIXMAP_BASEPATH + dir + "\\" + file + WAR3SLKTERRAIN_QPIXMAP_EXTENSION;
		//pixmap.load(path);
		comment = datas[4];
		name = datas[5];
		buildable = datas[6] != "0";
		footprints = datas[7] != "0";
		walkable = datas[8] != "0";
		flyable = datas[9] != "0";
		blightPri = datas[10].toInt(&tranOK);
		Q_ASSERT_X(tranOK, "War3SLKterrainStruct::ReadDatas", "Error data!");
		convertTo = datas[11].split(',', QString::SkipEmptyParts);
		inBeta = datas[12] != "0";
		version = datas[13].toInt(&tranOK);
		Q_ASSERT_X(tranOK, "War3SLKterrainStruct::ReadDatas", "Error data!");
		SetValid(true);
	}

	QImage War3SLKterrainStruct::GetFullTerrainTexture()
	{
		if (notLoadPixMap)
		{
			notLoadPixMap = false;
			Q_ASSERT_X(image.load(path), "War3SLKterrainStruct::GetFullTerrainTexture", ("Error load terrain texture: (" + path + ")!").toStdString().c_str());
		}
		return image;
	}

	QImage War3SLKterrainStruct::GetGridTerrainTexture(int index)
	{
		if (notLoadPixMap)
		{
			notLoadPixMap = false;
			Q_ASSERT_X(image.load(path), "War3SLKterrainStruct::GetFullTerrainTexture", ("Error load terrain texture: (" + path + ")!").toStdString().c_str());
		}

		return image.copy(index / 4 * WAR3DEFINE_TERRAIN_TILESIZE, index % 4 * WAR3DEFINE_TERRAIN_TILESIZE, WAR3DEFINE_TERRAIN_TILESIZE, WAR3DEFINE_TERRAIN_TILESIZE);
	}
}