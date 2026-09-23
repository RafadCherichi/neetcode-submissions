class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        if(n==0) return false;
        int nw = 0;
        while(n != 1){
            if(seen.count(n)) return false;

            seen.insert(n);

            nw=0;
            //need to find a way to change the new to the new n  
            while(n>0){
                int temp = n%10;
                nw+=(temp*temp);
                n=n/10;
            }
            n=nw;
        }
        return true;//also need to find a way to output false if it doesn't give 1
    }
};
