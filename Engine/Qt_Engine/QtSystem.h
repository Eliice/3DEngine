#pragma once
#include <QWidget>
#include "system.h"
class QtSystem :
	public System
{
public:
	QtSystem();
	virtual ~QtSystem();

	virtual void Initialize() override;
};

