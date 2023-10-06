#include <bits/stdc++.h>
//原题地址 :https://oj.socoding.cn/contest/problem?id=601&pid=14
//题解地址：https://leetcode.cn/problems/remove-k-digits/solutions/484940/yi-diao-kwei-shu-zi-by-leetcode-solution/ 

using namespace std;

string removeKdigits(string num, int k){
	vector<char> stk;//存储结果的栈
	for(auto&digit: num){//遍历num当中的每个元素 
		while(stk.size()>0 && k && stk.back() > digit ){//当结果栈不为空的时候，发现将要入栈的数字比栈尾的数字大，就连续出栈 
			stk.pop_back(); 
			k--;//第一次修改：忘记加这行让k减少的操作:一时忘记自己要干什么 
		} 
		stk.push_back(digit);//数字入栈 
//		cout<<digit;//这种情况下可以遍历到num的每个元素 
	} 
	for(;k>0;k--){//针对升序排列的特殊情况（k还没有减到0），就从栈尾弹出剩余的元素 
		stk.pop_back();
	}
//	cout << stk[0]; 
	
	//数据类型转换 
	string ans = "0";//第二次修改：将初值从""换成"0"，似乎这样就能避免返回空字符串。 
	for(auto&digit: stk){//第0次修改：将for循环迭代从 for(auto&digit: stk)换成  for(int i = 0; i < stk.size(); i++)
//		ans += stk[i];
//		cout << stk[i];
		ans += digit;
	}
//	cout << ans[0];
	
	//删除前导0的元素
	while(ans.size()>1 && ans[0] == '0'){
		ans.erase(ans.begin());
	} 
	return ans;
} 

int main()

{
	string num ;
	int k;
	cin >> num >> k; 
	cout<<removeKdigits(num, k); 

return 0;

}

