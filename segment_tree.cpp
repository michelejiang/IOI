#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define endl '\n'
 
const int N = 2147483647;
const int MOD = 1e9+7;
const int MAX = 200001;
const ll INF = 1e18;

int n, q;
vector<ll> tree;

ll f(int node, int node_low, int node_high, int query_low, int query_high){
	if(query_low <= node_low && node_high <= query_high){
		return tree[node];
	}
	if(node_high < query_low || node_low > query_high){
		return 0;
	}
	int last_in_left = (node_low + node_high) / 2;
	return f(2*node, node_low, last_in_left, query_low, query_high) + f(2*node+1, last_in_left + 1, node_high, query_low, query_high);
}

void update(int i, long v){
	tree[n+i] = v;
	for(int j = (n+i) / 2 ; j >= 1 ; j /= 2){
		tree[j] = tree[j*2] + tree[j*2+1];
	}
}

void solve(){
	cin >> n >> q;
	vector<long> v(n);
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	while(__builtin_popcount(n) != 1){
		v.push_back(0);
		n++;
	}
	tree.resize(2*n);	
	for(int i = 0 ; i < n ; i++){
		tree[n+i] = v[i];
	}
	for(int i = n - 1; i >= 1 ; i--){
		tree[i] = tree[2*i] + tree[2*i+1];
	}

	long low, high, t;
	for(int i = 0 ; i < q ; i++){
		cin >> t >> low >> high;
		if(t == 1){
			low--;
			update(low, high);
		}
		else{
			low--;
			high--;
			cout << f(1, 0, n-1, low, high) << endl;
		}
	}
}	
 
int main(){
	/*#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	*/
    ios::sync_with_stdio(0);cin.tie(0);  cout.tie(0);
   	int tt = 1;
   	//cin >> tt;
   	while(tt--){
   		solve();
   	}
    return 0;
   	
   	
    
}
