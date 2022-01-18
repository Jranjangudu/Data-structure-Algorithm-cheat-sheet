
https://leetcode.com/problems/permutation-in-string/

Input: s1 = "ab", s2 = "eidbaooo"
Output: true

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

class Solution {
public:
    //  sliding window technique!
    
    bool checkInclusion(string s1, string s2) {
        
        vector<int> s1hash(26 , 0);
        vector<int> s2hash(26 , 0);
        
        // Length
        int s1len = s1.length();
        int s2len = s2.length();
        
        if(s1len > s2len){
            return false ;// s2 can't contain any Permutation  of s1 , if length of s1 is graterthen s2
        }
        
        int left = 0;
        int right = 0;
        
        while(right < s1len){
            s1hash[s1[right] - 'a'] +=1;
            s2hash[s2[right] - 'a'] +=1;
            right +=1;
        }
        
        // now move our window
       right -= 1; // decrement by one cause it move one step more
        
        while(right < s2len){
            if(s1hash == s2hash){ // compair both the hash vector array
                return true; // we found the permutation 
            }
            right += 1;
            if(right != s2len){
                 s2hash[s2[right] - 'a'] +=1;
            }
           
            s2hash[s2[left] - 'a'] -= 1;
            left++;
            
        }     
        return false;

    }
};