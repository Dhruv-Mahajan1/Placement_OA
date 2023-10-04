// Given n items, weight of item i is 2^i and cost of the item is c_i
// Find the min cost to get a weight >=W.

void solve(){
	int n;
	cin>>n;
	vector<ll> prices(30,1e18);
	for(int x=0;x<n;x++) cin>>prices[x];
	for(int i = 0;i<30;i++){
		for(int j = i+1;j<30;j++){
			prices[j] = min(prices[j], (1<<(j-i))*prices[i]);
		}
	}
	n = 30;
	int mnwt;cin>>mnwt;
	vector<ll> wts(1<<16,1e18);
	int l = n/2;
	int r = n-l;
	for(int i = 0;i<(1<<l);i++){
		ll prc = 0;
		ll wt = 0;
		for(int j = 0;j<l;j++){
			if(i&(1<<j)){
				prc+=prices[j];
				wt+=(1<<j);
			}
		}
		wts[wt] = min(wts[wt], prc); 
 	}
	vector<ll> minvs(1<<16,1e18);
	ll best = 1e18;
	for(int i = (1<<16)-1 ;i>=0;i--){
		if(i==(1<<16)-1){
			minvs[i] = wts[i];
		}
		else{
			minvs[i] = min(minvs[i+1], wts[i]);
		}
	}
	for(int i = 0;i<(1<<r);i++){
		ll prc = 0;
		ll wt = 0;
		for(int j = 0;j<r;j++){
			if(j&(1<<j)){
				prc+=(prices[l+j]);
				wt+=(1<<(l+j));
			}
		}
		ll left = (mnwt-wt);
		if(left<0){
			best = min(best,prc);
		}
		else if(left>=(1<<16)){
			continue;
		}else{
			best = min(best,prc+minvs[left]);
		}
	}
	cout<<best<<"\n";
}
