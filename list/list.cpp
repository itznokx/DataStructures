#include <iostream>
struct ListIndex {
	ListIndex(int v) : value(v),next(nullptr) {}
	ListIndex* next;
	int value;
};
struct List
{	
private:
	ListIndex* first;
	int size;
public:
	List() : size(0),first(nullptr){}
	void list(){
		ListIndex* aux = first;
		if (aux==nullptr)
			std::cout << "Empty list";
		while (aux != nullptr){
			std::cout << aux->value;
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
		if (pos > (this->size)-1){
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
				while (count == pos-1){
					aux = aux->next;
					count++;
				}
				addIndex->next = aux->next;
				aux->next = addIndex;
			}
			

		}
	}
	void put(int v,int pos){
		if (pos > (this->size)-1){
			std::cout << "Invalid position";
		}
		else{
			int count = 0;
			ListIndex* aux = first;
			while (count == pos-1){
				aux = aux->next;
				count++;
			}
			aux.value = v;
		}
	}
	int size(){
		return this->size;
	}
};