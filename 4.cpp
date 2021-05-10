/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <iostream>
#include<assert.h>
using namespace std;

void printvec(vector<int>v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

int query(int i,int j, int k){
    cout << i << j << k << endl;
    int resp;
    cin >> resp;
    return resp;
}

void solve(int n, int &q){
    int med;
    vector<int>v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    if(q > 0){
        for(int i = 1; i <= n-2; i++)
        {
            med = query(i,i+1,i+2);
            q--;
            if(med == i)
                swap(v[i],v[i+1]);
            if(med == i+2)
                swap(v[i+1],v[i+2]);
        }
    }
    printvec(v);
    int ans;
    cin >> ans;
    assert(ans == 1);
}


int main ()
{
    int t,n,q;
    cin >> t >> n >> q;
    while(t--){
        solve(n,q);
    }
    return 0;
}


