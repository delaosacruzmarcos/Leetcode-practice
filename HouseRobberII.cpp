class Solution {
public:
    /*
    Idea: create two caches one that holds the loot from the index starting at 1 (backC), and another holding the loot from zero (frontC). They increment over different bounds. With frontC ending at the nums.size()-2 and back
    */
    int rob(vector<int>& nums) {
        if(nums.size() == 1){return nums[0];}
        int size = nums.size() + 1;
        int frontC[size]; int backC[size];
        memset(frontC,0,size*sizeof(*frontC));
        memset(backC,0,size*sizeof(*backC));
        int houseIdx = 0;
        int cacheIdx = 2;
        while (houseIdx < nums.size()-1){
            int first = nums[houseIdx] + frontC[cacheIdx-2];
            int second = frontC[cacheIdx-1];
            int max = (first > second) ? (first) : (second);
            cout << "frontC max: " << max << endl;
            frontC[cacheIdx] = max;
            houseIdx++;cacheIdx++;
        }
        houseIdx = 1;
        cacheIdx = 2;
        while (houseIdx < nums.size()){
            int first = nums[houseIdx] + backC[cacheIdx-2];
            int second = backC[cacheIdx-1];
            int max = (first > second) ? (first) : (second);
            backC[cacheIdx] = max;
            houseIdx++;cacheIdx++;
        }
        return max(frontC[size-1], backC[size-1]);
    } 
};
