#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000

vector<int> primes;
void SieveOfEratosthenes(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

    prime[0] = false;
    prime[1] = false;
    for (int p = 0; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
				for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
    int cnt = 0;
    for (int p = 0; p <= n; p++)
        if (prime[p]){
            cnt++;
            primes.push_back(cnt);
        }else{
            primes.push_back(cnt);
        }
}

int main(){

    SieveOfEratosthenes(MAXN);
    // getdistinctFactorization(MAXN-1);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


    int t;
    cin >> t;
    while(t--){

        int x,y;
        cin >> x >> y;
        int cnt = primes[x];

        if(cnt <= y){

            cout << "Chef\n";
        }else{

            cout << "Divyam\n";
        }
    }
}