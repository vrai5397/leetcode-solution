class Solution {
public:
    unsigned int reverseBits(unsigned int n) {
        vector<int> arr(32, 0);
        
        int i = 0;
        
        // Fill 32 bits
        while (i < 32) {
            arr[i] = n % 2;   // take last bit
            n = n / 2;        // remove last bit
            i++;
        }

        unsigned int num = 0;

        // Build reversed number
        for (int i = 0; i < 32; i++) {
            num = num * 2 + arr[i];
        }

        return num;
    }
};
