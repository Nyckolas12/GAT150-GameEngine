#include "PlayerComponent.h"
#include "Engine.h"

void PlayerComponent::Initialize()
{
}

void PlayerComponent::Update(float dt)
{
	Vector2 direction{ 0,0 };
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.x = -1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.x = 1;
		owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * 100);
}

void PlayerComponent::Read(const json_t& value)
{
}

void PlayerComponent::Write(json_t& value)
{
}