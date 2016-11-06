// program for finding the longest common subsequence from two input sequences
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void prinL(int m,int n,int *a, int* b1, char b[][101]){
    if(m==0 || n==0)
        return;
    if(b[m][n]=='d'){
        prinL(m-1,n-1,a,b1,b);
        cout<<a[m-1]<<" ";
    }
    else if(b[m][n]=='s'){
        prinL(m,n-1,a,b1,b);
    }
    else
        prinL(m-1,n,a,b1,b);
        
}

int main() {
    int m,n;
    cout<<"Enter first sequence:"<<endl;
    cin>>m;
    cout<<"Enter second sequence:"<<endl;
    cin>>n;
    int a[m],b1[n];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b1[i];
    }
    int c=0;
    int l[m+1][n+1];
    for(int i=0;i<=m;i++)
        l[i][0]=0;
    for(int i=0;i<=n;i++)
        l[0][i]=0;
    
    char b[m+1][101];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b1[j-1]){
                l[i][j]=l[i-1][j-1]+1;
                b[i][j]='d';
            }
            else{
                if(l[i][j-1]>=l[i-1][j]){
                    l[i][j]=l[i][j-1];
                    b[i][j]='s';
                }
                else{
                    l[i][j]=l[i-1][j];
                    b[i][j]='u';
                }
            }
        }
    }
    
    cout<<"\n the longest common subsequence is:"
    prinL(m,n,a,b1,b);
    return 0;
}
