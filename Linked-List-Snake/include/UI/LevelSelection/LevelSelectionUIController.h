//LevelSelectionUIController.h
#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"

namespace UI
{
	namespace LevelSelection
	{
		class LevelSelectionUIController : public Interface::IUIController
		{
		private:
			const float button_width = 400.0f;
			const float button_height = 140.0f;

			const float level_one_button_y_position = 100.0f;
			const float level_two_button_y_position = 300.0f;
			const float level_three_button_y_position = 500.0f;
			const float level_four_button_y_position = 700.0f;
			const float menu_button_y_position = 900.0f;

			const float background_alpha = 85.0f;

			UI::UIElement::ImageView* background_image;
			UI::UIElement::ButtonView* level_one_button;
			UI::UIElement::ButtonView* level_two_button;
			UI::UIElement::ButtonView* level_three_button;
			UI::UIElement::ButtonView* level_four_button;
			UI::UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();

			float calculateLeftOffsetForButton();

			void registerButtonCallback();

			void levelOneButtonCallback();
			void levelTwoButtonCallback();
			void levelThreeButtonCallback();
			void levelFourButtonCallback();
			void menuButtonCallback();

			void destroy();

		public:
			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize() override;
			void update() override;
			void render()override;
			void show() override;
		};
	}
}