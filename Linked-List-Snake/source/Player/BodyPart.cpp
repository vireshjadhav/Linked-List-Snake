//BodyPart.cpp
#include "Player/BodyPart.h"
#include "Global/Config.h"
#include "Level/LevelView.h"

using namespace Global;
using namespace UI::UIElement;
using namespace Level;

namespace Player
{
	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();
	}

	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return sf::Vector2f(x_screen_position, y_screen_position);
	}

	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Direction::UP:
			return 270.0f;
		case Direction::DOWN:
			return 90.0f;
		case Direction::RIGHT:
			return 0.0f;
		case Direction::LEFT:
			return 180.0f;
		}
	}


	sf::Vector2i BodyPart::getNextPosition()
	{
		switch (direction)
		{
		case Direction::UP:
			return getNextPositionUp();
		case Direction::DOWN:
			return getNextPositionDown();
		case Direction::LEFT:
			return getNextPositionLeft();
		case Direction::RIGHT:
			return getNextPositionRight();
		}
	}

	sf::Vector2i BodyPart::getNextPositionUp()
	{
		return sf::Vector2i(grid_position.x, grid_position.y - 1);
	}
	sf::Vector2i BodyPart::getNextPositionDown()
	{
		return sf::Vector2i(grid_position.x, grid_position.y + 1);
	}
	sf::Vector2i BodyPart::getNextPositionLeft()
	{
		return sf::Vector2i(grid_position.x - 1, grid_position.y);
	}
	sf::Vector2i BodyPart::getNextPositionRight()
	{
		return sf::Vector2i(grid_position.x + 1, grid_position.y);
	}

	void BodyPart::setDirection(Direction direction)
	{
		this->direction = direction;
	}

	void BodyPart::setPosition(sf::Vector2i position)
	{
		this->grid_position = position;
	}

	void BodyPart::updatePosition()
	{
		bodypart_image->setPosition(getBodyPartScreenPosition());
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->update();
	}

	Direction BodyPart::getDirection()
	{
		return direction;
	}

	sf::Vector2i BodyPart::getPosition()
	{
		return grid_position;
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	void BodyPart::destroy()
	{
		delete (bodypart_image);
	}
}