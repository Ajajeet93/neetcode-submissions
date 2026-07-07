class Solution {
    bool valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')) return true;
        return false;
    }
    char to_lower(char ch){
        if(ch>='A' && ch<='Z'){
            int t = ch-'A';
            ch = 'a'+ t;
        }
        return ch;
    }
public:
    bool isPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        while(i<=j){
            char ch_i = to_lower(s[i]);
            char ch_j = to_lower(s[j]);
            if(!valid(ch_i)){
                i++;
                continue;
            }
            if(!valid(ch_j)){
                j--;
                continue;
            }
            if(ch_i!=ch_j) return false;
            i++;
            j--;
        }
        return true;
    }
};
