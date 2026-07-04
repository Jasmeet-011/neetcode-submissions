class Solution {
    void printSubsequences(vector<int>& arr, int index, vector<vector<int>>& all, vector<int>& sq, int target) {
    if (index == arr.size()) {
        if (target == 0)
            all.push_back(sq);
        return; 
    }
    if(arr[index]<=target){
        sq.push_back(arr[index]);
        printSubsequences(arr, index, all, sq, target - arr[index]); 

        sq.pop_back();
    }
    printSubsequences(arr, index + 1, all, sq, target); 
}

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>all;
        vector<int>sq;
        printSubsequences(nums,0,all,sq,target);
        return all;
        
    }
};
