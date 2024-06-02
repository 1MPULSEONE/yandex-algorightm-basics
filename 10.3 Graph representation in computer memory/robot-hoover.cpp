#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> room(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char input;
            cin >> input;
            switch (input)
            {
            case '.':
                room[i][j] = 1;
                break;
            case '#':
                room[i][j] = -1;
                break;
            }
        }
    }

    int r, c;
    cin >> r >> c;
    r = r - 1;
    c = c - 1;

    int commCount;
    cin >> commCount;

    string commands;
    cin >> commands;

    int direction = 0; // 0 - UP, 1 - LEFT, 2 - DOWN, 3 - RIGHT
    int resCount = 1;
    room[r][c] = 0;

    for (char command : commands)
    {
        switch (command)
        {
        case 'M':
            // Move UP
            if (r > 0 && room[r - 1][c] != -1 && direction == 0)
            {
                resCount += room[r - 1][c];
                room[r - 1][c] = 0;
                r -= 1;
            }
            // Move LEFT
            else if (c > 0 && room[r][c - 1] != -1 && direction == 1)
            {
                resCount += room[r][c - 1];
                room[r][c - 1] = 0;
                c -= 1;
            }
            // Move DOWN
            else if (r < room.size() - 1 && room[r + 1][c] != -1 && direction == 2)
            {
                resCount += room[r + 1][c];
                room[r + 1][c] = 0;
                r += 1;
            }
            // Move RIGHT
            else if (c < room[r].size() - 1 && room[r][c + 1] != -1 && direction == 3)
            {
                resCount += room[r][c + 1];
                room[r][c + 1] = 0;
                c += 1;
            }
            break;
        case 'L':
            direction = (direction + 1) % 4;
            break;
        case 'R':
            direction = (direction + 3) % 4;
            break;
        }
    }

    cout << resCount << " ";
    return 0;
}