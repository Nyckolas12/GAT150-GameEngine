#include <iostream>
#include "Engine.h"
#include <cstdlib>
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include <vector>
#include <Resources/ResourceManager.h>
#include <Renderer/Texture.h>



int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	
	
	engine->Initialize();


	File::SetFilePath("Assest");
	std::cout<< File::GetFilePath()<< std::endl;
	{
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ReliableSource.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });

		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("days_gone.jpg", engine->GetRenderer());

		Transform t{ {30,30}, };
		std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
		std::unique_ptr<TextureComponent> component = std::make_unique<TextureComponent>();
		component->texture = texture;
		actor->AddComponent(std::move(component));

		while (!engine->IsQuit())
		{
			//update
			engine->Update();
			actor->Update(engine->GetTime().GetDeltaTime());
			//render
			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();


			engine->GetRenderer().DrawTexture(texture.get(), 30, 30);
			text->Draw(engine->GetRenderer(), 200, 200);

			//actor->Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;


}