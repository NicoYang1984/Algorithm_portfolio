#include <bits/stdc++.h>
//ԭ���ַ��https://oj.socoding.cn/contest/problem?id=601&pid=11
using namespace std;

string result(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '6') {
			s[i] = '9';//��һ���޸ģ�C++�ĵ����ַ��õ����������� 
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

