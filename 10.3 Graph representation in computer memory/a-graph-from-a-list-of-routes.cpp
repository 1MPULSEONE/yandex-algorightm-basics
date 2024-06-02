#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Initialise vectors for storing adjacency graphs

    vector<vector<bool>> adj_matrix_1(n, vector<bool>(n, false));
    vector<vector<bool>> adj_matrix_2(n, vector<bool>(n, false));

    // Reading the routes line by line
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        vector<int> stops(k);
        for (int j = 0; j < k; j++)
        {
            cin >> stops[j];
        }

        // Build the first graph.

        /* We construct the first graph according to the following algorithm. Set the value true for each element of
        the two-dimensional array, the first index of which is the current number - 1,
        and the second index is the next number - 1.
        We also swap the indices and set true (because the adjacency matrix is symmetric).*/

        for (int j = 0; j < k - 1; j++)
        {
            adj_matrix_1[stops[j] - 1][stops[j + 1] - 1] = true;
            adj_matrix_1[stops[j + 1] - 1][stops[j] - 1] = true;
        }

        // Build the second graph.

        /* We construct the second graph similarly to the first one, but we use this algorithm not only for the current
        and the next element, but for the current and all subsequent elements. To realise this, we use two nested loops*/
        for (int j = 0; j < k; j++)
        {
            for (int l = j + 1; l < k; l++)
            {
                adj_matrix_2[stops[j] - 1][stops[l] - 1] = true;
                adj_matrix_2[stops[l] - 1][stops[j] - 1] = true;
            }
        }
    }

    // Output of the first graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                cout << adj_matrix_1[i][j] << "";
                break;
            }
            cout << adj_matrix_1[i][j] << " ";
        }
        cout << endl;
    }

    // Output of the second graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                cout << adj_matrix_2[i][j] << "";
                break;
            }
            cout << adj_matrix_2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}