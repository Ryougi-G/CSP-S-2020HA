#include <cstdio>
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

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int mod = 998244353;
inline int pls( int a , int b ) { a += b - mod; return a + ( a >> 31 & mod ); }
inline int mns( int a , int b ) { a -= b; return a + ( a >> 31 & mod ); }
inline void inc( int & a , int b ) { a += b - mod; a += a >> 31 & mod; }
inline void dec( int & a , int b ) { a -= b; a += a >> 31 & mod; }
FILE * _f; inline void file( void ) { _f = freopen("call.in","r",stdin); _f = freopen("call.out","w",stdout); }

int head[N] , eidx , nidx , n , m , q , dat[N] , ans[N] , tag , qry[N];
struct Edge { int nxt , to; } edge[M];
inline void addedge( int u , int v ) { edge[++eidx] = (Edge) { head[u] , v }; head[u] = eidx; }
struct OPT {
  int tp , a , b;
} opt[N];

void dfs( int u ) {
  if( opt[u].tp != 3 ) { 
    if( opt[u].tp == 1 )
      ans[opt[u].a] = ( ans[opt[u].a] + (lol)opt[u].b * tag ) % mod;
    else tag = (lol)tag * opt[u].b % mod;
    return;
  }
  for( int i = head[u] ; i ; i = edge[i].nxt )
    dfs( edge[i].to );
}

int main( void ) {
  file();
  read( n ) , tag = 1;
  for( int i = 1 ; i <= n ; ++i ) 
    read( dat[i] );
  read( m );
  for( int i = 1 ; i <= m ; ++i ) {
    read( opt[i].tp );
    if( opt[i].tp == 1 ) read( opt[i].a ) , read( opt[i].b );
    if( opt[i].tp == 2 ) read( opt[i].b );
    if( opt[i].tp == 3 ) {
      int c , v;
      read( c );
      while( c-- ) {
        read( v );
        addedge( i , v );
      }
    }
  }
  read( q );
  for( int i = 1 ; i <= q ; ++i )
    read( qry[i] );
  for( int i = q ; i ; --i ) 
    dfs( qry[i] );
  for( int i = 1 ; i <= n ; ++i )
    ans[i] = ( ans[i] + (lol)tag * dat[i] ) % mod;
  for( int i = 1 ; i <= n ; ++i )
    printf("%d ",ans[i]);
  return 0;
}

