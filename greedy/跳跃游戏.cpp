#include <bits/stdc++.h>
//ԭ�⣺https://oj.socoding.cn/contest/problem?id=601&pid=23 
//�������̣�https://spotless-bit-924.notion.site/897a7b7ba08a4a72bd1a67b16ce9aa16?pvs=4 

using namespace std;

string jumpGame(vector<int>& a){
	string result = "true";
	int i,j = 0;
	for(i = 0; i < a.size(); i++){
		if(a[i] == 0){
			if(a[i+1] > 0){//ȡ��������0�����һ�� 
				for(j = i - 1; j >= 0; j--){
					if(a[j] >= i - j + 1){
						break;
					}
				}
				if(j < 0){//���������� 
					result = "false";
					break;
				}
			}
		else if(i == a.size() - 1){//ȡ��������ĩβ��0 
			for(j = i - 1; j >= 0; j--){
				if(a[j] >= i - j){
					break;
				}
				if(j < 0){
					result = "false";
					break;
				}
				}
			}
		else{//��û��ȡ������0 
			continue;
			}
		}
	}
	return result;
}

int main()

{
	vector<int> a;
	int num;
	while(cin >> num){
		a.push_back(num);
	}
	cout << jumpGame(a);
return 0;

}

