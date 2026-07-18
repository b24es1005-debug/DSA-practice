class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {//do this until carry becomes 0

            // Carry bits
            unsigned int carry = (unsigned int)(a & b);

            // Sum without carry
            a = a ^ b;

            // Carry shifted to next bit
            b = carry << 1;
        }

        return a;
    }
};