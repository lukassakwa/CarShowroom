#pragma once

//GUI
#include <QtWidgets/QMainWindow>
#include "ui_qtCarShowroom.h"

//Car Controller
#include "CarController.h"

//Widgety
#include <QSpinBox>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QLineEdit>

class qtCarShowroom : public QMainWindow
{
    Q_OBJECT

public:
    qtCarShowroom(QWidget *parent = Q_NULLPTR);

private slots:
    //Funkcja wykonywana na sygnal wcisniecia klawisza dalej
    void clickedSearchButton();
    //Funkcja wykonywana jesli nacisniemy 2 razy na element listy
    void doubleClickedListView();
    //Funkcja wykonywana na sygnal wcisniecia przycisku dalej
    void clickedSubmitButton();

signals:
    //signal wysylany do Main Window jak zamkniemy okno
    void BackToMainWindow();
  
protected:
    void connections();

private:
    void closeEvent(QCloseEvent* event);

private:
    Ui::qtCarShowroomClass* ui;

    QListView* listView;
    QSpinBox* carBodySpinBox;
    QDoubleSpinBox* fuelConsumptionDoubleSpinBox;
    QSpinBox* enginePowerSpinBox;
    QSpinBox* carPriceSpinBox;
    QStringListModel* model;
    QPushButton* submitButton;
    QPushButton* nextButton;

    CarController* carController;
    CarModel* carModel;

    int carIndex;
    QVector<CarModel> cars;
};
