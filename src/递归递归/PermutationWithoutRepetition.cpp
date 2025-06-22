// 有重复项数组的去重全排列
// 测试链接 : https://leetcode.cn/problems/permutations-ii/


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums,0,ans);
        set<vector<int>> unique_set;
        for (auto& vec : ans) {
            unique_set.insert(vec);
        }
        
        // 转回 vector
        vector<vector<int>> result(unique_set.begin(), unique_set.end());    //容器和容器之间相互构造
        return result;
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


//* 更高效的方法
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums,0,ans);
        return ans;
    }
    void f(vector<int>& nums,int i,vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> set;
        for(int j = i ;j<nums.size();j++){
            if(set.count(nums[j]) > 0)
                continue;
            set.insert(nums[j]);
            swap(nums,j,i);
            f(nums,i+1,ans);
            swap(nums,j,i);
        }
    }
    void swap(vector<int>& nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};