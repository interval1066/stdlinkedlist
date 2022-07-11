#pragma once

namespace data
{
	class VNode
	{
	public:
		virtual VNode* getNext(void) = 0;
		virtual void setNext(VNode*) { };
	};

	template <class T>
	class Node : public VNode
	{
		T key;  
		Node<T>* next;

	public:
		explicit Node<T>(void) : next(nullptr) { }
		explicit Node<T>(T n) { key = n; }
		virtual ~Node<T>(void) { }

		inline Node<T>* getNext(void) { return next; }
		inline int getKey(void) { return key; }
		inline void setKey(T n) { key = n; }

		inline void setNext(Node<T>* n) { next = n; }
		void push(Node<T>**, T);
		Node* search(Node<T>*, T);

		size_t count(Node<T>*);
		Node* deletefirst(Node<T>*);
		void deletelast(Node<T>*);

		bool deletevalue(Node<T>*, T);
	};
}

