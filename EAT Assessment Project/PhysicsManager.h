#pragma once

#include "Singleton.h"

class PhysicsManager : public Singleton<PhysicsManager>
{
public:
	void Clean() override;
};

