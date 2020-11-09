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

const int N = 1e6 + 5;
FILE * _f;
inline void file( void ) { _f = freopen("snakes.in","r",stdin); _f = freopen("snakes.out","w",stdout); }

int n , dat[N] , m;

inline int Rand( int L , int R ) {
  return L + rand() % ( R - L + 1 );
}

inline void work( void ) {
  sort( dat + 1 , dat + 1 + n );
  if( n == 3 ) {
    if( dat[3] >= dat[1] + dat[2] ) {
      puts("1");
      return;
    }
    puts("3");
    return;
  }
  int ans = 0;
  srand( 'g' + 'u' + 'y' + 'a' + 'n' );
  int cur = 1;
  int las = dat[n];
  while( cur < n && dat[n] >= dat[cur] ) 
    dat[n] -= dat[cur++] , ++ans;
  dat[n] = las;
  if( cur == n ) {
    printf("%d\n",n);
    return;
  }
  printf("%d\n", n - Rand( 0 , ans ) );
}

int main( void ) {
  file();
  int T;
  read( T );
  read( n );
  for( int i = 1 ; i <= n ; ++i ) read( dat[i] );
  work();
  while( --T ) {
    read( m );
    for( int i = 1 , a , b ; i <= m ; ++i ) {
      read( a ) , read( b );
      dat[a] = b;
    }
    work();
  }
  return 0;
}
