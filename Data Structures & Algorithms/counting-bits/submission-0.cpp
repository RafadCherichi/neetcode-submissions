class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> output(n+1);
        for(int i=0;i<=n;i++){
            int count = 0;
            int num = i;
            while(num>0){
                num &= (num-1);//n=n&(n-1);
                count +=1;
            }
            output[i]=count;
        }
        return output;
    }
};
