//LevelModel.h
#pragma once
#include <SFML/Graphics.hpp>


namespace Level
{
	class LevelModel
	{
	public:
		LevelModel();
		~LevelModel();

		void initialize();
		void update();
		void render();
	};
}