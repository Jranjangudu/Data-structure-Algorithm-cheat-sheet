// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1#
class Solution
{
    private:
    char getMaxChar(char arr[]){
         int maxi = -1;
         char ans;
         for(int i = 0 ; i < 26 ; i++){
             if(arr[i] > maxi){
                 maxi = arr[i];
                 ans = i;
             }
         }
        char findans = 'a' + ans;
        return findans;
     }

    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        
        char arr[26] = {0};
        for(int i = 0 ; i  < str.length(); i++){
            char ch = str[i];
            int index = 0;
            if(ch >= 'a' && ch <= 'z'){
                index = ch - 'a';
            }
            else{
                index = ch - 'A';
            }
            arr[index]++;
        }
        
        // getmaximum char;
        return getMaxChar(arr);
    }

};
// time complexity O(n);
// space complexity O(1);
