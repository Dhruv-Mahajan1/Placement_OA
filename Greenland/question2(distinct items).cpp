// Finding the maximum number of unique elements which can be bought given n items.
// ith item is priced at i and currently the items present in the array are already bought
// te maximum dolalrs you can spend is k.
int find_ans(int n,int k, vector<int> arr){
    int m = arr.size();
    set<int> s;
    rep(x,0,m){
        s.insert(arr[x]);
    }
    rep(x,1,n+1){
        if(s.find(x)==s.end()){
            if(x<=k){
                k-=x;
                s.insert(x);
            }
        }
    }
    return s.size();

}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(m);
    rep(x,0,m){
        cin>>arr[x];
    }
    cout<<find_ans(n,k,arr)<<'\n';
	
}
 
 
 
 
int main(){
	ios_base ::sync_with_stdio(0), cin.tie(0);
	clock_t start, end;
	start = clock();
	int t = 1;
	cin >> t;
	// int x=0
	while (t-->0)
	{
        //cout<<"Case #"<<x<<": ";
		solve();
        // x++;
	}
	end = clock();
	cerr << double(end - start) / double(CLOCKS_PER_SEC) << '\n';
}
