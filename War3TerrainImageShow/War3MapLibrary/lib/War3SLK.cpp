#include "War3MapLibrary\include\War3SLK.h"

namespace LibraryWar3Map
{
	War3SLKtype::War3SLKtype() : isValid(false)
	{
	}

	War3SLKtype::~War3SLKtype()
	{
	}

	bool War3SLKtype::IsValid()
	{
		return isValid;
	}

	void War3SLKtype::ReadDatas(int count, const QStringList datas)
	{
		typeList.clear();
		if (datas.size() != count) return;
		for (size_t i = 0; i < datas.size(); i++)
		{
			if (typeList.contains(datas[i])) return;
			typeList.append(datas[i]);
		}
		isValid = true;
		return;
	}
	int War3SLKtype::GetTypeIndex(QString type)
	{
		return typeList.indexOf(type);
	}

	QString War3SLKtype::GetType(int index)
	{
		return typeList[index];
	}

	War3SLKstruct::War3SLKstruct() : isValid(false)
	{
	}

	War3SLKstruct::~War3SLKstruct()
	{
	}

	void War3SLKstruct::SetIndex(int structIndex)
	{
		index = structIndex;
	}

	int War3SLKstruct::GetIndex()
	{
		return index;
	}

	bool War3SLKstruct::IsValid()
	{
		return isValid;
	}

	void War3SLKstruct::SetValid(bool valid)
	{
		isValid = valid;
	}
}