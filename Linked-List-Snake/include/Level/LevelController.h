//LevelController.h
#pragma once
#include <SFML/Graphics.hpp>


namespace Level
{
	class LevelController
	{
	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();
	};
}