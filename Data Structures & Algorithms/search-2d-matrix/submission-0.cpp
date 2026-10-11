class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Treat the 2D matrix as a flat 1D array from index 0 to (total elements - 1)
        int left = 0;
        int right = (rows * cols) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Map the 1D 'mid' index back to 2D matrix coordinates (row, col)
            int r = mid / cols;
            int c = mid % cols;
            
            // Standard binary search comparisons
            if (matrix[r][c] == target) {
                return true; // Found the target!
            } 
            else if (matrix[r][c] < target) {
                left = mid + 1;  // Target is larger, discard the left half
            } 
            else {
                right = mid - 1; // Target is smaller, discard the right half
            }
        }
        
        // If pointers cross and we find nothing, the target doesn't exist
        return false;
    }
};