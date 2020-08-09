#include"DisjSets.h"
#include <string>
#include <queue>
#include <algorithm>
#include <list>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int maxNonOverlapping(vector<int>& nums, int target) {
        dp.resize(nums.size(),vector<int>(nums.size(),0));
        n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(i==j)
                    dp[i][j]=nums[i];
                else
                    dp[i][j]=dp[i][j-1]+nums[j];
            }
        }
        return dp[0][1];
        return find(0,target);
    }
    int find(int begin,int target)
    {
        int end=begin;
        while(end<n)
        {
            for(int i=begin;i<=end;i++)
            {
                if(dp[i][end]==target)
                {
                    return 1+find(end+1,target);
                    break;
                }
            }
            end++;
        }
        return 0;
    }
};
int main() {
    Solution s;
    vector<int>vec={-1,3,5,1,4,2,-9};
    int k=6;
    auto m=s.maxNonOverlapping(vec,k);
    return 0;
}
