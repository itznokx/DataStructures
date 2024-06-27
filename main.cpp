#include "list/list.cpp"
#include <iostream>

int main (void){
	List* listTest = new List();
	listTest->add(2);
	listTest->add(8);
	listTest->add(90);
	listTest->add(56);
	listTest->add(37);
	listTest->add(5);
	listTest->add(23);
	listTest->list();
	return 0;
}