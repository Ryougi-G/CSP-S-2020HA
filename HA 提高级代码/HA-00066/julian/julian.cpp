#include <iostream>
#include <cstdio>
using namespace std;
long long q,p,x,y,z,year;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>p;
		if(p<1721424){
			x=p/1461;
			year=4713-x*4-(p%1461-1)/365;
			p-=(4713-year)*365+(4716-year)/4;
			if(year%4==1){
				if(p<31){
					cout<<p+1<<" "<<1<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<60){
					cout<<p-30<<" "<<2<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<91){
					cout<<p-59<<" "<<3<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<121){
					cout<<p-90<<" "<<4<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<152){
					cout<<p-120<<" "<<5<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<182){
					cout<<p-151<<" "<<6<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<213){
					cout<<p-181<<" "<<7<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<244){
					cout<<p-212<<" "<<8<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<274){
					cout<<p-243<<" "<<9<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<305){
					cout<<p-273<<" "<<10<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<335){
					cout<<p-304<<" "<<11<<" "<<year<<" "<<"BC"<<endl;
				}else{
					cout<<p-334<<" "<<12<<" "<<year<<" "<<"BC"<<endl;
				}
			}else{
				if(p<31){
					cout<<p+1<<" "<<1<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<59){
					cout<<p-30<<" "<<2<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<90){
					cout<<p-58<<" "<<3<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<120){
					cout<<p-89<<" "<<4<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<151){
					cout<<p-119<<" "<<5<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<181){
					cout<<p-150<<" "<<6<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<212){
					cout<<p-180<<" "<<7<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<243){
					cout<<p-211<<" "<<8<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<273){
					cout<<p-242<<" "<<9<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<304){
					cout<<p-272<<" "<<10<<" "<<year<<" "<<"BC"<<endl;
				}else if(p<334){
					cout<<p-303<<" "<<11<<" "<<year<<" "<<"BC"<<endl;
				}else{
					cout<<p-333<<" "<<12<<" "<<year<<" "<<"BC"<<endl;
				}
			}
		}else if(p<2305448){
		    if(p>2299160){
		    	p+=10;
		    }
			p-=1721424;
			x=p/1461;
			if(p%1461==1460){
				cout<<31<<" "<<12<<" "<<x*4+3<<endl;
			}else{
				year=x*4+(p%1461)/365+1;
				p-=(year-1)*365+(year-1)/4;
				if(year%4==0){
				    if(p<31){
					    cout<<p+1<<" "<<1<<" "<<year<<endl;
				    }else if(p<60){
					    cout<<p-30<<" "<<2<<" "<<year<<endl;
				    }else if(p<91){
					    cout<<p-59<<" "<<3<<" "<<year<<endl;
				    }else if(p<121){
					    cout<<p-90<<" "<<4<<" "<<year<<endl;
				    }else if(p<152){
					    cout<<p-120<<" "<<5<<" "<<year<<endl;
				    }else if(p<182){
					    cout<<p-151<<" "<<6<<" "<<year<<endl;
				    }else if(p<213){
					    cout<<p-181<<" "<<7<<" "<<year<<endl;
				    }else if(p<244){
					    cout<<p-212<<" "<<8<<" "<<year<<endl;
				    }else if(p<274){
					    cout<<p-243<<" "<<9<<" "<<year<<endl;
				    }else if(p<305){
					    cout<<p-273<<" "<<10<<" "<<year<<endl;
				    }else if(p<335){
					    cout<<p-304<<" "<<11<<" "<<year<<endl;
				    }else{
					    cout<<p-334<<" "<<12<<" "<<year<<endl;
				    }
			    }else{
				    if(p<31){
					    cout<<p+1<<" "<<1<<" "<<year<<endl;
				    }else if(p<59){
					    cout<<p-30<<" "<<2<<" "<<year<<endl;
				    }else if(p<90){
					    cout<<p-58<<" "<<3<<" "<<year<<endl;
				    }else if(p<120){
					    cout<<p-89<<" "<<4<<" "<<year<<endl;
				    }else if(p<151){
					    cout<<p-119<<" "<<5<<" "<<year<<endl;
				    }else if(p<181){
					    cout<<p-150<<" "<<6<<" "<<year<<endl;
				    }else if(p<212){
					    cout<<p-180<<" "<<7<<" "<<year<<endl;
				    }else if(p<243){
					    cout<<p-211<<" "<<8<<" "<<year<<endl;
				    }else if(p<273){
					    cout<<p-242<<" "<<9<<" "<<year<<endl;
				    }else if(p<304){
					    cout<<p-272<<" "<<10<<" "<<year<<endl;
				    }else if(p<334){
					    cout<<p-303<<" "<<11<<" "<<year<<endl;
				    }else{
					    cout<<p-333<<" "<<12<<" "<<year<<endl;
				    }
			    }
		    }
	    }else{
	    	p-=2305448;
	    	x=p/146097;
	    	z=p%146097;
	    	if(z<36525){
	    		y=z/1461;
	    		if(z%1461<366){
	    			year=1600+x*400+y*4;
	    		}else{
	    			year=1600+x*400+y*4+(z%1461-366)/365+1;
	    		}
	    	}else if(z<73049){
	    		z-=36525;
	    		y=z/1461;
	    		if(z==1460){
	    			year=1700+x*400+y*4+3;
	    		}else{
	    			year=1700+x*400+y*4+(z%1461)/365;
	    		}
	    	}else if(z<109578){
	    		z-=73049;
	    		y=z/1461;
	    		if(z==1460){
	    			year=1800+x*400+y*4+3;
	    		}else{
	    			year=1800+x*400+y*4+(z%1461)/365;
	    		}
	    	}else{
	    		z-=109578;
	    		y=z/1461;
	    		if(z==1460){
	    			year=1900+x*400+y*4+3;
	    		}else{
	    			year=1900+x*400+y*4+(z%1461)/365;
	    		}
	    	}
	    	p-=(year-1600)*365+(year-1600)/4+(year-1600)/400-(year-1600)/100;
	    	if(year>1600){
	    		p-=1;
	    	}
	    	if((year%4==0&&year%100!=0)||year%400==0){
				if(p<31){
					cout<<p+1<<" "<<1<<" "<<year<<endl;
				}else if(p<59){
					cout<<p-30<<" "<<2<<" "<<year<<endl;
				}else if(p<90){
					cout<<p-58<<" "<<3<<" "<<year<<endl;
				}else if(p<120){
					cout<<p-89<<" "<<4<<" "<<year<<endl;
				}else if(p<151){
					cout<<p-119<<" "<<5<<" "<<year<<endl;
				}else if(p<181){
					cout<<p-150<<" "<<6<<" "<<year<<endl;
				}else if(p<212){
					cout<<p-180<<" "<<7<<" "<<year<<endl;
				}else if(p<243){
					cout<<p-211<<" "<<8<<" "<<year<<endl;
				}else if(p<273){
					cout<<p-242<<" "<<9<<" "<<year<<endl;
				}else if(p<304){
					cout<<p-272<<" "<<10<<" "<<year<<endl;
				}else if(p<334){
					cout<<p-303<<" "<<11<<" "<<year<<endl;
				}else{
					cout<<p-333<<" "<<12<<" "<<year<<endl;
				}
			}else{
				if(p<31){
					cout<<p+1<<" "<<1<<" "<<year<<endl;
				}else if(p<59){
					cout<<p-30<<" "<<2<<" "<<year<<endl;
				}else if(p<90){
					cout<<p-58<<" "<<3<<" "<<year<<endl;
				}else if(p<120){
					cout<<p-89<<" "<<4<<" "<<year<<endl;
				}else if(p<151){
					cout<<p-119<<" "<<5<<" "<<year<<endl;
				}else if(p<181){
					cout<<p-150<<" "<<6<<" "<<year<<endl;
				}else if(p<212){
					cout<<p-180<<" "<<7<<" "<<year<<endl;
				}else if(p<243){
					cout<<p-211<<" "<<8<<" "<<year<<endl;
				}else if(p<273){
					cout<<p-242<<" "<<9<<" "<<year<<endl;
				}else if(p<304){
					cout<<p-272<<" "<<10<<" "<<year<<endl;
				}else if(p<334){
					cout<<p-303<<" "<<11<<" "<<year<<endl;
				}else{
					cout<<p-333<<" "<<12<<" "<<year<<endl;
				}
			}
	    }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
