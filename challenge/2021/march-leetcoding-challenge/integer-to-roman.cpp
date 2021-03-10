// O(1) time and space
class Solution {
public:
    string intToRoman(int num) {
        vector<string> dict{"I", "X", "C", "M", "V", "L", "D"};
        int i = 0;
        string roman;
        while(num) {
            int pop = num%10;
            switch(pop) {
                case 1: roman.insert(0, dict[i]); break;
                case 2: roman.insert(0, dict[i] + dict[i]); break;
                case 3: roman.insert(0, dict[i] + dict[i] + dict[i]); break;
                case 4: roman.insert(0, dict[i] + dict[i+4]); break;
                case 5: roman.insert(0, dict[i+4]); break;
                case 6: roman.insert(0, dict[i+4] + dict[i]); break;
                case 7: roman.insert(0, dict[i+4] + dict[i] + dict[i]); break;
                case 8: roman.insert(0, dict[i+4] + dict[i] + dict[i] + dict[i]); break;
                case 9: roman.insert(0, dict[i] + dict[i+1]); break;
            }
            num /= 10;
            i++;
        }
        return roman;
    }
};
