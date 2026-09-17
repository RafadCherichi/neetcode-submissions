class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left<right){    
            int width = right - left;
            int h = min(heights[left],heights[right]);

            int area = width * h;
            if (area > max){
                max = area;
            }
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return max;
        

    }   
};
