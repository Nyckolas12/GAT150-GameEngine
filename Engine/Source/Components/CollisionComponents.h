#pragma once
#include "Components/Component.h"

class CollisionComponent : public Component
{
public:
	virtual bool CheckCollision(const CollisionComponent* colliion) = 0;
};