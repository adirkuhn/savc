#include "SAVCWidget.h"

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
