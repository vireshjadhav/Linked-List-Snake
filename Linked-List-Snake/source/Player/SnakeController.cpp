//SnakeController.cpp
#include "Player/SnakeController.h"

namespace Player
{
	SnakeController::SnakeController()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{
		spawnSnake();
	}

	void SnakeController::spawnSnake()
	{
		current_snake_direction = default_direction;
	}

	void SnakeController::processPlayerInput()
	{

	}

	void SnakeController::updateSnakeDirection()
	{

	}
	
	void SnakeController::moveSnake()
	{

	}

	void SnakeController::processSnakeCollision()
	{

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
			moveSnake();
			processSnakeCollision();
			break;
		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		
	}

	void SnakeController::destroy()
	{

	}
}