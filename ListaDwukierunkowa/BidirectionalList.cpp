#include <iostream>
#include "BidirectionalList.h"

BidirectionalList::BidirectionalList(int dane)
{
	next = nullptr;
	prev = nullptr;
	this->dane = dane;
}
int BidirectionalList::Size()
{
	int count = 0;
	BidirectionalList* tmp = this;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->next;
	}
	tmp = nullptr;
	delete tmp;
	return count;
}
BidirectionalList* BidirectionalList::RemoveFirst()
{
	BidirectionalList* tmp = this;
	BidirectionalList* tmp2 = this->next;
	tmp2->prev = nullptr;
	tmp->next = nullptr;
	tmp = nullptr;
	delete tmp;
	return tmp2;
}
void BidirectionalList::PrintNext()
{
	BidirectionalList* tmp = this;
	while (tmp != nullptr)
	{
		std::cout<<tmp->dane << "->";
		tmp = tmp->next;
	}
	std::cout<<"\n";
	tmp = nullptr;
	delete tmp;
}
BidirectionalList* BidirectionalList::RemoveElement(int index)
{
	if (index == 1)
	{
		if (Size() >= 2)
		{
			BidirectionalList* tmp = this;
			BidirectionalList* tmp2 = this->next;
			tmp2->prev = nullptr;
			tmp->next = nullptr;
			tmp = nullptr;
			return tmp2;
		}
		else
		{
			BidirectionalList* tmp = this;
			tmp->next = nullptr;
			tmp = nullptr;
			return tmp;
		}
	}
	else
	{
		if (index <= Size())
		{
			BidirectionalList* tmp = this;
			BidirectionalList* tmp2 = this;
			for (int i = 1; i <= index; i++)
			{
				if (i == index)
				{
					if (i == Size())
					{
						tmp2->next = nullptr;
						tmp->prev = nullptr;
					}
					else
					{
						tmp2->next = tmp->next;
						tmp->next->prev = tmp2;
					}
				}
				else
				{
					tmp2 = tmp;
					tmp = tmp->next;
				}
			}
			return tmp2;
		}
		else
		{
			std::cout<<"nie ma takiego elementu\n";
			return nullptr;
		}
	}
}
BidirectionalList* BidirectionalList::AddToTheBegining(int dane)
{
	BidirectionalList* tmp = this;
	if (tmp != nullptr)
	{
		BidirectionalList* tmp2 = new BidirectionalList(dane);
		tmp2->next = tmp;
		tmp->prev = tmp2;
		return tmp2;
	}
	return new BidirectionalList(dane);
}
void BidirectionalList::PrintPrev()
{
	BidirectionalList* tmp = this;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	while (tmp != nullptr)
	{
		std::cout<<tmp->dane << "->";
		tmp = tmp->prev;
	}
	std::cout<<"\n";
	delete tmp;
}
BidirectionalList* BidirectionalList::AddToTheEnd(int dane)
{
	BidirectionalList* tmp = this;
	if (tmp->next == nullptr)
	{
		tmp->prev = nullptr;
		tmp->next = new BidirectionalList(dane);
		tmp->next->prev = this;
		return tmp;
	}
	else
	{
		BidirectionalList* tmp2 = tmp->next;
		while (true)
		{
			if (tmp2->next == nullptr)
			{
				tmp2->next = new BidirectionalList(dane);
				tmp2->next->prev = tmp2;
				return tmp2;

			}
			else {
				tmp2 = tmp2->next;
				tmp = tmp->next;
				tmp2->prev = tmp;
			}
		}
	}
}
BidirectionalList::~BidirectionalList()
{
	
}
bool BidirectionalList::IsEmpty()
{
	if (this != nullptr)
		return false;
	else
		return true;
}