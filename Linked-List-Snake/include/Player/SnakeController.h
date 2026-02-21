//SnakeController.h
#pragma once
#include <SFML/System/Vector2.hpp>
#include "Direction.h"
#include "LinkedList/SingleLinkedList.h"

using namespace LinkedList;
namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	class SnakeController
	{
	private:
		const int intial_snake_length = 10;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;
		SnakeState current_snake_state;

		LinkedList::SingleLinkedList* single_linked_list;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void createLinkedList();
		void handleRestart();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();


		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}