#include <bits/stdc++.h>
//题目地址：https://oj.socoding.cn/contest/problem?id=601&pid=1
//算法地址：https://www.zhihu.com/question/358255792/answer/990604037


using namespace std;

int findMajority(vector<int>&nums){
	int candidate,count;
	candidate = count = 0;
	for (int i = 0; i < nums.size()-1; i++){
		if(count == 0) candidate = nums[i];//当计数器减到0时更换众数
		if(candidate == nums[i]) count++;//相同就加一
		else count--; 
	}
	return candidate;
}

int main()

{
	vector<int> nums;//注意<int>紧跟在vector处
    int num,count;
    
    cin >> count;

    while(cin>>num){
        nums.push_back(num);//使用该方法装入nums中
    }
    
    cout << findMajority(nums); 

return 0;

}

