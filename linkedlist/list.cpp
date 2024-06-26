#include <iostream>
#include <cmath>
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
		std::cout << "\n";
	}
	int getSize(){
		return this->size;
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
	//add to pos
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
	//change the pos value for v
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
	ListIndex* getIndex(int pos){
		if ((pos>=this->size)){
			std::cout << "Invalid Position.\n";
			return nullptr;
		}else{
			ListIndex* aux = this->first;
			for (int i=0;i<this->size;i++){
				if (i == pos)
					return (aux);
				aux = aux->next;
			}
		}
		return nullptr;
	}
	void sort(){
		this->mergeSort(this);
	}
	void mergeSort(List *head){
		
			ListIndex* headRef = head->first;
			List* left = new List();
			List* right = new List();
			if (headRef == nullptr || headRef->next == nullptr){
				return;
			}
			splitList(headRef,left,right);
			mergeSort(left);
			mergeSort(right);
			head->first = sort2Lists(left->first,right->first);
	}
	void splitList (ListIndex* headRef,List* left,List* right){
		
		ListIndex* jumper;
		ListIndex* doubleJumber;
		jumper = headRef;
		doubleJumber = headRef->next;
		while (doubleJumber!=nullptr){
			doubleJumber = doubleJumber->next;
			if (doubleJumber!=nullptr){
				jumper = jumper->next;
				doubleJumber = doubleJumber->next;
			}
		}

		left->first = headRef;
		right->first = jumper->next;
		jumper->next = nullptr;
	}
	ListIndex* sort2Lists(ListIndex* left, ListIndex* right){
		ListIndex* aux = nullptr;
		if (left==nullptr)
			return right;
		else if (right==nullptr)
			return left;
		if (left->value <= right->value){
			aux = left;
			aux->next = sort2Lists(left->next,right);

		}else {
			aux = right;
			aux->next = sort2Lists(left,right->next);
		}
		return aux;

	}
	ListIndex* getTail (){
		if (this->first==nullptr)
			return nullptr;
		ListIndex* aux = this->first;
		while(aux->next != nullptr){
			aux = aux->next;
		}
		return aux;
	}
};
