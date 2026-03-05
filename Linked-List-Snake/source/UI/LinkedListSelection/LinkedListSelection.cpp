//LinkedListSelection.cpp
#include "UI/LinkedListSelection/LinkedListSelection.h"
#include "Main/GameService.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace UI
{
	using namespace UIElement;
	using namespace Global;
	using namespace Main;

	namespace LinkedListSelection
	{
		LinkedListSelection::LinkedListSelection()
		{
			createButton();
			createImage();
		}

		LinkedListSelection::~LinkedListSelection()
		{
			destroy();
		}

		void LinkedListSelection::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}

		void LinkedListSelection::createButton()
		{
			single_linked_list_button = new ButtonView();
			double_linked_list_button = new ButtonView();
			menu_button = new ButtonView();
		}

		void LinkedListSelection::createImage()
		{
			background_image = new ImageView();
		}

		void LinkedListSelection::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0,0));
			background_image->setImageAlpha(background_alpha);
		}

		void LinkedListSelection::initializeButtons()
		{
			float x_offset = calculateLeftOffsetForButton();

			single_linked_list_button->initialize("Single Linked List", Config::single_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, single_linked_list_button_y_position));
			double_linked_list_button->initialize("Double Linked List", Config::double_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, double_linked_list_button_y_position));
			menu_button->initialize("Menu", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, menu_button_y_position));
		}

		float LinkedListSelection::calculateLeftOffsetForButton()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			return (static_cast<float>(game_window->getSize().x / 2) - button_width / 2);
		}

		void LinkedListSelection::registerButtonCallback()
		{

		}

		void LinkedListSelection::singleLinkedListButtonCallback()
		{

		}

		void LinkedListSelection::doubleLinkedListButtonCallback()
		{

		}

		void LinkedListSelection::menuButtonCallback()
		{

		}

		void LinkedListSelection::update()
		{
			background_image->update();
			single_linked_list_button->update();
			double_linked_list_button->update();
			menu_button->update();
		}

		void LinkedListSelection::render()
		{
			background_image->render();
			single_linked_list_button->render();
			double_linked_list_button->render();
			menu_button->render();
		}

		void LinkedListSelection::show()
		{
			background_image->show();
			single_linked_list_button->show();
			double_linked_list_button->show();
			menu_button->show();
		}

		void LinkedListSelection::destroy()
		{
			delete(background_image);
			delete(single_linked_list_button);
			delete(double_linked_list_button);
			delete(menu_button);
		}
	}
}