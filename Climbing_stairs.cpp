class Solution {
public:
    /*
    After noticing that the permutations of possible stair combinations followed the fibianocci sequence. I leveraged that to my advantage to write this recursively. Again using an array for the fastest access and entry times.
    */
    
   int cache [50]; 
    int climbStairs(int n) {
        if (cache[n] != 0){return cache[n];}
        if (n < 3){
            switch(n){
                case(2):
                    cache[n] = 2;
                    break;
                    
                case(1):
                    cache[n] = 1;
                    break;
                    
                case (0):
                    cache[n] = 0;
                    break;
            }
            return cache[n];
        }else{
            cache[n] = climbStairs(n-1) + climbStairs(n-2);
            return cache[n];
        }
    }
};
