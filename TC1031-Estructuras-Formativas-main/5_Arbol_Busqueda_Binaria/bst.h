#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	void add(T);
    bool find(T);
    int height() const;
    void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
    void postorder(std::stringstream&) const;
    void levelbylevel(std::stringstream&) const;

	friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
int Node<T>::height() const{
    int lheight = 0;
    int rheight = 0;

    if(left != 0)
        lheight = left->height();

    if(right != 0)
        rheight = right->height();

    if (lheight < rheight)
        return rheight + 1;
    else
        return lheight + 1;

}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
	}
	if (right != 0) {
		right->postorder(aux);
	}
    if (aux.tellp() != 1) {
		aux << " ";
	}
    aux << value;
}

template <class T>
void Node<T>::levelbylevel(std::stringstream &aux) const {
    if (aux.tellp() != 1) {
		aux << " ";
	}
    aux << value;

    if(left != 0)
        left->levelbylevel(aux);
    if(right != 0)
        right->levelbylevel(aux);
}

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
    bool empty() const;
	void add(T);
    bool find(T) const;
    std::string visit();
	int height();
	std::string ancestors(T val);
	int whatlevelamI(int val);
	std::string inorder() const;
	std::string preorder() const;
    std::string postorder() const;
    std::string levelbylevel() const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
std::string BST<T>::visit(void) {
	return (preorder() + "\n" + inorder() + "\n" + postorder() + "\n" + levelbylevel());
}

template <class T>
int BST<T>::height(){
    if(root)
        return root->height();
    return 0;
}

template <class T>
std::string BST<T>::ancestors(T val) {
    std::stringstream ret;
    Node<T> *aux = root;
    
    ret << "[";
    while (aux != nullptr && val != aux->value) {
        if (ret.tellp() > 1)
            ret << " ";
        ret << aux->value;
        if (val < aux->value)
            aux = aux->left;
        else
            aux = aux->right;
    }
    if (aux == nullptr)
        return "[]";
    ret << "]";
    return ret.str();
}

template <class T>
int BST<T>::whatlevelamI(int val) {
    Node<T> *aux;
    int level = 1;

    aux = root;
    while(val != aux->value){
        if (val < aux->value) {
            level ++;
            aux = aux->left;
        } else if (val > aux->value) {
            level++;
            aux = aux->right;
        }
    }
    return level;
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;
	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::postorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::levelbylevel() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levelbylevel(aux);
	}
	aux << "]";
	return aux.str();
}

#endif