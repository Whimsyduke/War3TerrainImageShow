#ifndef QBLPIMAGE_H
#define QBLPIMAGE_H
#include <QPixmap.h>
class QBlpImage
{
public:
	QBlpImage();
	~QBlpImage();

private:
	QPixmap imageData;
};

#endif //QBLPIMAGE_H