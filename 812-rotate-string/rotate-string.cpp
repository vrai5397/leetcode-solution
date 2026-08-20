class Solution {
public:
void reverse(string& st,int i,int j){
    while(i<j){
        swap(st[i],st[j]);
        i++;
        j--;
    }
}
    bool rotateString(string s, string goal) {
        // brute force
        int n=s.size();
        for(int i=1;i<=s.size();i++){
            string helper=s;
            reverse(helper,0,helper.size()-1);
            reverse(helper,0,n-1-i);
            reverse(helper,n-i,n-1);
            cout<<helper<<endl;
            if(helper==goal)
            return true;

        }
        return false;
    }
};