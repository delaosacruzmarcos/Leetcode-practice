/*Solution I used to determine the memoization
input [3,5,1,3,4,5]
cache [3,5,5,8,9,13]
using either the sum of cache[idx-2] and nums[idx]
or cache[idx-1] 
with the last element in the cache being the one that is the largest loot
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size() + 2;
        int cache[size];
        memset(cache, 0, size*sizeof(*cache));
        int houseIdx = 0; int cacheIdx = 2;
        while (houseIdx < nums.size()){
            int first = nums[houseIdx] + cache[cacheIdx-2];
            int second = cache[cacheIdx-1];
            int max = (first > second) ? (first) : (second);
            cache[cacheIdx] = max;
            houseIdx++;cacheIdx++;
        }
        return cache[cacheIdx-1];
    }
};
