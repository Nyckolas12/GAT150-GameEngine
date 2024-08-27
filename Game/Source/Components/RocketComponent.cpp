#include "RocketComponent.h"
#include "Engine.h"


FACTORY_REGISTER(RocketComponent)

void RocketComponent::Initialize()
{
}

void RocketComponent::Update(float dt)
{
	owner->GetComponent<PhysicsComponent>()->SetVelocity(owner->transform.Forward() * speed);
}

void RocketComponent::Read(const json_t& value)
{
}

void RocketComponent::Write(json_t& value)
{
}