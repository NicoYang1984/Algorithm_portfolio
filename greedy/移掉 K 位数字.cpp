#include <bits/stdc++.h>
//ԭ���ַ��https://oj.socoding.cn/contest/problem?id=601&pid=14 
//��̰���㷨���Ļ�����Ҫ��ֲ������Ž⡣��ֲ������Ž��Ҫ��֤�Ƴ�����ĸ�λ�������ܵ�С
//ԭ������˵���Ƚ����Ĵ�С��һλһλ���Ӹߵ��ͱ���ȥ�ġ� 

//�������㷨����һ�����Ե㶼������ 

using namespace std;

string removeNum(string num, int k){
	if(k == num.size()){//ɾ��ȫ�� 
		return "0";
	}else{
		for(int i = 0; i < num.size(); i++){
			start://�ڶ����޸ģ�������goto�����ɾ����ǰ�±����ܻ�������һ���±������ 
			if(k == 0) break; //�������޸ģ�������ѭ�����оݷ���start���� 
			if(i == 0){
				if(num[i] >= num[i+1]){
					num.erase(i,1);
					k--;
					goto start;
				}
			}else if(i == num.size() - 1){
				if(num[i - 1] <= num[i]) {
					num.erase(i,1);
					k--;
					goto start;
				}
			}
			else{//�м�� 
				if(num[i - 1] <= num[i] && num[i + 1] <= num[i])  {//��һ���޸ģ������е��ϸ����С�ںŸĳɷ��ϸ�� 
					num.erase(i,1);
					k--;
					goto start;
					}
				}
			}
		while(num[0] == '0' && num.size() > 1){//���Ĵ��޸ģ�����ɾ��ǰ��0��ѭ�� ����֤���Ȳ�Ϊ1ʱ�� 
			num.erase(0,1); 
		} 
	return num;
	}
}

int main()

{
	string num ;
	int k;
	cin >> num >> k; 
	cout<<removeNum(num, k); 

return 0;

}

