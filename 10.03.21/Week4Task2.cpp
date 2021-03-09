#include <iostream>;

using namespace std;

struct Node
{
	int item;
	struct Node* next = 0;
	struct Node* prev = 0;
};

struct Queue
{

	Node* pHead = 0;
	Node* pTail = 0;

	void enQueue(int item)
	{
		Node* node = new Node;
		node->item = item;
		node->next = pHead;
		if (pHead) 
			pHead->prev = node;
		pHead = node;
		if (!pTail)
			pTail = pHead;
	}

	int deQueue()
	{
		if (!pTail) { cout << "Empty queue" << endl; return 0; }
		else {

			Node* tmp = pTail;
			int val = tmp->item;
			pTail = tmp->prev;
			delete tmp;
			return val;
		}
	}
};

int main()
{
	Queue* queue = new Queue;

	queue->enQueue(1);
	queue->enQueue(2);
	queue->enQueue(3);

	cout << queue->deQueue() << endl << queue->deQueue() << endl << queue->deQueue() << endl;

	return 0;
}