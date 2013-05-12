#include <QTreeWidget>
#include "readingsui.h"
#include "readings.h"

void ReadingsUI::init(QTreeWidget* treeWidget)
{
    treeWidget->setColumnCount(2);

    treeWidget->setColumnWidth(0, treeWidget->width() * 0.6);
    treeWidget->setColumnWidth(1, treeWidget->width() * 0.35);

    QTreeWidgetItem* world = new QTreeWidgetItem((QTreeWidget*)NULL, QStringList("World") );
    QTreeWidgetItem* object = new QTreeWidgetItem((QTreeWidget*)NULL, QStringList("Object") );
    QTreeWidgetItem* leap  = new QTreeWidgetItem((QTreeWidget*)NULL, QStringList("Leap") );

    treeWidget->insertTopLevelItem(0, leap);
    treeWidget->insertTopLevelItem(0, object);
    treeWidget->insertTopLevelItem(0, world);

    itemWorldSize = new QTreeWidgetItem(world, QStringList("Size:"));
    itemWorldFill = new QTreeWidgetItem(world, QStringList("Fill:"));

    itemObjectSizeAbs = new QTreeWidgetItem(object, QStringList("Size(abs):"));
    itemObjectSizeRel = new QTreeWidgetItem(object, QStringList("Size(rel):"));

    itemLeapFrom = new QTreeWidgetItem(leap, QStringList("From:"));
    itemLeapTo = new QTreeWidgetItem(leap, QStringList("To:"));
    itemLeapDistance = new QTreeWidgetItem(leap, QStringList("Distance:"));
    itemLeapDifMax = new QTreeWidgetItem(leap, QStringList("Dif max.:"));
    itemLeapDifRoot = new QTreeWidgetItem(leap, QStringList("Dif root:"));
    itemLeapDifK = new QTreeWidgetItem(leap, QStringList("Dif coef.:"));
    itemLeapRootInvar = new QTreeWidgetItem(leap, QStringList("Root invar:"));
    itemLeapType = new QTreeWidgetItem(leap, QStringList("Leap type:"));

    treeWidget->expandAll();
}


void ReadingsUI::update(const Readings& readings)
{
    itemWorldSize->setText(1, QString("%1 x %2").arg(readings.worldWidth).arg(readings.worldHeight));
    itemWorldFill->setText(1, QString::number(readings.worldFill));

    itemObjectSizeAbs->setText(1, QString::number(readings.objectSizeAbs));
    itemObjectSizeRel->setText(1, QString("%1%").arg(readings.objectSizeRel));

    itemLeapFrom->setText(1, QString::number(readings.leapFrom));
    itemLeapTo->setText(1, QString::number(readings.leapTo));
    itemLeapDistance->setText(1, QString::number(readings.leapDistance));

    itemLeapDifMax->setText(1, QString::number(readings.leapDifMax));
    itemLeapDifRoot->setText(1, QString::number(readings.leapDifRoot));
    itemLeapDifK->setText(1, QString::number(readings.leapDifK));
    itemLeapRootInvar->setText(1, QString::number(readings.leapRootInvar));

    QString leapType;
    switch(readings.leapType)
    {
      case 0: leapType = "-"; break;
      case 1: leapType = "(1) observe"; break;
      case 2: leapType = "(2) change"; break;
      case 3: leapType = "(3) paradox"; break;
    };
    itemLeapType->setText(1, leapType);
}
