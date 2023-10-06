#include <bits/stdc++.h>

using namespace std;

string findLongestPalindromicSubstring(string s){
	int n = s.length();
	if(n == 1) return s;
	bool dp[n][n] = {false};//��ʼ������������
	int i,j;
	int start = 0;
	int maxLen = 1; 
	
	for(i = 0; i < n; i++){
		dp[i][i] = true;//һλ���ַ�Ҳ����� 
	} 
	
	for(i = 0; i < n-1; i++){//Ѱ����λ�����Ӵ���һλ����λ����Ϊת�Ʒ��̵���ʼ���� 
		if(s[i] == s[i+1]){
			dp[i][i+1] = true;
			start = i;
			maxLen = 2;
		}
	}
	
	for(int len = 3; len <= n; len++){//Ѱ�ҳ��ȴ������Ļ����ַ��� 
		for(i = 0; i <= n - len; i++){//�趨���Ӵ�����ʼ�±� 
			j = i + len - 1;//�趨���Ӵ��Ľ����±�
			if(s[i] == s[j] && dp[i+1][j-1])//Ѱ��������Ľ⣺����С��ģ���Ӵ��ǻ��ĵ�ͬʱ��ͷβ�������Ӵ����
			{
				dp[i][j] = true; 
				if(len > maxLen){//������Ӵ� 
					start = i;
					maxLen = len; //֮ǰ�Լ���˼ʱ��֪����ô�ҳ�����Ӵ�����ʵֻ��Ҫ�������������洢�����¾ͺ� 
				}
			} 
		} 
	} 
	return s.substr(start, maxLen);
}

int main()

{
	string s;
	cin >> s;
	cout << findLongestPalindromicSubstring(s);

return 0;

}

