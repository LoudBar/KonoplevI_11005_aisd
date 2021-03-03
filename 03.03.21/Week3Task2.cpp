//Linked list (with printAll)

#include <iostream>;
#include <string>;

using namespace std;

struct Node
{
	int item;
	struct Node* next = 0;
};

struct List
{
	string s = "empty list";

	Node* pRoot = 0;

	void add(int item)
	{
		Node* node = new Node;
		node->item = item;

		if (!pRoot)
			pRoot = node;
		else
		{
			Node* tmp = pRoot;

			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = node;
		}
	}

	int size()
	{
		if (!pRoot)
			cout << "list is empty";

		int i = 0;
		Node* tmp = pRoot;

		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		return i + 1;
	}

	int get(int id)
	{
		if (!pRoot)
			throw s;

		int i = 0;
		Node* tmp = pRoot;

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
		if (!pRoot)
			cout << "list is empty";

		Node* temp = pRoot;

		while (temp)
		{
			cout << temp->item << ' ';
			temp = temp->next;
		}
	}
};

int main()
{
	List* list = new List;

	list->add(1);
	list->add(2);
	list->add(3);

	try {
		cout << "element with id 1: " << list->get(1) << endl << "list size: " << list->size() << endl;
		cout << "listed elements: ";
		list->printAll();
	}
	catch (string s) {
		cout << s << endl;
	}

	return 0;
}