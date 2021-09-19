#include<bits/stdc++.h>

using namespace std;

#define mod  998244353
typedef long long int ll;

ll countSetBits(ll n)
{

    if (n == 0)
    {
        // cout<<"end f1\n";
        return 0;
    }
    else
        return 1 + countSetBits(n & (n - 1));
}

ll findIndexOfSetBits(vector<ll>arr,ll i){

    // cout<<"start f2\n";
    int pos = 0;
    // int n = 1;
    vector<ll> index;
    string num = "";
    ll xorval = 0;
    while (i > 0) {

        // cout<<" pos:- "<<pos<<"\n";
        if((i&1) == 1){

            num+="1";
            xorval ^= arr[pos];
            index.push_back(pos);
        }else{

            num+="0";
        }
        pos++;
        i = i >> 1;
        // increment position
    }
    reverse(num.begin(),num.end());
    cout<<num<<endl;
    // cout<<"end f2\n";
    for(auto i = index.begin(); i != index.end(); i++){

        cout << " - " << *i << " ";
    }
    cout << "\n";

    return xorval;
}


int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    ll n;
    cin>>n;
    vector<ll> arr;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    

    ll q;
    cin >> q;
    while(q--){
        ll m1;
        cin >> m1;
    }
    return 0;
}