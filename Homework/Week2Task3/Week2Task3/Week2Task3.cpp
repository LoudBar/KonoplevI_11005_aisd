/*Написать функцию сортировки массива (алгоритм сортировки - любой).
void sort(int * a, int size) { … }
*/

#include <iostream>;

using namespace std;

void sort(int* a, int size) // Сортировка подсчетом
{
	int max = 0;

	for (int i = 0; i < size; i++) // Поиск максимального элемента массива а
	{
		if (a[i] > max)
			max = a[i];
	}

	int* tmp = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
	{
		tmp[i] = 0;
	}

	for (int i = 0; i < size; i++) // Запись в количества чисел в ячейки tmp. Если в a было 4 двойки, то в tmp[a[2]] будет 4
	{
		tmp[a[i]]++;
	}

	int k = 0;

	for (int i = 0; i < max + 1; i++) // Сама сортировка
		for (int j = 0; j < tmp[i]; j++)
		{
			a[k] = i;
			k++;
		}
}

int main()
{
	int a[3]{ 5,3,1 };

	sort(a, 3);

	for (int i = 0; i < 3; i++)
	{
		cout << a[i];
	}

	return 0;
}