import java.util.*;
public class LCS {
	
	static void lcs(String X, String Y) {
		int[][] L =new int[X.length()+1][Y.length()+1];
		for(int i=0;i<=X.length();i++) {
			for(int j=0;j<=Y.length();j++) {
				if(i==0 || j==0) {
					L[i][j]=0;
				}
				else if(X.charAt(i-1)==Y.charAt(j-1)) {
					L[i][j]=L[i-1][j-1]+1;
				}
				else {
					L[i][j] = Math.max(L[i-1][j], L[i][j-1]);
				}
			}
		}
		int index=L[X.length()][Y.length()];
		int temp=index;
		int i=X.length();
		int j=Y.length();
		char[] lcs = new char[index+1];
		lcs[index]=' ';
		while(i>0&&j>0) {
			if(X.charAt(i-1)==Y.charAt(j-1)) {
				lcs[index-1]=X.charAt(i-1);
				i--;
				j--;
				index--;
			}
			else if(L[i-1][j]>L[i][j-1]){
				i--;
			}
			else {
				j--;
			}
			
		}
		System.out.print("LCS of "+X+" and "+Y+" is ");
		for(int k=0;k<=temp;k++) {
	           System.out.print(lcs[k]);
		}
		
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		System.out.println("Enter String1 :");
		String s1=s.next();
		System.out.println("Enter String2 :");
		String s2=s.next();
		lcs(s1,s2);
		
	}

}
