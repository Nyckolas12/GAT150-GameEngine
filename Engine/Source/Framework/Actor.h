#pragma once
#include "../Math/Transform.h"
#include <string>
#include "Components/Component.h"
#include <vector>
#include <memory>
#include <functional>

class Model;
class Renderer;
class Scene;

class Actor :public Object
{
public:
	Actor() = default;
	Actor(const Transform& transform) : transform{ transform } {}
	Actor(const Actor& other);
	
	CLASS_DECLARATION(Actor)
	CLASS_PROTOTYPE(Actor)

	 void Initialize() override;
	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);
	void AddComponent(std::unique_ptr<Component> component);
	template<typename T>
	T* GetComponent();
	std::function<void(Actor*)> OnCollisionEnter;
	std::function<void(Actor*)> OnCollisionExit;
	template<typename T>
	std::vector<T*> GetComponents();

	friend class Scene;

public:
	std::string tag;
	float lifespan = 0;
	bool destroyed = false;
	Transform transform;
	Scene* scene{ nullptr };


protected:
	 std::vector<std::unique_ptr<Component>> components;
	 // Inherited via Object

};

template<typename T>
inline T* Actor::GetComponent()
{
	for (auto& component : components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) return result;
	}

	return nullptr;
}

template<typename T>
inline std::vector<T*> Actor::GetComponents()
{
	std::vector<T*> results;
	for (auto& component : components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) return result;
	}
	return results;
}
