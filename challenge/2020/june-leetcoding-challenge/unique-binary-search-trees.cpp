// O(n^2) time, O(1) space. Catalan number.
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1);
        G[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++)
                G[i] += G[j] * G[i-j-1];
        }
        return G[n];
    }
};

/*

G(n) = nth catalan number (what we need for this problem) be the unique BSTs that can be built with seq 1 to n
F(i, n) = number of BSTs that can be build with root i and total seq 1 to n
                                                                            left     right
So, G(n) = F(1, n) + F(2, n) + ... + F(n, n), which in turn means, G(n) += G(i-1) * G(n-i), for all 1 ≤ i ≤ n

Ex: Consider n = 3, we need to build unique BSTs with number {1, 2, 3}    
n = 3;     1				  2                  3
            \		        /   \               /
          {2, 3}          {1}   {3}          {1, 2}

        1      1               2              3       3
         \      \            /   \           /       /
          3      2         1       3        2       1           --> 5 unique BSTs
         /        \                        /         \
        2          3                      1           2


The catalan sequence goes like this:

    n = 0;     null   
    
    G[0] = 1
    
    
    n = 1;      1       
    
    G[1] = 1 
    
    
    n = 2;    1      			 2     
    		/   \			   /   \            
    	 G[0]    G[1]	   	G[1]	G[0]
    
    G[2] = 1 + 1 = 2
      
    
    n = 3;    1				      2	                   3
    		/   \		        /   \			     /	 \	
    	  G[0]   G[2]		  G[1]   G[1]		   G[2]  G[0]
    
    G[3] = 2 + 1 + 2  = 5
    
    
    n = 4;    1  				   2                    3                   4
    		/   \				 /   \                /	  \			      /   \
    	  G[0]  G[3]		   G[1]  G[2]		   G[2]    G[1]         G[3]   G[0]
    
    G[4] = 5 + 2 + 2 + 5 = 14  

*/
