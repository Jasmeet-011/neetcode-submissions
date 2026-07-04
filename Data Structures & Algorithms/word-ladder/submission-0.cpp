class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end()) return 0;
        queue<pair<string,int>>q;
        
        q.push({beginWord,1});
        words.erase(beginWord);
        while(!q.empty()){
            auto [st,step]=q.front();
            q.pop();
            if (st==endWord)return step;
            for(int i=0;i<st.size();i++){
                string temp=st;
                for(char ch='a';ch<='z';ch++){
                    if(ch==temp[i])continue;
                    temp[i]=ch;
                    if(words.find(temp)!=words.end()){
                        q.push({temp,step+1});
                        words.erase(temp);
                    }
                }    
            }
        }
        return 0;


        
    }
};
