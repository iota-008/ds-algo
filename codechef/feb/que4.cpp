#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);

    if (it != v.end())
    {
        int index = it - v.begin();
		return index;
		cout << index << endl;
    }
    else {

		return -1;
    }
}
int main() {
	// your code goes here

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int t;
	cin>>t;
	while(t--){

		int n;
		cin >> n;
		vector<int> w;
		vector<int> l;

		int x;
		for(int i=0; i<n; i++){

			cin >> x;
			w.push_back(x);
		}
		for(int i=0; i<n; i++){

			cin >> x;
			l.push_back(x);
		}

		vector<int> pos(n);
		vector<int> b(w.begin(), w.end());

		for(int i=0; i<n; i++){
			pos[i] = i;
		}
		sort(b.begin(), b.end());
		int count = 0;
		for(int i=1; i<n; i++){

			int index = getIndex(w, b[i]);
			int p = pos[getIndex(w, b[i - 1])];
			int c = index;
			while(c <= p){

				c += l[index];
				pos[index] = c;
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}