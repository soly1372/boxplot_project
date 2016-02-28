#include<iostream>
#include<math.h>


using namespace std ; 
int main()
{
	float median;
	int medindex;
	double iqr ; 
	double q1 ; 
	double q3 ; 
	double Min ; 
	double Max ; 
	int outliers[100] ; 
	int x;
	int z ; 
	int n ; 
	cout<< "please enter the size of the array : " << endl ; 
	cin>>  n ;   //  getting an integer number for the size of the array
	int *m = new int[n];  // an array with size of n 
	cout<< " please enter the numbers with spacebar or pushing the enter button each time : " << endl ;
	for( int i=1 ; i<=n ; i++ ) 
	{
		cin>>m[i]; // getting the numbers
	}
	
	 for(int i=1 ; i<=n ; i++)
	 {
		 for(int j=1 ; j<=n ; j++ )
		 {
			 if(m[i]<m[j])
				 swap(m[i] ,m[j]) ; 
		 }
	 }
	 cout<< "sorted numbers are : " << endl ;
	 for(int i=1 ; i<=n ; i++ )
	 {
		 cout<<m[i]<< " " ; 
	 }

	 if(n==2) // exeption if we had 2 numbers we wont have q1 and q2 
	 {
		 median = (m[1]+m[2])/2 ; 
		 cout<< endl << "median is :" << " " << median  << endl; 
		 cout<< " there is no q1 and q3" ; 
	 }
 
	 else if(n%2==1) // if n is odd
	 {
		 median = m[(1+n)/2];
		 medindex = (1+n)/2;
		 if((medindex-1) %2==1)
		 {
			 q1=m[((medindex-1)+1)/2];
			 q3=m[(n+(medindex+1))/2];
			 
		 }
		 else   
		 {
			 x=(((medindex-1)+1)/2);
			 z=x+1;
			 q1=((double)m[x]+m[z])/2;
			 int b =(n+(medindex+1))/2;
			 int c= b+1 ; 
			 q3=((double)m[b]+m[c])/2;
		 }
		cout<<" median is :" << " " << median << endl ; 
		cout << "q1 is : " << " " << q1 << endl ;
		cout << "q3 is : " << " " << q3 << endl ;

	 }
	 else // if n is even
	 {
	
		int s1 = (n+1)/2;
		int s2 = s1+1 ; 
		median = ((double)m[s1]+m[s2])/2;
		
	

		if((n/2)%2==1)
		{
			q1=m[(s1+1)/2] ; 
			q3 =m[(n+s2)/2];
		}
		else
		{
			int l = (s1+1)/2 ; 
			int l1 = l+1 ; 
			int h = (s2+n)/2 ; 
			int h1 = h+1 ; 
			q1 = ((double)m[l]+m[l1])/2 ; 
			q3 = ((double)m[h]+m[h1])/2 ; 
		}
		cout<<" median is :" << " " << median << endl ; 
		cout << "q1 is : " << " " << q1 << endl ;
		cout << "q3 is : " << " " << q3 << endl ;
	 }
	 
	 Min = m[1] ; 
	 Max = m[n] ; 
	
		cout << "Max is : " << " " << Max << endl ;
		cout << "Min is : " << " " << Min << endl ;
	 
		// finding outliers 
	 iqr = q3 - q1 ; 
	 int p = 0 ;
	 double k1 = (q1-1.5*iqr);
	 double k2 = q3+1.5*iqr ; 
	 for(int i=1 ; i<=n ; i++ ) 
	 {
		 if(m[i]<k1 || m[i]>k2)
		 {
			 outliers[p] = m[i] ;
			 p++ ; 
		 }

	 }
	 if(p==0)
	 {
		 cout<< " there are no outliers " << endl ;
	 }
	 else
	 {
		 cout<<"outliers are: "<<endl ; 
			 for(int i=0 ; i<p ; i++ ) 
		 {
			 cout<<  outliers[i]<< " "  ; 
		 }
	 }



	
	return 0 ; 
}