#pragma once


//core
#include "Core/ETime.h"
#include "Core/EFile.h"
#include "Core/ETime.h"
#include "rapidjson/document.h"
#include "Core/Factory.h"
#include "Core/Singleton.h"

//Renderer
#include "Renderer/Particle.h"
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include "Renderer/Model.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"
#include "Renderer/Color.h"

//Events
#include "Event/EventSystem.h"
#include "Event/Event.h"
#include "Event/Observer.h"

//input
#include "Input/Input.h"

//audio
#include "Audio/Audio.h"

//math
#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/Random.h"
#include "Math/Vector2.h"
#include "Math/Rect.h"

//framework
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"

//Resources
#include "Resources/Resources.h"
#include "Resources/ResourceManager.h"

//Components
#include "Components/TextureComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/EnginePhsicsComponent.h"
#include "Components/TextComponent.h"

//Physics
#include "Physics/Physics.h"

#include <fmod.h>
#include <SDL.h>
#include <memory>
#include<cassert>

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	Time& GetTime() { return *m_time; }
	bool IsQuit() { return quit; }
	Physics& GetPhysics() { return *m_physics; }

	ParticleSystem& GetPS() { return *m_particleSystem; }


private:
	bool quit{ false };
	std::unique_ptr<Renderer> m_renderer{ nullptr };
	std::unique_ptr<Input> m_input{ nullptr };
	std::unique_ptr<Audio> m_audio{ nullptr };
	std::unique_ptr<Time> m_time{ nullptr };
	std::unique_ptr<ParticleSystem> m_particleSystem;
	std::unique_ptr<Physics> m_physics;
};
