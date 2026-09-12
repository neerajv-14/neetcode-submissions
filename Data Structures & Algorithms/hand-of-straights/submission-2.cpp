class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize)return false;
        int groups = n/groupSize;
        unordered_map<int,int>m;

        //multiset<int>se;

        for(auto &it: hand)m[it]++;
        int count=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(hand.begin(),hand.end());

        for(int i=0;i<n;i++){
            if(m.find(hand[i]-1)==m.end()){
                count++;
                pq.push(hand[i]);
            }
            else{
                m[hand[i]-1]--;
                if(m[hand[i]-1]==0)m.erase(hand[i]-1);
                if(pq.top()==hand[i]-groupSize+1){
                    pq.pop();
                    m[hand[i]]--;
                    if(m[hand[i]]==0)m.erase(hand[i]);
                }
            }

            if(count>groups)return false;
        }

        return true;
    }
};
