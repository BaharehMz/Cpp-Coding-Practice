class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int min = numeric_limits<int>::min(), max = 0;
        int start = 0;
        while(nums[start] <= nums[start + 1] && start < nums.size() - 1){
            start++;
        }
        //start++;
        int end = nums.size() - 1;
        while(end && nums[end] >= nums[end - 1]){
            end--;
        }
        min = nums[start];
        max = nums[start];
        for(int i = start; i <= end; i++){
            if(nums[i] < min) min = nums[i];
            if(nums[i] > max) max = nums[i];
        }
        if(start == nums.size() - 1 && end == 0)
            return 0;
        int left = start, right = end;
        for(int i = 0; i <= nums.size(); i++){
            if(nums[i] > min) {
                left = i;
                break;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < max) {
                right = i;
                break;
            }
        }
        return right - left + 1;
    }
};
