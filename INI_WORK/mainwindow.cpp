#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayTable();

    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection); //отключить выделение заголовка в QTableWidget
    ui->tableWidget->setCornerButtonEnabled(false); //отключить верхнюю левую кнопку, что нужна для выделения всех строк и столбцов
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_save_action_triggered()
{
    QSettings *settings = new QSettings("MOTIONS.ini", QSettings::IniFormat);
    setValues();
    for(int j = 0; j < namesOfGroups.length(); j++)
    {
        settings->beginGroup(namesOfGroups[j]);
        QStringList child_groups_1 = settings->childGroups();
        for(int i = 0; i < child_groups_1.length(); i++)
        {
            settings->beginGroup(child_groups_1[i]);
            QStringList child_groups_2 = settings->childKeys();
            if (j == 0)
            setValuesInFile(i,settings,changeOfReceiver,child_groups_2,temperaryReceiverValues,initialReceiverValues);
            else if (j == 1)
            setValuesInFile(i,settings,changeOfSource,child_groups_2,temperarySourceValues,initialSourceValues);
            else if (j == 2)
            setValuesInFile(i,settings,changeOfMotion,child_groups_2,temperaryMotionValues,initialMotionValues);
            else if (j == 3)
            setValuesInFile(i,settings,changeOfSensors,child_groups_2,temperarySensorsValues,initialSensorsValues);
            else if (j == 4)
            setValuesInFile(i,settings,changeOfProgramm,child_groups_2,temperaryProgrammValues,initialProgrammValues);
            settings->endGroup();
        }
        settings->endGroup();
    }
    delete settings;
}

void MainWindow::on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
    temperaryReceiverValues.clear();
    temperarySourceValues.clear();
    temperaryMotionValues.clear();
    temperarySensorsValues.clear();
    temperaryProgrammValues.clear();

    if(ui->listOfGroups->currentText() == "RECEIVER")
    {
        changeOfReceiver = true;
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        temperaryReceiverValues.append(ui->tableWidget->item(i,0)->text());
    }
    else if(ui->listOfGroups->currentText() == "SOURCE")
    {
        changeOfSource = true;
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        temperarySourceValues.append(ui->tableWidget->item(i,0)->text());
    }
    else if(ui->listOfGroups->currentText() == "MOTION")
    {
        changeOfMotion = true;
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        temperaryMotionValues.append(ui->tableWidget->item(i,0)->text());
    }
    else if(ui->listOfGroups->currentText() == "SENSORS")
    {
        changeOfSensors = true;
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        temperarySensorsValues.append(ui->tableWidget->item(i,0)->text());
    }
    else if(ui->listOfGroups->currentText() == "PROGRAMM")
    {
        changeOfProgramm = true;
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        temperaryProgrammValues.append(ui->tableWidget->item(i,0)->text());
    }
}

void MainWindow::on_listOfGroups_currentTextChanged(const QString &arg1)
{
    displayTable();
    values.clear();
    typeOfAcces.clear();
    nameOfValues.clear();
}
