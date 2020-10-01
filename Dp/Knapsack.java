import java.util.*;
public class Knapsack {
	
	static int knapSack(int W, int wt[], int val[], int n) {
		int k[][]=new int[n+1][W+1];
		for(int i=0;i<=n;i++) {
			for(int w=0;w<=W;w++) {
				if(i==0 || w==0) {
					k[i][w]=0;
				}
				else if (wt[i-1] <= w)
	                 k[i][w] = Math.max(val[i-1] + k[i-1][w-wt[i-1]],k[i-1][w]);
	            else
	                 k[i][w] = k[i-1][w];
			}
		}
		return k[n][W];
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		System.out.println("Enter number of elements: ");
		int n=s.nextInt();
		System.out.println("Enter Weight Constraint: ");
		int W=s.nextInt();
		int val[]=new int[n];
		int wt[]=new int[n];
		System.out.println("Enter values of Items: ");
		for(int i=0;i<n;i++) {
			val[i]=s.nextInt();
		}
		System.out.println("Enter weights of Items: ");
		for(int i=0;i<n;i++) {
			wt[i]=s.nextInt();
		}
		System.out.println(knapSack(W, wt, val, n));
		
		
	}

}
