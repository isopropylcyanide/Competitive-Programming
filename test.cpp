    #include<bits/stdc++.h>
    using namespace std;
    int seg[555555],a[100005],lazy1[555555],lazy2[555555][2],trail[100005];
    int count5(int num)
    {
    	int c=0;
    	while(num%5==0)
    	{
            c++;
            num/=5;
    	}
    	return c;
    }
    void banale()
    {
    	int sum=1,i,j;
    	for(i=5;i<100005;i*=5)
    	{
            for(j=i;j<100005;j+=i)
            {
            	trail[j]=sum;
            }
            sum++;
        }
        for(i=2;i<100005;i++)
        {
        	trail[i]+=trail[i-1];
        }
    }
    void build(int start,int end,int root)
    {
    	if(start==end)
    	{
    		seg[root]=count5(a[start]);
    		return ;
    	}
    	int l=(root<<1)+1,r=l+1,mid=(start+end)/2;
    	build(start,mid,l);
    	build(mid+1,end,r);
    	seg[root]=seg[l]+seg[r];
    }
    void upd(int l,int r,int start,int end,int root,int val,int flag)
    {
        if(flag==1)
        {
        	if(lazy2[root][0])
        	{
        		seg[root]=(lazy2[root][0]*(end-start+1))+(trail[end-start+1+lazy2[root][1]]-trail[lazy2[root][1]]);
        		if(start!=end)
        		{
        			int m=(end-start)/2;
        			lazy2[root*2+1][0]=lazy2[root*2+2][0]=lazy2[root][0];
        			lazy2[root*2+1][1]=lazy2[root][1];
        			lazy2[root*2+2][1]=lazy2[root*2+1][1]+m+1;
        		}
        		lazy2[root][0]=0;
            	seg[root]+=((val)*(end-start+1));
        	    if(start!=end)
        	    {
        		    lazy1[root*2+1]=val;
        		    lazy1[root*2+2]=val;
        	    }
            }
            else
            {
            	if(lazy1[root])
            	{
            		seg[root]+=((lazy1[root]*(end-start+1)));
            	if(start!=end)
        	    {
        		    lazy1[root*2+1]+=lazy1[root];
        		    lazy1[root*2+2]+=lazy1[root];
        	    }
        	    lazy1[root]=0;
        	    seg[root]+=((val)*(end-start+1));
        	    if(start!=end)
        	    {
        		    lazy1[root*2+1]+=val;
        		    lazy1[root*2+2]+=val;
        	    }
            }
        }
        if(start > end || start > r || end < l)
            return;
        if(start >= l and end <= r)
        {
            seg[root]+=((val)*(end-start+1));
        	    if(start!=end)
        	    {
        		    lazy1[root*2+1]+=val;
        		    lazy1[root*2+2]+=val;
        	    }
            return;
        }
        int mid = (start + end) / 2;
        upd(l,r,start,mid,root*2+1,val,1);
        upd(l,r,mid+1,end,root*2+2,val,1);
        seg[root] = seg[root*2+1] + seg[root*2+2];
        }
    }
    int query(int l,int r,int start,int end,int root)
    {
    	if(start>r||end<l||start>end)
    		return 0;
    	else if(start>=l&&end<=r)
    		return seg[root];
    	else
    	{
    		int mid=(start+end)/2,left=(root<<1)+1,right=left+1;
    		return(query(l,r,start,mid,left)+query(l,r,mid+1,end,right));
    	}
    }
    int main()
    {
    	int t;
    	scanf("%d",&t);
    	banale();

    	while(t--)
    	{
    		int n,m;
    		scanf("%d %d",&n,&m);
    		int i;
    		for(i=0;i<n;i++)
    		   scanf("%d",&a[i]);
    		build(0, n -1, 0);
    		long long sum=0;
            while(m--)
            {
            	int u,v,w,x;
            	scanf("%d%d%d",&u,&v,&w);
            	if(u==3)
            	{
            		int  tt = query(u-1, v-1, 0, n-1, 0);
                    sum+=tt;
            	}
            	else
            	{
            		scanf("%d",&x);
            		if(u==1)
            			upd(u-1,v-1,0,n-1,0,x, 1);
            		else
            			upd(u-1,v-1,0,n-1,0,x, 2);
            	}
            }
            printf("%lld\n",sum);
    	}
    	return 0;
    }
