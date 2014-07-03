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
#include <QJsonObject>
#include <QJsonArray>
#include <iterator>

#include <QDebug>

class SAVCWidget: public QWidget
{
    Q_OBJECT

private:
    //breaker
    QTableWidget *breakerTable;

    //tps
    QLabel *tp1Label;
    QLineEdit *tp1LineEdit;
    QLabel *tp2Label;
    QLineEdit *tp2LineEdit;

    //trafos
    QTableWidget *trafoTable;

    void UpdateBreakerTable(QJsonObject jsonBreakers);
    void UpdateBuses(QJsonObject jsonBuses);
    void UpdateTrafos(QJsonObject jsonTrafos);

public:
    SAVCWidget();
    ~SAVCWidget();

    void setupUi(QWidget *mainWindow);

    //supervisao
    //add equips
    void supervisaoAddTP(QTabWidget *mainTab);
    void supervisaoAddBreakers(QTabWidget *mainTab);
    void supervisaoAddTrafos(QTabWidget *mainTab);

public slots:
    //void savcUpdateData(const QJsonObject &receivedData);
    void savcUpdateData(QJsonObject receivedData);
};

#endif // SAVCWIDGET_H
