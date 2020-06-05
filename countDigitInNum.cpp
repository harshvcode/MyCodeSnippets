/* Count no. of digits in a decimal number( formula= (int)log10(num) +  1)
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 13:24 27-05-2020
 */
#include <bits/stdc++.h>
#define mod 1000000007
#define nl '\n'
#define lol long long
#define lo long
#define pb push_back
using namespace std;	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >>n;
	cout <<"Total no. of Digits in "<<n<<": "<<(int)log10(n) + 1<<nl;	
	return 0;
}
