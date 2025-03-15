#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline "\n"
int main() 
{
    int n; cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int val; cin>>val;

    int flag = 0;
    int l = 0, r = n - 1;

    while(l <= r){
        int mid = (l + r) / 2;

        if(a[mid] == val){
            flag = 1;
            break;
        }
        else if(a[mid] > val)
            r = mid - 1;
        else
            l = mid + 1;
    }

    if(flag)
        cout<<"Found";
    else 
        cout<<"Not Found";
}
