class Solution {
public:
    bool isPalindrome(int x) {
        bool ret = false;
        //Without writing atoi 
        if(x >= 0){ //Must not be negative
            if(x < 10){
                return true;
            }
          // (x/div)%10=desired digit
            long div = 1; // incremented such that 1,10,100,1000...
            int array[10]; //2^31 has 10 digits
            int digit = 0; //Corresponds to the index of array access
            while((x-div)>=0){
                int y = floor(x/div);
                int integer = y % 10;
                array[digit] = integer;
                digit++;
                div *= 10;
            }//Now with x stored in the array, we can use the double pointers to compare
            cout << digit << endl;
            cout<<"this is the array"<<endl;
            for (int k=0; k <= digit-1; k++){
                cout<<array[k]<<endl;
            }
            int i = 0;
            int j = digit-1;
            cout<<"This is J"<<endl;
            cout << j << endl;
            while (i < j){
                int iarray = array[i];
                int jarray = array[j];
                if(iarray == jarray){
                    ret = true;
                }else{
                    return false;}
                i++;
                j--;
            }
            }
         cout << "First section finished";   
        return ret;   
    }
};
