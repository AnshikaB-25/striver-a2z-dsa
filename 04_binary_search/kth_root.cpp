class Solution {
public:
long long valuess(int i, int N){
  long long ans = 1;
  for(int j = 1 ; j<=N ; j++){
    ans*=i;
  }
  return ans;

}
  int NthRoot(int N, int M) {
    int low =1;
    int high = M;
    while(low<=high){
      int mid = (low + high)/2;
      long long vals = valuess(mid,N);
      if(vals == 1ll * M) return mid;
      else if(vals> 1ll * M) high = mid-1;
      else low = mid+1;
    }
    return -1;
       
    }
};
