#pragma once

#include "DatabaseController.h"

class UserRepository : public DatabaseController{
protected:
	UserRepository();
	~UserRepository();
public:
	virtual void SelectData() = 0;
};