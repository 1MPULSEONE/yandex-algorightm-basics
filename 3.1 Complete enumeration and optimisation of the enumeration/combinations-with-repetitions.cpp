#include <iostream>
#include <vector>
#include <string>

using namespace std;

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

int main()
{

    int n, k;
    cin >> n >> k;

    int fN = factorial(n + k - 1);
    int determinator = factorial(k) * factorial(n - 1);

    cout << fN / determinator << endl;

    return 0;
}
