#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&);

    std::string toString() const;
    bool empty() const;

    void insertion(T);
	unsigned int search(T) const;
    void update(int, T) const;
    int deleteAt(int);

private:
	Link<T> *head;
	int 	size;

};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream val;
	Link<T> *p;

	p = head;
	val << "[";
	while (p != 0) {
		val << p->value;
		if (p->next != 0) {
			val << ", ";
		}
		p = p->next;
	}
	val << "]";
	return val.str();
}

template <class T>
void List<T>::insertion(T val){
    Link<T> *newLink, *p;

    newLink = new Link<T>(val);

    if (empty()) {
		newLink->next = head;
        head = newLink;
        size++;
		return;
	}
    p = head;
    while (p->next != 0) {
        p = p->next;
    }

    newLink->next = 0;
    p->next = newLink;
    size++;
}

template <class T>
unsigned int List<T>::search(T val) const {
	Link<T> *p;

    int n = 0;
	p = head;
	while (p != 0) {
		if (p->value == val)
			return n;
		p = p->next;
        n++;
	}
	return -1;
}

template <class T>
void List<T>::update(int v, T val) const {
    Link<T> *p;

    p = head;
    for(int i = 0; i <= val; i++){
        if(i == v){
            p->value = val;
            return;
        }
        p = p->next;
    }
}

template <class T>
int List<T>::deleteAt(int v){
    Link<T> *p, *aux;
    T val;

    p = head;
    aux = p;
    for(int i = 0; i <= v; i++){
        if(i == v){
            if(i == 0)
                head = p->next;
            val = aux-> value;
            delete aux;
            size--;
            return val;
        }
        aux = p->next;
        p->next = aux->next;
    }
}

#endif