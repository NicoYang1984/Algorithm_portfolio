#include <bits/stdc++.h>
//原题地址： https://oj.socoding.cn/contest/problem?id=601&pid=3

using namespace std;

void printResult(vector<int> nums, int k){
	for(int i = 0; i < k; i++){
		int min = INT_MAX;//将最小值初始化为最大值 
		int minIndex = i;
		for(int j = i; j < nums.size(); j++){//找到原定数列的最小值与其下标 
			if(nums[j]<min){
				minIndex = j;
				min = nums[j];
			}
		}
//		cout << nums[minIndex]<<endl;
		if(nums[i] > nums[minIndex]){
				int temp = nums[minIndex];
				nums[minIndex] = nums[i];
				nums[i] = temp;//第一处修改：交换部分的代码写错，将nums[minIndex]修改成temp ，改掉了之前赋值失败的问题 
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

