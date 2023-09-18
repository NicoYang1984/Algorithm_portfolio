#include <iostream>
#include <vector>//使用容器类装数组
//原题地址 ：https://oj.socoding.cn/contest/problem?id=601&pid=1和https://leetcode.cn/problems/maximum-binary-tree/description/ 

using namespace std;

struct TreeNode{//写节点结构，并构造函数
    int val;
    TreeNode* leftNode;
    TreeNode* rightNode;
    TreeNode(int x):val(x),leftNode(NULL),rightNode(NULL){}
};

// 递归构造二叉树
TreeNode* constructMaximumBinaryTree(vector<int>&nums, int start, int end){
    if(start > end)//设置退出递归条件 
    {
        return NULL;
    }

    int maxIndex = start;
    for(int i = start; i <= end; i++){
        if(nums[i]>nums[maxIndex]){
            maxIndex = i;
        }
    }

    //递归构建二叉树
    TreeNode* root = new TreeNode(nums[maxIndex]);
    root -> leftNode = constructMaximumBinaryTree(nums, start, maxIndex-1);
    root -> rightNode = constructMaximumBinaryTree(nums, maxIndex+1, end);
    return root;
}

// 打印输出结果（前序遍历）
void printMaximumBinaryTree(TreeNode* root){
//    cout << "blablabla ";
    if(root == NULL){
        cout << "null ";
        return;
    }
    else{
        cout << root->val << " ";
        if(root->leftNode == NULL&&root->rightNode==NULL) return;//仿照标准示例：如果是叶子节点就不遍历其子节点 
        printMaximumBinaryTree(root->leftNode);
        printMaximumBinaryTree(root->rightNode);
    }
}

int main(){
    vector<int> nums;//注意<int>紧跟在vector处
    int num;

    while(cin>>num){
        nums.push_back(num);//使用该方法装入nums中
    }
//	cout << nums[2] << " "<< "\n";
    TreeNode *root = constructMaximumBinaryTree(nums, 0, nums.size()-1);
//    cout << root->val;
    printMaximumBinaryTree(root);
    return 0;

}
