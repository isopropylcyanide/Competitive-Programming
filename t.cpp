#include<stdio.h>
#include<string.h>
#define M 1000000007
long long int pope(long long int a)
{int ans=1,p=2;
    while(a){if(a&1){ans=(ans%M*p)%M;}
        a=a/2;p=(p%M*p%M)%M;}
    return ans;}
int main()
{
    long long int t,a,i,f,s,x,ans;char s1[100001],s2[100001],sa[100001],sb[100001];
    scanf("%lld",&t);
    while(t--)
    {f=0;s=0;x=0;
        scanf("%s",sa);scanf("%s",sb);a=strlen(sa);
        for(i=0;i<a;i++){s1[i]=sa[i];s2[i]=sb[i];}//printf("s1  %s\ns2  %s\n\n",s1,s2);
        for(i=0;i<a-1;)
        {
            if(s1[i]=='2')
            {if(i+1<a-1)
                    {if(s1[i+1]=='2')
                            {if(i+2<a-1)
                                {if(s1[i+2]!='1'&&s2[i+2]=='1')
                                    {
                                        ///swap
                                        s1[i+2]='1';s2[i+2]='2';
                                        ///
                                        if(s2[i+1]=='2');else if(i+3<a-1&&s2[i+3]=='2');else if(i+3<a-1&&s1[i+3]=='2'){s1[i+3]='1';s2[i+3]='2';}
                                        else {f=1;break;}
                                        ///swap
                                    //x++;
                                    i=i+3;
                                    }
                                    else if(s1[i+2]=='1')i=i+3;else{f=1;break;}
                                }else{f=1;break;}
                            }
                        else if(s2[i+1]=='2')
                        {
                            ///swap
                            s1[i+1]='2';
                            s2[i+1]='1';
                            ///swap
                            //x++;
                            if(i+2<a-1)
                                {if(s1[i+2]!='1'&&s2[i+2]=='1')
                                    {
                                        ///swap
                                        s1[i+2]='1';s2[i+2]='2';
                                        if(s2[i+1]=='2');else if(i+3<a-1&&s2[i+3]=='2');else if(i+3<a-1&&s1[i+3]=='2'){s1[i+3]='1';s2[i+3]='2';}
                                        else {f=1;break;}
                                        ///swap
                                    //x++;
                                    i=i+3;
                                    }
                                    else if(s1[i+2]=='1')i=i+3;else{f=1;break;}
                                }else{f=1;break;}
                        }
                        else{f=1;break;}
                    }
                    else {f=1;break;}
            }
            else i++;
        }
        for(i=0;i<a-1;)
        {
            if(s2[i]=='2')
            {
                if(i+2<a-1&&s2[i+1]=='2'&&s2[i+2]=='1')
                    i=i+3;
                else
                {
                    f=1;break;
                }
            }else i++;
        }
        for(i=0;i<a-1;)
        {
            if(s1[i]=='2')
            {
                if(i+2<a-1&&s1[i+1]=='2'&&s1[i+2]=='1')
                    i=i+3;
                else
                {
                    f=1;break;
                }
            }else i++;
        }
        if(f==1)
        {f=0;
            for(i=0;i<a;i++){s2[i]=sa[i];s1[i]=sb[i];}//printf("s1  %s\ns2  %s\n\n",s1,s2);
            for(i=0;i<a-1;)
        {
            if(s1[i]=='2')
            {if(i+1<a-1)
                    {if(s1[i+1]=='2')
                            {if(i+2<a-1)
                                {if(s1[i+2]!='1'&&s2[i+2]=='1')
                                    {
                                        ///swap
                                        s1[i+2]='1';s2[i+2]='2';
                                        ///
                                        if(s2[i+1]=='2');else if(i+3<a-1&&s2[i+3]=='2');else if(i+3<a-1&&s1[i+3]=='2'){s1[i+3]='1';s2[i+3]='2';}
                                        else {f=1;break;}
                                        ///swap
                                    //x++;
                                    i=i+3;
                                    }
                                    else if(s1[i+2]=='1')i=i+3;else{f=1;break;}
                                }else{f=1;break;}
                            }
                        else if(s2[i+1]=='2')
                        {
                            ///swap
                            s1[i+1]='2';
                            s2[i+1]='1';
                            ///swap
                            //x++;
                            if(i+2<a-1)
                                {if(s1[i+2]!='1'&&s2[i+2]=='1')
                                    {
                                        ///swap
                                        s1[i+2]='1';s2[i+2]='2';
                                        if(s2[i+1]=='2');else if(i+3<a-1&&s2[i+3]=='2');else if(i+3<a-1&&s1[i+3]=='2'){s1[i+3]='1';s2[i+3]='2';}
                                        else {f=1;break;}
                                        ///swap
                                    //x++;
                                    i=i+3;
                                    }
                                    else if(s1[i+2]=='1')i=i+3;else{f=1;break;}
                                }else{f=1;break;}
                        }
                        else{f=1;break;}
                    }
                    else {f=1;break;}
            }
            else i++;
        }
        for(i=0;i<a-1;)
        {
            if(s2[i]=='2')
            {
                if(i+2<a-1&&s2[i+1]=='2'&&s2[i+2]=='1')
                    i=i+3;
                else
                {
                    f=1;break;
                }
            }else i++;
        }
        for(i=0;i<a-1;)
        {
            if(s1[i]=='2')
            {
                if(i+2<a-1&&s1[i+1]=='2'&&s1[i+2]=='1')
                    i=i+3;
                else
                {
                    f=1;break;
                }
            }else i++;
        }
        }
        //printf("%s\n",s1);
        //printf("%s\n\n",s2);
        ///ans calculation
        if(f==0){long long int x2,g;x2=0;ans=0;

                long long int h,y,z,single,final,y1;final=1;h=0;y=0;z=single=0;y1=0;g=1;//printf("//////////////////////////////\n");
                //printf("\n%s\n\n%s\n",s1,s2);
            for(i=0;i<a-1;)
            {
                if(s1[i]!=sa[i])
                    {
                        h=1;i++;g=0;
                    }
                else if(s1[i]=='1'&&s2[i]=='1')
                    {
                        if(h==0)
                            {
                                if(g==0)
                                {y=y+1;g=1;}ans++;i++;
                            }
                        else if(h==1)
                            {
                                ans++;h=0;i++;ans+=single;single=0;
                            }
                            else if(h==2)
                            {y1=pope(single);
                                final=((final%M)*(y1+1)%M)%M;
                                single=0;i++;ans++;
                            }
                    }
                else if(s1[i]=='2'&&s2[i]=='2')
                    {g=0;
                        if(s1[i+1]=='2'&&s2[i+1]=='2')
                            {
                                z++;i=i+2;
                            }
                        else
                            {
                                i++;if(h!=1){single++;h=2;}else ans++;
                            }
                    }
                else {i++;g=0;}
            }
        ///if(s1[0]=='1'&&s2[0]=='1'&&y>0)y=y-1;
        ///printf("x=%lld\ny==%lld\nans=%lld\nz=%lldfinal=%lld\n",x,y,ans,z,final);
        ///ans=ans+x+y+z+1;
        ans=ans+y+z+1;
        ///printf("ans=%lld\n",ans);
        ans=pope(ans);
        ans=(final*ans)%M;
                    if(a==1)
                            printf("2\n");
                    else
                            printf("%lld\n",ans);
                }
    else printf("0\n");
    }
    return 0;
}
