// Simply finding the maximum contiguous subsegment sum such that the size of the
// subsegment is not greater than k.
int find_ans(int n,vector<ll> arr,int k){
    vector<ll> pref(n+1,0);
    rep(x,1,n+1) pref[x] = (pref[x-1]+arr[x-1]);
    ll ans = 0;
    rep(x,0,n) ans = max(ans, arr[x]);
    multiset<ll> s = {0};
    rep(x,1,k){
        ans = max(ans,pref[x]-*s.begin());
        s.insert(pref[x]);
    }
    int l = 0,r = k;
    while(r<(n+1)){
        ans = max(ans,pref[r]-*s.begin());
        s.erase(s.find(pref[l]));
        s.insert(pref[r]);
        l++;
        r++;
    }
    return ans;
}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    rep(x,0,n) cin>>arr[x];
    cout<<find_ans(n,arr,k)<<"\n";
	
}
