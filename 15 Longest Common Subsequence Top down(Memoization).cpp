#include <bits/stdc++.h>
using namespace std;


int dp[1001][1001];

int LCS(string X, string Y, int n, int m) {
    if(n==0||m==0)
        dp[n][m]=0;
    
    if (dp[n][m] != -1) // when table is not having -1 then return the value which is preseent in that block
		return dp[n][m];
    if(X[n-1]==Y[m-1])
    dp[n][m]=1+LCS(X,Y,m-1,n-1);
    else
    dp[n][m]=max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    return dp[n][m];
}
int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	memset(dp, -1, sizeof(dp)); // intialize the whole dp matrix with -1; // from memset we can initialise either -1 and zero;

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}


