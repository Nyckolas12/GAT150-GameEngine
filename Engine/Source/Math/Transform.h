#pragma once
#include "Vector2.h"
#include "Core/Serializable.h"
struct Transform : public Serializable
{
	Vector2 position;
	float rotation{ 0 };
	float scale{ 1 };
	
	Transform(Vector2 position, float rotation = 0, float scale = 1) : position{ position }, rotation{ rotation }, scale{ scale } {}
	Transform() = default;


	Vector2 Forward() { return  Vector2{ 1,0 }.Rotate(Math::DegToRad(rotation)); }

	// Inherited via Serializable
	void Read(const json_t& value) override;
	void Write(json_t& value) override;
};
