#include <bits/stdc++.h>
//那就种种看呗，看一下按照理想的方法种完以后还有没有花剩 

using namespace std;

string plantFlower(vector<int>&flowerbed, int count){
	int flower = count;
	//第一次修改： 除了减少花的数量还会修改 flowerbed的数值（后来种上去的花也会有影响的） 
	for(int i = 0; i < flowerbed.size(); i++){
		if(i == 0){//第一朵 
			if(flowerbed[i + 1] == 1) flower--;
		}else if(i == flowerbed.size()){//最后一朵 
			if(flowerbed[i - 1] == 1) flower--;
		}
		else{//中间的 
			if(flowerbed[i - 1] == 1 && flowerbed[i + 1] == 1) flower--;
		}
		if(flower == 0) return "true"; 
	}
	return "false";
}

int main()

{
	
	string line;
    vector<int> flowerbed; // 用于存储第一行的变量
    int count; // 用于存储第二行的值

    getline(cin, line); // 读取第一行
   	istringstream iss(line);
    
    int num;
    while (iss >> num) {
        flowerbed.push_back(num); // 将读取的数字存入 vector
    }

    cin >> count; // 读取第二行的值

//	cout << plantFlower(flowerbed, count);

//开始种花 
	for(int i = 0; i < flowerbed.size(); i++){
		if(i == 0){//第一朵 
			if(flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
				flowerbed[i] = 1;
				count--;
			}
		}else if(i == flowerbed.size()-1){//最后一朵 
			if(flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
				flowerbed[i] = 1;
				count--;
			}
		}
		else{//中间的 
			if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {//第二次修改：增加了flowerbed[i] == 0的条件，需要本地也能种才行 
				flowerbed[i] = 1;
				count--;
			}
		}
		if(count == 0)  {//花被种完了 
			cout<<"true"; 
			return 0;
		}
	}
	cout<< "false";

    

return 0;

}

