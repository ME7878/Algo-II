#include <bits/stdc++.h>

using namespace std;

class batcher
{
private:
    int n;
    int *A;
    int *sort(int low, int no);
    int *merge(int u[], int v[], int m, int n);
    void compareInterchange(int *u, int *v);

public:
    void setArr();
    void print();
    void printSorted();
};

void batcher ::setArr()
{
    cout << "Enter The Number Of Elements In The Arrey: " << endl;
    cin >> n;
    A = new int[n];
    cout << "Enter The " << n << " Elements Of The Arrey: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << endl;
    return;
}
void batcher ::print()
{
    cout << "The " << n << " Elements Of The Arrey Are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}
void batcher ::printSorted()
{
    A = sort(0, n);
    cout << "After Sorting The " << n << " Elements Of The Arrey Are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}
int *batcher ::sort(int low, int no)
{
    int *s;
    if (no > 1)
    {
        int m = no / 2;
        int n1 = no - m;
        int *u = new int[m];
        int *v = new int[n1];
        u = sort(low, m);
        v = sort(low + m, n1);
        s = merge(u, v, m, n1);
        return s;
    }
    else
    {
        s = new int[1];
        s[0] = A[low];
        return s;
    }
}
void batcher::compareInterchange(int *a, int *b)
{
    if (*a < *b)
    {
        *a += *b;
        *b = *a - *b;
        *a = *a - *b;
    }
    return;
}
int *batcher::merge(int *u, int *v, int m, int n1)
{
    int *s;
    int x, y, c = (m / 2) + (n1 / 2);
    if (m == 0)
    {
        s = new int[1];
        s[0] = v[0];
    }
    else if (n == 0)
    {
        s = new int[1];
        s[0] = u[0];
    }
    else if (m == 1 && n1 == 1)
    {
        compareInterchange(&v[0], &u[0]);
        s = new int[2];
        s[0] = u[0];
        s[1] = v[0];
    }
    else
    {
        if (m % 2 == 1)
            x = m / 2 + 1;
        else
            x = m / 2;
        if (n1 % 2 == 1)
            y = n1 / 2 + 1;
        else
            y = n1 / 2;
        int *ou = new int[x];
        int *ov = new int[y];
        for (int i = 0, j = 0; i < m; i += 2, j++)
        {
            ou[j] = u[i];
        }
        for (int i = 0, j = 0; i < n1; i += 2, j++)
        {
            ov[j] = v[i];
        }
        int *a = new int[x + y];
        a = merge(ou, ov, x, y);
        int *eu = new int[m / 2];
        int *ev = new int[n1 / 2];
        for (int i = 1, j = 0; i < m; i += 2, j++)
        {
            eu[j] = u[i];
        }
        for (int i = 1, j = 0; i < n1; i += 2, j++)
        {
            ev[j] = v[i];
        }
        int *b = new int[(m / 2) + (n1 / 2)];
        b = merge(eu, ev, m / 2, n1 / 2);
        if (m % 2 == 0 && n1 % 2 == 0)
            c = (m / 2) + (n1 / 2) - 1;
        for (int i = 1; i <= c; i++)
        {
            compareInterchange(&a[i], &b[i - 1]);
        }
        s = new int[m + n1];
        int j = 0;
        s[j++] = a[0];
        for (int i = 1; i <= c; i++)
        {
            s[j++] = b[i - 1];
            s[j++] = a[i];
        }
        if (m % 2 == 0 && n1 % 2 == 0)
        {
            s[j++] = b[(m / 2) + (n1 / 2) - 1];
        }
        if (m % 2 == 1 && n1 % 2 == 1)
        {
            s[j++] = a[(m / 2) + (n1 / 2) + 1];
        }
    }
    return s;
}

int main()
{
    batcher obj;
    obj.setArr();
    obj.print();
    obj.printSorted();
    return 0;
}