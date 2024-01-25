#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setValues()
{
    for(int i = 0; i < namesOfGroups.length(); i++)
    {
        QSettings settings("MOTIONS.ini", QSettings::IniFormat);
        //Присваивание значений из файла
        settings.beginGroup(namesOfGroups[i]);
        nameOfValues = settings.childGroups();
        for(QString &group : settings.childGroups())
        {
            settings.beginGroup(group);
            QStringList list_of_keys = settings.childKeys();
            if (i == 0)
                initialReceiverValues.append(settings.value(list_of_keys[1]).toString());
            else if(i == 1)
                initialSourceValues.append(settings.value(list_of_keys[1]).toString());
            else if (i == 2)
                initialMotionValues.append(settings.value(list_of_keys[1]).toString());
            else if (i == 3)
                initialSensorsValues.append(settings.value(list_of_keys[1]).toString());
            else if (i == 4)
                initialProgrammValues.append(settings.value(list_of_keys[1]).toString());
            settings.endGroup();
        }
        settings.endGroup();
    }
}

void MainWindow::displayTable()
{
    for(int i = 0; i < namesOfGroups.length(); i++)
    {
        if(ui->listOfGroups->currentText() == namesOfGroups[i])
        {
            QSettings settings("MOTIONS.ini", QSettings::IniFormat);
            //Присваивание значений из файла
            settings.beginGroup(namesOfGroups[i]);
            nameOfValues = settings.childGroups();
            for(QString &group : settings.childGroups())
            {
                settings.beginGroup(group);
                QStringList list_of_keys = settings.childKeys();
                if(changeOfReceiver == false || changeOfSource == false || changeOfMotion == false || changeOfSensors == false || changeOfProgramm == false)
                {
                    values.append(settings.value(list_of_keys[1]).toString());
                }
                typeOfAcces.append(settings.value(list_of_keys[0]).toString());
                settings.endGroup();
            }
            settings.endGroup();
            //Конец

            //Установка горизонтального заголовка "Значения"
            ui->tableWidget->setColumnCount(1);
            horizontalTableHeader.append("Значения");
            ui->tableWidget->setHorizontalHeaderLabels(horizontalTableHeader);
            //Конец

            //Установка вертикальных заголовков
            ui->tableWidget->setRowCount(nameOfValues.length());
            ui->tableWidget->setVerticalHeaderLabels(nameOfValues);
            //Конец

            //Центровка текста вертикальных заголовков
            for(int i = 0; i < ui->tableWidget->rowCount(); i++)
            {
                ui->tableWidget->verticalHeaderItem(i)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            }
            //Конец

            //Заполнение ячеек таблицы значениями из файла, установка класса допуска к переменным файла
            for(int i = 0; i < nameOfValues.length(); i++)
            {
                if(changeOfReceiver == false || changeOfSource == false || changeOfMotion == false || changeOfSensors == false || changeOfProgramm == false)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(values[i]);
                    ui->tableWidget->setItem(i,0,item);
                    if(typeOfAcces[i] == "ReadOnly")
                    {
                        ui->tableWidget->item(i,0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                    }
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }

                if(ui->listOfGroups->currentText() == "RECEIVER" && changeOfReceiver == true)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(temperaryReceiverValues[i]);
                    ui->tableWidget->setItem(i,0,item);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }

                else if(ui->listOfGroups->currentText() == "SOURCE" && changeOfSource == true)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(temperarySourceValues[i]);
                    ui->tableWidget->setItem(i,0,item);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }

                else if(ui->listOfGroups->currentText() == "MOTION" && changeOfMotion == true)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(temperaryMotionValues[i]);
                    ui->tableWidget->setItem(i,0,item);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }

                else if(ui->listOfGroups->currentText() == "SENSORS" && changeOfSensors == true)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(temperarySensorsValues[i]);
                    ui->tableWidget->setItem(i,0,item);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }

                else if(ui->listOfGroups->currentText() == "PROGRAMM" && changeOfProgramm == true)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(temperaryProgrammValues[i]);
                    ui->tableWidget->setItem(i,0,item);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }

                if(typeOfAcces[i] == "ReadOnly")
                {
                    ui->tableWidget->item(i,0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                }
            }
            //Конец
        }
    }
}

void MainWindow::setValuesInFile(int i, QSettings *settingsFile, bool changeSignal, QStringList keysNamesOfValue, QStringList temperaryValues, QStringList initialValues)
{
    if(changeSignal)
        settingsFile->setValue(keysNamesOfValue[1],temperaryValues[i]);
    else
        settingsFile->setValue(keysNamesOfValue[1],initialValues[i]);
}
