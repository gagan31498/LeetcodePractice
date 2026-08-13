class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        int start = -1;
        unordered_map<int, int > frequency;
        for( int i =0 ; i< nums.size(); i++){
            frequency[nums[i]]++;
            while(frequency[nums[i]]> k){
                start ++;
                frequency[nums[start]]--;

            }
            res = max(res, i - start);
        }
         return res;
    }
   
};