#include <bits/stdc++.h>
//ԭ���ַ�� https://oj.socoding.cn/contest/problem?id=601&pid=3

using namespace std;

void printResult(vector<int> nums, int k){
	for(int i = 0; i < k; i++){
		int min = INT_MAX;//����Сֵ��ʼ��Ϊ���ֵ 
		int minIndex = i;
		for(int j = i; j < nums.size(); j++){//�ҵ�ԭ�����е���Сֵ�����±� 
			if(nums[j]<min){
				minIndex = j;
				min = nums[j];
			}
		}
//		cout << nums[minIndex]<<endl;
		if(nums[i] > nums[minIndex]){
				int temp = nums[minIndex];
				nums[minIndex] = nums[i];
				nums[i] = temp;//��һ���޸ģ��������ֵĴ���д����nums[minIndex]�޸ĳ�temp ���ĵ���֮ǰ��ֵʧ�ܵ����� 
			}
		cout << nums[i] << " ";
	}
	
}

int main()

{
	int n = 0;
	int k = 0;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	printResult(nums,k);

return 0;

}

