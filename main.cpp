#include <iostream>

using namespace std;

void StraightInsert_sort(int a[],int n)
{
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

void BinaryInsert_sort(int *a,int n)
{
    int i,j,temp,left,right,middle;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        left=0;
        right=i-1;
        while(left<=right)
        {
            middle=left+(right-left)/2;
            if(a[middle]>temp)
            {
                right=middle-1;
            }
            else
            {
                left=middle+1;
            }
        }
        for(j=i-1;j>=right+1;j--)
        {
            a[j+1]=a[j];
        }
        a[right+1]=temp;
    }
}

void Print(int *a)
{
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int i;
    int a[10];
    for(i=0;i<10;i++)
    {
        cin>>a[i];
    }
    StraightInsert_sort(a,10);
    Print(a);
    BinaryInsert_sort(a,10);
    Print(a);
    return 0;
}
