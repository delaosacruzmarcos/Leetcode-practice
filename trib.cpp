class Solution {
/* 
originally I used a map for memoization, however I found that the insert and access times 
were slower, and I kept getting overtime errors. So I used an array. Since we are given the high end cap of n, we can cheese this question by initializing the array outside of the problem. To do this question legit a dynamic data structure with O(1) access and insertion time would be nessisary
*/
    
public:
    int cache[38];
    int tribonacci(int n) {
     if (cache[n] != 0){ return cache[n]; }
    if (n < 3){
        switch (n){
                case(0):
                    cache[n] = 0;
                    break;
                case(1):
                    cache[n] = 1;
                    break;
                case(2):
                    cache[n] = 1;
                    break;
        }
    }else{
       cache[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
     }
    return cache[n];
    }
};
