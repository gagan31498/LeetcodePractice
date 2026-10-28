class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool neg = false;
        if(dividend < 0 || divisor < 0){
            neg = true;
        }
        if(dividend < 0 && divisor < 0) neg = false;
        long long dividend1 = abs((long long)dividend);
        long long divisor1 = abs((long long)divisor);
        long long  n = divisor1;
        int i = 0;
        long long  cost = 0;
        while(dividend1 >= divisor1){
            i = 0;
            while(dividend1 >= n){
                n = n << 1;
                i++;
            }
            cost += 1LL << (i-1);
            dividend1 -= n >> 1;
            n = divisor1;
        }
        if(neg){
            cost = -cost;
        }
        if(cost > INT_MAX) return INT_MAX;
        if(cost < INT_MIN) return INT_MIN;
        return cost;
    }
};