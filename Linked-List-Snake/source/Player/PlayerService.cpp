//PlayerService.cpp
#include "Player/PlayerService.h"
#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;
	using namespace Level;

	PlayerService::PlayerService()
	{
		snake_controller = nullptr;
		createController();
	}

	PlayerService::~PlayerService()
	{
		destroy();
	}

	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}

	void PlayerService::spawnPlayer()
	{
		level_type = ServiceLocator::getInstance()->getLevelService()->getCurrentLinkedListType();
		snake_controller->createLinkedList(level_type);
		snake_controller->spawnSnake();
	}
	
	void PlayerService::initialize()
	{
		snake_controller->initialize();
	}

	void PlayerService::update()
	{
		snake_controller->update();
	}

	void PlayerService::render()
	{
		snake_controller->render();
	}

	std::vector<sf::Vector2i> PlayerService::getCurrentSnakePositionList()
	{
		return snake_controller->getCurrentSnakePositionList();
	}

	int PlayerService::getPlayerScore()
	{
		return snake_controller->getPlayerScore();
	}

	TimeComplexity PlayerService::getTimeComplexity()
	{
		return snake_controller->getTimeComplexity();
	}

	LinkedListOperations PlayerService::getLastOperation()
	{
		return snake_controller->getLastOperation();
	}

	bool PlayerService::isSnakeSizeMinimum()
	{
		return snake_controller->isSnakeSizeMinimum();
	}

	void PlayerService::destroy()
	{
		delete(snake_controller);
	}
}