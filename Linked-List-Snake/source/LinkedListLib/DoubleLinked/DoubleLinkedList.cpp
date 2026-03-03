//DoubleLinkedList.cpp
#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "LinkedListLib/DoubleLinked/DoubleNode.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		DoubleLinkedList::DoubleLinkedList() = default;

		DoubleLinkedList::~DoubleLinkedList() = default;

		Node* DoubleLinkedList::createNode()
		{
			return new DoubleNode();
		}

		void DoubleLinkedList::insertNodeAtHead()
		{
			linked_list_size++;
			Node* new_node = createNode();

			if (head_node == nullptr)
			{
				head_node = new_node;
				static_cast<DoubleNode*>(new_node)->previous = nullptr;
				initializeNode(head_node, nullptr, Operation::HEAD);
				return;
			}

			initializeNode(new_node, head_node, Operation::HEAD);

			new_node->next = head_node;
			static_cast<DoubleNode*>(head_node)->previous = new_node;

			head_node = new_node;
		}

		void DoubleLinkedList::insertNodeAtTail()
		{
			linked_list_size++;
			Node* new_node = createNode();
			Node* cur_node = head_node;

			if (head_node == nullptr)
			{
				head_node = new_node;
				static_cast<DoubleNode*>(new_node)->previous = nullptr;
				initializeNode(new_node, nullptr, Operation::TAIL);
				return;
			}

			while (cur_node->next != nullptr)
			{
				cur_node = cur_node->next;
			}

			cur_node->next = new_node;
			static_cast<DoubleNode*>(new_node)->previous = cur_node;
			initializeNode(new_node, cur_node, Operation::TAIL);
		}

		void DoubleLinkedList::insertNodeAtIndex(int index)
		{
			if (index < 0 || index >= linked_list_size) return;

			if (index == 0)
			{
				insertNodeAtHead();
				return;
			}

			int current_index = 0;
			Node* new_node = createNode();
			Node* cur_node = head_node;
			Node* prev_node = nullptr;

			while (cur_node != nullptr && current_index < index)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
				current_index++;
			}

			prev_node->next = new_node;
			static_cast<DoubleNode*>(new_node)->previous = prev_node;
			new_node->next = cur_node;
			static_cast<DoubleNode*>(cur_node)->previous = new_node;

			initializeNode(new_node, prev_node, Operation::TAIL);
			linked_list_size++;

			shiftNodesAfterInsertion(new_node, cur_node, prev_node);
		}

		void DoubleLinkedList::insertNodeAtMiddle()
		{
			if (head_node == nullptr)
			{
				insertNodeAtHead();
				return;
			}

			int midIndex = findMiddleNode();
			insertNodeAtIndex(midIndex);
		}

		void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
			Node* next_node = cur_node;
			cur_node = new_node;

			while (next_node != nullptr && cur_node != nullptr)
			{
				cur_node->body_part.setPosition(next_node->body_part.getPosition());
				cur_node->body_part.setDirection(next_node->body_part.getDirection());

				prev_node = cur_node;
				cur_node = next_node;
				next_node = next_node->next;
			}

			initializeNode(cur_node, prev_node, Operation::TAIL);
		}

		void DoubleLinkedList::removeNodeAtHead()
		{
			if (head_node == nullptr) return;

			Node* cur_node = head_node;
			head_node = head_node->next;

			if (head_node != nullptr)
			{
				static_cast<DoubleNode*>(head_node)->previous = nullptr;
			}

			cur_node->next = nullptr;
			delete(cur_node);

			linked_list_size--;
		}

		void DoubleLinkedList::removeNodeAtTail()
		{
			if (head_node == nullptr) return;

			Node* cur_node = head_node;

			if (cur_node->next == nullptr)
			{
				removeNodeAtHead();
				return;
			}

			while (cur_node->next != nullptr)
			{
				cur_node = cur_node->next;
			}

			Node* prev_node = static_cast<DoubleNode*>(cur_node)->previous;
			prev_node->next = nullptr;
			delete(cur_node);

			linked_list_size--;
		}

		void DoubleLinkedList::removeNodeAtIndex(int index)
		{
			int current_index = 0;
			Node* cur_node = head_node;
			Node* prev_node = nullptr;

			while (cur_node != nullptr && current_index < index)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
				current_index++;
			}
			prev_node->next = cur_node->next;

			Node* next_node = cur_node->next;
			if(cur_node->next != nullptr)
			{
				static_cast<DoubleNode*>(next_node)->previous = prev_node;
			}

			shiftNodesAfterRemoval(cur_node);
			delete(cur_node);

			linked_list_size--;
		}

		void DoubleLinkedList::removeNodeAt(int index)
		{
			if (index < 0 || index >= linked_list_size) return;

			if (index == 0)
			{
				removeNodeAtHead();
			}
			else
			{
				removeNodeAtIndex(index);
			}
		}

		void DoubleLinkedList::removeNodeAtMiddle()
		{
			if (head_node == nullptr) return;

			int midIndex = findMiddleNode();
			removeNodeAt(midIndex);
		}

		void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
		{
			sf::Vector2i prev_node_pos = cur_node->body_part.getPosition();
			Direction prev_node_dir = cur_node->body_part.getDirection();

			cur_node = cur_node->next;

			while (cur_node != nullptr)
			{
				sf::Vector2i temp_pos = cur_node->body_part.getPosition();
				Direction temp_dir = cur_node->body_part.getDirection();

				cur_node->body_part.setPosition(prev_node_pos);
				cur_node->body_part.setDirection(prev_node_dir);

				cur_node = cur_node->next;

				prev_node_pos = temp_pos;
				prev_node_dir = temp_dir;
			}
		}

	}
}