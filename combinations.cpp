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

    int terminator = factorial(n);
    int determinator = factorial(k) * factorial(n - k);

    cout << terminator / determinator << endl;

    return 0;
}
