#include <iostream>
#include "Engine.h"
#include <cstdlib>
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include <vector>
#include <Resources/ResourceManager.h>
#include <Renderer/Texture.h>
#include "Core/Json.h"



int main(int argc, char* argv[])
{

	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>("Texture");
	

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	
	
	engine->Initialize();


	File::SetFilePath("Assest");
	std::cout<< File::GetFilePath()<< std::endl;
	std::string s;
	File::ReadFile("Helloguys.txt", s);
	std::cout << s;

	rapidjson::Document document;
	Json::Load("Helloguys.txt", document);

	std::string name;
	int age;
	bool isAwake;
	Vector2 position;
	Color color;
	READ_DATA(document, age);
	READ_DATA(document, name);
	READ_DATA(document, isAwake);
	READ_DATA(document, position);
	READ_DATA(document, color);
	/*Json::Read(document, "age", age);
	Json::Read(document, "name", name);
	Json::Read(document, "isAwake", isAwake);
	*/
	std::cout << " " << name << " " << age << " " << isAwake << " "  << std::endl;
	std::cout << position.x << " " << position.y << std::endl;
	std::cout << color.r << " " << color.g << " " << color.b << " " << color.a << std::endl;
	
	{
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ReliableSource.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });

		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("days_gone.jpg", engine->GetRenderer());

		Transform t{ {30,30}, };
		std::unique_ptr<Actor> actor = Factory::Instance().Create<Actor>("Actor");
		actor->SetTransform({ {30,30} });
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