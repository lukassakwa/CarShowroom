#include "QtStartWindowClass.h"
#include "ui_QtStartWindowClass.h"

QtStartWindowClass::QtStartWindowClass(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::QtStartWindowClass();
	ui->setupUi(this);

	userPanelPushButton = ui->UserPanelPushButton;
	adminPanelPushButton = ui->AdminPanelPushButton;

	this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

	connections();
}

void QtStartWindowClass::connections() {
	connect(userPanelPushButton, SIGNAL(clicked()), this, SLOT(openUserPanel()));
	connect(adminPanelPushButton, SIGNAL(clicked()), this, SLOT(openAdminPanel()));
}

//Otwiera UserPanel
void QtStartWindowClass::openUserPanel() {
	qtCarShowroom* carShowroom = new qtCarShowroom();
	connect(carShowroom, &qtCarShowroom::BackToMainWindow, this, &QtStartWindowClass::BackFromSubPages);
	this->setDisabled(true);
	carShowroom->show();
}

//Admin Panle otwarty z mainWindow
//Laczy funkcje signal z LoginWindow z slotem BackFromLoginWindow z qtCarShowroom
void QtStartWindowClass::openAdminPanel() {
	LoginWindowClass* loginWindow = new LoginWindowClass();
	connect(loginWindow, &LoginWindowClass::BackToMainWindow, this, &QtStartWindowClass::BackFromSubPages);
	connect(loginWindow, &LoginWindowClass::LoginSucces, this, &QtStartWindowClass::Login);
	this->setDisabled(true);
	loginWindow->show();
}

void QtStartWindowClass::BackFromSubPages()
{
	this->setDisabled(false);
}

void QtStartWindowClass::Login()
{
	QtAdminPanel* qtAdminPanel = new QtAdminPanel();
	connect(qtAdminPanel, &QtAdminPanel::BackToMainWindow, this, &QtStartWindowClass::BackFromSubPages);
	this->setDisabled(true);
	qtAdminPanel->show();
}

QtStartWindowClass::~QtStartWindowClass()
{
	delete ui;
}
