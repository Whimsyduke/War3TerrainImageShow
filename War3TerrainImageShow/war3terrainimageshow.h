#ifndef WAR3TERRAINIMAGESHOW_H
#define WAR3TERRAINIMAGESHOW_H

#include <QtWidgets/QMainWindow>
#include "ui_war3terrainimageshow.h"
#include "War3MapLibrary\include\War3MapEnvironment.h"
#include "War3MapLibrary\include\War3SLKterrain.h"
#include "War3MapLibrary\include\War3TerrainTexture.h"

class War3TerrainImageShow : public QMainWindow
{
	Q_OBJECT

public:
	War3TerrainImageShow(QWidget *parent = 0);
	~War3TerrainImageShow();
public slots:
	void addSingleTexture();
	void addAllTexture();

private:
	Ui::War3TerrainImageShowClass ui;
	QGraphicsScene scene;
	LibraryWar3Map::War3SLK<LibraryWar3Map::War3SLKterrainStruct> war3TerrainData;
	LibraryWar3Map::War3MapEnvironment war3Environment;
	LibraryWar3Map::War3TerrainTexture war3Texture;
};

#endif // WAR3TERRAINIMAGESHOW_H
