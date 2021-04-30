#include "QtAdminPanel.h"
#include "ui_QtAdminPanel.h"

QtAdminPanel::QtAdminPanel(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::QtAdminPanel();
	ui->setupUi(this);

	//Dodac widgety
	carModelLineEdit = ui->carModelLineEdit;
	carBrandLineEdit = ui->carBrandLineEdit;
	enginePowerSpinBox = ui->enginePowerSpinBox;
	carBodySpinBox = ui->carBodySpinBox;
	fuelConsumptionSpinDoubleBox = ui->fuelConsumptionDoubleSpinBox;
	carPriceSpinBox = ui->carPricespinBox;

	addPushButton = ui->addPushButton;
	updatePushButton = ui->modifyPushButton;
	deletePushButton = ui->deletePushButton;

	this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

	connections();
}

QtAdminPanel::~QtAdminPanel()
{
	delete ui;
}

void QtAdminPanel::addOnClick(){
	
}

void QtAdminPanel::updateOnClick(){

}

void QtAdminPanel::deleteOnClick(){

}

void QtAdminPanel::closeEvent(QCloseEvent* event)
{
	//Przy zamykaniu okna uruchamia sie sygnal ktory wywoluje funkcje ze slotu z Main Window
	emit BackToMainWindow();
}

void QtAdminPanel::connections()
{
	connect(addPushButton, SIGNAL(clicked()), this, SLOT(addOnClick()));
	connect(updatePushButton, SIGNAL(clicked()), this, SLOT(updateOnClick()));
	connect(deletePushButton, SIGNAL(clicked()), this, SLOT(deleteOnClick()));
}
