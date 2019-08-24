#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
class cal
{
	private:
		int sum[500];
	public:
		int length,l=0,te;
		cal()					// constructor()
		{
		memset(sum, 0, sizeof(sum));	
		}
		void copy(int b[500],int c[500],int l)		// copy of element a to b array
		{
			int i;
			for(i=0;i<=l;i++)
			{
				c[i]=b[i];
			}
		}
		void reverse(int c[500],int t)		// to reverse an array
		{			
			int i,b[500],k=0;
			for(i=t;i>=0;i--)
			{
				b[k]=c[i];
				k++;
			}
			copy(b,c,t);
		}

	void multiply(int a,int b[500])			// to multiply an integer array and an integer
	{			
		int i,t,k=0,c[500],m=0;
		memset(c, 0, sizeof(c));
		for(i=length;i>=0;i--)
		{
			c[k]=c[k]+ b[i]*a;
			c[k+1]=c[k]/10;
			c[k]=c[k]%10;
			k++;
		}
		if(c[k]!=0)
		k++;
		t=k-1;
		m=t;		
		if(c[t]>10)
		{
		while(c[t]>10)
		{
			c[t+1]=c[t+1]+c[t]/10;
			c[t]=c[t]%10;
			t++;
		}
		m=t;
		for(i=k-1;i<=m;i++)
		{
		int temp=c[k-1];
			c[k-1]=c[m];
			c[m]=temp;
		}
		}
		length=m;		
		reverse(c,m);
		copy(c,b,m);
	}
		void add(int a[500])	// for adding array
		{
			int k=499,i,t,y;		
			for(i=length;i>=0;i--)
			{
				sum[k]=sum[k]+a[i];
				sum[k-1]=sum[k-1]+(sum[k]/10);
				sum[k]=sum[k]%10;
				k--;
				}	
				if(sum[k-1]!=0)
				l= length -1;	
				else
				l=length;
		}	


		void result()           // printing final output or sum
		{
			int i;
			if(sum[te]==0)
			te--;
			for(i=499-te;i<500;i++)
			{
				cout<<sum[i];
			}
			cout<<endl;
		}
}ob[50];


void convert(char arr[],int ar[100],int l)			//converts char array to int array
{
	int i,j,q=0,m=0,n=0,x,y,z;
		for(i=0;i<=l;i++)
			{
				if(arr[i]==' ' ||i==l)
				{
				q=0;
					ar[m]=0;
					for(j=i-1;arr[j]!=' '&&j>=0;j--)
					{
						if(arr[j]>=48&&arr[j]<=57)
						{
						x=arr[j]-48;
						y=pow(10,q);
						z=x*y ;
						ar[m]=ar[m]+ z;
						}
						else
						{
							ar[m]=arr[j];
						}
							q++;
					}
					m++;
				}
			}		
}

int main()
{	
	ifstream fp("m.txt");
	int i,j,l,t=0;
	int a,d,y=0;
	string b;
	char r[10];
	int x[10],br[500];
	cout<<" INPUT \n";
	while(!fp.eof())				//untill end of file
	{
		getline(fp,b);
		strcpy(r,b.c_str());		// copy of sring to char
		cout<<b<<endl;
		l=b.size();					// size of b string
		convert(r,x,l);
		a=x[0];
		d=x[1];
		memset(br, 0, sizeof(br));		// initilizing br[] =0 to all elements
		for(i=a;i>=1;i--)
		{
			if(d>10)
		{
			br[0]=d/10;
			br[1]=d%10;
			t=1;
		}
		else
		{
			br[0]=d;t=0;
		}
		ob[y].length=t;
		for(j=1;j<i;j++)
			{	
				ob[y].multiply(d,br);   // multiply br with d
			}
			ob[y].multiply(i,br);		// multiply br with i
			if(i==a)
			ob[y].te=ob[y].length+1;
			ob[y].add(br);
		}
		y++;
	}
	cout<<"\n OUTPUT \n\n";
	for(i=0;i<=y;i++)
	ob[i].result();
fp.close();
}


