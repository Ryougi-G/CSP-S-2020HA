#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

namespace IO {
  const int IN_LEN = 1 << 18 | 1;
  static char buf[IN_LEN] , *s , *t;
  inline int Getchar( void ) { return s == t && ( t = ( s = buf ) + fread( buf , 1 , IN_LEN , stdin ) ) , s == t ? -1 : *s++; }
  template <class T> inline void read( T & x ) {
    static int c , f; c = Getchar() , x = f = 0;
    while( c < '0' || c > '9' ) { if( c == '-' ) f = 1; c = Getchar(); }
    while( c <= '9' && c >= '0' ) x = x * 10 + c - 48 , c = Getchar();
    x = f ? -x : x;
  }
} using IO::read;

using namespace std;

typedef long long lol;
typedef unsigned long long ull; 

const int N = 1e6 + 5;
int _w; FILE * _f;

inline void file( void ) { _f = freopen("zoo.in","r",stdin) , _f = freopen("zoo.out","w",stdout); }


int n , m , c , k;
ull tot , now , ans , mask;

int main( void ) {
  file();
  read( n ) , read( m ) , read( c ) , read( k );
  for( int i = 1 ; i <= n ; ++i ) {
    read( now );
    tot |= now;
  }
  int a , b;
  for( int i = 1 ; i <= m ; ++i ) {
    read( a ) , read( b );
    mask |= ( 1ull << a );
  }
  int cnt = 0;
  for( int i = 0 ; i < k ; ++i ) 
    if( ( tot >> i ) & 1 ) {
      ++cnt;
    } else {
      if( (~mask) >> i & 1 )
        ++cnt;
    }
  if( cnt == 64 ) {
    if( n == 0 ) {
      puts("18446744073709551616");
      return 0;
    }
    ans = 18446744073709551615ull - n + 1;
  } else 
    ans = ( 1ull << cnt ) - n;
  printf("%llu",ans);
  return 0;
}
