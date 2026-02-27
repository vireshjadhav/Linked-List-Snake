//SingleLinkedList.h
#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void insertNodeAtTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();

		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);

		Node* getHeadNode();

		std::vector<sf::Vector2i>  getNodesPositionList();

		bool processNodeCollision();

		void removeNodeAtHead();
		void removeAllNodes();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		void render();
	};
}
