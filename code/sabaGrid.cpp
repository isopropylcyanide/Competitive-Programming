#include <bits/stdc++.h>
using namespace std;

// Print the number of times the word “saba” appears in the grid.
// It can appear horizontally, vertically, and diagonally in the grid
// N, M Grid <= (100 * 100)
const int MAX = 101;
char A[MAX][MAX];

int numFound = 0;

bool outOfBounds(int i, int j, int N, int M){
    return !(i >= 0 && i < N && j >= 0 && j < M);
}

void printArray(int N, int M){
 for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int existsEast(int i, int j, int N, int M){
    // Check if next four characters east exist and if they do, they match 's','a','b','a'
    if (!outOfBounds(i + 3, j, N, M)){
        if (A[i][j] == 's' && A[i + 1][j] == 'a' && A[i + 2][j] == 'b' && A[i + 3][j] == 'a'){
            // printf("\n Found horizontal from (%d, %d) to (%d, %d)", i, j, i + 3, j);
            return 1;
        }
        return 0;
    }
    else return 0;
}

int existsSouth(int i, int j, int N, int M){
    // Check if next four characters south exist and if they do, they match 's','a','b','a'
    if (!outOfBounds(i, j + 3, N, M)){
        if (A[i][j] == 's' && A[i][j + 1] == 'a' && A[i][j + 2] == 'b' && A[i][j + 3] == 'a'){
            // printf("\n Found vertical from (%d, %d) to (%d, %d)", i, j, i, j + 3);
            return 1;
        }
        return 0;
    }
    else return 0;
}


int existsSouthEast(int i, int j, int N, int M){
    // Check if next four characters south east exist and if they do, they match 's','a','b','a'
    if (!outOfBounds(i + 3, j + 3, N, M)){
        if (A[i][j] == 's' && A[i + 1][j + 1] == 'a' && A[i + 2][j + 2] == 'b' && A[i + 3][j + 3] == 'a'){
            // printf("\n Found southeast from (%d, %d) to (%d, %d)", i, j, i + 3, j + 3);
            return 1;
        }
        return 0;
    }
    else return 0;
}

int existsNorthEast(int i, int j, int N, int M){
    // Check if next four characters south east exist and if they do, they match 's','a','b','a'
    if (!outOfBounds(i - 3, j + 3, N, M)){
        if (A[i][j] == 's' && A[i - 1][j + 1] == 'a' && A[i - 2][j + 2] == 'b' && A[i - 3][j + 3] == 'a'){
            // printf("\n Found northeast from (%d, %d) to (%d, %d)", i, j, i - 3, j + 3);
            return 1;
        }
        return 0;
    }
    else return 0;
}

int traverseInOrder(int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            // cout << "\n Testing " << i << " and " << j << "\n";
            numFound += existsEast(i, j, N, M);
            numFound += existsSouth(i, j, N, M);
            numFound += existsSouthEast(i, j, N, M);
            numFound += existsNorthEast(i, j, N, M);       
        }
    }
    return numFound;
}

int main(){
    int N, M;
    cin >> N >> M;
    char temp;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> temp;
            A[i][j] = temp;
        }
    }
    int res = traverseInOrder(N, M);
    cout << res << "\n";
    return 0;
}