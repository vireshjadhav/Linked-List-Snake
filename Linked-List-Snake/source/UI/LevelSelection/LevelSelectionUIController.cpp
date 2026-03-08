//LevelSelectionUIController.cpp
#include "UI/LevelSelection/LevelSelectionUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"


namespace UI
{
	using namespace UIElement;
	using namespace Global;
	using namespace Event;
	using namespace Sound;
	using namespace Main;
	

	namespace LevelSelection 
	{
		LevelSelectionUIController::LevelSelectionUIController()
		{
			createButtons();
			createImage();
		}

		LevelSelectionUIController::~LevelSelectionUIController() 
		{
			destroy();
		}

		void LevelSelectionUIController::initialize() 
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}

		void LevelSelectionUIController::createImage()
		{
			background_image = new ImageView();
		}

		void LevelSelectionUIController::createButtons()
		{
			level_one_button = new ButtonView();
			level_two_button = new ButtonView();
			level_three_button = new ButtonView();
			level_four_button = new ButtonView();
			menu_button = new ButtonView();
		}

		void LevelSelectionUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void LevelSelectionUIController::initializeButtons()
		{
			float x_position = calculateLeftOffsetForButton();

			level_one_button->initialize("Level One", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(x_position, level_one_button_y_position));
			level_two_button->initialize("Level Two", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(x_position, level_two_button_y_position));
			level_three_button->initialize("Level Three", Config::level_three_button_texture_path, button_width, button_height, sf::Vector2f(x_position, level_three_button_y_position));
			level_four_button->initialize("Level Four", Config::level_four_button_texture_path, button_width, button_height, sf::Vector2f(x_position, level_four_button_y_position));
			menu_button->initialize("Menu", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_position, menu_button_y_position));
		}

		float LevelSelectionUIController::calculateLeftOffsetForButton()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			return (static_cast<float>(game_window->getSize().x / 2) - button_width / 2);
		}

		void LevelSelectionUIController::registerButtonCallback()
		{
			level_one_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelOneButtonCallback, this));
			level_two_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelTwoButtonCallback, this));
			level_three_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelThreeButtonCallback, this));
			level_four_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelFourButtonCallback, this));
			menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menuButtonCallback, this));
		}

		void LevelSelectionUIController::levelOneButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->getLevelService()->setCurrentLevelNumber(Level::LevelNumber::ONE);
		}

		void LevelSelectionUIController::levelTwoButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->getLevelService()->setCurrentLevelNumber(Level::LevelNumber::TWO);
		}

		void LevelSelectionUIController::levelThreeButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->getLevelService()->setCurrentLevelNumber(Level::LevelNumber::THREE);
		}

		void LevelSelectionUIController::levelFourButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->getLevelService()->setCurrentLevelNumber(Level::LevelNumber::FOUR);
		}

		void LevelSelectionUIController::menuButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void LevelSelectionUIController::update()
		{
			background_image->update();
			level_one_button->update();
			level_two_button->update();
			level_three_button->update();
			level_four_button->update();
			menu_button->update();
		}

		void LevelSelectionUIController::render()
		{
			background_image->render();
			level_one_button->render();
			level_two_button->render();
			level_three_button->render();
			level_four_button->render();
			menu_button->render();
		}

		void LevelSelectionUIController::show()
		{
			background_image->show();
			level_one_button->show();
			level_two_button->show();
			level_three_button->show();
			level_four_button->show();
			menu_button->show();
		}

		void LevelSelectionUIController::destroy()
		{
			delete(background_image);
			delete(level_one_button);
			delete(level_two_button);
			delete(level_three_button);
			delete(level_four_button);
			delete(menu_button);
		}
	}
}
