#pragma once

#include "Singleton.h"

class TimeManager : public Singleton<TimeManager>
{
public:
	void Clean() override;
};

