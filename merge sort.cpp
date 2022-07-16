/*
This algorithm is for merge sort for two-dimensional arrays. sorting the array with respect to selected parameters as in this example you can choose either x or y to sort your array by:
arr[3][3]={{x1,y1,z1},{x2,y2,z2},{x3,y3,z3}}
*****array[3][3]={{2,4,0},{-1,5,1},{9,2,2}};*****
Sort with X parameter: array[3][3]={{-1,5,1},{2,4,0},{9,2,2}};
 Sort with Y parameter: array[3][3]={{9,2,2},{2,4,0},{-1,5,1}};
 Sort with Z parameter: array[3][3]={{2,4,0},{-1,5,1},{9,2,2}};

*/
#include <bits/stdc++.h>
using namespace std;




// Merge two subarrays Left and right into array "a"
void merg (int a[][3],int l,int mid,int r,int level,int dimension)
{
     int n1 = mid - l + 1,n2 = r-mid;
 
 // Create Left ← a[l..mid] and right ← a[mid+1..r]
     int ** left=new int*[n1],
         ** right=new int*[n2];
       for(int i=0;i<n1;i++)
            left[i]=new int [dimension];
       for(int i=0;i<n2;i++)
            right[i]=new int [dimension];

     for (int i = 0; i < n1; i++)
      for(int j=0;j<dimension;j++)
        left[i][j] = a[l + i][j];

     for (int i = 0; i< n2; i++)
      for(int j=0;j<dimension;j++)
        right[i][j] = a[mid + 1 + i][j];

  // Maintain current index of sub-arrays and main array
int i=0,k=l,j=0;
// Until we reach either end of either Left or right , pick larger among
  // elements Left and right and place them in the correct position at A[l..r]
   while(i<n1&&j<n2)
   {
    if(left[i][level]<=right[j][level])
    {
       for(int ite=0;ite<dimension;ite++)
        a[k][ite]=left[i][ite];
        i++;
    }
    else
    {
       for(int ite=0;ite<dimension;ite++)
        a[k][ite]=right[j][ite];
        j++;
    }
    k++;
   }
   
// When we run out of elements in either Left or right,
  // pick up the remaining elements and put in A[l..r]   
while (i < n1)
  {
   for(int ite=0;ite<dimension;ite++)
    a[k][ite] = left[i][ite];
    i++;
    k++;
  }

  while (j < n2) {
   for(int ite=0;ite<dimension;ite++)
    a[k][ite] = right[j][ite];
    j++;
    k++;
  }
  
  
  
//demolish the temporary containers left and right  
for(int i=0;i<n1;i++)
            delete left[i];
delete left;
for(int i=0;i<n2;i++)
            delete right[i];
delete right;

}



// Divide the array into two subarrays, sort them and merge them
void mergesort(int arr[][3],int l,int r,int level,int dimension)
{
   if(l<r)
   {
       // mid is the point where the array is divided into two subarrays
    int mid =l+(r-l)/2;
    mergesort(arr,l,mid,level,dimension);
    mergesort(arr,mid+1,r,level,dimension);
        // Merge the sorted subarrays
    merg(arr,l,mid,r,level,dimension);

   }

}




int main()
{
    int d=3,level;
    cin>>level;         //level is related to the parameters ** level=0 in this case =>x**
    level%=d;
   int sr[][3]={{2,4,0},{-1,5,1},{9,2,2}};
   mergesort(sr,0,2,level,d);
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<d;j++)
       cout<<sr[i][j]<<"  ";
   cout<<endl;
   }



    return 0;
}
