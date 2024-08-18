#include <iostream>
#include "Engine.h"
#include <cstdlib>
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include <vector>
#include <Resources/ResourceManager.h>
#include <Renderer/Texture.h>
#include "Components/PlayerComponent.h"
#include "Components/TextComponent.h"
#include "Core/Json.h"



int main(int argc, char* argv[])
{

	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	Factory::Instance().Register<EnginePhysicsComponent>(EnginePhysicsComponent::GetTypeName());
	Factory::Instance().Register<PlayerComponent>(PlayerComponent::GetTypeName());
	Factory::Instance().Register<TextComponent>(TextComponent::GetTypeName());
	

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	
	
	engine->Initialize();
	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	
	File::SetFilePath("Assest");
	std::cout<< File::GetFilePath()<< std::endl;
	std::string s;
	File::ReadFile("Scenes/scenes.json", s);
	std::cout << s;

	rapidjson::Document document;
	Json::Load("Scenes/scenes.json", document);
	scene->Read(document);
	scene->Initialize();
	
	{
		while (!engine->IsQuit())
		{
			//update
			engine->Update();
			scene->Update(engine->GetTime().GetDeltaTime());
			auto* actor = scene->GetActor<Actor>("Text");

			if (actor)
			{
				//actor->transform.scale = (1.0f + (Math::Sin(engine->GetTime().GetTime())) * 5);
				actor->transform.rotation += 90 * engine->GetTime().GetDeltaTime();
			}
			
			//render
			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();

			scene->Draw(engine->GetRenderer());
			

			engine->GetRenderer().EndFrame();
		}
	}
	scene->RemoveAll();
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}