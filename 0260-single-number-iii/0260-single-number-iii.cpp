class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;

        for(int i=0; i<nums.size(); i++){
            num = num ^ nums[i];
        }

        bool isOne = false;
        isOne = num & 1;
        int i = 0;

        while(!isOne){
            i++;
            isOne = num >> i & 1;
        }
        int xor1 = 0;
        int xor2 = 0;
        int mask = 1 << i;

        for(int i=0; i<nums.size(); i++){
            if((nums[i] & mask) != 0){
                xor1 = xor1 ^ nums[i];
            }
            else{
                xor2 = xor2 ^ nums[i];
            }
        }
        return {xor1, xor2};
    }
};