#include <stdio.h>
#include <stdlib.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

 struct TreeNode *creatnewnode(int num)
 {
    struct TreeNode* temp = malloc(sizeof(struct TreeNode));
    temp->right = NULL;
    temp->left = NULL;
    temp->val = num;
    return temp;
}

struct TreeNode* recursionsortedarray_2(int* nums, int l, int r)
{
	if (l > r) return NULL;
	int mid = (l + r) / 2;
    struct TreeNode* root =  creatnewnode(nums[mid]);
    root->left = recursionsortedarray_2(nums, l, mid-1);
    root->right = recursionsortedarray_2(nums, mid + 1, r);
	
    return root;
}

struct TreeNode* recursionsortedarray(int* nums, int l, int r)
{
	if (l >= r) return NULL;
	int mid = (l + r) / 2;
    struct TreeNode* root =  creatnewnode(nums[mid]);
    root->left = recursionsortedarray(nums, l, mid);
    root->right = recursionsortedarray(nums, mid + 1, r);
	
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return recursionsortedarray(nums, 0, numsSize);
}


void disTree(struct TreeNode* T)
{
    if(T != NULL)
    {
        printf("%d",T->val);
        if(T->left != NULL || T->right != NULL)
        {
            printf("(");
            if(T->left != NULL)
            {
                disTree(T->left);
            }
            if(T->right != NULL)
            {
                printf(",");
                disTree(T->right);
            }
            printf(")");
        }
    }
}

int main()
{
    int nums[10] = {1,3,5,7,9,11,13,15,17,19};
    int numsSize = 10;
    struct TreeNode* T = sortedArrayToBST(nums,numsSize);
    disTree(T);
    return 0;
}