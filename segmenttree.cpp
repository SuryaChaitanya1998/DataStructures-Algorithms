#include<bits/stdc++.h>
using namespace std;
int tree[18];
int arr[8];
int query(int,int,int,int,int);
void build(int n,int start,int end)
{
	if(start==end)
	{
		tree[n]=arr[start];
	}else
	{
		int mid= (start+end)/2;
		build(2*n,start,mid);
		build(2*n+1,mid+1,end);
		tree[n]=tree[2*n]+tree[(2*n)+1];
	}
//	return tree;
}
int query(int n,int start,int end,int l, int r)
{
	if(start>r || end<l)
	{
		return 0;
	
	}
	if(l<=start && r>=end)
	{
		return tree[n];
	}
	int mid=(start+end)/2;
	int s1=query(2*n,start,mid,l,r);
	int s2=query(2*n+1,mid+1,end,l,r);
	return s1+s2;
}
int main()
{
	arr[1]=8;
	arr[2]=-1;
	arr[3]=5;
	arr[4]=3;
	arr[5]=-6;
	arr[6]=1;
	arr[7]=4;
	build(1,1,7);
	int i=0;
	for(i=1;i<18;i++)
	{
		cout << tree[i] << " " ;
	}
	cout << endl;
	int ans=query(1,1,7,1,1);
	cout << ans;
}
	
	
	
