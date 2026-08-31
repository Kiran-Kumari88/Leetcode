class Solution {
public:
    bool checkValidString(string s) {
        int min=0;//low = minimum possible number of unmatched '('
        int max=0; //high = maximum possible number of unmatched '('

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){ //Because balance definitely increases.
                min=min+1;
                max=max+1;
            }
            else if(s[i]==')'){ //Because balance decreases.
                min=min-1;
                max=max-1;
            }
            else{ // "*"" -> 3 cases
            //'('  → balance +1
            //')'  → balance -1
            //empty → balance same

                min=min-1;
                max=max+1;
            }
            
            if(min<0) min=0;
            if(max<0) return false;
        }
        return (min==0); 
    }
};