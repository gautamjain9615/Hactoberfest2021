//Trapping Rain Water
//Problem Link - https://leetcode.com/problems/trapping-rain-water/

//Solution - 3 different approaches

class Solution {
public:
    int trap(vector<int>& height) {
        //---------------OPTIMAL SOLUTION----------------------
        int n = height.size(), sum=0;
        int l=0, r=n-1, leftMax=0, rightMax=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=leftMax)
                    leftMax = height[l];
                else
                    sum += leftMax-height[l];
                l++;
            }
            else{
                if(height[r]>=rightMax)
                    rightMax = height[r];
                else
                    sum += rightMax-height[r];
                r--;
            }
        }
        return sum;
        
        
        //----------------------------BETTER APPROCH--------------------
        
        // int n = height.size(), sum=0;
        // if(n==0)
        //     return 0;
        // int prefix[n], suffix[n];
        // prefix[0] = height[0];
        // suffix[n-1] = height[n-1];
        // for(int i=1; i<n; i++){
        //     prefix[i] = max(prefix[i-1], height[i]);
        // }
        // for(int i=n-2; i>=0; i--){
        //     suffix[i] = max(suffix[i+1], height[i]);
        // }
        // for(int i=0; i<n; i++){
        //     int mini = min(prefix[i], suffix[i]);
        //     if(mini>height[i])
        //         sum += mini-height[i];
        // }
        // return sum;
        
        
        //------------------------BRUTE FORCE APPROACH---------------------
        
        // int n = height.size(), sum=0;
        // for(int i=0; i<n; i++){
        //     int left=0, right=0;
        //     for(int j=0; j<=i; j++) left = max(left, height[j]);
        //     for(int j=i; j<n; j++) right = max(right, height[j]);
        //     int mini = min(left, right);
        //     if(mini>height[i])
        //         sum += mini-height[i];
        // }
        // return sum;
    }
};
