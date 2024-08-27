#include "Box2DPhysicsComponent.h"
#include "Engine.h"

FACTORY_REGISTER(Box2DPhysicsComponent)

Box2DPhysicsComponent::Box2DPhysicsComponent(const Box2DPhysicsComponent& other)
{
	rigidBodyDef = other.rigidBodyDef;
	size = other.size;
	//if (other.m_rigidBody)
	//{
	//	m_rigidBody = std::make_unique<RigidBody>(*other.m_rigidBody.get());
	//}
}

void Box2DPhysicsComponent::Initialize()
{
	rigidBodyDef.actor = owner;
	if (size.x == 0 && size.y == 0)
	{
		auto textureComponent = owner->GetComponent<TextureComponent>();
		size = Vector2{ textureComponent->source.width,textureComponent->source.height };
	}

	m_rigidBody = std::make_unique<RigidBody>(owner->transform, size, rigidBodyDef, owner->scene->engine->GetPhysics());
}

void Box2DPhysicsComponent::Update(float dt)
{
	owner->transform.position = m_rigidBody->GetPosition();
	owner->transform.rotation = m_rigidBody->GetAngle();
	velocity = m_rigidBody->GetVelocity();
}

void Box2DPhysicsComponent::ApplyForce(const Vector2& force)
{
	m_rigidBody->ApplyForce(force);
}

void Box2DPhysicsComponent::ApplyTorque(float torque)
{
	m_rigidBody->ApplyTorque(torque);
}

void Box2DPhysicsComponent::SetPosition(const Vector2& position)
{
	m_rigidBody->SetTransform(position, m_rigidBody->GetAngle());
}

void Box2DPhysicsComponent::SetVelocity(const Vector2& velocity)
{
	m_rigidBody->SetVelocity(velocity);
}

void Box2DPhysicsComponent::Read(const json_t& value)
{
Json::Read(value, "gravityScale", rigidBodyDef.gravityScale);
Json::Read(value, "damping", rigidBodyDef.damping);
Json::Read(value, "angularDamping", rigidBodyDef.angularDamping);
Json::Read(value, "constrainAngle", rigidBodyDef.constrainAngle);
Json::Read(value, "isDynamic", rigidBodyDef.isDynamic);
Json::Read(value, "friction", rigidBodyDef.friction);
Json::Read(value, "restitution", rigidBodyDef.restitution);
Json::Read(value, "density", rigidBodyDef.density);
	READ_DATA_NAME(value, "isSensor", rigidBodyDef.isSensor);

	READ_DATA_STRUCT(value, gravityScale, rigidBodyDef);

	READ_DATA(value, size);
}

void Box2DPhysicsComponent::Write(json_t& value)
{
	//
}