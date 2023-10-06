ll dp[13][2][2];
ll calc_dp(vector<int>& digits, int d, int pos, int cnt, int flag1){
	if(pos>=digits.size()){
		return cnt;
	}
	if(dp[pos][cnt][flag1]){
		return dp[pos][cnt][flag1];
	}
	int limit = 9;
	if(flag1) limit = digits[pos];
	ll ans = 0;
	for(int x = 0;x<limit+1;x++){
		int new_flag1 = flag1;
		if(flag1==1 && x==digits[pos]){
			new_flag1 = 1;
		}else new_flag1 = 0;
		int new_cnt = cnt;
		if(x==d || new_cnt){
			new_cnt = 1;
		}else new_cnt = 0;

		ans+= calc_dp(digits, d, pos+1,new_cnt, new_flag1);
	}
	return dp[pos][cnt][flag1] = ans;
}
vector<int> get_digits(ll n){
	vector<int> temp;
	while(n>0){
		temp.push_back(n%10);
		n/=10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
void solve(){
	ll n,a,b;
	cin>>a>>b>>n;
	ll l = 1,r = 1e12;
	ll best = r;
	if(a>=n) best = 0;
	while(l<=r){
		ll mid = (l+r)>>1;
		vector<int> digits = get_digits(mid);
		memset(dp, 0, sizeof(dp));
		ll cost = (mid*a+b*(calc_dp(digits,7, 0, 0,1)));
		// cout<<l<<" "<<r<<" "<<mid<<" "<<cost<<'\n';
		if(cost+a>=n){
			if(l==r){
				best = min(best, mid);
				break;
			}
			r = mid-1;
			best = min(best, mid);
		}else{
			l = mid+1;
		}
	}
	cout<<best<<'\n';
}

