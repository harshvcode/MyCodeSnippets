/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Program to find longest Autobiographic Numbers      *
 * subsequence in a sequence.			       		   *
 * 	( GeeksForGeeks Problem Solution )	    		   *
 * author : h2000vs223 | harshvs.official223@gmail.com *
 * timestamp : 18.05.2020_at_09:06:32  		       	   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include<bits/stdc++.h>
#define st string
#define lol long long
#define in int
#define pb push_back
#define ch char
#define lo long
#define db double
#define flo float
using namespace std;
bool isAutobio( st s , int len )
{
  int fst = s.at(0) - 48;
  for ( int j = 1 ; j < len ; j++ )
  {
    fst--;
  }
  return fst == 0;
}
int main()
{
  int n;
  cin >> n;
  st arr[n];
  for(int k = 0 ; k < n ; k++)
    cin >> arr[k];
  int j , mlen = 0 ;
  for(int m = 0 ; m < n ; m++)
  {
    j = m + 1;
    while( j < n )
    {
      if ( isAutobio( arr[j] , arr[j].size() ) ) mlen = max (mlen ,j - m);
      else break;
      j++;
    }
  } 
  cout << "Ans: " << mlen << '\n';
}
