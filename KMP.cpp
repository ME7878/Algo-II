#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void cm_lps(char* p,int N,int* lps)
{
    int i=1,len=0;
    lps[0] = 0;
    while(i<N)
    {
        if(p[i]==p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(len!=0)
        {
            len = lps[len-1];
        }
        else
        {
            lps[i]=0;
            i++;
        }
    }
    
    for(int i=0;i<N-1;i++)
    {
        cout<< lps[i] <<" , ";
    }
    cout<< lps[N-1] <<endl;
}

void kmp(char* t,char* p)
{
   int M = strlen(t);
   int N = strlen(p);
   cout<<"the length of main string :"<<M<<endl;
   cout<<"the length of pattern string:"<<N<<p[N]<<endl;
   int lps[N];
   cm_lps(p,N,lps);
   int i=0,j=0;
   while(i<M)
   {
       if (p[j] == t[i])
       {
            j++;
            i++;
        }
        // mismatch after j matches
        else if (j != 0) 
        {
                j = lps[j - 1];
        }
        else
        {
                i = i + 1;
             
        }
           if (j == N)
        {
            printf("\nFound pattern at index %d ", i - j);
            j = lps[j - 1];
        }
     
   }
}

int main() 
{
   char txt[] = "onionionspl";
   char pat[] = "onions";
   kmp(txt,pat);
}