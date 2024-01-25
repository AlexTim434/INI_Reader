#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QSettings>
#include <QVariant>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QWidget>
#include <QTableWidget>
#include <QKeyEvent>
#include <QBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QHeaderView>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setValues();
    void displayTable();
    void setValuesInFile(int i, QSettings *settingsFile, bool changeSignal, QStringList keysNamesOfValue, QStringList temperaryValues, QStringList initialValues);

private slots:
    void on_save_action_triggered();

    void on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

    void on_listOfGroups_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStringList nameOfValues;
    QStringList values; //временная переменная, необходимая для записи значений в таблицу
    QStringList horizontalTableHeader;
    QStringList typeOfAcces; //тип доступа к переменной в INI файле
    QStringList namesOfGroups = {"RECEIVER","SOURCE","MOTION","SENSORS","PROGRAMM"};
    //Буфер-обмена для разных групп
    QStringList temperaryReceiverValues,temperarySourceValues,temperaryMotionValues,temperarySensorsValues,temperaryProgrammValues;
    //Хранение значений из файла для разных групп
    QStringList initialReceiverValues,initialSourceValues,initialMotionValues,initialSensorsValues,initialProgrammValues;
    bool changeOfReceiver = false,changeOfSource = false,changeOfMotion = false ,changeOfSensors = false,changeOfProgramm = false;
};
#endif // MAINWINDOW_H
