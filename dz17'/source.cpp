#include <iostream>
#include <iomanip>
using namespace std;

int** AddColumn(int** parr, int index, int CountArr, int CountElements)
{

	int** new_parr = new int* [CountArr];
	for (int i = 0; i < CountArr; i++)
	{
		new_parr[i] = new int[CountElements + 1];
	}
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements + 1; j++)
		{
			if (j < index)
			{
				new_parr[i][j] = parr[i][j];
			}
			else if (j == index)
			{
				new_parr[i][j] = 0;
			}
			else
			{
				new_parr[i][j] = parr[i][j - 1];
			}
		}
	}
	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;

	return new_parr;
}

int** DeleteColumn(int** parr, int index, int CountArr, int CountElements)
{

	int** new_parr = new int* [CountArr];
	for (int i = 0; i < CountArr; i++)
	{
		new_parr[i] = new int[CountElements - 1];
	}
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements - 1; j++)
		{
			if (j < index)
			{
				new_parr[i][j] = parr[i][j];
			}
			else if (j >= index)
			{
				new_parr[i][j] = parr[i][j + 1];
			}
		}
	}
	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;

	return new_parr;
}

//int** MoveArr(int** parr, int index, int CountArr, int CountElements)
//{
//	int choice;
//	cout << "Chose in what direction you need move arr\n1)Right\n2)Down\n3)Left\n4)Up\n";
//	cin >> choice;
//	
//	int** new_parr;
//
//}
// Із-за того що я робив це пізно, просто міски не вивезли це все писать. Алгоритим пересування: має бети змінна темп ві неї зберігаємо значення і потім замість нього ставимо минуле чи наступне значення і це все в циклі.


int** TransponseArr(int** parr, int CountArr, int CountElements)
{
	int** new_parr = new int* [CountElements];

	for (int i = 0; i < CountElements; i++)
	{
		new_parr[i] = new int[CountArr];
	}

	for (int i = 0; i < CountElements; i++)
	{
		for (int j = 0; j < CountArr; j++)
		{
			new_parr[i][j] = parr[j][i];
		}
	}

	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;

	return new_parr;
}

int main()
{
	srand(time(NULL));
	int CountArr, CountElements;
	cout << "Enter count of arr -> ";
	cin >> CountArr;
	cout << "Enter count of elements -> ";
	cin >> CountElements;

	int** parr = new int* [CountArr];

	for (int i = 0; i < CountArr; i++)
	{
		parr[i] = new int[CountElements];
	}
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements; j++)
		{
			parr[i][j] = rand() % 100;
		}
	}

	/*int index = 0;
	cout << "Enter index -> ";
	cin >> index;
	if (index > CountElements || index < 0)
	{
		cout << "Invalid index!" << endl;
		return 1;
	}
	parr = AddColumn(parr, index, CountArr, CountElements);


	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements + 1; j++)
		{
			cout << setw(3) << parr[i][j];
		}
		cout << endl;
	}

	parr = DeleteColumn(parr, index, CountArr, CountElements + 1);*/
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements; j++)
		{
			cout << setw(3) << parr[i][j];
		}
		cout << endl;
	}
	parr = TransponseArr(parr, CountArr, CountElements);
	for (int i = 0; i < CountElements; i++)
	{
		for (int j = 0; j < CountArr; j++)
		{
			cout << setw(3) << parr[i][j];
		}
	}

	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;

}