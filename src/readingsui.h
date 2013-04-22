///////////////////////////////////////////////////////////////////////////////
//  ReadingsUI - view of time machine data
//
//  Project: "LifeTime"
//  Autor: Zimaev Igor (i.zimaev@timeacademy.ru)
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
