/*
    Author  :   Harshvardhan Singh ( harshvcode )
    Title   :   32 bit binary representation of number entered by user
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    printf("Enter the number(1-2147483647): ");
    cin >> n;
    for(int i=31; i>=0; i--)
        if(n & (1 << i)) cout << 1;
        else cout << 0;
    return 0;
} 