//LinkedListSelection.h
#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"

namespace UI
{
	namespace LinkedListUI
	{

		class LinkedListSelectionUIController:public Interface::IUIController
		{
		private:
			const float button_width = 400.0f;
			const float button_height = 140.0f;

			const float single_linked_list_button_y_position = 500.0f;
			const float double_linked_list_button_y_position = 700.0f;
			const float menu_button_y_position = 900.0f;

			const float background_alpha = 85.0f;

			UI::UIElement::ImageView* background_image;
			UI::UIElement::ButtonView* single_linked_list_button;
			UI::UIElement::ButtonView* double_linked_list_button;
			UI::UIElement::ButtonView* menu_button;

			void createImage();
			void createButton();

			void initializeButtons();
			void initializeBackgroundImage();

			float calculateLeftOffsetForButton();

			void registerButtonCallback();
			void singleLinkedListButtonCallback();
			void doubleLinkedListButtonCallback();
			void menuButtonCallback();

			void destroy();

		public:
			LinkedListSelectionUIController();
			~LinkedListSelectionUIController();

			void initialize();


			void update();
			void render();
			void show();
		};
	}
}