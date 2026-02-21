//LevelModel.h
#pragma once
#include <SFML/Graphics.hpp>
#include "../../Include/Level/LevelData.h"


namespace Level
{
	class LevelModel
	{
	private:
		std::vector<LevelData> level_configuration;

		float cell_width;
		float cell_height;

	public:
		static const int number_of_rows = 50;
		static const int number_of_columns = 28;

		LevelModel();
		~LevelModel();

		void initialize(int width, int height);
		void update();
		void render();

		int getCellWidth();
		int getCellHeight();
	};
}