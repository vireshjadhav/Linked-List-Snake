//LevelService.h
#pragma once
#include "LevelConfig.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;
		LinkedListType current_linked_list_type;

		void createLevelController();
		void destroy();

		void spawnFood();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LinkedListType linked_list_type);
		
		void spawnPlayer();

		void spawnLevelElements(LevelNumber level_to_load);

		float getCellWidth();
		float getCellHeight();
		LevelNumber getCurrentLevel();
		void setCurrentLevelNumber(LevelNumber level_to_load);
		LinkedListType getCurrentLinkedListType();
	};
}