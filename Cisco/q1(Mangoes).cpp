// Problem was about finding the maximum mangues that can be taken by going back and forth between two grids
// where both the grids are connected at some point. 
// (0,n-1) in Grid 1 -> (n-1,0) in grid 1 -> (n-1,n-1) in grid 2 -> (0,0) in grid 2 and back.
// (n-1,0) and (n-1,n-1) are connected.
char arr[105][105];
char marr[105][105];
int dp[105][105];
pair<int,int> path[105][105];

void solve(){
    int n;
    cin>>n;
    for(int x = 0;x<n;x++){
        string s;
        cin>>s;
        for(int y = 0;y<n;y++){
            arr[x][y] = s[y];
            dp[x][y] = -INF;
            path[x][y] = {-1,-1};
            marr[x][y] = s[y];
        }
    }
    dp[0][0] = 0;
    if(arr[0][0]=='X'){
        cout<<"0\n";
        return;
    }
    else if(arr[0][0]=='$') dp[0][0] = 1;
    for(int x = 0;x<n;x++){
        for(int y = 0;y<n;y++){
            if(dp[x][y]==-INF) continue;
            vector<pair<int,int>> dirs = {{0,1},{1,0}};
            for(auto [dx,dy] : dirs){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=n || ny>=n) continue;
                if(arr[nx][ny]=='X') continue;
                int v = 0;
                if(arr[nx][ny]=='$') v = 1;
                if(dp[nx][ny]<(dp[x][y]+v)){
                    dp[nx][ny] = dp[x][y]+v;
                    path[nx][ny] = {x,y};
                }
            }
        }
    }
    int a1 = dp[n-1][n-1];
    if(a1==-INF){
        cout<<"0\n";
        return;
    }
    int i = n-1,j = n-1;
    while(i!=0 || j!=0){
        cout<<i<<" "<<j<<"\n";
        arr[i][j] = '*';
        cout<<i<<" "<<j<<"\n";
        tie(i,j) = path[i][j];
    }
    arr[0][0] = '*';
    for(int x = 0 ;x<n;x++){
        for(int y = 0;y<n;y++){
            dp[x][y] = -INF;
        }
    }
    dp[n-1][n-1] = 0;
    for(int x = n-1;x>=0;x--){
        for(int y = n-1;y>=0;y--){
            if(dp[x][y]==-INF) continue;
            vector<pair<int,int>> dirs = {{0,-1},{-1,0}};
            for(auto [dx,dy] : dirs){
                int nx = x+dx;
                int ny = y+dy;
                if(nx<0 || ny<0) continue;
                if(arr[nx][ny]=='X') continue;
                int v = 0;
                if(arr[nx][ny]=='$') v = 1;
                if(dp[nx][ny]<(dp[x][y]+v)){
                    dp[nx][ny] = dp[x][y]+v;
                    path[nx][ny] = {x,y};
                }
            }
        }
    }
    int a2 = dp[0][0];
    // cout<<a1<<" "<<a2<<"\n";
    cout<<(a1+a2)*2<<"\n";
	
}
