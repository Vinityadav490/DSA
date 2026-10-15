class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        bool flag=true;
        long long sum=mass;
        for(int i=0; i<asteroids.size(); i++){
            if(sum>=asteroids[i]){
                sum+=asteroids[i];
            }
            else{
              flag=false;
              break;
            }
        }
        return flag;
    }
};