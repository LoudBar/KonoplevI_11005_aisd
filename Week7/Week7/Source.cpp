#include <iostream>;


using namespace std;

bool binarySearch(int arr[], int l, int r, int key)
{
	int mid = 0;

	while (true)
	{
		mid = (l + r) / 2;

		if (key < arr[mid]) r = mid - 1;   
		else if (key > arr[mid])  l = mid + 1;  
		else return true;
		if (l > r)  return false;
	}
}

int bs1(int arr[], int l, int r, int key, bool last)
{
	while (l <= r) {

		int mid = (l + r) / 2;

		if (arr[mid] < key) l = mid + 1;
		else if (arr[mid] > key) r = mid - 1;
		else if (arr[mid] == key) {
			if (last)
				if (arr[r] == key) return r;
				else { l == mid; r = r - 1; }
			else if (arr[l] == key) return l;
			else { r == mid; }
		}
	}

	if (last) return r;
	return l;
}

bool bs2(int m[][3], int key, int s, int c)
{
	for (int i = 0; i < c; i++)
		if (key <= m[i][s - 1]) return binarySearch(m[i], 0, s - 1, key);
	return false;
}

int bs3(int key)
{
	int l = 0;
	int r = key / 2;
	
	while (r - l > 1) {

		int mid = (l + r) / 2;
		int x = mid * mid;
		
		if (x < key) l = mid;
		else if (x > key) r = mid;
		else return mid;
	}
	return r;
}

int bs4(int a[][4], int n, int m)
{
	int min, max = -1;
	int minvalue = INT_MAX;
	int maxvalue = INT_MIN;

	for (int i = 0; i < m; i++) {
		if (a[i][0] < minvalue) {
			min = i;
			minvalue = a[i][0];
		}
		if (a[i][m - 1] > maxvalue) {
			max = i;
			maxvalue = a[i][m - 1];
		}
	}

	int l = a[min][0];
	int r = a[max][m - 1];

	while (r - l > 1) {

		int mid = (r + l) / 2;
		int bigger = 0;
		int lesser = 0;

		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++) {
				if (a[i][j] < mid) lesser++;
				else if (a[i][j] > mid) bigger++;
			}

		if (abs(lesser - bigger)) return mid;
		
		if (bigger > lesser) l = mid;
		else if (lesser > bigger) r = mid;
		else return mid;
	}
}

int main()
{

	/*int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	bool ans = binarySearch(arr, 0, 6, 2);
	cout << ans << endl;*/

	cout << "<------------------------- Task 1 ------------------------->" << endl << endl;

	int arr[11] = { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3 };
	int first = bs1(arr, 0, 10, 0, false);
	int last = bs1(arr, 0, 10, 0, true);
	cout << "index of first zero is: " << first << endl << "index of last zero is: " << last << endl;
	cout << endl << "<------------------------- Task 2 ------------------------->" << endl << endl;

	int m[3][3] = { {1, 3, 4},
					{6, 8, 10},
					{45, 67, 68} };
	cout << "1 if matrix contains zero, 0 if it doesn't. The answer is: " << bs2(m, 0, 3, 3) << endl;
	cout << endl << "<------------------------- Task 3 ------------------------->" << endl << endl;

	cout << "approximate root of 13 is: " << bs3(13) << endl;
	cout << endl << "<------------------------- Task 4 ------------------------->" << endl << endl;

	int a[4][4] = { {4, 6, 8, 9},
				  {1, 4, 5, 6},
				  {2, 4, 7, 10},
				  {3, 6, 8, 12} };
	cout << "The median of matrix is: " << bs4(a, 4, 4) << endl;

	return 0;
}