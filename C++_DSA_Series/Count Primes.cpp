class Solution {
public:
    // this approach is called Sieve eratosthenes algorithm
    int countPrimes(int n) {
       
      if(n == 0) return 0; // base case
        
       vector <int> prime( n+1 , true );
        prime[0] = prime[1] = false;
        int count = 0;
        for(int i = 2 ; i < n ; i++){
            if(prime[i]){
                count++;
                for(int j = i*2 ; j < n ; j = j+i){
                    prime[j] = 0;
                }
            }
        }
            
         return count;
        
    }
};