#pragma once

//GUI
#include "ui_LoginWindowClass.h"
#include "QtStartWindowClass.h"

//Login Controller
#include "LoginController.h"

//Widgety
#include <QWidget>
#include <QLineEdit>
#include "QtAdminPanel.h"

namespace Ui { class LoginWindowClass; };

class LoginWindowClass : public QWidget
{
	Q_OBJECT

public:
	LoginWindowClass(QWidget *parent = Q_NULLPTR);
	~LoginWindowClass();

private slots:
	void submit();

signals:
	//signal wysylany do Main Window jak zamkniemy okno
	void BackToMainWindow();
	//Signal wysylany do Main Window jak logowanie zakonczy sie sukcesem
	void LoginSucces();

private:
	void closeEvent(QCloseEvent* event);

private:
	Ui::LoginWindowClass *ui;

	QLineEdit* loginLineEdit;
	QLineEdit* passwordLineEdit;
	QPushButton* loginPushButton;

	LoginController* loginController;
	LoginModel loginModel;
};
