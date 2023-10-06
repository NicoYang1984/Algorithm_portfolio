#include <iostream>
#include <vector>//ʹ��������װ����
//ԭ���ַ ��https://oj.socoding.cn/contest/problem?id=601&pid=1��https://leetcode.cn/problems/maximum-binary-tree/description/ 

using namespace std;

struct TreeNode{//д�ڵ�ṹ�������캯��
    int val;
    TreeNode* leftNode;
    TreeNode* rightNode;
    TreeNode(int x):val(x),leftNode(NULL),rightNode(NULL){}
};

// �ݹ鹹�������
TreeNode* constructMaximumBinaryTree(vector<int>&nums, int start, int end){
    if(start > end)//�����˳��ݹ����� 
    {
        return NULL;
    }

    int maxIndex = start;
    for(int i = start; i <= end; i++){
        if(nums[i]>nums[maxIndex]){
            maxIndex = i;
        }
    }

    //�ݹ鹹��������
    TreeNode* root = new TreeNode(nums[maxIndex]);
    root -> leftNode = constructMaximumBinaryTree(nums, start, maxIndex-1);
    root -> rightNode = constructMaximumBinaryTree(nums, maxIndex+1, end);
    return root;
}

// ��ӡ��������ǰ�������
void printMaximumBinaryTree(TreeNode* root){
//    cout << "blablabla ";
    if(root == NULL){
        cout << "null ";
        return;
    }
    else{
        cout << root->val << " ";
        if(root->leftNode == NULL&&root->rightNode==NULL) return;//���ձ�׼ʾ���������Ҷ�ӽڵ�Ͳ��������ӽڵ� 
        printMaximumBinaryTree(root->leftNode);
        printMaximumBinaryTree(root->rightNode);
    }
}

int main(){
    vector<int> nums;//ע��<int>������vector��
    int num;

    while(cin>>num){
        nums.push_back(num);//ʹ�ø÷���װ��nums��
    }
//	cout << nums[2] << " "<< "\n";
    TreeNode *root = constructMaximumBinaryTree(nums, 0, nums.size()-1);
//    cout << root->val;
    printMaximumBinaryTree(root);
    return 0;

}
