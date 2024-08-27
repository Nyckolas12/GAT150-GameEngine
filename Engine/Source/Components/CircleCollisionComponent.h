#pragma once
#include "CollisionComponents.h"

class CircleCollisionComponent : public CollisionComponent
{
public:
	void Initialize() override;
	void Update(float dt) override;
	bool CheckCollision(const CollisionComponent* collision) override;
	CLASS_DECLARATION(CircleCollisionComponent)
	CLASS_PROTOTYPE(CircleCollisionComponent)

public:
	float radius = 0;

};