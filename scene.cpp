#include "scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent), gridSize(20)
{
    Q_ASSERT(gridSize > 0);
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
        QColor c (10,140,255,155);
        painter->setPen(c);
        qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
        qreal top = int(rect.top()) - (int(rect.top()) % gridSize);
        QVarLengthArray<QLineF,100> lines;
        for (qreal x = left; x < rect.right(); x += gridSize)
            lines.append(QLineF(x,rect.top(),x,rect.bottom()));

        for (qreal y = top; y < rect.bottom(); y += gridSize)
            lines.append(QLineF(rect.left(),y,rect.right(),y));
        painter->drawLines(lines.data(),lines.size());
}
