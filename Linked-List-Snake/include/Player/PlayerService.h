//PlayerService.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Player/SnakeController.h"
#include "Level/LevelService.h"

namespace Player
{

	class SnakeController;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;
		Level::LinkedListType level_type;

		void createController();
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
		bool isSnakeSizeMinimum();
	};
}