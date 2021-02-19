/*Создать два массива (ввести с клавиатуры, или в коде заранее), 
склеить их и записать в третий массив. Массивы создавать в куче (с помощью new[]), предыдущие освободить.
*/

#include <iostream>;

using namespace std;

int main()
{
	int* a = new int[3]{ 2,4,1 };
	int* b = new int[4]{ 1,9,15,4 };
	int* c = new int[7];

	for (int i = 0; i < 3; i++)  c[i] = a[i]; 
	for (int i = 3; i < 7; i++) c[i] = b[i - 3];
	for (int i = 0; i < 7; i++) cout << c[i] << endl;

	delete[] a;
	delete[] b;

	return 0;
}