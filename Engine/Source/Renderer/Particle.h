#pragma once
#include "../Math/Vector2.h"
#include "../Renderer/Renderer.h"

struct Particle
{
	struct Data
	{
	Vector2 position{ 0,0 };
	Vector2 velocity{0,0};
	float lifespan = 0;

	};
	Vector2 position{ 0,0 };
	Vector2 velocity{ 0,0 };
	float lifespan = 0;

	Particle() = default;
	Particle(Vector2 position, Vector2 velocity) : position{ position }, velocity{ velocity } {}
	Particle(Vector2 position, Vector2 velocity, float lifespan) : position{ position }, velocity{ velocity },  lifespan{lifespan} {}

	bool isActive{ false };

	void Initialize(const Data& data);

	void Update(float dt);
	void Draw(Renderer& renderer);


};