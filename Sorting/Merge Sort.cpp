#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
void conquer(int c[], int l, int mid, int r)
{
    //Left array
    int n = mid - l + 1; 
    int a[n];
    int k = l;
    for(int i = 0; i < n; i++, k++)
        a[i] = c[k];

    //Right array
    int m = r - mid;
    int b[m];
    k = mid + 1;
    for(int i = 0; i < m; i++)
        b[i] = c[k];

    int i = 0, j = 0, curr = l;
    while(i < n && j < m){
        if(a[i] < b[j]){
            c[curr] = a[i];
            i++;
            curr++;
        }
        else{
            c[curr] = b[j];
            j++;
            curr++;
        }
    }
    while(i < n){
        c[curr] = a[i];
        i++;
        curr++;
    }
    while(j < m){
        c[curr] = b[j];
        j++;
        curr++;
    }
}
void divide(int a[], int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    divide(a, l, mid);
    divide(a, mid + 1, r);
    conquer(a, l, mid, r);
}
int main() 
{
    int n; cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    divide(a, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}