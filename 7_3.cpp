#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,k,ans;
int f[55][55];
void xx()
{
	ans=0;
	memset(f,0,sizeof(f));
}
int main()
{
	while (scanf("%d%d",&n,&k)==2)//读入几个数，就等于几
	   {
	   	  //第一问
	   	  xx();
          for (int i=0;i<=n;i++)
	        {
	  	      f[i][1]=1;
	  	      f[i][i]=1;
	        }
	      for (int i=2;i<=n;i++)
	        for (int j=2;j<=k;j++)
	          {
	            f[i][j]=f[i-1][j-1];
	            if (i-j>=j)
	              f[i][j]+=f[i-j][j];
	          }
	     cout<<f[n][k]<<endl;
	     //第二问
	     xx();
         for (int i=1;i<=n;i++)
           f[i][1]=1;
         for (int j=2;j*(j+1)/2<=n;j++)
           for (int i=j*(j+1)/2;i<=n;i++)
             for (int k=1;k*j+j*(j-1)/2<=i;k++)
               f[i][j]+=f[i-j*k][j-1];
        for (int j=1;j*(j+1)/2<=n;j++)
          ans+=f[n][j];
        cout<<ans<<endl;
        //第三问
        xx();
        for (int i=1;i<=n;i++)
          if (i%2)
	        {
	  	      f[i][1]=1;
	  	      f[i][2]=0;
	        }
	    else
	      {
	   	    f[i][1]=0;
	   	    f[i][2]=(i/2+1)/2;
	      }
	    for (int i=3;i<=n;i++)
	      for (int j=1;j<=i;j++)
	        {
	          f[i][j]=f[i-1][j-1];
	          if (i-2*j>=j)
	            f[i][j]+=f[i-2*j][j];
	        }
	    for (int i=1;i<=n;i++)
	      ans+=f[n][i];
	    cout<<ans<<endl;
       }
}