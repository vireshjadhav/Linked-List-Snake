//SnakeController.h
#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include "LinkedList/SingleLinkedList.h"
#include "Food/FoodType.h"

namespace Player
{
	using namespace Food;

	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;
		SnakeState current_snake_state;

		float elapsed_duration = 0.0f;

		LinkedList::SingleLinkedList* single_linked_list;

		const float movement_frame_duration = 0.1f;

		const float restart_duration = 2.0f;
		
		float restart_counter = 0.0f;

		InputState current_input_state = InputState::PROCESSING;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void createLinkedList();
		void handleRestart();
		void delayUpdate();
		void reset();
		void destroy();

		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		void onFoodCollected(FoodType food_type);
	};
}