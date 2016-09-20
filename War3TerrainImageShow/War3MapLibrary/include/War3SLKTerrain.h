#ifndef WAR3SLKTERRAIN_H
#define WAR3SLKTERRAIN_H

#include <QImage>

#include "War3MapLibrary\include\War3CommonDefines.h"
#include "War3MapLibrary\include\War3SLK.h"

#define WAR3SLKTERRAIN_TYPE_NOTHINGTYPE "noth"

namespace LibraryWar3Map
{
	class War3SLKterrainStruct : public War3SLKstruct
	{
	public:
		War3SLKterrainStruct();
		War3SLKterrainStruct(int StructIndex, QString StructTileID);
		War3SLKterrainStruct(
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
			);
		~War3SLKterrainStruct();

		void ReadDatas(int structIndex, QStringList datas);

		QImage GetFullTerrainTexture();
		QImage GetGridTerrainTexture(int index);
		QImage GetGridTerrainTextureRandomDetails(int index);
		bool IsExistRandomDetails();
	private:
		QString tileID;
		int cliffSet;
		QString dir;
		QString file;
		QString path;
		bool notLoadPixMap;
		bool existRandomDetails;
		QImage image;
		QString comment;
		QString name;
		bool buildable;
		bool footprints;
		bool walkable;
		bool flyable;
		int blightPri;
		QStringList convertTo;
		bool inBeta;
		int version;
	};

}
#endif // WAR3SLKTERRAIN_H