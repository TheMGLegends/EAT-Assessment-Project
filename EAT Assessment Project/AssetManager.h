#pragma once

#include "Singleton.h"

class AssetManager : public Singleton<AssetManager>
{
public:
	void Clean() override;
};

