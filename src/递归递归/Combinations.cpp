// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的组合
// 答案 不能 包含重复的组合。返回的答案中，组合可以按 任意顺序 排列
// 注意其实要求返回的不是子集，因为子集一定是不包含相同元素的，要返回的其实是不重复的组合
// 比如输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 测试链接 : https://leetcode.cn/problems/subsets-ii/


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path(nums.size());
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        f(nums,0,0,path,ans);
        return ans;
    }

    void f(vector<int>& nums , int i, int size,vector<int>& path,vector<vector<int>>& ans){
        if(i == nums.size()){
            vector<int> tmp;
            for(int x = 0;x<size;x++){
                tmp.push_back(path[x]);
            }
            ans.push_back(tmp);
        }
        else{
            int j = i+1;
            while(j<nums.size()&&nums[i] == nums[j]){
                j++;
            }

            f(nums,j,size,path,ans);
            for(;i<j;i++){
                path[size++] = nums[i];
                f(nums,j,size,path,ans);
            }
        }
    }
};
