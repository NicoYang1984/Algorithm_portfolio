#include <bits/stdc++.h>
//原题地址：https://oj.socoding.cn/contest/problem?id=601&pid=14 
//用贪婪算法求解的话，就要求局部的最优解。求局部的最优解就要保证移除结果的高位数尽可能地小
//原理上来说，比较数的大小是一位一位，从高到低比下去的。 

//结果这个算法连第一个测试点都过不了 

using namespace std;

string removeNum(string num, int k){
	if(k == num.size()){//删掉全部 
		return "0";
	}else{
		for(int i = 0; i < num.size(); i++){
			start://第二次修改：尝试用goto语句解决删除当前下标后可能会跳过后一个下标的问题 
			if(k == 0) break; //第三次修改：把跳出循环的判据放在start后面 
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
			else{//中间的 
				if(num[i - 1] <= num[i] && num[i + 1] <= num[i])  {//第一次修改：将所有的严格大于小于号改成非严格的 
					num.erase(i,1);
					k--;
					goto start;
					}
				}
			}
		while(num[0] == '0' && num.size() > 1){//第四次修改：增加删除前导0的循环 （保证长度不为1时） 
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

