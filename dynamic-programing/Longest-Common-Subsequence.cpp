#include <bits/stdc++.h>
//原题地址：https://oj.socoding.cn/contest/problem?id=601&pid=10 
using namespace std;

int LCS(string s1,string s2){
	int m = s1.size();
	int n = s2.size();
//	cout << m <<endl; 
	int dp[m+1][n+1] = {0};//难道这行代码没有起到它该有的作用吗？ 
//	cout << dp[0][2] <<endl;//这行代码的结果显示0行0列的元素根本没有被初始化为0
	dp[0][0] = 0;//第二次修改：增加初始化为0的操作 
	 
//	cout << s1[0]<<s2[0]<<endl;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			dp[0][j] = 0;
			dp[i][0] = 0; //第二次修改：额外增加初始化为0的操作 
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
//			cout<<i<<","<<j<<":"<<dp[i][j]<<endl;
		}
	}
	return dp[m][n];
	
}

int main()

{
	string s1,s2;
	cin >> s1>>s2;//第一次修改：这里忘记写两个输入流 
	cout << LCS(s1,s2); 

return 0;

}

