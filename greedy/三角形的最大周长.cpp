#include <bits/stdc++.h>
//原题地址：https://oj.socoding.cn/contest/problem?id=601&pid=12 

using namespace std;

bool isTriangle(int a, int b, int c){//判断是否能够组成三角形，其中c为较大的边 
	if(a + b > c) return true;
	else return false;
}

int maxPerimeter(vector<int>&A){
	int perimeter = 0;
	std::sort(A.begin(), A.end());
//	cout << A[0];
	for(int i = A.size() - 1; i > 1; i--){
		if(isTriangle(A[i-2],A[i-1],A[i])){//只判断大小相邻的。因为大小相邻的都无法组成结果的话，那隔开的就更不行了 
			perimeter = A[i-2]+A[i-1]+A[i];
			break;
		}
	} 
	return perimeter;
}
int main()

{
	
	vector<int> A;
	int num;
	while(cin>>num){
		A.push_back(num);//处理不定长输入的方法 
	} 
	cout <<  maxPerimeter(A);

return 0;

}

