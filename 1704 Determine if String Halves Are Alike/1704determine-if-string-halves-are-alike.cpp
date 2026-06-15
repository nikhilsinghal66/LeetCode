class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        int leftvowel=0;
        int rightvowel=0;
        int i=0;
        int j=s.length()/2;
        int n=s.length();
        while(i<n/2 && j<n){
            if(st.find(s[i])!=st.end()) leftvowel++;
            if(st.find(s[j])!=st.end()) rightvowel++;
            i++;
            j++;
        }
        return leftvowel==rightvowel;
    }
};