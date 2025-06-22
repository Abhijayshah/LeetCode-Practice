class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 1e9;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            long long  sum = 0;
            while(j<k){
            sum = nums[i]+nums[j]+nums[k];
            if(abs(sum-target)<abs(ans-target)) ans = sum;
            if(sum==target) return sum;
            if(sum<target){
                j++;
                continue;
            }
            else k--;
            }
        }
        return ans ;
    }
};