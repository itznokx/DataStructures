#include "linkedlist/list.cpp"
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
	listTest->put(902,1);
	listTest->add(507,3);
	listTest->list();
	listTest->sort();
	listTest->list();
	std::cout << listTest->size << "\n";
	return 0;
}
