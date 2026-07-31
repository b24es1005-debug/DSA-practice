int start = 0;
    int maxlen = 1;
    void expand(string& s,int left,int right){
        while(left>=0 && right <s.size() && s[left]==s[right]){//check for palindrome
            left--;//expand to the left
            right++;//expand to the right
        }
        int len = right - left -1;//length of the palindrome
        if(len > maxlen){
            maxlen = len;
            start = left + 1;
        }

    }
    string longestPalindrome(string s) {
        for(int i = 0;i<s.size();i++){
            expand(s,i,i);//odd length
            expand(s,i,i+1);//even length
        }
        return s.substr(start,maxlen);//return the longest palindrome substring
    }