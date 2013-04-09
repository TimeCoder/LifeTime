///////////////////////////////////////////////////////////////////////////////
//  ReadingsUI - визуальное представление рабочих данных от МВ
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
///////////////////////////////////////////////////////////////////////////////
#ifndef READINGSUI_H
#define READINGSUI_H

class Readings;
class QTreeWidget;
class QTreeWidgetItem;

struct ReadingsUI
{
    QTreeWidgetItem* itemWorldSize;
    QTreeWidgetItem* itemWorldFill;

    QTreeWidgetItem* itemObjectSizeAbs;
    QTreeWidgetItem* itemObjectSizeRel;

    QTreeWidgetItem* itemLeapFrom;
    QTreeWidgetItem* itemLeapTo;
    QTreeWidgetItem* itemLeapDistance;

    QTreeWidgetItem* itemLeapDifMax;
    QTreeWidgetItem* itemLeapDifRoot;
    QTreeWidgetItem* itemLeapDifFade;
    QTreeWidgetItem* itemLeapRootInvar;
    QTreeWidgetItem* itemLeapType;

    void init(QTreeWidget* treeWidget);
    void update(const Readings& readings);
};

#endif // READINGSUI_H
