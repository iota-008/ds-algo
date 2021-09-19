#include <bits/stdc++.h>
using namespace std;

int convert(string s,int t){

	int h1 = (int)s[t] - '0';
	int h2 = (int)s[t+1] - '0';
	int hh = (h1*10 + h2%10 );

	if(s[t+6] == 'A'){

		if(hh == 12){

			return 0;
		}else{

			return hh;
		}
	}

	if(s[t+6] == 'P'){

		if(hh == 12){

			return 12;
		}else{

			return hh+12;
		}
	}
	return hh;
}

int main() {
	// your code goes here

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	getchar();
	while(t--){

	    string mt,ans="";
	    getline(cin,mt);

	    int n;
	    cin>>n;

	    cout<<"meeting time :"<<mt<<"--"<<n<<endl;
		int MeetingHour = convert(mt,0);
		int MeetingMinute = ((int)mt[3] - '0')*10 + ((int)mt[4] - '0')%10;
		cout<<"MeetingHour : "<<MeetingHour<<"	MeetingMinute : "<<MeetingMinute<<endl;
	    // unordered_map<string,string> map;
	    string start,end;
	   // cout<<n<<endl;
	    getchar();
	    for(int i=0;i<n;i++){
	        getline(cin,start);
			int hourStart = convert(start,0);
			int minuteStart = ((int)start[3] - '0')*10 + ((int)start[4] - '0')%10;

			int hourEnd = convert(start,9);
			int minuteEnd = ((int)start[12] - '0')*10 + ((int)start[13] - '0')%10;
			cout<<ans<<endl;
			if(MeetingHour > hourStart ){

				if(MeetingHour < hourEnd){

					ans+='1';
				}else if(MeetingHour == hourEnd){

					if(MeetingMinute <= minuteEnd){

						ans+='1';
					}else{

						ans+='0';
					}
				}
				else{

					ans+='0';
				}

			}else if (MeetingHour == hourStart){
				if(MeetingMinute >= minuteStart){

					if(MeetingHour < hourEnd){

						ans+='1';
					}else if(MeetingHour == hourEnd){

						if(MeetingMinute <= minuteEnd){

							ans+='1';
						}else{

							ans+='0';
						}
					}else{

						ans+='0';
					}
				}else{

					ans+='0';
				}
			}else{

				ans+='0';
			}
			cout<<"Start Hour : "<<hourStart<<" Start Minute : "<<minuteStart<<" End Hour : "<<hourEnd<<" End Minute : "<<minuteEnd<<endl;
			// cout<<start<<endl;

	    }
	    // getchar();
		cout<<ans<<endl;
	}
	return 0;
}
