#include <bits/stdc++.h>
//���㷢������㷨��������ʱ������ô���أ�
//�Ǽ���Ѱ��������֤���㷨�Ĵ����ԣ�����ֱ�ӿ��𰸣� 


using namespace std;

int containWater(vector<int>&num)//�Լ�д���㷨 
{
	int i = 0;
	int j = num.size() - 1;
	int result = min(num[i],num[j]) * j;
//	cout << result;
	while(i < j){
		if(result < min(num[i + 1],num[j]) * (j - i - 1)){
			result = min(num[i + 1],num[j]) * (j - i - 1);
			i++;
		}
		else if(result < min(num[i],num[j - 1]) * (j - i - 1)){
			result = min(num[i],num[j - 1]) * (j - i - 1);
			j--;
		}else{
			i++;
			j--;
		}
	}
	return result;
}

int containWater2(vector<int>&h){//���ϳ����㷨�� 
	int left = 0;
	int right = h.size() - 1;
	int res = 0;
	while(left < right){
		res = h[left] < h [right] ? 
			max(res, (right - left) * h[left++])://���ź����Ų�Ҫ��һ��Ӱ��ɶ��� 
			max(res, (right - left) * h[right--]);//�����Ԫ���ʽ̫��������ˣ���������������һ���Ŀɶ��� 
	} 
	return res; 
}

int main()

{
	vector<int> a;
	int num;
	while(cin >> num){
		a.push_back(num);
	} 
	cout << containWater2(a);
	

return 0;

}

