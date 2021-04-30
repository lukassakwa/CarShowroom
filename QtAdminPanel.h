#pragma once

//Admin Controller
#include "AdminController.h"

//Widgety
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

namespace Ui { class QtAdminPanel; };

class QtAdminPanel : public QWidget
{
	Q_OBJECT

public:
	QtAdminPanel(QWidget *parent = Q_NULLPTR);
	~QtAdminPanel();

signals:
	//signal wysylany do Main Window jak zamkniemy okno
	void BackToMainWindow();

private slots:
	void addOnClick();
	void updateOnClick();
	void deleteOnClick();

private:
	void closeEvent(QCloseEvent* event);
	void connections();

private:
	Ui::QtAdminPanel *ui;

	//Dodac wskazniki na widgety
	QLineEdit* carBrandLineEdit;
	QLineEdit* carModelLineEdit;
	QSpinBox* enginePowerSpinBox;
	QSpinBox* carBodySpinBox;
	QDoubleSpinBox* fuelConsumptionSpinDoubleBox;
	QSpinBox* carPriceSpinBox;

	QPushButton* addPushButton;
	QPushButton* updatePushButton;
	QPushButton* deletePushButton;

	//Controller
	AdminController* adminController;
	CarModel carModel;
};
