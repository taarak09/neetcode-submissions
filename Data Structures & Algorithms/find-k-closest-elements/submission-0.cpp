class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //sliding window problem it izz
        int left=0;
        int right=0;
        //window size is fixed and it is already given 
        if(k==arr.size())
        {
            return arr;
        }
        right=k-1;
        for(int i=right+1;i<arr.size();i++)
        {
          if(abs(arr[i]-x)<abs(arr[left]-x))
          {
            left++;
          }
          else if(abs(arr[i]-x)==abs(arr[left]-x))
          {
             if(arr[i]==arr[left])
             {
                left++;
             }
             else if(abs(arr[i]-x)==abs(arr[left]-x))
             {
                break;
             }
          }
          else{
            break;
          }


        }
 vector<int>result;
 for(int i=left;i<left+k;i++)
 {
    result.push_back(arr[i]);
 }
  return result;  }
};