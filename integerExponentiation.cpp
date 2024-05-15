#include <bits/stdc++.h>

using namespace std;

int intExpoResult(int Z, int N)
{
    int Y = 1;
    while (N != 0)
    {
        if (N % 2 != 0)
        {
            Y = Z * Y;
        }
        N /= 2;
        if (N != 0)
        {
            Z = Z * Z;
        }
    }
    return Y;
}

int main()
{
    int x, n;
    cout << "\nEnter The Integer : ";
    cin >> x;
    cout << "\nEnter The Expo : ";
    cin >> n;
    int result = intExpoResult(x, n);
    cout<<"\nThe Result of "<<x<<"^"<<n<<" is : ";
    cout << result << endl;
    return 0;
}