#include <iostream>
#include <thread>
#include <fstream>
#define N 100
#define M 100
using namespace std;
char field[N][M];
int steps[N][M];

void Search(int i, int j, int step)
{
    if(steps[i][j] <= step) return;
    steps[i][j] = step;
    if(field[i][j] == 'E') return;
    if((i + 1 < N )&& (field[i + 1][j] != '#'))
        Search(i + 1, j,  step + 1);
    if((i - 1 >= 0)&& (field[i - 1][j] != '#'))
        Search(i - 1, j, step + 1);
    if((j + 1 < M )&& (field[i][j + 1] != '#'))
        Search(i, j + 1, step + 1);
    if((j - 1 >= 0)&& (field[i][j - 1] != '#'))
        Search(i, j - 1, step + 1);
    if((i + 1 < N ) && (j + 1 < M ) && (field[i + 1][j + 1] != '#'))
        Search(i + 1, j + 1,  step + 1);
    if((i - 1 >= 0)&& (j + 1 < M ) &&  (field[i - 1][j + 1] != '#'))
        Search(i - 1, j + 1, step + 1);
    if((j - 1 >= 0 ) && (i + 1 < N ) && (field[i + 1][j - 1] != '#'))
        Search(i + 1, j - 1, step + 1);
    if((j - 1 >= 0) && (i - 1 >= 0) && (field[i - 1][j - 1] != '#'))
        Search(i - 1, j - 1, step + 1);
}



int main()
{
    int si, sj, ei, ej;
    int n, m;
    ifstream in("input.txt");
    in >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            in >> field[i][j];
            steps[i][j] = INT_MAX;
            if(field[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            else if(field[i][j] == 'E')
            {
                ei = i;
                ej = j;
            }
        }
    }
    Search(si, sj, 0);
    cout << steps[ei][ej];

    return 0;
}
