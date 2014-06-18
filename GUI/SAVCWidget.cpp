#include "SAVCWidget.h"

SAVCWidget::SAVCWidget()
{
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
    QLabel *tp1Label = new QLabel("Barra 1");
    QLineEdit *tp1LineEdit = new QLineEdit("550kv");

    tpMainLayout->addWidget(tp1Label, 0, 0);
    tpMainLayout->addWidget(tp1LineEdit, 0, 1, 1, 2);


    //tp2
    QLabel *tp2Label = new QLabel("Barra 2");
    QLineEdit *tp2LineEdit = new QLineEdit("200kv");

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
    QTableWidget *breakerTable = new QTableWidget;

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
    QTableWidget *trafoTable = new QTableWidget;

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
