#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;

    long long res = 1;

    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }

    cout << res << endl;

    return 0;
}