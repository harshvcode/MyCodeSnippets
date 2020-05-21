/*
 * No.of even and odd index occured between zero to that number(0 to n-1)
 * author: h2000vs223 | harshvs.official223@gmail.com
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , noOfEvens = 0 , noOfOdds = 0;
	cin >> n;
	if(n % 2 == 0)//If no.is even
	{
		noOfEvens = n / 2;
		noOfOdds = n / 2;
	}
	else// when no.is odd
	{
		noOfEvens = ( n / 2 ) + 1;
		noOfOdds = n / 2;
	}
	cout << "No. of even indexes: " << noOfEvens << '\n';
	cout << "No. of odd indexes: " << noOfOdds << '\n';
	return 0;
}
