/* Sirri Kirimlioglu
*/

#include <iostream>
#include "AdderRemover.h"
#include <string>


using namespace std;

Node::Node(int new_element) { //constructor
	element = new_element;  //initializing value
	next = 0;  //NULL
	prev = 0;  //NULL
}

void AdderRemover::traverse() {
	Node *current = traverser->current; //taking current node
	cout << name << "  ||   NodeCount:" << nodeCount << endl;
	cout << "----" << endl;
	if (traverser->hasNode()) {
		for (int i = 0; i < nodeCount; i++) {
			current->element = traverser->next(); //passing next element with specified traversing strategy
			cout << current->element << endl;
		}
	}
	else
		cout << "The list has no element." << endl;
}

void AdderRemover::display() {
	Node *current = head;  //first node
	cout << name << "  ||  NodeCount:" << nodeCount<< endl;
	cout << "----" << endl;
	if (nodeCount != 0) {
		for (int i = 0; i < nodeCount; i++) {
			cout << current->element << endl;  //print
			current = current->next;  // pass to next element
		}
	}
	if (nodeCount == 0)
		cout << "There is no element to print." <<  endl;
}

void AdderRemover::removeAll() {
	Node *temp;  //temporary node
	for (int i = 0; i < nodeCount; i++) {
		temp = head;  //taking head
		head = head->next;  //new head is the next coming one
		delete temp; //deleting old head
	}
	nodeCount = 0;
}


void FAFR::add(int new_element) {
	Node *temp;
	temp = new Node(new_element); //new element created

	if (head) {
		temp->next = head; //new element's next is head
		head->prev = temp; //old head's previous is new element
		head = temp; //new element is head
	}
	else { //if list is empty
		head = temp;
		tail = temp;
	}
	nodeCount++;
}

void FAFR::remove() {
	Node *temp;
	if (head) { //if list is not empty
		temp = head;  // taking first one
		head->next->prev = 0; // coming element after head is head now so no previous of it 
		head = head->next; // coming element is head now
		delete temp; // deleting tail
	}
	nodeCount--;
}

void FAFR::setTraverser() {
	traverser = new ARTF(head); //adjusting traverser strategy
}


void FALR::add(int new_element) { //same add func with FAFR
	Node *temp;
	temp = new Node(new_element);

	if (head) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		head = temp;
		tail = temp;
	}
	nodeCount++;
}

void FALR::remove() {
	Node *temp;
	if (tail) { //if list is not empty
		temp = tail; //taking the last
		tail->prev->next = 0; // before element of the last's is the last now so no next
		tail = tail->prev; // before element is tail now
		delete temp; //deleting tail
	}
	nodeCount--;
}

void FALR::setTraverser() {
	traverser = new ARTF(head); //adjusting traverser strategy
}

void LAFR::add(int new_element) {
	Node *temp;
	temp = new Node(new_element); //new element
	if (tail) {
		temp->prev = tail; //new element is gonna be tail so initial tail is it's previous
		tail->next = temp; // initial tail's next became new element
		tail = temp; // tail is the new element now
	}
	else { //if list is empty
		tail = temp;
		head = temp;
	}
	nodeCount++;
}

void LAFR::remove() { //same remove func with FAFR
	Node *temp;
	if (head) {
		temp = head;
		head->next->prev = 0;
		head = head->next;
		delete temp;
	}
	nodeCount--;
}

void LAFR::setTraverser() {
	traverser = new ARTL(tail);  //adjusting traverser strategy
}


void LALR::add(int new_element) { //same add func with LAFR
	Node *temp;
	temp = new Node(new_element);
	if (tail) {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	else {
		tail = temp;
		head = temp;
	}
	nodeCount++;
}

void LALR::remove() { //same remove func with FALR
	Node *temp;
	if (tail) {
		temp = tail;
		tail->prev->next = 0;
		tail = tail->prev;
		delete temp;
	}
	nodeCount--;
}

void LALR::setTraverser() {
	traverser = new ARTL(tail); //adjusting traverser strategy
}


ARTF::ARTF(Node *head) { //constructor
	current = head;
}

bool ARTF::hasNode() {
	if (current)
		return true;  //returns true if list not empty
	else
		return false;
}

int ARTF::next() {
	int temp;
	temp = current->element; //taking value of current node
	current = current->next; // iterating current node (advancing)
	return temp;
}



ARTL::ARTL(Node *tail) { //constructor
	current = tail;
}

bool ARTL::hasNode() {
	if (current)
		return true; //returns true if list not empty
	else
		return false;
}

int ARTL::next() {
	int temp;
	temp = current->element; //taking value of current node
	current = current->prev;  // iterating current node (advancing)
	return temp;
}




