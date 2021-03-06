#include "war3terrainimageshow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QScrollArea>
#include "QTextCodec"
#pragma execution_character_set("utf-8")

using namespace LibraryWar3Map;

War3TerrainImageShow::War3TerrainImageShow(QWidget *parent)
	: QMainWindow(parent)
{
	war3Environment.Load("war3map.w3e");
	war3TerrainData.Load("War3TexturesAndSetting\\TerrainArt\\Terrain.slk");
	War3SLKterrainStruct nothing(war3TerrainData.TilesCount(), WAR3SLKTERRAIN_TYPE_NOTHINGTYPE);
	war3TerrainData.AddSingleTileType(WAR3SLKTERRAIN_TYPE_NOTHINGTYPE, nothing);
	war3Texture.InitTexture(war3Environment, war3TerrainData);
	ui.setupUi(this); 
	//ui.centralWidget->

	scene.setSceneRect(war3Texture.Rect());

	ui.graphicsView->setScene(&scene);

	scene.addItem(&war3Texture);
	war3Texture.setPos(0, 0);

	bool b;
	b = QObject::connect(ui.Action_SingleTerrain, SIGNAL(triggered()), this, SLOT(addSingleTexture()));
	b = QObject::connect(ui.Action_ALLTerrain, SIGNAL(triggered()), this, SLOT(addAllTexture()));
	//b = QObject::connect(ui.menu_SingleTerrain, SIGNAL(triggered()), this, SLOT(addSingleTexture()));
	//b = QObject::connect(ui.menu_AllTerrain, SIGNAL(triggered()), this, SLOT(addAllTexture()));

}

War3TerrainImageShow::~War3TerrainImageShow()
{
}


void War3TerrainImageShow::addSingleTexture()
{
	if (war3Texture.IsGenerationEnd()) return;
	war3Texture.AddSingleTexture();
	if (war3Texture.IsGenerationEnd())
	{
		ui.Action_SingleTerrain->setEnabled(false);
		ui.Action_ALLTerrain->setEnabled(false);
	}
	//war3Texture.update();
}
void War3TerrainImageShow::addAllTexture()
{
	if (war3Texture.IsGenerationEnd()) return;
	war3Texture.AddAllTexture();
	if (war3Texture.IsGenerationEnd())
	{
		ui.Action_SingleTerrain->setEnabled(false);
		ui.Action_ALLTerrain->setEnabled(false);
	}
	//war3Texture.update();
}