#include <iostream>
#include <vector>

using namespace std;

// 0 - lose, 1 - win
int rocks(int n, int m)
{
    // Использование std::vector для динамической матрицы
    vector<vector<int>> matrix(n, vector<int>(m));
    matrix[0][0] = 0;

    // First row
    for (int i = 1; i < m; i++)
    {
        if (i == 1 || i == 2)
        {
            matrix[0][i] = 1;
        }
        else if (i >= 3 && matrix[0][i - 1] == 1 && matrix[0][i - 2] == 1)
        {
            matrix[0][i] = 0;
        }
        else
        {
            matrix[0][i] = 1;
        }
    }

    // First column
    for (int i = 1; i < n; i++)
    {
        if (i == 1 || i == 2)
        {
            matrix[i][0] = 1;
        }
        else if (i >= 3 && matrix[i - 1][0] == 1 && matrix[i - 2][0] == 1)
        {
            matrix[i][0] = 0;
        }
        else
        {
            matrix[i][0] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (i == 1 && j == 1)
            {
                matrix[i][j] = 0;
                continue;
            }
            if (i == 1)
            {
                if (j >= 2 && matrix[i][j - 1] == 1 && matrix[i][j - 2] == 1)
                {
                    matrix[i][j] = 0;
                    continue;
                }
                else
                {
                    matrix[i][j] = 1;
                    continue;
                }
            }
            if (j == 1)
            {
                if (i >= 2 && matrix[i - 1][j] == 1 && matrix[i - 2][j] == 1)
                {
                    matrix[i][j] = 0;
                    continue;
                }
                else
                {
                    matrix[i][j] = 1;
                    continue;
                }
            }
            if (matrix[i][j - 1] == 1 && matrix[i - 1][j] == 1 && matrix[i - 2][j] == 1 &&
                matrix[i][j - 2] == 1 && matrix[i - 2][j - 1] == 1 && matrix[i - 1][j - 2] == 1)
            {
                matrix[i][j] = 0;
                continue;
            }
            else
            {
                matrix[i][j] = 1;
                continue;
            }
        }
    }

    return matrix[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    int answer = rocks(n + 1, m + 1);

    if (answer == 1)
    {
        cout << "Win" << endl;
    }
    else
    {
        cout << "Loose" << endl;
    }

    return 0;
}