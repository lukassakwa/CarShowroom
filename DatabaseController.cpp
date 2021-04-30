#include "DatabaseController.h"

DatabaseController::DatabaseController(){
	qSqlDatabase = &QSqlDatabase::addDatabase(sqlDriver);
	qSqlDatabase->setHostName(host);
	qSqlDatabase->setPort(port);
	qSqlDatabase->setDatabaseName(database);
	qSqlDatabase->setUserName(username);
	qSqlDatabase->setPassword(password);

	if (!qSqlDatabase->open()) {
		qDebug("Failed to connect to root mysql admin");
		exit(-1);
	}
	qDebug("Connection success");
}

DatabaseController::~DatabaseController(){
	{
		QSqlDatabase* db = &QSqlDatabase::database();
		db->close();
	}
	QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
	qDebug("Connection close");
}