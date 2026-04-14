class Solution {
private:
    bool isValid(vector<int>& piles, int h,int givenHour){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=ceil(double(piles[i])/double(givenHour));
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high){
            int mid=(low+high)/2;

            if(isValid(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
