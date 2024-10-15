#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Low,
    const int High, int i = 0, int j = 0);
void Print(int** z, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** z, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** z, const int col1, const int col2, const int rowCount, int i = 0);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -34;
    int High = 26;
    int rowCount = 8;
    int colCount = 6;

    int** z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        z[i] = new int[colCount];

    Create(z, rowCount, colCount, Low, High);
    cout << "Initial array:" << endl;
    Print(z, rowCount, colCount);
    Sort(z, rowCount, colCount);
    cout << "Sorted array:" << endl;
    Print(z, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(z, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    cout << "Modified array after Calc:" << endl;
    Print(z, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] z[i];
    delete[] z;

    return 0;
}

void Create(int** z, const int rowCount, const int colCount, const int Low,
    const int High, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            z[i][j] = Low + rand() % (High - Low + 1);
            Create(z, rowCount, colCount, Low, High, i, j + 1);
        }
        else {
            Create(z, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** z, const int rowCount, const int colCount, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << z[i][j];
            Print(z, rowCount, colCount, i, j + 1);
        }
        else {
            cout << endl;
            Print(z, rowCount, colCount, i + 1, 0);
        }
    }
}

void Sort(int** z, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 < colCount - 1) {  
        if (i1 < colCount - i0 - 1) {
          
            if ((z[0][i1] > z[0][i1 + 1]) ||
                (z[0][i1] == z[0][i1 + 1] && z[1][i1] > z[1][i1 + 1]) ||
                (z[0][i1] == z[0][i1 + 1] && z[1][i1] == z[1][i1 + 1] && z[2][i1] > z[2][i1 + 1]))
            {
                Change(z, i1, i1 + 1, rowCount); 
            }
            Sort(z, rowCount, colCount, i0, i1 + 1);  
        }
        else {
            Sort(z, rowCount, colCount, i0 + 1, 0);   
        }
    }
}


void Change(int** z, const int col1, const int col2, const int rowCount, int i)
{
    if (i < rowCount) {
        int tmp = z[i][col1];
        z[i][col1] = z[i][col2];
        z[i][col2] = tmp;
        Change(z, col1, col2, rowCount, i + 1);   
    }
}

void Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            if (z[i][j] > 0 && z[i][j] % 2 != 0)  
            {
                S += z[i][j];  
                k++;  
                z[i][j] = 0; 
            }
            Calc(z, rowCount, colCount, S, k, i, j + 1);  
        }
        else {
            Calc(z, rowCount, colCount, S, k, i + 1, 0);  
        }
    }
}