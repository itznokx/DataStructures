#include <iostream>
struct ListIndex {
	ListIndex(int v) : value(v),next(nullptr) {}
	ListIndex* next;
	int value;
};
// The linkedlist is index-0 based
struct List
{	
	ListIndex* first;
	int size;
	List() : size(0),first(nullptr){}
	void list(){
		ListIndex* aux = first;
		if (aux==nullptr)
			std::cout << "Empty list";
		while (aux != nullptr){
			std::cout << aux->value << " ";
			aux = aux->next;
		}
	}
	//add to end
	void add(int v){
		if (this->first==nullptr){
			ListIndex* aux = new ListIndex(v);
			this->first = aux;
			this->size++;
		}
		else{
			ListIndex* aux = first;
			while (aux->next!=nullptr){
				aux = aux->next;
			}
			aux->next = new ListIndex(v);
			this->size++;
		}
	}
	void add(int v,int pos){
		if (pos >this->size){
			std::cout << "Invalid position";
		}
		else{
			ListIndex* addIndex = new ListIndex(v);
			if (pos == 0){
				addIndex->next = this->first;
				this->first = addIndex;
			}else{
				int count = 0;
				ListIndex* aux = first;
				while (count < pos-1){
					aux = aux->next;
					count++;
				}
				addIndex->next = aux->next;
				aux->next = addIndex;
			}
			this->size++;

		}
	}
	void put(int v,int pos){
		if (pos > this->size){
			std::cout << "Invalid position";
		}
		else{
			int count = 0;
			ListIndex* aux = first;
			while (count < pos){
				aux = aux->next;
				count++;
			}
			aux->value = v;
		}
	}
	int get(int pos){
		if ((pos>=this->size)){
			std::cout << "Invalid Position.\n";
		}else{
			ListIndex* aux = this->first;
			for (int i=0;i<this->size;i++){
				if (i == pos)
					return (aux->value);
				aux = aux->next;
			}
		}
	}
	
	LinkedIndex* getTail (){
		if (this->first==nullptr)
			return nullptr
		LinkedIndex* aux = this->first;
		while(aux->next != nullptr){
			aux = aux->next;
		}
		return aux;
	}
};
