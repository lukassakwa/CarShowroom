#include "LoginController.h"

LoginController::LoginController() : UserRepository()
{
	table = "admin";
}

LoginController::~LoginController()
{
}

void LoginController::SelectData()
{
	QSqlQuery* query = new QSqlQuery();
	query->prepare(QString("SELECT * FROM %1 WHERE login=:login AND password<=:password;").arg(table));
	query->bindValue(":login", userInputModel.login);
	query->bindValue(":password", userInputModel.password);

	if (!query->exec())
	{
		qDebug() << "SQL error: " << query->lastError();
	}

	while(query->next()){
		userOutputModel.login = query->value(1).toString();
		userOutputModel.password = query->value(2).toString();
	}

	query = NULL;
}

void LoginController::setUserModel(LoginModel userModel)
{
	this->userInputModel = userModel;
}

LoginModel LoginController::getUserOutputModel()
{
	return this->userOutputModel;
}
