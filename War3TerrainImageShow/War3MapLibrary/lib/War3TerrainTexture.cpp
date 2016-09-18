#include "War3MapLibrary\include\War3TerrainTexture.h"

namespace LibraryWar3Map
{
	War3TerrainTexture::War3TerrainTexture() :
		x(0), y(0)
	{

	}

	War3TerrainTexture::War3TerrainTexture(War3MapEnvironment &enviroment, War3SLK<War3SLKterrainStruct> &terrain) :
		x(0), y(0), baseImage(enviroment.GetMapWidth(), enviroment.GetMapHeight(), QImage::Format_ARGB32), baseEnviroment(&enviroment), baseTerrain(&terrain)
	{
		QPainter painter(&baseImage);
		for (size_t j = 0; j < enviroment.GetHeight() - 1; j++)
		{
			for (size_t i = 0; i < enviroment.GetWidth() - 1; i++)
			{
				painter.drawImage(i * WAR3DEFINE_TERRAIN_TILESIZE, baseImage.height() - j * WAR3DEFINE_TERRAIN_TILESIZE, enviroment.GetGridTerrainImage(i, j, terrain));
			}
		}
	}

	War3TerrainTexture::~War3TerrainTexture()
	{
	}

	void War3TerrainTexture::InitTexture(War3MapEnvironment &enviroment, War3SLK<War3SLKterrainStruct> &terrain)
	{
		baseImage = { enviroment.GetMapWidth(), enviroment.GetMapHeight(), QImage::Format_ARGB32 };
		baseEnviroment = &enviroment;
		baseTerrain = &terrain;
		//QPainter painter(&baseImage);
		//for (size_t j = 0; j < enviroment.GetHeight() - 1; j++)
		//{
		//	for (size_t i = 0; i < enviroment.GetWidth() - 1; i++)
		//	{
		//		painter.drawImage(i * WAR3DEFINE_TERRAIN_TILESIZE, baseImage.height() - j * WAR3DEFINE_TERRAIN_TILESIZE, enviroment.GetGridTerrainImage(i, j, terrain));
		//	}
		//}
	}

	void War3TerrainTexture::AddSingleTexture(QImage &image, int x, int y)
	{
		QPainter painter(&baseImage);
		painter.drawImage(x * baseSizePerTile, baseImage.height() - y * baseSizePerTile, image);
	}

	void War3TerrainTexture::AddSingleTexture()
	{
		QPainter painter(&baseImage);
		//baseImage.load("image.png");
		painter.drawImage(x * WAR3DEFINE_TERRAIN_TILESIZE, baseImage.height() - (y + 1) * WAR3DEFINE_TERRAIN_TILESIZE, baseEnviroment->GetGridTerrainImage(x, y, *baseTerrain));
		//baseImage = baseEnviroment->GetGridTerrainImage(x, y, *baseTerrain);
		x += 1;
		if (x >= baseEnviroment->GetWidth())
		{
			x = 0;
			y += 1;
		}
	}
	void War3TerrainTexture::AddAllTexture()
	{
		QPainter painter(&baseImage);
		for (; y < baseEnviroment->GetHeight() - 1; y++)
		{
			for (; x < baseEnviroment->GetWidth() - 1; x++)
			{
				painter.drawImage(x * WAR3DEFINE_TERRAIN_TILESIZE, baseImage.height() - (y + 1) * WAR3DEFINE_TERRAIN_TILESIZE, baseEnviroment->GetGridTerrainImage(x, y, *baseTerrain));
			}
			x = 0;
		}
	}

	QRect War3TerrainTexture::Rect()
	{
		return baseImage.rect();
	}

	bool War3TerrainTexture::IsGenerationEnd()
	{
		return x >= baseEnviroment->GetWidth() - 1 || y >= baseEnviroment->GetHeight() - 1;
	}

	void War3TerrainTexture::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
	{
		painter->drawImage(0, 0, baseImage);
	}

	QRectF War3TerrainTexture::boundingRect() const
	{
		return QRectF(0, 0, baseImage.width(), baseImage.height());
	}
}