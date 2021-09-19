#include<bits/stdc++.h>
using namespace std;


int distinct(unordered_set<char> s1, unordered_set<char> s2){

    int c1 = 0, c2 = 0;
    for(auto i = s1.begin(); i != s1.end();i++){

       if( s2.find(*i) == s1.end()){
           c1++;
       }
    }
    for(auto i = s2.begin(); i != s2.end();i++){

       if( s1.find(*i) == s2.end()){
           c2++;
       }
    }


    return c1*c2;
}
int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        unordered_set<string> funny;
        string name;

        int k = 0;
        for (int i = 0; i < n;i++){

            cin >> name;

            funny.insert(name);
        }
        string x = *(funny.begin());

        char y = x[0];
        for (auto i = next(funny.begin(),1);i!= funny.end();i++){

            x = *i;

            if(y == x[0]){
                k++;
            }else{
                break;
            }
        }

        if(k == n){

            cout << "0" << endl;
            continue;
        }


        int count = 0;

        unordered_map<string, unordered_set<char>> funnyWords;

        for(auto i = funny.begin(); i != funny.end();i++){

            string s = *i;
            string body = s.substr(1,s.length() - 1);
            char head = s[0];
            funnyWords[body].insert(head);
        }



        for (auto i = funnyWords.begin(); i != funnyWords.end();i++)
        {

            for(auto j = next(i,1);j!= funnyWords.end();j++){

                count += distinct(i->second, j->second);
            }

        }


            cout << count * 2 << "\n";
    }
}