// O(1) time and space
class Solution {
public:
    int numberOfSteps (int num) {
        if(!num)    return 0;
        int steps = 0;

        while(num) {
            // if lsb == 1 (num is odd), add 2 to total steps (-1 to make num even and half it), otherwise add 1 (to half num)
            steps += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return steps-1;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(logn) time, O(1) space. Simulating the process.
class Solution {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        
        while(num) {
            if(num & 1)
                num--;
            else    
                num /= 2;

            steps++;
        }
        return steps;
    }
};
