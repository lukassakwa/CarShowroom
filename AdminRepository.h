#pragma once

#include "DatabaseController.h"

class AdminRepository : public DatabaseController
{
protected:
	AdminRepository();
	~AdminRepository();
public:
	//virtual void SelectData() = 0;
	virtual void InsertData() = 0;
	virtual void UpdateData() = 0;
	virtual void DeleteData() = 0;
};

