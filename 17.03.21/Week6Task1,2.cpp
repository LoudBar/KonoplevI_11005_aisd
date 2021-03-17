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

};

int main()
{
	UniqueSortedList* list = new UniqueSortedList;

	list->add(2);
	list->add(3);
	list->add(7);
	list->add(4);
	list->add(5);
	list->add(2);
	list->add(5);
	list->add(1);

	list->remove(0);

	list->printAll();


	return 0;
}