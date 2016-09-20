#ifndef WAR3SLKCLIFF_H
#define WAR3SLKCLIFF_H

#include "War3MapLibrary\include\War3CommonDefines.h"
#include "War3MapLibrary\include\War3SLK.h"

namespace LibraryWar3Map
{
	class War3SLKcliff : public War3SLKstruct
	{
	public:
		War3SLKcliff();
		~War3SLKcliff();

		void ReadDatas(int structIndex, QStringList datas);
	private:
		QString cliffID;
		QString cliffModeID;
		QString rampModelDir;
		QString dir;
		QString file;
		QString path;
		bool notLoadPixMap;
		QString name;
		QString groundTile;
		QString upperTile;
		int cliffClass;
		int oldID;
		int version;
		int InBeta;
	};
}
#endif // WAR3SLKCLIFF_H