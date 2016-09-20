#include "War3MapLibrary\include\War3SLKcliff.h"

namespace LibraryWar3Map
{

	War3SLKcliff::War3SLKcliff() : notLoadPixMap(true)
	{
	}

	War3SLKcliff::~War3SLKcliff()
	{
	}


	void War3SLKcliff::ReadDatas(int structIndex, QStringList datas)
	{
		bool tranOK;
		SetIndex(structIndex);
		cliffID = datas[0];
		cliffModeID = datas[1];
		rampModelDir = datas[2];
		dir = datas[3];
		file = datas[4];
		path = WAR3DEFINE_WAR3SLK_BASEPATH + dir + "\\" + file + WAR3DEFINE_WAR3SLK_EXTENSION;
		name = datas[5];
		groundTile = datas[6];
		upperTile = datas[7];
		cliffClass = datas[8].toInt(&tranOK);
	}

}