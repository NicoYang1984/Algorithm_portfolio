#include <bits/stdc++.h>
//ԭ���ַ��https://oj.socoding.cn/contest/problem?id=601&pid=10 
using namespace std;

int LCS(string s1,string s2){
	int m = s1.size();
	int n = s2.size();
//	cout << m <<endl; 
	int dp[m+1][n+1] = {0};//�ѵ����д���û���������е������� 
//	cout << dp[0][2] <<endl;//���д���Ľ����ʾ0��0�е�Ԫ�ظ���û�б���ʼ��Ϊ0
	dp[0][0] = 0;//�ڶ����޸ģ����ӳ�ʼ��Ϊ0�Ĳ��� 
	 
//	cout << s1[0]<<s2[0]<<endl;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			dp[0][j] = 0;
			dp[i][0] = 0; //�ڶ����޸ģ��������ӳ�ʼ��Ϊ0�Ĳ��� 
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
	cin >> s1>>s2;//��һ���޸ģ���������д���������� 
	cout << LCS(s1,s2); 

return 0;

}

