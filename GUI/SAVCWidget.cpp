/****************************************************************************
** Meta object code from reading C++ file 'SAVCWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SAVCWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SAVCWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SAVCWidget_t {
    QByteArrayData data[4];
    char stringdata[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SAVCWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SAVCWidget_t qt_meta_stringdata_SAVCWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12)
    },
    "SAVCWidget\0savcUpdateData\0\0receivedData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SAVCWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,

       0        // eod
};

void SAVCWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SAVCWidget *_t = static_cast<SAVCWidget *>(_o);
        switch (_id) {
        case 0: _t->savcUpdateData((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SAVCWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SAVCWidget.data,
      qt_meta_data_SAVCWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *SAVCWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SAVCWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SAVCWidget.stringdata))
        return static_cast<void*>(const_cast< SAVCWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SAVCWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE


SAVCWidget::SAVCWidget()
{
}

SAVCWidget::~SAVCWidget() {
    delete breakerTable;
    delete tp1Label;
    delete tp1LineEdit;
    delete tp2Label;
    delete tp2LineEdit;
}

void SAVCWidget::setupUi(QWidget *mainWindow) {


    //Layout Principal do SAVC
    QGridLayout *mainLayout = new QGridLayout;


    //Layout de Supervisao
    QTabWidget *supervisaoTabs = new QTabWidget;

    //Add equipamentos
   supervisaoAddTP(supervisaoTabs);
   supervisaoAddBreakers(supervisaoTabs);
   supervisaoAddTrafos(supervisaoTabs);

    //Adiciona tabs no layout principal
    mainLayout->addWidget(supervisaoTabs, 0, 0);
    //mainLayout->addWidget(barras,0,1);


    //Seta Layout principal na janela
    mainWindow->setLayout(mainLayout);
}

void SAVCWidget::supervisaoAddTP(QTabWidget *mainTab) {

    //TP Layout
    QGridLayout *tpMainLayout = new QGridLayout;
    QGroupBox *tpBox = new QGroupBox;

    //tp1
    this->tp1Label = new QLabel("Barra 1");
    this->tp1LineEdit = new QLineEdit("550kv");

    tpMainLayout->addWidget(tp1Label, 0, 0);
    tpMainLayout->addWidget(tp1LineEdit, 0, 1, 1, 2);


    //tp2
    tp2Label = new QLabel("Barra 2");
    tp2LineEdit = new QLineEdit("200kv");

    tpMainLayout->addWidget(tp2Label, 1, 0);
    tpMainLayout->addWidget(tp2LineEdit, 1, 1, 1, 2);

    //add tab
    tpBox->setLayout(tpMainLayout);
    mainTab->addTab(tpBox, "Barra");
}

void SAVCWidget::supervisaoAddBreakers(QTabWidget *mainTab) {

    //Breaker Layout
    QGroupBox *breakerBox = new QGroupBox;
    QHBoxLayout *breakerLayout = new QHBoxLayout;
    breakerTable = new QTableWidget;

    //populate table
    breakerTable->insertColumn(0);
    breakerTable->insertColumn(1);

    breakerTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Breaker"));
    breakerTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Status"));

    for(int i=0; i<10; i++) {
        breakerTable->insertRow(i);

        breakerTable->setItem(i, 0, new QTableWidgetItem(QString("Breaker %1").arg(i)));
        breakerTable->setItem(i, 1, new QTableWidgetItem("Closed"));
    }

    breakerLayout->addWidget(breakerTable);

    //add tab
    breakerBox->setLayout(breakerLayout);
    mainTab->addTab(breakerBox, "Breakers");

}

void SAVCWidget::supervisaoAddTrafos(QTabWidget *mainTab) {

    //Trafo layout
    QHBoxLayout *trafoLayout = new QHBoxLayout;
    QGroupBox *trafoBox = new QGroupBox;
    trafoTable = new QTableWidget;

    QList<QString> *headers = new QList<QString>;
    headers->append("Nome");
    headers->append("EndPosL");
    headers->append("EndPosR");
    headers->append("LTCMvm");
    headers->append("LTCMod");
    headers->append("LTCCycAlm");
    headers->append("TapPos");
    headers->append("Loc");

    //populate table
    for (int i=0; i<8; i++) {
        trafoTable->insertColumn(i);
        trafoTable->setHorizontalHeaderItem(i, new QTableWidgetItem(headers->at(i)));
    }


    trafoLayout->addWidget(trafoTable);

    trafoBox->setLayout(trafoLayout);

    //add tab
    mainTab->addTab(trafoBox, "Trafos");
}

//SLot para atualizacao de dados na tela
void SAVCWidget::savcUpdateData(QJsonObject receivedData) {
    qDebug() << receivedData.keys();

    qDebug() << "TODO: Atualizar dados breaker";
    this->UpdateBreakerTable(receivedData["breakers"].toObject());

    qDebug() << "TODO: Atualizar dados Barras (TPs)";
    this->UpdateBuses(receivedData["buses"].toObject());

    qDebug() << "TODO: Atualizar dados Trafos";
    this->UpdateTrafos(receivedData["trafos"].toObject());
}

//Atualiza dados do breaker
void SAVCWidget::UpdateBreakerTable(QJsonObject jsonBreakers) {
    qDebug() << "TODO: UpdateBreakerTable (remover debug)";

    //clear rows
    this->breakerTable->setRowCount(0);

    //populate rows with new and fresh data
    int rowCount = 0;
    for(QJsonObject::iterator it = jsonBreakers.begin(); it != jsonBreakers.end(); it++) {

        //set new table
        this->breakerTable->insertRow(rowCount);
        this->breakerTable->setItem(rowCount, 0, new QTableWidgetItem(QString("%1").arg(it.key())));
        this->breakerTable->setItem(rowCount, 1, new QTableWidgetItem(QString("%1").arg(it.value().toInt())));
        rowCount++;
    }
}

//Atualiza Dados das barras (TPs)
void SAVCWidget::UpdateBuses(QJsonObject jsonBuses) {

    QString label;
    QString value;

    qDebug() << "TODO: UpateBuses (remove debug)";

    for(QJsonObject::iterator it = jsonBuses.begin(); it != jsonBuses.end(); it++) {

        label = QString("Barra (%1)").arg(it.key());
        value = QString("%1").arg(it.value().toInt());

        //tp1
        if(it.key().endsWith("220kV")) {
            this->tp1Label->setText(label);
            this->tp1LineEdit->setText(value);
        }
        //tp2
        else {
            this->tp2Label->setText(label);
            this->tp2LineEdit->setText(value);
        }
    }
}

//Atualiza dados do trafo
void SAVCWidget::UpdateTrafos(QJsonObject jsonTrafos) {

    qDebug() << "TODO: UpdateTrafos";

    //clear rows
    this->trafoTable->setRowCount(0);

    //populate rows with new and fresh data
    int rowCount = 0;
    for(QJsonObject::iterator it = jsonTrafos.begin(); it != jsonTrafos.end(); it++) {

        QJsonObject itemTrafo = it.value().toObject();
        QString endPosL, endPosR;

        endPosL = (itemTrafo["endposl"] == true)? "true" : "false";
        endPosR = (itemTrafo["endposr"] == true)? "true" : "false";

        //set new table
        this->trafoTable->insertRow(rowCount);
        //name
        this->trafoTable->setItem(rowCount, 0, new QTableWidgetItem(QString("%1").arg(it.key())));

        //endPosL
        this->trafoTable->setItem(rowCount, 1, new QTableWidgetItem(endPosL));

        //endPosR
        this->trafoTable->setItem(rowCount, 2, new QTableWidgetItem(endPosR));

        //tapPos
        this->trafoTable->setItem(rowCount, 6, new QTableWidgetItem(QString("%1").arg(itemTrafo["pos"].toInt())));

        rowCount++;
    }
}
