#include <bits/stdc++.h>
//ԭ���ַ��https://oj.socoding.cn/contest/problem?id=601&pid=6 

using namespace std;

//���ö�̬�滮�����¥������ 
int climbStairs(int n){
	//Ҫ֪��climbStairs(n)����Ҳ���ж��ٸ��߷���ֻ��֪�� climbStairs(n-1)��climbStairs(n-2)����
	vector<int> dp(n+1);
	dp[0] = 0; dp[1] = 1; dp[2] = 2;//�Գ�ʼֵ��ѡ��һ��Ҫ�걸:���м�����Ū 
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

