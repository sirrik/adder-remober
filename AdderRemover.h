/* Sirri Kirimlioglu
*/



class Node {  //Node class for doubly link list
public:
	Node *next;  //next node
	Node *prev;  // previous node  
	int element;
	Node(int new_element);
};

class ARTraverser{
private:
	char *method_name = "ART";
public:
	Node* current;
	virtual bool hasNode() = 0; //pure virtual function
	virtual int next() = 0; //pure virtual function
};

class AdderRemover {
public:
	Node *head;
	Node *tail;
	char *name;
	int nodeCount;
	ARTraverser * traverser;
	virtual void add(int) = 0; //pure virtual function
	virtual void remove() = 0; //pure virtual function
	virtual void setTraverser() = 0; //pure virtual function
	void display();
	void removeAll();
	void traverse();
};


class FAFR :public AdderRemover {
public:
	FAFR() { name = "FAFR"; } //constructor
	void add(int);
	void remove();
	void setTraverser();
};

class FALR :public AdderRemover {
public:
	FALR() { name = "FALR"; } //constructor
	void add(int);
	void remove();
	void setTraverser();
};

class LAFR :public AdderRemover {
public:
	LAFR() { name = "LAFR"; } //constructor
	void add(int);
	void remove();
	void setTraverser();
};

class LALR :public AdderRemover {
public:
	LALR() { name = "LALR"; } //constructor
	void add(int);
	void remove();
	void setTraverser();
};

class ARTF : public ARTraverser {
public:
	bool hasNode();
	int next(); //returns the value of current node
	ARTF(Node *); //takes the tail
};

class ARTL : public ARTraverser {
public:
	bool hasNode();
	int next(); //returns the value of current node
	ARTL(Node *); // takes the tail
};
