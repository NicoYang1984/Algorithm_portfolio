#include <bits/stdc++.h>
//原题地址：https://oj.socoding.cn/contest/problem?id=601&pid=11
using namespace std;

string result(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '6') {
			s[i] = '9';//第一次修改：C++的单个字符用单引号括起来 
			break;
		}
	}
	return s;
}

int main()

{
	string s;
	cin >> s;
//	cout << s[0]; 
	cout << result(s);

return 0;

}

