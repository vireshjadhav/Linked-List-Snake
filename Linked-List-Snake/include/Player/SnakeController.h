//SnakeController.h
#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedListLib/Node.h"
#include "LinkedListLib/LinkedList.h"
#include "Food/FoodType.h"
#include "Level/LevelConfig.h"

namespace Player
{
	using namespace Food;
	using namespace LinkedListLib;
	using namespace Level;

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

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
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 2.0f;
		const int minimum_snake_size = 3;

		int player_score= 0;

		float elapsed_duration = 0.0f;
		float restart_counter = 0.0f;

		LinkedList* linked_list;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;
		Direction current_snake_direction;
		SnakeState current_snake_state;

		InputState current_input_state = InputState::PROCESSING;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
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

		void initializeLinkedList();

		void createLinkedList(LinkedListType level_type);

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		int getPlayerScore();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();

		void onFoodCollected(FoodType food_type);

		bool isSnakeSizeMinimum();
	};
}