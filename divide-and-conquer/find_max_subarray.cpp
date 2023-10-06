#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> nums,int left, int right){
	if(left == right){
		return nums[left];
	} 
	int mid = (left + right) / 2;
	
	//���㲻���е���������� 
	int leftMaxSum = maxSubArray(nums, left, mid);//�������޸ģ���mid-1�ĳ�mid ���������ܹ����� 
	//�ڵ������޸ĺ�ɹ����У�������ĳ�����Ե���������� 
	int rightMaxSum= maxSubArray(nums, mid+1, right);
	
	int leftSum = INT_MIN;//��ֵΪint���͵���Сֵ
	int rightSum = INT_MIN;
	int maxCrossingSum = 0;//�ڶ����޸ģ�û�г�ʼ��Ϊ0 
	
	for(int i = mid; i >= left; i--){//����������е�����ߵ����ֵ 
		maxCrossingSum += nums[i];
		leftSum = max(maxCrossingSum, leftSum);
	}
	maxCrossingSum = 0;
	for(int i = mid+1; i <= right; i++){//��һ���޸ģ����ƺ������޸ı��� 
		maxCrossingSum += nums[i];
		rightSum = max(maxCrossingSum, rightSum);
	}
	
	//���������е����ֵ
	return max(leftMaxSum, max(rightMaxSum, leftSum + rightSum)); //���Ĵ��޸ģ���Դ������ rightSum��Ϊ rightMaxSum�� 
	
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

