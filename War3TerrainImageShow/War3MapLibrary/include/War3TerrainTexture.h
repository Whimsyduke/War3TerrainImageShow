#ifndef WAR3TERRAINTEXTURE_H
#define WAR3TERRAINTEXTURE_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

#include "War3MapLibrary\include\War3SLKterrain.h"
#include "War3MapLibrary\include\War3MapEnvironment.h"

namespace LibraryWar3Map
{
	class War3TerrainTexture :
		public QGraphicsItem
	{
	public:
		War3TerrainTexture();
		War3TerrainTexture(War3MapEnvironment &enviroment, War3SLK<War3SLKterrainStruct> &terrain);
		~War3TerrainTexture();

		void InitTexture(War3MapEnvironment &enviroment, War3SLK<War3SLKterrainStruct> &terrain);
		void AddSingleTexture(QImage &image, int x, int y);
		void AddSingleTexture();
		void AddAllTexture();
		QRect Rect();
		bool IsGenerationEnd();

		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	private:
		int x;
		int y;
		int baseSizePerTile;
		QImage baseImage;
		War3MapEnvironment * baseEnviroment;
		War3SLK<War3SLKterrainStruct> * baseTerrain;
	};
}

#endif //WAR3TERRAINTEXTURE_H
