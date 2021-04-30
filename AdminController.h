#pragma once

#include "AdminRepository.h"
#include "CarModel.h"

class AdminController : public AdminRepository
{
public:
	AdminController();
	~AdminController();

	// Inherited via AdminRepository
	virtual void InsertData() override;
	virtual void UpdateData() override;
	virtual void DeleteData() override;

private:
	CarModel carModel;
	bool operation;
};

