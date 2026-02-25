//SnakeController.h
#pragma once
#include <SFML/Graphics.hpp>


namespace Player
{
	class SnakeController
	{
	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();
	};
}