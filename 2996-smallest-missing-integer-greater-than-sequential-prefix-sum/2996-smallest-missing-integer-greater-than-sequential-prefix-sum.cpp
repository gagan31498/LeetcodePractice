class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum =nums[0];
        int prefixSum = INT_MIN;
        prefixSum = sum;
        for ( int i = 1;i<n ; i++){
            if(nums[i] - nums[i-1] == 1){
                sum += nums[i];
                prefixSum = max(prefixSum, sum);
            }
            else{ 
                // sum =nums[i];
                
                // prefixSum = max(sum, prefixSum);
                break;
            }
        }
        while(true){
            bool found = false;
            for(int i=0; i<n; i++){
                if(prefixSum == nums[i]){
                    found = true;
                }
            }
            if(!found){
                return prefixSum;
            }
            else{
                prefixSum++;
            }
        }
        return prefixSum;
    }
};