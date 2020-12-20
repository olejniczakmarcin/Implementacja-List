#pragma once

class BidirectionalList {
private:
	BidirectionalList* next;
	BidirectionalList* prev;
	int dane;
public:
	BidirectionalList(int dane);
	int Size();
	BidirectionalList* RemoveFirst();
	void PrintNext();
	BidirectionalList* RemoveElement(int index);
	BidirectionalList* AddToTheBegining(int dane);
	void PrintPrev();
	bool IsEmpty();
	BidirectionalList* AddToTheEnd(int dane);
	~BidirectionalList();
};