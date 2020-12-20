#include <iostream>
#include "Node.h"

int main() 
{
	Node* head = new Node(4);
	head->AddToTheEnd(7);
	head = head->AddToTheBegining(1);
	head->AddToTheEnd(5);
	int size = head->ListSize();
	std::cout<<size << "\n";
	head->PrintList();
	std::cout << "ostatni element listy " << head->PopLast()->GetData() << "\n";

}