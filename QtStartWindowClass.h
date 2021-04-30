#pragma once

#include "qtCarShowroom.h"
#include "LoginWindowClass.h"
#include "QtAdminPanel.h"

#include <QWidget>
#include <QPushButton>

namespace Ui { class QtStartWindowClass; };

class QtStartWindowClass : public QWidget
{
	Q_OBJECT

public:
	QtStartWindowClass(QWidget *parent = Q_NULLPTR);
	~QtStartWindowClass();

private slots:
	//Funkcja wywolywana gdy dostaniemy emit z QtAdminPanel albo LohinWindowClass
	void BackFromSubPages();
	//Funkcja wywolywana jak logowanie w oknie Login Window zakonczy sie sukcesem
	void Login();
	//Funkcja wywolywana gdy wcisniemy przycisk Admin Panel
	void openAdminPanel();
	//Funkcja wywolana gdy wcisniemy User Panel
	void openUserPanel();

private:
	void connections();

private:
	Ui::QtStartWindowClass *ui;

	QPushButton *userPanelPushButton;
	QPushButton *adminPanelPushButton;
};
