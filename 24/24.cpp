#include<iostream>

using namespace std;

class Node {
private:
	bool locked;
	int lockedDescendants;

public:
	int val;
	Node* padre;
	Node* l;
	Node* r;

	Node(int val, Node* padre = NULL) : val(val), padre(padre), l(NULL), r(NULL), locked(false), lockedDescendants(0) {}

	bool isLocked()
	{
		return locked;
	}

	bool lock()
	{
		if (lockedDescendants == 0)
		{
			locked = true;

			Node* tmp = this->padre;
			while (tmp != NULL) {
				tmp->lockedDescendants++;
				tmp = tmp->padre;
			}
			return true;
		}
		return false;
	}

	bool unlock()
	{
		if (!this->isLocked())
			return false;
		locked = false;

		Node* tmp = this->padre;
		while (tmp != NULL) {
			tmp->lockedDescendants--;
			tmp = tmp->padre;
		}
		return true;
	}
};

int main()
{
	Node* root = new Node(0);
	root->l = new Node(2, root);
	root->r = new Node(6, root);
	root->l->l = new Node(1, root->l);
	root->l->r = new Node(3, root->l);
	root->r->l = new Node(5, root->r);
	root->r->r = new Node(7, root->r);

	cout << root->l->r->lock() << endl;
	cout << root->r->l->lock() << endl;
	cout << root->l->lock() << endl;

	return 0;
}