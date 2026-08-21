
class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0)
            return 0;

        int i = 0;

        while ( s[i] == ' ')
            i++;

        string st = s.substr(i, s.size());

        int sign = 1;
        long long ans = 0;

        for (int j = 0; j < st.size(); j++) {

            if (j == 0 && st[j] == '-') {
                sign = -1;
            }
            else if (j == 0 && st[j] == '+') {
                sign = 1;
            }
            else if (!isdigit(st[j])) {
                break;
            }
            else {
                ans = ans * 10 + (st[j] - '0');

                // overflow check
                if (sign == 1 && ans > INT_MAX)
                    return INT_MAX;

                if (sign == -1 && -ans < INT_MIN)
                    return INT_MIN;
            }
        }

        return ans * sign;
    }
};