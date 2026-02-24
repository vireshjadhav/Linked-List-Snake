//SnakeController.cpp
#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelService.h"
#include "Event/EventService.h"
#include "Time/TimeService.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Global;
	using namespace Level;
	using namespace Event;
	using namespace Time;

	SnakeController::SnakeController()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		single_linked_list = nullptr;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			single_linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
		}
		else  if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
		}
	}

	void SnakeController::updateSnakeDirection()
	{
		single_linked_list->updateNodeDirection(current_snake_direction);
	}
	
	void SnakeController::moveSnake()
	{
		single_linked_list->updateNodePosition();
	}

	void SnakeController::processSnakeCollision()
	{
		if (single_linked_list->processNodeCollision())
		{
			current_snake_state = SnakeState::DEAD;
		}
	}

	void SnakeController::handleRestart()
	{

	}

	void SnakeController::reset()
	{

	}

	void SnakeController::respawnSnake()
	{

	}

	void SnakeController::delayUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0;
			updateSnakeDirection();
			processSnakeCollision();
			if (current_snake_state == SnakeState::ALIVE)
			{
				moveSnake();
			}
		}
	}

	SnakeState SnakeController::getSnakeState() 
	{ 
		return current_snake_state; 
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayUpdate();
			break;
		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	void SnakeController::render()
	{
		single_linked_list->render();
	}

	void SnakeController::destroy()
	{
		delete single_linked_list;
		single_linked_list = nullptr;
	}
}