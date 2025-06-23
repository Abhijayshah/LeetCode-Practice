class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> v;
        v=nums;
        int n=v.size();
        sort(v.begin(),v.begin()+n);
        int sum=0;
        for(int i=n-2;i>=0;i=i-2){
            sum=sum+v[i];
        }
        return sum;
    }
};