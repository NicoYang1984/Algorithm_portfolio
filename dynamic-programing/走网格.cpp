#include <bits/stdc++.h>

using namespace std;

int navigateGrid(int m, int n){
	int dp[11][11];
	int i,j;
	
	//�����������Ԫ�س�ʼ�� 
//	dp[1][1] = 0;
	for(i = 1; i <= 11; i++){
		dp[0][i] = 0;
		dp[i][0] = 0; 
	}
	
	//ʹ�ö�̬�滮����洢���
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
			if(i == 1 && j ==1){
				dp[i][j] = 1;//��һ���޸ģ��޸��˳�ʼ����������Ϊ	dp[i][j] = dp[i][j-1] + dp[i-1][j];���лḲ�ǵ�ԭ�е�ֵ 
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

