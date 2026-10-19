class Solution {
public:
    vector<int>memLeak(int memory1, int memory2) {
        for(int i=1; i<1000000; i++){
            if(memory1<i&&memory2<i){
                return {i,memory1,memory2};
            }
            if(memory1>=memory2) memory1-=i;
            else if(memory1<memory2) memory2-=i;
            
        }
        return {};
    }
};