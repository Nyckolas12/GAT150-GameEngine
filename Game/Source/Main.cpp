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
#include "SpaceGame.h"



int main(int argc, char* argv[])
{


	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	std::unique_ptr<SpaceGame> game = std::make_unique <SpaceGame>(engine.get());
	game->Initialize();
	engine->Initialize();
	File::SetFilePath("Assest");
	

	
	
	{
		while (!engine->IsQuit())
		{
			//update
			engine->Update();
			game->Update(engine->GetTime().GetDeltaTime());
			//render
			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();
			game->Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}
	}
	game->Shutdown();
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}