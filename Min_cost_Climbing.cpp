class Solution {
public:
   
/*
A fun little Climbing cost problem the hardest part for me was to determine the recurance relation.
located on line (18), I can tell that I will be using this relationship again for similar problems. 
Also I was running into issues with initalizing a dynamic array of zeros. 
I jogged my memory on how to do this and realized that I had to use memset, darn c++ lol
*/
    
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size() + 2;
        cout << "this is the size of the cache: "<< size << endl;
        int cache[size];
        memset(cache, 0, size*sizeof(*cache));
        int idx = 0; int i = 2;
        while (idx < cost.size()){
            cache[i] = cost[idx] + min(cache[i-1], cache[i-2]);
            idx++; i++;
            }
        return min(cache[i-1], cache[i-2]);
    }
};
