class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,h=height.size()-1;
        int ans=0;
        int lmax=height[l],rmax=height[h];
        while(l<h){
            if(height[l]<height[h]){
                lmax=max(height[l],lmax);
                ans+=lmax-height[l];
                l++;
            }
            else{
                rmax=max(height[h],rmax);
                ans+=rmax-height[h];
                h--;
            }
        }
        return ans;
    }
};
