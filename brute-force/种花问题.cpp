#include <bits/stdc++.h>
//�Ǿ����ֿ��£���һ�°�������ķ��������Ժ���û�л�ʣ 

using namespace std;

string plantFlower(vector<int>&flowerbed, int count){
	int flower = count;
	//��һ���޸ģ� ���˼��ٻ������������޸� flowerbed����ֵ����������ȥ�Ļ�Ҳ����Ӱ��ģ� 
	for(int i = 0; i < flowerbed.size(); i++){
		if(i == 0){//��һ�� 
			if(flowerbed[i + 1] == 1) flower--;
		}else if(i == flowerbed.size()){//���һ�� 
			if(flowerbed[i - 1] == 1) flower--;
		}
		else{//�м�� 
			if(flowerbed[i - 1] == 1 && flowerbed[i + 1] == 1) flower--;
		}
		if(flower == 0) return "true"; 
	}
	return "false";
}

int main()

{
	
	string line;
    vector<int> flowerbed; // ���ڴ洢��һ�еı���
    int count; // ���ڴ洢�ڶ��е�ֵ

    getline(cin, line); // ��ȡ��һ��
   	istringstream iss(line);
    
    int num;
    while (iss >> num) {
        flowerbed.push_back(num); // ����ȡ�����ִ��� vector
    }

    cin >> count; // ��ȡ�ڶ��е�ֵ

//	cout << plantFlower(flowerbed, count);

//��ʼ�ֻ� 
	for(int i = 0; i < flowerbed.size(); i++){
		if(i == 0){//��һ�� 
			if(flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
				flowerbed[i] = 1;
				count--;
			}
		}else if(i == flowerbed.size()-1){//���һ�� 
			if(flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
				flowerbed[i] = 1;
				count--;
			}
		}
		else{//�м�� 
			if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {//�ڶ����޸ģ�������flowerbed[i] == 0����������Ҫ����Ҳ���ֲ��� 
				flowerbed[i] = 1;
				count--;
			}
		}
		if(count == 0)  {//���������� 
			cout<<"true"; 
			return 0;
		}
	}
	cout<< "false";

    

return 0;

}

