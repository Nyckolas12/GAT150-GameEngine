#include "CharacterComponent.h"
#include "Engine.h"


FACTORY_REGISTER(CharacterComponent)

void CharacterComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&CharacterComponent::OnCollisionEnter, this, std::placeholders::_1);
}

void CharacterComponent::Update(float dt)
{
	

	float rotate = 0;
	float thrust = 0;

	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;
	owner->GetComponent<PhysicsComponent>()->ApplyTorque(rotate * 90 * dt);
	Vector2 direction = Vector2 { 1,0 }.Rotate(Math::DegToRad(owner->transform.rotation));
	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed * thrust);

		if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
		{
			auto rocket = Factory::Instance().Create<Actor>("rocket");
			rocket->transform.position = owner->transform.position;
			rocket->transform.rotation = owner->transform.rotation;
			owner->scene->AddActor(std::move(rocket), true);

		}
}

void CharacterComponent::Read(const json_t& value)
{
}

void CharacterComponent::Write(json_t& value)
{
}

void CharacterComponent::OnCollisionEnter(Actor*)
{
	EVENT_NOTIFY("PlayerDead")
	EventSystem::Instance().Notify({ "AddPoints", 100 });
	
}
