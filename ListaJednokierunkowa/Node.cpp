#include <iostream>
#include "Node.h"
Node::Node(int dane)
{
	this->data=dane;
	this->next = nullptr;
}
Node* Node::AddToTheBegining(int dane)
{
	if (this != nullptr) 
	{
		Node* tmp = this;
		Node* tmp2 = new Node(dane);
		tmp2->next = tmp;
		return tmp2;
	}
	else
		return new Node(dane);
}
Node* Node::AddToTheEnd(int dane)
{
	Node* tmp = new Node(dane);
	tmp->data = dane;
	Node* ptr = this;
	if (ptr != nullptr) {
		while (true) {
			if (ptr->next == nullptr) {
				ptr->next = tmp;
				return ptr;
			}
			else {
				ptr = ptr->next;
			}
		}
	}
	else
		return AddToTheBegining(dane);
}
int Node::ListSize()
{
	Node* tmp = this;
	int count = 0;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}
void Node::PrintList()
{
	Node* ptr2 = this;
	while (ptr2 != nullptr) {
		std::cout<< ptr2->data << "->";
		ptr2 = ptr2->next;
	}
	std::cout<<"\n";
}
Node* Node::RemoveElement(int element) {
	if (this->data == element)
		return RemoveFirst(element);
	else 
	{
		Node* tmp = this;
		while (true)
		{
			Node* tmp2 = tmp;
			Node*  tmp3 = tmp->next->next;
			if (tmp->next->data == element) {
				tmp2->next = tmp3;
				tmp = nullptr;
				tmp = tmp2;
				return tmp;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
}
Node* Node::RemoveFirst(int element) {
	if (this->data == element) {
		Node* tmp = this->next;
		delete tmp;
		return nullptr;
	}
	return 
		RemoveElement(element);
}
Node* Node::PopLast()
{
	Node* tmp = this;
	if (tmp->next == nullptr)
		return tmp;
	else
	{
		tmp = tmp->next;
		tmp->PopLast();
	}
}
int Node::GetData()
{
	return this->data;
}
bool Node::ListIsEmpty()
{
	if (this != nullptr)
		return false;
	else
		return true;
}