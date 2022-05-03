#include <iostream>
#include <memory>
#include <data/sllinkedlist.h>
#include <data/sllinkedlistimpl.h>

using namespace std;
using namespace data;

// This isn't part of the linkedlist class; separation of resposibilities 
// principal. Rendering the data should be the responsibilty of something 
// else. Also; more composition.
class NodeUtil
{
public:
    void
    listall(Node<int>* head)  
    {  
	    auto current = head;

	    while(current != nullptr) {
	    	cout << current->getKey();
	    	current = current->getNext();
	    	if(current != nullptr) cout << ", ";
	    }
	    cout << endl;
    }

    // Struggled with weather these should be part of the data class collection
    // or some other name space. They aren't rendering classes, I would probably
    // create a new sub-namespace ("data/something") whose sole responsibility is
    // to manipulate/transform the data.
    template <class T>
    void
    sortasc(Node<T>* head)
    {
	    Node<T>* temphead = head;
	    T tempkey;
	    auto counter = temphead->count(head);

	    for(unsigned n = 0; n < counter; n++) {
	    	while(temphead->getNext()) {
	    		if(temphead->getKey() > temphead->getNext()->getKey()) {		
	    			tempkey = temphead->getKey();

	    			temphead->setKey(temphead->getNext()->getKey());
	    			temphead->getNext()->setKey(tempkey);
	    		}
	    		temphead = temphead->getNext();
	    	}
	    	temphead = head;
	    }
    }

    template <class T>
    void
    sortdsc(Node<T>* head)
    {
    	Node<T>* temphead = head;
    	T tempkey;
    	unsigned counter = temphead->count(head);

    	for(unsigned n = 0; n < counter; n++) {
    		while(temphead->getNext()) {
    			if(temphead->getKey() < temphead->getNext()->getKey()) {		
    				tempkey = temphead->getKey();

    				temphead->setKey(temphead->getNext()->getKey());
    				temphead->getNext()->setKey(tempkey);
    			}
    			temphead = temphead->getNext();
    		}
    		temphead = head;
    	}
    }
};

int
main(__attribute__((unused))int argc, __attribute__((unused))char** argv)
{  
	auto utl = make_unique<Node<int>>(10);
    	NodeUtil disp;
	Node<int>* head = nullptr;  

	utl->push(&head, 30);  
	utl->push(&head, 11);  
	utl->push(&head, 21);  
	utl->push(&head, 14);
	utl->push(&head, 22);  
	utl->push(&head, 56);  
 	utl->push(&head, 57);  
	utl->push(&head, 104);

 	utl->search(head, 21)? cout << "Node found" << endl :
		cout << "Node not found" << endl;
	disp.listall(head);
	
	cout << "number of elements: " << utl->count(head) << endl;
	disp.sortasc(head);
	cout << endl << "Sorted ascending:" << endl;
	
	disp.listall(head);
	disp.sortdsc(head);
	cout << endl << "Sorted descending:" << endl;
	
	disp.listall(head);
	cout << endl << "Deleteing head node: " << head->getKey() << endl;
	head = utl->deletefirst(head);
	
	disp.listall(head);
	cout << endl << "Searching for 14" << endl;
	(utl->search(head, 14) != nullptr)? cout << "Found" << endl :
		cout << "Not found" << endl;
	
	cout << endl << "Deleting tail" << endl;
	utl->deletelast(head);
	disp.listall(head);
	
	cout << endl << "Deleting node valued 14" << endl;
	utl->deletevalue(head, 14);
	disp.listall(head);

	return EXIT_SUCCESS;  
}
