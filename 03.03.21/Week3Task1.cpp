//Stack with printAll

#include <iostream>;
#include <string>;

using namespace std;

struct Node
{
	int item;
	Node* next = 0;
};

struct Stack
{

	string s = "empty stack";
	
	Node* phead = 0;

	void Push(int item)
	{
		Node* node = new Node;
		node->item = item;
		node->next = phead;
		phead = node;
	}

	int Pop()
	{
		if (!phead)
			throw s;

		

		Node* temp = phead;
		int x = temp->item;
		phead = temp->next;
		delete temp;
		return x;
	}

	int Peek()
	{
		if (!phead)
			throw s;

		return phead->item;
	}

	void printAll()
	{

		if (!phead)
			throw s;

		Node* temp = phead;

		while (temp)
		{ 
			cout << temp->item << ' ';
			temp = temp->next;
		}
	}
};

int main()
{
	Stack* stack = new Stack;

	stack->Push(1);
	stack->Push(2);
	stack->Push(3);

	
	
	

	try {
		stack->printAll();
		cout << endl;
		cout << stack->Pop() << endl;
		cout << stack->Pop() << endl;
	}
	catch (string s) {
		cout << s << endl;
	}

	delete stack;
	return 0;
}