class Solution {
public:
//mergesort
    void merge(vector<int>& nums,vector<int> &a,vector<int> &b,int &s,int &n,int &m){
       cout<<s<<" ";
        int k=s;
        int i=0,j=0;
        while(i<n and j<m){
            if(a[i]<b[j])
                nums[k++]=a[i++];
            else
                nums[k++]=b[j++];
        }
        while(i<n)
            nums[k++]=a[i++];
        while(j<m)
            nums[k++]=b[j++];
        return ;
    }
    void mergesort(vector<int>&nums,int st,int end){
        if(st>=end){
            return ;
        }
        
        int mid=(st+end)/2;
       // cout<<mid<<" ";
         mergesort(nums,st,mid);
        mergesort(nums,mid+1,end);
        vector<int> a;
        vector<int> b;
        for(int i=st;i<=mid;i++){
            a.push_back(nums[i]);
        }
        int n1=a.size();
         for(int i=mid+1;i<=end;i++){
            b.push_back(nums[i]);
        }
        int n2=b.size();
      
        merge(nums,a,b,st,n1,n2);
    }
    vector<int> sortArray(vector<int>& nums) {
        int end=nums.size()-1;
        mergesort(nums,0,end);
        return nums;
    }
};
