/*Написать функцию, которая получает на вход указатель на начало массива, размер массива и возвращает сумму элементов массива.
int sum(int * a, int size) { … }
*/

#include <iostream>;

using namespace std;

int sum(int* a, int size)
{
	int ans = 0;

	for (int i = 0; i < size; i++)
	{
		ans += a[i];
	}

	return ans;
}

int main()
{
	int a[3]{ 1,2,3 };

	cout << sum(a, 3);

	return 0;
}