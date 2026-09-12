class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int evensum=0;
        int oddsum=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
            evensum+=nums[i];
            else
            oddsum+=nums[i];
        }

        // 8  [1,6,4]
        // 5

        int count=0;
        int prevevensum=0;
        int prevoddsum=0;

        for(int i=0;i<nums.size();i++){

            if(i%2==0){
                // next wala odd even
                int nexteven=evensum-prevevensum-nums[i];
                int nextodd=oddsum-prevoddsum;

                int totaleven=nextodd+prevevensum;
                int totalodd=nexteven+prevoddsum;

                if(totaleven==totalodd)
                    count++;
            }
            else{
                // deleting odd one
                // even will become odd
                // odd will become even
                // 8--> even
                // 5---> odd
                // 2 preveven  [2,6,4]

                int nexteven=evensum-prevevensum;
                int nextodd=oddsum-prevoddsum-nums[i];

                int totalevensum=nextodd+prevevensum;
                int totaloddsum=nexteven+prevoddsum;

                if(totalevensum==totaloddsum)
                    count++;
            }

            if(i%2==0)
                prevevensum+=nums[i];
            else
                prevoddsum+=nums[i];
        }

        return count;
    }
};