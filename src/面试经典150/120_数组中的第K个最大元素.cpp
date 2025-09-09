// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
#include <random>
#include <ctime>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    int quicksearch(vector<int>& nums, int l, int r, int k){
        int a = l;
        int b = r;
        int i = l;
        int x = nums[l];
        while(i <= b){
            if(nums[i] < x){
                swap(nums, i++, a++);    //! 最终的边界 a 和 边界b 都是等于x的
            }
            else if(nums[i] > x){
                swap(nums, i, b--);
            }
            else{
                i++;
            }
        }
        if(a <= k && k <= b){
            return nums[k];
        }
        else if(k <= a){
            return quicksearch(nums, l, a - 1, k);
        }
        else{
            return quicksearch(nums, b + 1, r, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quicksearch(nums, 0, n-1, n-k);
    }   
};