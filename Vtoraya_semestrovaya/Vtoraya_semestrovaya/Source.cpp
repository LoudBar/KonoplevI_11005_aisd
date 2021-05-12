#include <iostream>;
#include <ctime>;
#include <fstream>;

using namespace std;

int* quickSort(int* a, int l, int r, int* counter)
{
    int i = l;
    int j = r;
    int pivot = a[(i + j) / 2];
    int temp = 0;

    while (i <= j)
    {
        while (a[i] < pivot) { i++; *counter += 1; }
        while (a[j] > pivot) { j--; *counter += 1; }

        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        *counter += 1;
    }

    if (j > l) quickSort(a, l, j, counter);
    if (i < r) quickSort(a, i, r, counter);

    return counter;
}

void countingSort(int* a, int size)
{
	int max = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	int* tmp = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
	{
		tmp[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		tmp[a[i]]++;
	}

	int k = 0;

	for (int i = 0; i < max + 1; i++)
		for (int j = 0; j < tmp[i]; j++)
		{
			a[k] = i;
			k++;
		}
}

void printArray(int* array, int n)
{
	for (int i = 0; i < n; i++) cout << array[i] << endl;
}

int main()
{

	int a[5]{ 4, 2, 3, 1, 5 };
	int b[5]{ 4, 2, 3, 1, 5 };

    int k = 0;
	int* x = quickSort(a, 0, 4, &k);
	countingSort(b, 5);

	printArray(a, 5);
	cout <<"iteration quantity: "<< *x << endl;
	printArray(b, 5);
    cout << endl;
	
    ofstream fout1;
    fout1.open("quickSort.txt");
    int* ans = 0;

    for (int n = 1000; n <= 100000; n += 1000)
    {
        int k1 = 0;
        double totalTime = 0;

        for (int j = 0; j < 10; j++)
        {
            int* c = new int[n];

            for (int i = 0; i < n; i++) c[i] = rand();                

            double startTime = clock();

            ans = quickSort(c, 0, n, &(k1));

            double endTime = clock();
            totalTime += endTime - startTime;
        }

        totalTime /= 10;

        fout1 << (int)totalTime << " iteration quantity " << *ans << endl;
    }

    fout1.close();

    ofstream fout2;
    fout2.open("countingSort.txt");

    for (int n = 1000; n <= 100000; n += 1000)
    {
        double totalTime = 0;

        for (int j = 0; j < 10; j++)
        {
            int* d = new int[n];

            for (int i = 0; i < n; i++) d[i] = rand();

            double startTime = clock();

            countingSort(d, n);

            double endTime = clock();
            totalTime += endTime - startTime;
        }

        totalTime /= 10;

        fout2 << (int)totalTime << endl;
    }

    fout2.close();

	return 0;
}