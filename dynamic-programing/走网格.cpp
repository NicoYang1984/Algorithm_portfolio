#include <bits/stdc++.h>

using namespace std;

int navigateGrid(int m, int n){
	int dp[11][11];
	int i,j;
	
	//对数组里面的元素初始化 
//	dp[1][1] = 0;
	for(i = 1; i <= 11; i++){
		dp[0][i] = 0;
		dp[i][0] = 0; 
	}
	
	//使用动态规划数组存储结果
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
			if(i == 1 && j ==1){
				dp[i][j] = 1;//第一次修改：修改了初始化条件：因为	dp[i][j] = dp[i][j-1] + dp[i-1][j];这行会覆盖掉原有的值 
			}
		}
	} 
	return dp[m][n];
}

int main()

{
	int m,n;
	cin >> m >>n;
	cout <<navigateGrid(m,n);

return 0;

}

