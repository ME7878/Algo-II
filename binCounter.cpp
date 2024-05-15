#include <bits/stdc++.h>
#include <stack>

using namespace std;
#define MAX 10

class binCounter
{
private:
    int n = 4, m = 15;
    int A[MAX];
    void initA()
    {
        for (int i = 0; i < n; i++)
        {
            A[i] = 0;
        }
        return;
    }
    void getM(){
        cout<<"Enter the Number To Count: "<<endl;
        cin>>m;
    }
    void getN(){
        n=0;
        int temp=m;
        while(temp>0){
            temp/=2;
            n++;
        }
    }
public:
    void count()
    {
        initA();
            cout << 0 <<" = 0 ";
            for (int j = n-2; j >= 0; j--)
            {
                cout << A[j] << " ";
            }
            cout<<endl;
        for (int i = 0; i < m; i++)
        {
            int j = 0;
            while (j < n)
            {
                if (A[j] == 0)
                {
                    A[j] = 1;
                    j = n;
                }
                else
                    A[j++] = 0;
            }
            cout << i+1 <<" = ";
            for (int j = n-1; j >= 0; j--)
            {
                cout << A[j] << " ";
            }
            cout<<endl;
        }
    }
    void countInput(){
        getM();
        getN();
        count();
        return;
    }
};

int main()
{
    binCounter A;
    char c;
    cout<<"Counting Till 15 In Binary"<<endl;
    A.count();
    cout<<"Do You Want To Input Number To Count?(Y/N)"<<endl;
    cin>>c;
    if(c=='y'||c=='Y')
    A.countInput();
    cout<<"Thank You."<<endl;
    return 0;
}