class Solution{
public:
    vector<vector<string>> groupAnagram(vector<string>& strs){
        unordered_map<string,vector<string>> mp;
        for(string s : strs){
            string key = s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};