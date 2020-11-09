#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r;
ll Q;
struct c{
	ll year;
	int month;
	int day;
	bool BC;
};
c Julian_day;
const int mday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int lday[13]={-1,30,59,90,120,151,181,212,243,273,304,334,365};
const int rday[13]={-1,29,58,89,119,149,179,211,242,272,303,333,364};
const int End_BC=146438;
const int End_old=723852;
const int Start_gl=724168;
inline void Cout(ll cD,ll cM,ll cY,bool iBC){
	if(iBC==true){
		cout<<cD<<" "<<cM<<" "<<cY<<" BC"<<"\n";
	}
	else if(iBC==false){
		cout<<cD<<" "<<cM<<" "<<cY<<"\n";
	}
}
inline void BC(ll julian){
	if(julian<365){
		int m_now;
		int k=julian;
		for(int i=1;i<=13;i++){
			if(julian<=lday[i]){
				m_now=i;
				julian=julian-lday[i-1];
				break;
			}
		}
		Cout(julian,m_now,Julian_day.year,true);
		return ;
	}
	if(julian==365){
		Cout(1,1,Julian_day.year-1,true);
	}
	if(julian>365){
//		julian++;
		int m_now,y_now=Julian_day.year;
		do{
			if(y_now%4==0)
			julian-=366;
			else
			julian-=365;
			y_now--;
//			cout<<julian<<endl;
		}while(julian>=366);
		ll k=julian;
		y_now++;	
		if(y_now%4==0){
			for(int i=1;i<=13;i++){
			if(julian<=rday[i]){
				m_now=i;
				julian=julian-rday[i-1];
				break;
			}
		}
			Cout(julian,m_now,y_now,true);
			return ;
		}
		else{
			for(int i=1;i<=13;i++){
				
			if(julian<=lday[i]){
				m_now=i;
				julian=julian-lday[i-1];
				break;
			}
			Cout(julian,m_now,y_now,true);
			return ;
		}	
	}
}
}
inline void DC1(ll julian){
		if(julian<365){
		int m_now;
		int k=julian;
		for(int i=1;i<=13;i++){
			if(julian<=lday[i]){
				m_now=i;
				julian=julian-lday[i-1];
				break;
			}
		}
		Cout(julian,m_now,Julian_day.year,true);
		return ;
	}
	if(julian==365){
		Cout(1,1,Julian_day.year-1,false);
	}
	if(julian>365){
//		julian++;
		int m_now,y_now=Julian_day.year;
		do{
			if(y_now%4==0)
			julian-=366;
			else
			julian-=365;
			y_now++;
//			cout<<julian<<endl;
		}while(julian>=366);
		ll k=julian;
		y_now++;	
		if(y_now%4==0){
			for(int i=1;i<=13;i++){
			if(julian<=rday[i]){
				m_now=i;
				julian=julian-rday[i-1];
				break;
			}
		}
			Cout(julian,m_now,y_now,false);
			return ;
		}
		else{
			for(int i=1;i<=13;i++){
				
			if(julian<=lday[i]){
				m_now=i;
				julian=julian-lday[i-1];
				break;
			}
			Cout(julian,m_now,y_now,false);
			return ;
		}	
	}
	}
} 
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	Julian_day.year=4713;
	Julian_day.month=1;
	Julian_day.day=1;
	Julian_day.BC=true;
	cin>>Q;
	while(Q--){
		cin>>r;
		if(r==End_BC){
		cout<<"1 1 1"<<"\n";
		continue;
//		continue;
		}
		if(r<End_BC){
			BC(r);
			continue;
		}
		if(r>End_BC&&r<End_old){
			DC1(r-End_BC);
			continue;
		}
	//	if(r<)
	//	while(r!=0){
			
	//	}
		}
	return 0;	
}
