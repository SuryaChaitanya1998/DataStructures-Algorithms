#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
char* removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
    return str;
    
}
int* createLSP(string s)
{
	int *a = new int[s.size()];
	a[0]=0;
	int len=0;
	int i=1;
	while(i<s.size())
	{
		if(s[len] == s[i])
		{
			len++;
			a[i]=len;
			i++;
		}
		else{
			if(len!=0)
			{
				len=a[len-1];
			}
			else
			{
				len=0;
				a[i]=0;
				i++;
			}
		}
	}
	return a;
}
string removeSpaces(string s)
{
	string temp = "";
	for (int i=0;i<s.size();i++){
		if (s[i] != ' '){
			temp = temp + s[i];
		}
	}
	return temp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; 
	cin >> t;
	int k=1;
	while(k<=t)
	{
		string s,S;
		getline(cin,S);
		getline(cin,S);
		S = removeSpaces(S);
		//cout << S;		
		cin >> s;
		//	cout << s << endl;	
		int *LSP=createLSP(s);
	    int i=0;
	    int j=0;
		int n=S.size();
		int n2=s.size();
		int count=0;
		while(i<n)
		{
			if(S[i]==s[j])
			{
				i++;
				j++;
			}
			if(j==n2)
			{
				count++;
				j=LSP[j-1];
			}
			else if(i<n && S[i]!=s[j])
			{
				if(j==0)
					i++;
				else
					j=LSP[j-1];
			}
		}
		cout << "Case " << k << ": " << count << endl;		
		k++;
	}
}
			
		
		
