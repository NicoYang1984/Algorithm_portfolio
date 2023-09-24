#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> nums,int left, int right){
	if(left == right){
		return nums[left];
	} 
	int mid = (left + right) / 2;
	
	//计算不跨中点的区间最大和 
	int leftMaxSum = maxSubArray(nums, left, mid);//第三次修改：将mid-1改成mid ：这样才能过测试 
	//在第三次修改后成功运行，但是在某个测试点里面过不了 
	int rightMaxSum= maxSubArray(nums, mid+1, right);
	
	int leftSum = INT_MIN;//赋值为int类型的最小值
	int rightSum = INT_MIN;
	int maxCrossingSum = 0;//第二次修改：没有初始化为0 
	
	for(int i = mid; i >= left; i--){//计算从区间中点往左边的最大值 
		maxCrossingSum += nums[i];
		leftSum = max(maxCrossingSum, leftSum);
	}
	maxCrossingSum = 0;
	for(int i = mid+1; i <= right; i++){//第一次修改：复制后忘记修改变量 
		maxCrossingSum += nums[i];
		rightSum = max(maxCrossingSum, rightSum);
	}
	
	//返回三者中的最大值
	return max(leftMaxSum, max(rightMaxSum, leftSum + rightSum)); //第四次修改：将源代码中 rightSum改为 rightMaxSum。 
	
} 

int main()

{
	int n;
	cin>> n;
	vector<int> nums(n);
	
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	
	cout << maxSubArray(nums, 0, n-1) <<endl;

return 0;

}

