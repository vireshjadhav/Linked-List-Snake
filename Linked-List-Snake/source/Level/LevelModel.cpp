//LevelModel.cpp
#include "../../Include/Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel() = default;

	LevelModel::~LevelModel() = default;

	void LevelModel::initialize(int width, int height)
	{
		cell_width = width / number_of_rows;
		cell_height = height / number_of_columns;
	}

	int LevelModel::getCellWidth() { return cell_width; }

	int LevelModel::getCellHeight() { return cell_height; }

	void LevelModel::update()
	{

	}

	void LevelModel::render()
	{

	}
}