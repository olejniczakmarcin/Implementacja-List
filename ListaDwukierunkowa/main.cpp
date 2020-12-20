#include <iostream>
#include "BidirectionalList.h"

int main() 
{
	BidirectionalList* head = new BidirectionalList(2);
	head->AddToTheEnd(3);
	head->AddToTheEnd(2);
	head->AddToTheEnd(1);
	head = head->AddToTheBegining(11);
	head->PrintNext();
	head->PrintPrev();
	std::cout<<"rozmiar listy "<< head->Size() << "\n";
	head = head->RemoveFirst();
	//head=head.removefirst();
	head->PrintNext();
	head->RemoveElement(4);
	head->PrintNext();
	//head.removeelement(2);
	//head.printnext();
	//head=head.removeelement(1);
	//head.printnext();
	head->RemoveElement(6);
	delete head;
}