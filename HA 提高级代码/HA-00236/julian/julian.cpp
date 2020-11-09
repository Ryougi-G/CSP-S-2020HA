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
const int _Days[13] = { 0 , 31 , -1 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
const int _1582_10_4 = 2299160;
const int _1600_1_1 = 2305448;
const int _1582_11_1 = 2299178;
const int _1582_10_15 = 2299161;
const lol BG = -4712;
FILE * _f; int _w;
inline void file( void ) { _f = freopen("julian.in","r",stdin); _f = freopen("julian.out","w",stdout ); }

int Days[13];

lol year , m , d;

void getdays( void ) {
  memcpy( Days , _Days , sizeof Days );
  if( year < 0 ) {
    if( ( -year ) % 4 == 0 ) 
      Days[2] = 29;
    else Days[2] = 28;
  } else {
    if( year <= 1582 ) {
    if( year % 4 == 0 )
      Days[2] = 29;
    else Days[2] = 28;
    } else {
      bool fl = 0;
      if( ( ( year % 100 ) && ( year % 4 == 0 ) ) || ( ( year % 100 == 0 ) && ( year % 400 == 0 ) ) )
        fl = 1;
      if( fl ) 
        Days[2] = 29;
      else Days[2] = 28;
    }
  }
}

int T;
lol n;

void _PRINT( void ) {
  printf("%lld %lld ",d,m);
  if( year <= 0 ) {
    printf("%lld BC\n",(-year) + 1);
  } else printf("%lld\n",year);
}

void _NOMAL_CALC_DAYS( void ) {
  getdays();
  m = 1 , d = 1;
  while( n >= Days[m] ) 
    n -= Days[m] , ++m;
  d += n;
}

void _NOMAL_CALC( void ) {
  static const int _4y = 1461;
  year = BG + ( n / _4y ) * 4;
  n %= _4y;
  if( n <= 365 ) {
    _NOMAL_CALC_DAYS();
    return;
  }
  n -= 366 , ++year;
  while( n >= 365 )
    n -= 365 , ++year;
  _NOMAL_CALC_DAYS();
}

void __SPECIAL_CALC( void ) {
  static const int SP_YEARS[19] = { 
365,730,1096,1461,1826,2191,2557,2922,3287,3652,4018,4383,4748,5113,5479,5844,6209,6574};
  static const int _1582_1_1 = 2298874;
  n -= _1582_1_1;
  year = 1582;
  int tmp = upper_bound( SP_YEARS , SP_YEARS + 19 , n ) - SP_YEARS;
  year += tmp;
  if( tmp ) n -= SP_YEARS[tmp - 1];
  _NOMAL_CALC_DAYS();
}

void _SPECIAL_CALC( void ) {
  if( n < _1600_1_1 ) {
    __SPECIAL_CALC();
    return;
  }
  static const int _4y = 1461;
  static const int _400y = 146097;
  n -= _1600_1_1;
  year = 1600 + ( n / _400y ) * 400;
  n %= _400y;
  bool fl = 0;
  if( n >= 36525 ) {
    n -= 36525 , year += 100 , fl = 1;
    while( n >= 36524 ) n -= 36524 , year += 100;
  }
  bool _ff = 0;
  if( fl ) {
    if( n >= 365 ) n -= 365 , ++year , _ff = 1;
  } else {
    if( n >= 366 ) n -= 366 , ++year , _ff = 1;
  }
  year += ( n / _4y ) * 4;
  n %= _4y;
  if( _ff ) {
    int t = 0;
    while( n >= 365 && t < 3 ) n -= 365 , ++year , ++t;
  }
  _NOMAL_CALC_DAYS();
}

inline void work( void ) {
  if( n <= _1582_10_4 ) _NOMAL_CALC();
  else _SPECIAL_CALC();
  _PRINT();
}

int main( void ) {
  file();
  read( T );
  while( T-- ) {
    read( n );
    work();
  }
  return 0;
}
