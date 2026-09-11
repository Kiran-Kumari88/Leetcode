class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int freq[26]={0};

        for(auto c : s){
            freq[c-'a']++; // -a for converting it into index
        }
        for(auto c : t){
            freq[c-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};