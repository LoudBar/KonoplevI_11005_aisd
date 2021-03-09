#include <iostream>;
#include <string>;

using namespace std;

struct Node
{
	int item;
	struct Node* next = 0;
	struct Node* prev = 0;
};

struct List
{
	string s = "empty list";

	Node* pHead = 0;
	Node* pTail = 0;

	void add(int item)
	{
		Node* node = new Node;
		node->item = item;

		if (!pHead) {

			pHead = node;
			pTail = node;
		}
		else
		{
			Node* tmp = pHead;

			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = node;
			node->prev = tmp;
			pTail = node;

		}
	}

	int size()
	{
		if (!pHead)
			cout << "list is empty";

		int i = 0;
		Node* tmp = pHead;

		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		return i + 1;
	}

	int get(int id)
	{
		if (!pHead)
			throw s;

		int i = 0;
		Node* tmp = pHead;

		while (i != id)
			if (tmp->next)
			{
				tmp = tmp->next;
				i++;
			}
		return tmp->item;
	}

	void printAll()
	{
		if (!pHead)
			cout << "list is empty";

		Node* temp = pHead;

		while (temp)
		{
			cout << temp->item << ' ';
			temp = temp->next;
		}
	}

	void insertAt(int item, int id)
	{


		if (!pHead)
			throw 1;

		Node* node = new Node;
		node->item = item;
		Node* tmp = pHead;
		int i = 0;

		if (id == 0) {

			pHead->prev = node;
			pHead = node;
			pHead->next = tmp;
		}
		else
		{
			while (i != id) {
				if (tmp->next) {
					tmp = tmp->next;
					i++;
				}
				else if (tmp == pTail) {

					pTail->next = node;
					node->prev = pTail;
					pTail = node;
					return;
				}
				else { cout << "Incorrect id" << endl; return; }

			}

			node->prev = tmp->prev;
			node->next = tmp;
			tmp->prev = node;
			tmp = node;
			if (tmp->prev)
				tmp->prev->next = node;
		}

	}


	void removeAt(int id)
	{
		if (!pHead)
			throw 1;

		Node* tmp = pHead;
		int i = 0;

		if (id == 0) { pHead = pHead->next; pHead->prev = NULL; }

		else {

			while (i != id) {
				if (tmp->next) {
					tmp = tmp->next;
					i++;
				}
				else { cout << "Incorrect id" << endl; return; }

			}
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			if (!tmp->prev)
				pHead = tmp;
			if (!tmp->next)
				pTail = tmp;
		}
	}
};

int main()
{
	List* list = new List;

	list->add(1);
	list->add(2);
	list->add(3);
	list->insertAt(5, 3);
	list->removeAt(0);

	try {
		cout << "element with id 0: " << list->get(0) << endl << "list size: " << list->size() << endl;
		cout << "listed elements: ";
		list->printAll();
	}
	catch (string s) {
		cout << s << endl;
	}

	return 0;
}