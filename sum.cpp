class merge_sort_tree
{
  public:
	struct node
    {
      int l,r;
      v64 pref;   
      v32 arr;
    };
	v32 a;
    vt <node> st; 
     void build(int l,int r,int k=0){
        st[k].l=l,st[k].r=r;
        st[k].arr.resize(r-l+1);
        st[k].pref.resize(r-l+2);
        if(l==r){
            st[k].arr[0]=a[l];
            st[k].pref[0]=0;
            st[k].pref[1]=a[l];
            return;
        }
        build(l,(l+r)>>1,2*k+1);
        build(((l+r)>>1)+1,r,2*k+2);
        merge(st[2*k+1].arr.begin(),st[2*k+1].arr.end(),st[2*k+2].arr.begin(),st[2*k+2].arr.end(),st[k].arr.begin());
        st[k].pref[0]=0;
        st[k].pref[1]=st[k].arr[0];
        f(i,1,st[k].arr.size())st[k].pref[i+1]=st[k].pref[i]+st[k].arr[i];
    }
    pair <lli,lli> query(int l,int r,lli val,int k=0){
        int ll=st[k].l,rr=st[k].r,mid=(ll+rr)>>1;
        if(rr<l || r<ll)return {0,0};
        if(ll>=l && rr<=r){
            lli cnt=lower_bound(st[k].arr.begin(),st[k].arr.end(),val)-st[k].arr.begin();
            return {st[k].pref[cnt],cnt};
        }
        pair <lli,lli> p1=query(l,r,val,2*k+1);
        pair <lli,lli> p2=query(l,r,val,2*k+2);
        return {p1.first+p2.first,p1.second+p2.second};
    }
};