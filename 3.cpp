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
using namespace std;


int n,c;
vector<int>v;
int checkcost(vector<int>v, int n)
{
    int j, cost = 0;
    for(int i = 0; i < n-1; i++) 
    {
        auto min = min_element(v.begin()+i, v.end());
        j = min - v.begin();
        reverse(v.begin()+i, min+1);
        cost = cost + j - i + 1 ;
    }
    return cost;
}

void printvec(vector<int>v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

void permute(vector<int>v,int n,int c,int &counter,int i = 0){
    if(i == v.size()-1){
        if(checkcost(v,n) == c){
            counter = counter*0;
            return;
        }
    }
    for(int j = i; j < v.size();j++)
    {
        swap(v[i],v[j]);
        permute(v,n,c,counter,i+1);
        swap(v[i],v[j]);
    }
}

void solve(){
    cin >> n >> c;
    int counter = 1;
    for(int i = n; i > 0; i--){
        v.push_back(i);
    }
    permute(v,n,c,counter);
    /*do {
        if(checkcost(v,n) == c){
            counter = counter*0;
            break;
        }
    } while (std::prev_permutation(v.begin(), v.end()));*/
    if(counter == 1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        printvec(v);
    }
    v.clear();
    cout << endl;
}


int main ()
{
    int t;
    cin >> t;
    int i = 1;
    while(t--){
        cout << "Case #" <<  i << ": ";
        solve();
        ++i;
    }
    return 0;
}
