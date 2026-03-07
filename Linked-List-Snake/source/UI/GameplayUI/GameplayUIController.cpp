//GameplayUIController.cpp
#include "UI/GameplayUI/GameplayUIController.h"
#include "UI/UIElement/TextView.h"
#include "Level/LevelService.h"
#include "Global/ServiceLocator.h"
#include "Player/SnakeController.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace UI::UIElement;
		using namespace Level;
		using namespace Global;
		using namespace Player;

		GameplayUIController::GameplayUIController()
		{
			createTexts();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::initialize() 
		{
			initializeTexts();
		}

		void GameplayUIController::createTexts()
		{
			level_number_text = new TextView();
			score_text = new TextView();
			time_complexity_text = new TextView();
			operation_text = new TextView();
		}

		void GameplayUIController::initializeTexts()
		{
			initializeLevelNumberText();
			initializeScoreText();
			initializeTimeComplexityText();
			initializeOperationText();
		}

		void GameplayUIController::initializeLevelNumberText()
		{
			level_number_text->initialize("Level: 1", sf::Vector2f(level_number_text_x_position, text_y_position), 
				FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
		}

		void GameplayUIController::initializeScoreText()
		{
			score_text->initialize("Score: 0", sf::Vector2f(score_text_x_position, text_y_position), 
				FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
		}

		void GameplayUIController::initializeTimeComplexityText()
		{
			time_complexity_text->initialize("Time Complexity: NONE", sf::Vector2f(time_complexity_text_x_position, time_complexity_text_y_position),
				FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
		}

		void GameplayUIController::initializeOperationText()
		{
			operation_text->initialize("Last Operation: ", sf::Vector2f(operations_text_x_position, operations_text_y_position),
				FontType::BUBBLE_BOBBLE,operations_font_size, sf::Color::Black);
		}

		void GameplayUIController::update()
		{
			updateLevelNumberText();
			updateScoreText();
			updateTimeComplexityText();
			updateOperationText();
		}

		void GameplayUIController::updateLevelNumberText()
		{
			LevelNumber level_number = ServiceLocator::getInstance()->getLevelService()->getCurrentLevel();
			sf::String level_number_value = std::to_string(1 + static_cast<int>(level_number));

			level_number_text->setText("Level: " + level_number_value);
			level_number_text->update();
		}

		void GameplayUIController::updateScoreText()
		{
			int player_score = ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();
			sf::String score_value = std::to_string(player_score);

			score_text->setText("Score: " + score_value);
			score_text->update();
		}

		void GameplayUIController::updateTimeComplexityText()
		{
			TimeComplexity time_complexity = ServiceLocator::getInstance()->getPlayerService()->getTimeComplexity();
			sf::String time_complexity_string;

			switch (time_complexity)
			{
			case TimeComplexity::NONE:
				time_complexity_string = "NONE";
				break;
			case TimeComplexity::ONE:
				time_complexity_string = "O(1)";
				break;
			case TimeComplexity::N:
				time_complexity_string = "O(N)";
				break;
			default:
				time_complexity_string = "NONE";
				break;
			}

			time_complexity_text->setText("Time Complexity : " + time_complexity_string);
			time_complexity_text->update();
		}

		void GameplayUIController::updateOperationText()
		{
			LinkedListOperations last_operation = ServiceLocator::getInstance()->getPlayerService()->getLastOperation();
			sf::String last_operation_string;

			switch (last_operation)
			{
			case LinkedListOperations::NONE:
				last_operation_string = "";
				break;

			case LinkedListOperations::INSERT_AT_HEAD:
				last_operation_string = "INSERT AT HEAD";
				break;
			case LinkedListOperations::INSERT_AT_TAIL:
				last_operation_string = "INSERT AT TAIL";
				break;
			case LinkedListOperations::INSERT_AT_MID:
				last_operation_string = "INSERT AT MID";
				break;
			case LinkedListOperations::REMOVE_AT_HEAD:
				last_operation_string = "REMOVE AT HEAD";
				break;
			case LinkedListOperations::REMOVE_AT_TAIL:
				last_operation_string = "REMOVE AT TAIL";
				break;
			case LinkedListOperations::REMOVE_AT_MID:
				last_operation_string = "REMOVE AT MID";
				break;
			case LinkedListOperations::DELETE_HALF_LIST:
				last_operation_string = "DELETE HALF LIST";
				break;
			case LinkedListOperations::REVERSE_LIST:
				last_operation_string = "REVERSE LIST";
				break;

			default:
				last_operation_string = "";
				break;
			}

			operation_text->setText("Last Operation: " + last_operation_string);
			operation_text->update();
		}

		void GameplayUIController::show()
		{
			level_number_text->show();
			score_text->show();
			time_complexity_text->show();
			operation_text->show();
		}

		void GameplayUIController::render()
		{
			level_number_text->render();
			score_text->render();
			time_complexity_text->render();
			operation_text->render();
		}

		void GameplayUIController::destroy()
		{
			delete(level_number_text);
			delete(score_text);
			delete(time_complexity_text);
			delete(operation_text);
		}
	}
}