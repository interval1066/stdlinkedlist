#include <data/sllinkedlist.h>

namespace data
{
	template <class T>
	void
	Node<T>::push(Node<T>** head_ref, T new_key)  
	{  
		Node<T>* new_node = new Node<T>(); 
		new_node->setKey(new_key);
		new_node->setNext(*head_ref);  
  
		(*head_ref) = new_node;  
	}  

	template <class T>
	Node<T>*
	Node<T>::search(Node<T>* head, T x)  
	{  
		Node<T>* current = head;
		while(current != nullptr) {  
			if (current->key == x)  
				return current;  
			current = current->next;  
		}  
		return nullptr;  
	}

	template <class T>
	unsigned
	Node<T>::count(Node<T>* head)
	{
		Node<T>* current = head;
		unsigned count = 0;
		
		while(current != nullptr) {
			current = current->next;
			count++;
		}

		return count;
	}

	template <class T>
	Node<T>*
	Node<T>::deletefirst(Node<T>* head)
	{
		Node<T>* temp = new Node;
		temp = head;
		head = head->next;
	
		delete temp;
		return head;
	}

	template <class T>
	void
	Node<T>::deletelast(Node<T>* head)
	{
		Node<T>* current = new Node;
		Node<T>* previous = new Node;
		current = head;

		while(current->next != nullptr) {
			previous = current;
			current = current->next;  
		}

		previous->setNext(nullptr);
		delete current;
	}

	template <class T>
	bool
	Node<T>::deletevalue(Node<T>* head, T val)
	{
		Node<T>* temp = head;
		if(head->key == val) {
			head = head->next;
			delete temp;
		}

		while(temp->next != nullptr && temp->next->key != val)
		temp = temp->next;

		if(temp->next == nullptr)
			return false;
		else {
			if(temp->next->key == val) {
				Node<T>* remove = temp->next;
				temp->next = temp->next->next;
				delete remove;
			}
		}
		return true;
	}
}
