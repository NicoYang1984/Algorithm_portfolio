#include <bits/stdc++.h>
//ԭ���ַ :https://oj.socoding.cn/contest/problem?id=601&pid=14
//����ַ��https://leetcode.cn/problems/remove-k-digits/solutions/484940/yi-diao-kwei-shu-zi-by-leetcode-solution/ 

using namespace std;

string removeKdigits(string num, int k){
	vector<char> stk;//�洢�����ջ
	for(auto&digit: num){//����num���е�ÿ��Ԫ�� 
		while(stk.size()>0 && k && stk.back() > digit ){//�����ջ��Ϊ�յ�ʱ�򣬷��ֽ�Ҫ��ջ�����ֱ�ջβ�����ִ󣬾�������ջ 
			stk.pop_back(); 
			k--;//��һ���޸ģ����Ǽ�������k���ٵĲ���:һʱ�����Լ�Ҫ��ʲô 
		} 
		stk.push_back(digit);//������ջ 
//		cout<<digit;//��������¿��Ա�����num��ÿ��Ԫ�� 
	} 
	for(;k>0;k--){//����������е����������k��û�м���0�����ʹ�ջβ����ʣ���Ԫ�� 
		stk.pop_back();
	}
//	cout << stk[0]; 
	
	//��������ת�� 
	string ans = "0";//�ڶ����޸ģ�����ֵ��""����"0"���ƺ��������ܱ��ⷵ�ؿ��ַ����� 
	for(auto&digit: stk){//��0���޸ģ���forѭ�������� for(auto&digit: stk)����  for(int i = 0; i < stk.size(); i++)
//		ans += stk[i];
//		cout << stk[i];
		ans += digit;
	}
//	cout << ans[0];
	
	//ɾ��ǰ��0��Ԫ��
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

