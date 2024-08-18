#pragma once
#include <list>
#include <memory>
#include "Object.h"
#include "Core/EString.h"

class Game;
class Renderer;
class Actor;
class Engine;

class Scene : public Object
{
public:
	
	Scene(Engine* engine,Game* game= nullptr) :
		engine{engine},
		game{ game } {}
	
	CLASS_DECLARATION(Scene);

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor);

	void RemoveAll();

	template<typename T> T* GetActor();
	template<typename T> T* GetActor(const std::string& name);

	Game* GetGame() { return game; }
	void Initialize() override;

public:
	Engine* engine{ nullptr };
	Game* game{ nullptr };
protected:
	std::list<std::unique_ptr<Actor>> actors;


	// Inherited via Object

};

template<typename T>
T* Scene::GetActor()
{
	for (auto& actor : actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}

	return nullptr;
}

template<typename T>
inline T* Scene::GetActor(const std::string& name)
{
	for (auto& actor : actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result &&  IsEqualIgnoreCase(result->name, name)) return result;
	}


	return nullptr;
}
