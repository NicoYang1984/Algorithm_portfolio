#include <bits/stdc++.h>
//原题地址：https://oj.socoding.cn/contest/problem?id=601&pid=6 

using namespace std;

//利用动态规划解决爬楼梯问题 
int climbStairs(int n){
	//要知道climbStairs(n)——也即有多少个走法，只需知道 climbStairs(n-1)和climbStairs(n-2)即可
	vector<int> dp(n+1);
	dp[0] = 0; dp[1] = 1; dp[2] = 2;//对初始值的选择一定要完备:多列几个来弄 
	for(int i = 3; i<= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	} 
	return dp[n];
	
}

int main()

{
	int n = 0;
	cin >> n;
	cout << climbStairs(n);
return 0;

}

