#include<bits/stdc++.h>
using namespace std;
int getsum(int index);
void update(int index,int key,int n);
int parent(int index);
int	next(int index);
int arr[10];
int BITree[11];
int getsum(int index)
{
	int sum=0;
	index=index+1;
	while(index>0)
	{
		sum=sum+BITree[index];
		index=parent(index);
	}
	return sum;
}
void update(int index,int key,int n)
{
	index=index+1;
	while(index<=n)
	{
		BITree[index]+=key;
		index=next(index);
	}
}
int next(int index)
{
	index=index+(index&-index);
	return index;
}
int parent(int index)
{
	index=index-(index&-index);
	return index;
}
int *constructBITree(int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    for (int i=0; i<n; i++)
        update(i, arr[i],n);
 
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
 
    return BITree;
}	
int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		arr[i]= i+1;
	}
	constructBITree(10);
	for(i=0;i<10;i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
	cout << getsum(3) <<endl;

	update(2,5,10);
	cout << getsum(3);
	
	
}
