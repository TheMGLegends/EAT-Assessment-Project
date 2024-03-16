#pragma once

#include "Singleton.h"

class CollisionManager : public Singleton<CollisionManager>
{
public:
	void Clean() override;
};

