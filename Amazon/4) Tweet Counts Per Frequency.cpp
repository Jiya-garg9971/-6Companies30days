class TweetCounts {
public:
map<string,vector<int>> mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        sort(mp[tweetName].begin(),mp[tweetName].end());
        int minute=60;int hour=3600;int day=86400;
        int gap=0;
        if(freq=="minute")gap=minute;
        if(freq=="hour")gap=hour;
        if(freq=="day")gap=day;
         vector<int> ans((endTime-startTime)/gap+1,0);
        int interval=(endTime-startTime)/gap;
        for(auto i:mp[tweetName]){
            if(i>=startTime and i<=endTime)ans[(i-startTime)/gap]++;
        }
        
        
        return ans;
    }
};
