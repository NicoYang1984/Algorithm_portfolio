#include <bits/stdc++.h>
//原题地址： https://oj.socoding.cn/contest/problem?id=601&pid=4

using namespace std;

void printResult(vector<int> nums, int k){
	for(int i = 0; i < k; i++){
		int max = INT_MIN;//将最大值初始化为极小值 
		int maxIndex = i;
		for(int j = i; j < nums.size(); j++){//找到原定数列的最大值与其下标 
			if(nums[j]>max){
				maxIndex = j;
				max = nums[j];
			}
		}
		if(nums[i] < nums[maxIndex]){
				int temp = nums[maxIndex];
				nums[maxIndex] = nums[i];
				nums[i] = temp;
			}
		
	}
	cout << nums[k - 1] ;
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

