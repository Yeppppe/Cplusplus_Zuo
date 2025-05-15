// 没有重复项数字的全排列
// 测试链接 : https://leetcode.cn/problems/permutations/



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums,0,ans);
        return ans;
    }

    void f(vector<int>& nums,int i,vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(nums);
        }
        else{
            for(int j = i ;j<nums.size();j++){
                swap(nums,j,i);
                f(nums,i+1,ans);
                swap(nums,j,i);
            }
        }
    }
    void swap(vector<int>& nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

