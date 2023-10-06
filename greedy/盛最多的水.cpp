#include <bits/stdc++.h>
//当你发现你的算法存在问题时，该怎么办呢？
//是继续寻找输入来证明算法的错误性，还是直接看答案？ 


using namespace std;

int containWater(vector<int>&num)//自己写的算法 
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

int containWater2(vector<int>&h){//网上抄的算法， 
	int left = 0;
	int right = h.size() - 1;
	int res = 0;
	while(left < right){
		res = h[left] < h [right] ? 
			max(res, (right - left) * h[left++])://括号和括号不要哎一起，影响可读性 
			max(res, (right - left) * h[right--]);//这个三元表达式太简洁优雅了，不过就是牺牲了一定的可读性 
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

