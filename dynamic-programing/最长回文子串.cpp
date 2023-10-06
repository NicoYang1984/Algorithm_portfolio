#include <bits/stdc++.h>

using namespace std;

string findLongestPalindromicSubstring(string s){
	int n = s.length();
	if(n == 1) return s;
	bool dp[n][n] = {false};//初始化动归结果数组
	int i,j;
	int start = 0;
	int maxLen = 1; 
	
	for(i = 0; i < n; i++){
		dp[i][i] = true;//一位的字符也算回文 
	} 
	
	for(i = 0; i < n-1; i++){//寻找两位回文子串：一位和两位都作为转移方程的起始条件 
		if(s[i] == s[i+1]){
			dp[i][i+1] = true;
			start = i;
			maxLen = 2;
		}
	}
	
	for(int len = 3; len <= n; len++){//寻找长度大于三的回文字符串 
		for(i = 0; i <= n - len; i++){//设定该子串的起始下标 
			j = i + len - 1;//设定该子串的结束下标
			if(s[i] == s[j] && dp[i+1][j-1])//寻找子问题的解：在缩小规模的子串是回文的同时，头尾的两个子串相等
			{
				dp[i][j] = true; 
				if(len > maxLen){//更新最长子串 
					start = i;
					maxLen = len; //之前自己构思时不知道怎么找出最大子串，其实只需要定义两个变量存储并更新就好 
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

