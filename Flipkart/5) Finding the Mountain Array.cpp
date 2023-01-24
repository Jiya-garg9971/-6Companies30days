/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarysrch(int target, MountainArray &arr,int s,int end,bool dir){
        if(s>end)return -1;
        int mid=(s+end)/2;
        //cout<<mid<<" ";
        if(dir){
            //sorted in ascending order
            int ele=arr.get(mid);
            if(ele==target)return mid;
            else if(ele>target){
                return binarysrch(target,arr,s,mid-1,true);
            }
            else{
               return binarysrch(target,arr,mid+1,end,true); 
            }
        }
         else{
            //sorted in descending order
            int ele=arr.get(mid);
            if(ele==target)return mid;
            else if(ele<target){
                return binarysrch(target,arr,s,mid-1,false);
            }
            else{
               return binarysrch(target,arr,mid+1,end,false); 
            }
        }
    }
    int peakIndexInMountainArray(MountainArray & arr,int target) {
        //using binary search
        int s=0,e=arr.length()-1;
        int mid=(s+e)/2;
        while(s<e){
            if(arr.get(mid)==target)return mid;
            int mid=s+(e-s)/2;
            if(arr.get(mid)>arr.get(mid+1)){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;
        
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int idx=peakIndexInMountainArray(mountainArr,target);
        cout<<idx<<" ";
        int end=mountainArr.length()-1;
        //if(mountainArr.get(idx)==target)return idx;
        int bsearch=binarysrch(target,mountainArr,0,idx,true);
        if(bsearch!=-1)return bsearch;
        cout<<bsearch<<" ";
        bsearch=binarysrch(target,mountainArr,idx+1,end,false);
        if(bsearch!=-1)return bsearch;
        cout<<bsearch<<" ";
        return -1;

    }
};
