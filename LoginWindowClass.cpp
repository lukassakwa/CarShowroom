#include "LoginWindowClass.h"
#include "ui_LoginWindowClass.h"

LoginWindowClass::LoginWindowClass(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LoginWindowClass();
	ui->setupUi(this);

	loginLineEdit = ui->loginLineEdit;
	passwordLineEdit = ui->passwordLineEdit;
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	loginPushButton = ui->loginPushButton;

	this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

	loginController = NULL;

	connect(loginPushButton, SIGNAL(clicked()), this, SLOT(submit()));
}

LoginWindowClass::~LoginWindowClass()
{
	delete ui;
}

void LoginWindowClass::closeEvent(QCloseEvent* event)
{
	//Przy zamykaniu okna uruchamia sie sygnal ktory wywoluje funkcje ze slotu z Main Window
	emit BackToMainWindow();
}

void LoginWindowClass::submit(){
	loginController = new LoginController();

	//Przypisywanie do modelu wartosci z pol
	LoginModel model;
	model.login = loginLineEdit->text();
	//Przypisuje zahaszowane haslo do pola hasla 
	model.password = QString("%1").arg(QString(QCryptographicHash::hash(passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha1).toHex()));
	
	//Operacje na danych
	loginController->setUserModel(model);
	loginController->SelectData();
	loginModel = loginController->getUserOutputModel();

	//Sprawdzanie czy login i haslo sa poprawne
	if(loginModel.login == model.login && loginModel.password == model.password){
		this->close();
		emit LoginSucces();
	}else{
		//Pop okno z nie zalogowaniem sie
	}

	delete loginController;
}