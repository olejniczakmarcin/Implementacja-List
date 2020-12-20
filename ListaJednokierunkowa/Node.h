class Node {
private:
	int data;
	Node* next;
public:
	Node(int dane);
	Node* AddToTheBegining(int val);
	Node* AddToTheEnd(int val);
	int ListSize();
	int GetData();
	bool ListIsEmpty();
	void PrintList();
	Node* RemoveElement(int element);
	Node* RemoveFirst(int element);
	Node* PopLast();
};