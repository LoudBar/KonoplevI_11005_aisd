/*Поиск целочисленного логарифма по основанию 2 (2^p < x):
Вводится число x, вывести наибольшее число p, такое, что 2 в степени p меньше x (наибольшая возможная степень двойки).
*/

#include <iostream>;
#include <cmath>;

using namespace std;

void log()
{
	int x;
	int p = 2;

	cin >> x;

	while (pow(2, p) < x)
	{
		p++;
	}
	cout << "The answer is " << p;
}

int main()
{
	log();

	return 0;
}
