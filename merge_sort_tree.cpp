lli cnt(lli x,vector <lli> &arr)
{
  lli n=arr.size();
  vector<int>::iterator low,high;
  low = lower_bound(arr.begin(), arr.end(), x);
  if (low == (arr.end()) || *low != x)
     return 0;
  high = upper_bound(low, arr.end(), x);
  return high - low;
}
lli get_last_smaller(vector<int>& v, int x)
{
  lli first = 0, last = v.size()-1;
  while (first <= last)
  {
    lli mid = (first + last) / 2;
    if (v[mid] >= x)
      last = mid - 1;
    else
      first = mid + 1;
  }
  return first - 1 < 0 ? -1 : first - 1;
}
bool intersection(int l,int r,int ll,int rr)
{
    if(r>=rr && l<=rr)
        return 1;
    else if(r>=ll && l<=ll)
        return 1;
    else if(l>=ll && r<=rr)
        return 1;
    return 0;
}
struct node
{
    int l,r;
    vector <int> arr;
};
void cst(int l,int r,int k,vector<node> &st,vector<int> &a)
{
    st[k].l=l,st[k].r=r;
    for(int i=l;i<r+1;i++)
        st[k].arr.push_back(a[i]);
    sort(st[k].arr.begin(),st[k].arr.end());
    if(l==r)
        return;
    cst(l,(l+r)/2,2*k+1,st,a);
    cst((l+r)/2+1,r,2*k+2,st,a);
}
lli query(int l,int r,int t,int k,vector<node> &st)
{
  int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
  if(ll>=l && rr<=r)
    return cnt(t,st[k].arr);
  lli ans=0;
  if(intersection(l,r,ll,mid)==1)
     ans+=query(l,r,t,2*k+1,st);
  if(intersection(l,r,mid+1,rr)==1)
      ans+=query(l,r,t,2*k+2,st);
  return ans;
}
lli query2(int l,int r,int t,int k,vector<node> &st)
{
  int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
  if(ll>=l && rr<=r)
    return get_last_smaller(st[k].arr,t)+1;
  lli ans=0;
  if(intersection(l,r,ll,mid)==1)
     ans+=query2(l,r,t,2*k+1,st);
  if(intersection(l,r,mid+1,rr)==1)
      ans+=query2(l,r,t,2*k+2,st);
  return ans;
}
