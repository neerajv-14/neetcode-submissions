class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int gas_total =0, cost_total=0;

        for(auto &it: gas)gas_total+=it;

        for(auto &it: cost)cost_total+=it;

        if(gas_total<cost_total)return -1;

        int res=0,total=0;

        for(int i=0;i<n;i++){
            total+=(gas[i]-cost[i]);
            if(total<0){
                res=i+1;
                total=0;
            }
        }

        return res;
    }
};
