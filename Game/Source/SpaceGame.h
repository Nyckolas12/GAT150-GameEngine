#pragma once
#include "Framework/Game.h"
#include <memory>
#include "Event/Event.h"


class SpaceGame : public Game
{
public:
	SpaceGame() = default;
	SpaceGame(Engine* engine) : Game{ engine } {}


	bool Initialize() override;
	void Shutdown() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	void OnPlayerDead(const Event& event);
	void OnAddPoints(const Event& event);

private:
	std::unique_ptr<Scene> m_scene;
};
