#include <iostream>;

using namespace std;

struct MaxHeap
{

	int size = -1;
	int maxSize = 6;
	int* arr = new int[maxSize];

	int Parent(int i) { return (i - 1) / 2; }
	int LeftChild(int i) { return 2 * i + 1; }
	int RightChild(int i) { return 2 * i + 2; }

	//void swap()

	void SiftUp(int i)
	{
		while (i > 0 && arr[i] > arr[Parent(i)])
		{
			int tmp = arr[Parent(i)];
			arr[Parent(i)] = arr[i];
			arr[i] = tmp;

			i = Parent(i);
		}
	}

	void SiftDown(int i)
	{
		int maxIndex = i;

		if (arr[LeftChild(i)] > arr[maxIndex] && LeftChild(i) <= size) { maxIndex = LeftChild(i); }
		if (arr[RightChild(i)] > arr[maxIndex] && RightChild(i) <= size) { maxIndex = RightChild(i); }
		if (maxIndex != i) { int tmp = arr[i]; arr[i] = arr[maxIndex]; arr[maxIndex] = tmp; SiftDown(maxIndex); }
	}

	void Insert(int data)
	{
		if (size >= maxSize)
			throw - 1;

		size++;
		arr[size] = data;
		SiftUp(size);
	}

	int ExtractMax()
	{
		int result = arr[0];

		int tmp = arr[0];
		arr[0] = arr[size];
		arr[size] = tmp;

		size--;
		SiftDown(0);

		return result;
	}

	int GetMax() { return arr[0]; }
};

int* HeapSort(int* arr, int size)
{
	MaxHeap* tmp = new MaxHeap;

	for (int i = 0; i < size + 1; i++) { tmp->Insert(arr[i]); }
	for (int i = size; i >= 0; i--) { arr[i] = tmp->ExtractMax(); }

	return arr;
}

int main()
{
	MaxHeap* heap = new MaxHeap;

	heap->Insert(2);
	heap->Insert(5);
	heap->Insert(10);
	heap->Insert(1);

	heap->ExtractMax();

	cout << heap->GetMax() << endl;

	heap->ExtractMax();

	cout << heap->GetMax() << endl;

	int* a = new int[3]{ 3,1,2 };

	for (int i = 0; i < 3; i++) { cout << a[i] << " "; }

	cout << endl;

	int* b = HeapSort(a, 2);

	for (int i = 0; i < 3; i++) { cout << b[i] << " "; }

	return 0;
}