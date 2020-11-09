#include<bits/stdc++.h>
using namespace std;
int tmp_month;
int tmp_day;
int tabl[15]={31,28,31,30,31,30,31,31,30,31,30,31};
int tabl_r[15]={31,29,31,30,31,30,31,31,30,31,30,31};
void day(int rest,int kind){
	if(rest==0){
		tmp_day=1;
		tmp_month=1;
	}
	if(kind==-1){
		int sum=0;
		for(int i=0;i<12;i++){
			sum+=tabl[i];
			if(rest==sum){
				tmp_day=1;
				tmp_month=i+2;
				return ;
			}else if(rest<sum){
				tmp_month=i+1;
				tmp_day=rest+1-(sum-tabl[i]);
				return ;
			}
		}
	}else if(kind==-2){
		int sum=0;
		for(int i=0;i<12;i++){
			sum+=tabl_r[i];
			if(rest==sum){
				tmp_day=1;
				tmp_month=i+2;
				return ;
			}else if(rest<sum){
				tmp_month=i+1;
				tmp_day=rest+1-(sum-tabl_r[i]);
				return ;
			}
		}
	}
}
void ans(int x){
	if(x<=1721424-1){
		int tim_4=0;
		int tim_1=0;
		tim_4=x/(366+365+365+365);
		x-=tim_4*(366+365+365+365);
		if(x==0){
			day(x,-1);
		}else if(x<366){;
			tim_1=0;
			day(x,-2);
		}else if(x<366+365){
			tim_1=1;
			x-=366;
			day(x,-1);
		}else if(x<366+365+365){;
			tim_1=2;
			x-=366+365;
			day(x,-1);
		}else{
			tim_1=3;
			x-=366+365+365;
			day(x,-1);
		}
		cout<<tmp_day<<" "<<tmp_month<<" "<<4713-(tim_4*4+tim_1)<<" BC"<<endl;
	}else{
		x-=1721424;//to AC 1 1 1 
		if(x<577738){
			int tim_4=0;
			int tim_1=0;
			tim_4=x/(366+365+365+365);
			x-=tim_4*(366+365+365+365);
			if(x==0){
				day(x,-1);
			}else if(x<365){
				tim_1=0;
				day(x,-1);
			}else if(x<365+365){
				tim_1=1;
				x-=365;
				day(x,-1);
			}else if(x<365+365+365){
				tim_1=2;
				x-=365+365;
				day(x,-1);
			}else{
				tim_1=3;
				x-=365+365+365;
				day(x,-2);
			}
			cout<<tmp_day<<" "<<tmp_month<<" "<<1+tim_4*4+tim_1<<endl;
		}else{
			x-=577738;//to AC 1582 10 15
			if(x<17+30+31){
				if(x<17){
					cout<<15+x<<" 10 1582"<<endl;
				}else if(x==17){
					cout<<"1 11 1582"<<endl;
				}else if(x<17+30){
					cout<<x-17<<" 11 1582"<<endl;
				}else if(x==17+30){
					cout<<"1 12 1582"<<endl;
				}else{
					cout<<x-17-30<<" 12 1582"<<endl;
				}
			}else{
				x-=17+30+31;//to AC 1583 1 1
				if(x<6209){
					if(x==0){
						cout<<"1 1 1583"<<endl;
					}if(x<365){
						day(x,-1);
						cout<<tmp_day<<" "<<tmp_month<<" 1583";
					}else if(x==365){
						cout<<"1 1 1584"<<endl;
					}if(x<731){
						day(x-365,-1);
						cout<<tmp_day<<" "<<tmp_month<<" 1584";
					}else if(x==731){
						cout<<"1 1 1585";
					}else if(x<2192){
						int qwq=(x-731)/365;
						day((x-731)-(x-731)*qwq*365,-1);
						cout<<tmp_day<<" "<<tmp_month<<" "<<1584+qwq;
					}else if(x==2192){
						cout<<"1 1 1589"<<endl;
					}else if(x<3653){
						int qwq=(x-2192)/365;
						day((x-2192)-(x-2192)*qwq*365,-1);
						cout<<tmp_day<<" "<<tmp_month<<" "<<1588+qwq;
					}else if(x==3653){
						cout<<"1 1 1593"<<endl;
					}else if(x<5114){
						int qwq=(x-3653)/365;
						day((x-3653)-(x-3653)*qwq*365,-1);
						cout<<tmp_day<<" "<<tmp_month<<" "<<1592+qwq;
					}else if(x==5114){
						cout<<"1 1 1597"<<endl;
					}else{
						int qwq=(x-5114)/365;
						day((x-5114)-(x-5114)*qwq*365,-1);
						cout<<tmp_day<<" "<<tmp_month<<" "<<1596+qwq;
					}
				}else{
					x-=6209;//to AC 1600 1 1
					int tim_f_h=x/(365*400+97);
					x-=tim_f_h*(365*400+97);
					if(x<=(365*100+24)*3){
						int tim_o_h=x/(365*100+24);
						x-=tim_o_h*(365*100+24);
						if(x<=(365*4+1)*24){
							int tim_f=x/(365*4+1);
							x-=tim_f*(365*4+1);
							int tim_1;
							if(x==0){
								day(x,-2);
							}else if(x<365){
								tim_1=0;
								day(x,-2);
							}else if(x<365+365){
								tim_1=1;
								x-=365;
								day(x,-1);
							}else if(x<365+365+365){
								tim_1=2;
								x-=365+365;
								day(x,-1);
							}else{
								tim_1=3;
								x-=365+365+365;
								day(x,-1);
							}
							cout<<tmp_day<<" "<<tmp_month<<" "<<1600+tim_f_h*400+tim_o_h*100+tim_f*4+tim_1<<endl;
						}else{
							int tim_f=24;
							x-=tim_f*(365*4+1);
							int tim_1;
							if(x==0){
								day(x,-1);
							}else if(x<365){
								tim_1=0;
								day(x,-1);
							}else if(x<365+365){
								tim_1=1;
								x-=365;
								day(x,-1);
							}else if(x<365+365+365){
								tim_1=2;
								x-=365+365;
								day(x,-1);
							}else{
								tim_1=3;
								x-=365+365+365;
								day(x,-1);
							}
							cout<<tmp_day<<" "<<tmp_month<<" "<<1600+tim_f_h*400+tim_o_h*100+tim_f*4+tim_1<<endl;
						}
					}else{
						int tim_o_h=3;
						x-=tim_o_h*(365*100+24);
						int tim_f=x/(365*4+1);
						x-=tim_f*(365*4+1);
						int tim_1;
						if(x==0){
							day(x,-2);
						}else if(x<365){
							tim_1=0;
							day(x,-2);
						}else if(x<365+365){
							tim_1=1;
							x-=365;
							day(x,-1);
						}else if(x<365+365+365){
							tim_1=2;
							x-=365+365;
							day(x,-1);
						}else{
							tim_1=3;
							x-=365+365+365;
							day(x,-1);
						}
						cout<<tmp_day<<" "<<tmp_month<<" "<<1600+tim_f_h*400+tim_o_h*100+tim_f*4+tim_1<<endl;
					}
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t,y;
	cin>>t;
	while(t--){
		cin>>y;
		ans(y);
	}
	return 0;
} 
