#include<bits/stdc++.h>
using namespace std;
int* createLSP(string sm,int k)
{
	int *a=new int[k];
	int len=0;
	a[0]=0;
	int i=1;
	while(i<k)
	{
		if(sm[len]==sm[i])
		{
			len++;
			a[i]=len;
			i++;
		}else
		{
			if(len!=0)
			{
				len=a[len-1];
			}else
			{
				len=0;
				a[i]=0;
				i++;
			}
		}
	}
	/*for(i=0;i<k;i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl;*/
	return a;
}
		
			
			
	
int main()
{
	long long int t;
	cin >> t;
	while(t>0)
	{
		long long int n,m,k;
		cin >> n >> m >> k;
		string sn,sm;
		cin >> sn >> sm;
		int *LSP = createLSP(sm,k);
		long long int count=0,i=0,j=0;
		while(i<n)
		{		
			//cout << sn[i]<< "hi " << sm[j] << endl;
			if(sn[i]==sm[j])
			{
				i++;
				j++;
			}
			//cout << sn[i]<< "hi2 " << sm[j] << endl;
			if(j==k)
			{
				//cout << "String found at " << i-j << endl;
				j=LSP[j-1];
				//cout << j <<"_J" <<endl;
				count++;
			}else if(i<n && sm[j]!=sn[i])
			{
				if(j==0)
				{
					i++;
				}else
				{
					j=LSP[j-1];
				}
			}
		}
		if(count==0)
		{
			cout << "-1" << endl;
		}else
		{
			cout << count << endl;
		}
		t--;
	}
}
			
	
