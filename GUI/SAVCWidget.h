#ifndef SAVCWIDGET_H
#define SAVCWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QTabWidget>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QHBoxLayout>

class SAVCWidget: public QWidget
{
    //Q_OBJECT
public:
    SAVCWidget();

    void setupUi(QWidget *mainWindow);

    //supervisao
    //add equips
    void supervisaoAddTP(QTabWidget *mainTab);
    void supervisaoAddBreakers(QTabWidget *mainTab);
    void supervisaoAddTrafos(QTabWidget *mainTab);
};

#endif // SAVCWIDGET_H
