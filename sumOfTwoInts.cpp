class Solution {
public:
    int getSum(int a, int b) {
        unsigned int res = 0;
        int carry = 0;
        int i = 0;

        unsigned int ua = (unsigned int) a;
        unsigned int ub = (unsigned int) b;
        
        while ((ua != 0) || (ub!= 0)) {
            int bitA = ua & 1;
            int bitB = ub & 1;

            // when current res bit should be 1
            if ((bitA ^ bitB) & !carry || (bitA & bitB & carry) || (!bitA & !bitB & carry)) {
                res |= (1 << i);
            // when current  res bit should be 0
            } else {
                res = res;
            }
            carry = (bitA & bitB) | ((bitA ^ bitB) & carry);
            ua = ua >> 1;
            ub = ub >> 1;
            ++i;
        }
        if (i != 32) res |= (carry << i);
        int final = (int) res;

        return final;
    }
};
