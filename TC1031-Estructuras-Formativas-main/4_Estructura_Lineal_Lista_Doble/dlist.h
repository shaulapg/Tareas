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
class DList {
public:
	DList();
	DList(const DList<T>&);

    std::string toStringForward() const;
    std::string toStringBackward() const;
    bool empty() const;

    void insertion(T);
	unsigned int search(T) const;
    void update(int, T) const;
    int deleteAt(int);

private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;
};

template <class T>
DList<T>::DList(): head(0), tail(0), size(0){}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void DList<T>::insertion(T val){
    DLink<T> *newLink, *p;

    newLink = new DLink<T>(val);

    if (empty()) {
        head = newLink;
        tail = newLink;
	} else{
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
    size++;
}

template <class T>
unsigned int DList<T>::search(T val) const {
	DLink<T> *p;

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
void DList<T>::update(int v, T val) const {
    DLink<T> *p = head;

    int i = 0;
    while (p != 0 && i < v) {
        p = p->next;
        i++;
    }
    if(p != 0){
        p->value = val;
    }
}

template <class T>
int DList<T>::deleteAt(int v){
    DLink<T> *p = head, *aux;
	int pos = 0;

	if(v == 0){
        p = p->next;
        p->previous = 0;
        delete head;
        head = p;
    } else if(v == size){
        p = tail;
        aux = p->previous;
        aux->next = 0;
        delete p;
        tail = aux;
    }
    
    else {
        while (pos != v){
            p = p->next;
            pos++;
        }
        aux = p->next;
        aux->previous = p->previous;
        p->previous->next = aux;
        delete p;
    }
    size --;
}

#endif