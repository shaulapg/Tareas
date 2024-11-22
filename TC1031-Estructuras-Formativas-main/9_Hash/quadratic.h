#ifndef QUADRATIC_H_
#define QUADRATIC_H_

#include <string>
#include <sstream>

template <class Key, class Value>
class Quadratic {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	Quadratic(unsigned int, Key, unsigned int (*f) (const Key)) ;
	bool full() const;
	bool put(Key, Value) ;
	Value get(const Key) ;
	std::string toString() const;
};

template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f) (const Key))  {
	size = sze;
	keys = new Key[size];
	if (keys == 0)
		std::cout << "Error" << std::endl;
	initialValue = init;
	for (unsigned int i = 0; i < size; i++)
		keys[i] = init;
	values = new Value[size];
	if (values == 0)
		std::cout << "Error" << std::endl;
	for (int i = 0; i  < sze; i++)
        values[i] = 0;

	func = f;
	count = 0;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::full() const {
	return (count > size);
}

template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;

	start = i = func(k) % size;
	do {
		if (keys[i] == k)
			return i;
		i = (i + 1) % size;
	} while (start != i);
	return -1;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v)  {
	unsigned int i, start, attempt = 0;
    long pos;

    if (full())
        std::cout << "Error" << std::endl;

    pos = indexOf(k);
    if (pos != -1) {
        values[pos] = v;
        return true;
    }

    start = func(k) % size;
    do {
        i = (start + attempt * attempt) % size;
        if (keys[i] == initialValue) {
            keys[i] = k;
            values[i] = v;
            count++;
            return true;
        }
        attempt++;
    } while (attempt < size);

    return false;
}

template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key k)  {
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1)
		return values[pos];
	std::cout << "Error" << std::endl;
}

template <class Key, class Value>
std::string Quadratic<Key, Value>::toString() const {
	std::stringstream aux;

	for (unsigned int i = 0; i < size; i++)
		if (values[i] != 0)
			aux << "(" << i << " " << keys[i] << " : " << values[i] << ") ";
	return aux.str();
}
#endif