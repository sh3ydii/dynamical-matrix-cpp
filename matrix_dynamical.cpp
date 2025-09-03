#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    srand(time(0));

    int n, m;
    cout << "Введите количество строк: ";
    cin >> m;
    cout << "Введите количество столбцов: ";
    cin >> n;

    int** matrix= new int*[m];

    for(int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = rand() % (100 - 1 + 1) + 1;
        }
    }

    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "[" << matrix[i][j] << "]";
        }
        cout << endl;
    }

    delete[] matrix;
    matrix = nullptr;
    
    return 0;
}