#include <bits/stdc++.h>
//��Ŀ��ַ��https://oj.socoding.cn/contest/problem?id=601&pid=1
//�㷨��ַ��https://www.zhihu.com/question/358255792/answer/990604037


using namespace std;

int findMajority(vector<int>&nums){
	int candidate,count;
	candidate = count = 0;
	for (int i = 0; i < nums.size()-1; i++){
		if(count == 0) candidate = nums[i];//������������0ʱ��������
		if(candidate == nums[i]) count++;//��ͬ�ͼ�һ
		else count--; 
	}
	return candidate;
}

int main()

{
	vector<int> nums;//ע��<int>������vector��
    int num,count;
    
    cin >> count;

    while(cin>>num){
        nums.push_back(num);//ʹ�ø÷���װ��nums��
    }
    
    cout << findMajority(nums); 

return 0;

}

