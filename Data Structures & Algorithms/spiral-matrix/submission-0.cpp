class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int c=0;
        int total=n*m;
        int srow=0;
        int erow=n-1;
        int scol=0;
        int ecol=m-1;
        vector<int>ans;
        while(c<total){
            for(int i=scol;i<=ecol&& c<total;i++){
                ans.push_back(matrix[srow][i]);
                c++;
            }
            srow++;
            for(int i=srow;i<=erow&& c<total;i++){
                ans.push_back(matrix[i][ecol]);
                c++;
            }
            ecol--;
            for(int i=ecol;i>=scol&& c<total;i--){
                ans.push_back(matrix[erow][i]);
                c++;
            }
            erow--;
            for(int i=erow;i>=srow&& c<total;i--){
                ans.push_back(matrix[i][scol]);
                c++;
            }
            scol++;
        }
        return ans;
        
    }
};
