#include <bits/stdc++.h>
//ԭ���ַ��https://oj.socoding.cn/contest/problem?id=601&pid=12 

using namespace std;

bool isTriangle(int a, int b, int c){//�ж��Ƿ��ܹ���������Σ�����cΪ�ϴ�ı� 
	if(a + b > c) return true;
	else return false;
}

int maxPerimeter(vector<int>&A){
	int perimeter = 0;
	std::sort(A.begin(), A.end());
//	cout << A[0];
	for(int i = A.size() - 1; i > 1; i--){
		if(isTriangle(A[i-2],A[i-1],A[i])){//ֻ�жϴ�С���ڵġ���Ϊ��С���ڵĶ��޷���ɽ���Ļ����Ǹ����ľ͸������� 
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
		A.push_back(num);//������������ķ��� 
	} 
	cout <<  maxPerimeter(A);

return 0;

}

