/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Title: [ PROGRAM THAT ARRANGES A SEQUENCE OF INTEGERS BY  *
 *	  SEPERATING EVEN ELEMENTS FIRST ,ODDS AFTER EVENS ] *
 * Author: h2000vs223 (harshvs.official223@gmail.com)        *
 * Time_stamp: 13 May 2020 18:44:26		      	     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter size of sequence: ";
  cin >> n;
  int arr[n];
  for ( int i = 0 ; i < n ; i++ )
    cin >> arr[i];
  cout << "\nBefore seperation: ";
  for ( int x : arr ) cout << x <<' ';
  cout << '\n';
  int evnFind;
  bool found = false;
  for( int i = 0 ; i < n ; i++ )
  {
    if( arr[i] % 2 != 0 )
    {
      evnFind = i;
      found = false;
      while( evnFind != n )
      {
        if ( arr[evnFind] % 2 == 0 )
        {
          swap( arr[i] , arr[evnFind] );
          found = true; break;
        }
        evnFind++;
      }
      if( ! found ) break;
    }
  }
  cout << "After seperation: ";
  for( int x: arr) cout<<x <<' ';
}
