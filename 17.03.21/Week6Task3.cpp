#include <iostream>;
#include <string>;

using namespace std;

struct Node
{
	int item;
	struct Node* next = 0;
	struct Node* prev = 0;
};

struct UniqueSortedList
{
	string s = "empty list";

	Node* pHead = 0;

	void add(int item)
	{
		Node* node = new Node;
		node->item = item;

		if (!pHead)
			pHead = node;

		else
		{

			Node* tmp = pHead;

			if (node->item == tmp->item)
				return;

			if (node->item < tmp->item) {
				pHead->prev = node;
				pHead = node;
				pHead->next = tmp;

			}

			else {

				while (node->item > tmp->item) {

					if (!tmp->next) {
						tmp->next = node;
						node->prev = tmp;
						return;
					}
					tmp = tmp->next;
				}
				if (node->item == tmp->item)
					return;

				node->prev = tmp->prev;
				node->next = tmp;
				tmp->prev = node;
				tmp = node;
				if (tmp->prev)
					tmp->prev->next = node;
			}
		}
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

	void remove(int id)
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
		}
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
};

UniqueSortedList* Union(UniqueSortedList* a, UniqueSortedList* b)
{
	UniqueSortedList* ans = new UniqueSortedList;

	int i = 0, j = 0;

	while (i < a->size()) { ans->add(a->get(i)); i++; }
	while (j < b->size()) { ans->add(b->get(j)); j++; }

	return ans;
}

UniqueSortedList* Intersect(UniqueSortedList* a, UniqueSortedList* b)
{
	UniqueSortedList* ans = new UniqueSortedList;

	int i = 0;

	for (int i = 0; i < a->size(); i++) {
		for (int j = 0; j < b->size(); j++)
		{
			if (a->get(i) == b->get(j))
				ans->add(a->get(i));
		}
	}
	return ans;
}

UniqueSortedList* Difference(UniqueSortedList* a, UniqueSortedList* b)
{
	UniqueSortedList* tmp = Intersect(a, b);

	for (int i = 0; i < a->size(); i++)
		for (int j = 0; j < tmp->size(); j++)
			if (a->get(i) == tmp->get(j)) { a->remove(i); }
	
	return a;
}

int main()
{
	UniqueSortedList* list = new UniqueSortedList;
	UniqueSortedList* list1 = new UniqueSortedList;
	UniqueSortedList* listans = new UniqueSortedList;
	UniqueSortedList* listans1 = new UniqueSortedList;
	UniqueSortedList* listans2 = new UniqueSortedList;

	list->add(2);
	list->add(3);
	list->add(7);
	list->add(4);

	list1->add(7);
	list1->add(3);

	listans = Union(list, list1);
	listans1 = Intersect(list, list1);
	listans2 = Difference(list, list1);

	listans->printAll();
	cout << endl;
	listans1->printAll();
	cout << endl;
	listans2->printAll();

	return 0;
}