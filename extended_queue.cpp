#include "Header.h"

int Extended_queue::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
   return count;
}

bool Extended_queue::full() const
{
	return maxqueue == this -> count;
}

void Extended_queue::clear()
{
	this -> count = 0;
	this -> front = 0;
	this -> rear = maxqueue - 1;
}
