#ifndef WAR3SLK_H
#define WAR3SLK_H

#include <QFile>
#include <QHash>
#include <QVariant>
#include <QTextStream>
#include <QRegularExpression>

#include "War3CommonDefines.h"

#define WAR3SLK_REGEXP_TABLESIZE_NAME_WIDTH "REGEXPVALUE_WIDTH"
#define WAR3SLK_REGEXP_TABLESIZE_NAME_HEIGHT "REGEXPVALUE_HEIGHT"
#define WAR3SLK_REGEXP_TABLESIZE_NAME_STRUCTINDEX "REGEXPVALUE_STRUCTINDEX"
#define WAR3SLK_REGEXP_TABLESIZE_NAME_VALUEINDEX "REGEXPVALUE_VALUEINDEX"
#define WAR3SLK_REGEXP_TABLESIZE_NAME_VALUE "REGEXPVALUE_VALUE"

#define WAR3SLK_REGEXP_TABLESIZE_SIZE "^B;X(?<REGEXPVALUE_WIDTH>\\d+);Y(?<REGEXPVALUE_HEIGHT>\\d+);D\\d+"
#define WAR3SLK_REGEXP_TABLESIZE_VALUE "^C;X(?<REGEXPVALUE_VALUEINDEX>\\d+)(;Y(?<REGEXPVALUE_STRUCTINDEX>\\d+))?;K(?<REGEXPVALUE_VALUE>[^\n\r]*)$"
namespace LibraryWar3Map
{
	class War3SLKtype
	{
	public:
		War3SLKtype();
		~War3SLKtype();

		bool IsValid();
		void ReadDatas(int count, const QStringList datas);
		int GetTypeIndex(QString type);
		QString GetType(int index);
	private:
		bool isValid;
		QStringList typeList;
		int count;
	};

	class War3SLKstruct
	{
	public:
		War3SLKstruct();
		~War3SLKstruct();
		
		void SetIndex(int structIndex);
		int GetIndex();
		bool IsValid();
		virtual void ReadDatas(int structIndex, QStringList datas) = 0;
	protected:
		void SetValid(bool valid);
	private:
		bool isValid;
		int index;
	};

	template <class T> class War3SLK
	{
	public:
		War3SLK<T>() : isValid(false)
		{
		}

		War3SLK<T>(QString path) : isValid(false)
		{
			Load(path);
		}

		~War3SLK<T>()
		{

		}

		void Load(QString path)
		{
			fileClass.setFileName(path);
			Q_ASSERT_X(fileClass.open(QIODevice::ReadOnly), "War3SLK::War3SLK<T>", "Error path!");
			QTextStream stream(&fileClass);
			Q_ASSERT_X(stream.readLine(0) == "ID;PWXL;N;E", "War3SLK::War3SLK<T>", "Error file header!");
			Q_ASSERT_X(!stream.atEnd(), "War3SLK::War3SLK<T>", "Error file is not complete!");
			QString tempLine = stream.readLine(0);
			QRegularExpression tableSizeRegExp(WAR3SLK_REGEXP_TABLESIZE_SIZE, QRegularExpression::InvertedGreedinessOption);
			QRegularExpressionMatch regexpMatch;
			bool tranOK;
			regexpMatch = tableSizeRegExp.match(tempLine);
			if (!regexpMatch.hasMatch()) return;
			int width = regexpMatch.captured(WAR3SLK_REGEXP_TABLESIZE_NAME_WIDTH).toInt(&tranOK);
			if (!tranOK) return;
			int height = regexpMatch.captured(WAR3SLK_REGEXP_TABLESIZE_NAME_HEIGHT).toInt(&tranOK);
			if (!tranOK) return;
			QStringList dataList;
			for (size_t i = 0; i < width; i++)
			{
				Q_ASSERT_X(!stream.atEnd(), "War3SLK::War3SLK<T>", "Error file is not complete!");
				dataList.append(stream.readLine());
			}
			typeStruct.ReadDatas(width, dataList);
			WAR3DEFINE_COMMON_RETURNIFNOTVALID(typeStruct, );
			QRegularExpression valueRegExp(WAR3SLK_REGEXP_TABLESIZE_VALUE, QRegularExpression::InvertedGreedinessOption);
			QString structKey;
			for (size_t i = 1; i < height; i++)
			{
				dataList.clear();
				Q_ASSERT_X(!stream.atEnd(), "War3SLK::War3SLK<T>", "Error file is not complete!");
				structKey = stream.readLine();
				regexpMatch = valueRegExp.match(structKey);
				if (!regexpMatch.hasMatch()) return;
				//int valueIndex = regexpMatch.captured(WAR3SLK_REGEXP_TABLESIZE_NAME_VALUEINDEX).toInt(&tranOK);
				//if (!tranOK) return;
				int structIndex = regexpMatch.captured(WAR3SLK_REGEXP_TABLESIZE_NAME_STRUCTINDEX).toInt(&tranOK);
				if (!tranOK) return;
				structKey = regexpMatch.captured(WAR3SLK_REGEXP_TABLESIZE_NAME_VALUE);
				if (structKey.startsWith('\"') && structKey.endsWith('\"'))
				{
					structKey = structKey.mid(1, structKey.size() - 2);
				}
				dataList.append(structKey);
				for (size_t j = 1; j < width; j++)
				{
					if (stream.atEnd())
						return;
					Q_ASSERT_X(!stream.atEnd(), "War3SLK::War3SLK<T>", "Error file is not complete!");
					tempLine = stream.readLine();
					regexpMatch = valueRegExp.match(tempLine);
					if (!regexpMatch.hasMatch())
						return;
					tempLine = regexpMatch.captured(WAR3SLK_REGEXP_TABLESIZE_NAME_VALUE);
					if (tempLine.startsWith('\"') && tempLine.endsWith('\"'))
					{
						tempLine = tempLine.mid(1, tempLine.size() - 2);
					}
					dataList.append(tempLine);
				}
				T tempT;
				tempT.ReadDatas(structIndex, dataList);
				baseData[structKey] = tempT;
			}
			isValid = true;
		}

		T * GetTileStruct(QString type)
		{
			return &baseData[type];
		}

		void AddSingleTileType(QString type, T &tile)
		{
			Q_ASSERT_X(!baseData.contains(type), "War3SLK<T>::AddSingleTileType", "Error exist add Type");
			baseData[type] = tile;
		}

		int TilesCount()
		{
			return baseData.count();
		}
	private: 
		bool isValid;
		QFile fileClass;
		War3SLKtype typeStruct;
		QHash<QString, T> baseData;
	};
}
#endif // WAR3SLK_H
