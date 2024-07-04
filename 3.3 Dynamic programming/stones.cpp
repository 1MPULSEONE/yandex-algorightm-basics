#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string Rocks(int i, int j)
{
    if (i % 2 != 0 || j % 2 != 0)
    {
        return "Win";
    }
    return "Loose";
}

int main()
{
    int n, m;
    cin >> n >> m;
    string ans = Rocks(n, m);

    cout << ans << endl;
    return 0;
}