#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    long long c1=0;
    long long c2=0;
    
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        long long temp=max(c1, c2 + x);
        c2=c1;
        c1=temp;
    }
    
    cout<<c1<<endl;
    return 0;
}