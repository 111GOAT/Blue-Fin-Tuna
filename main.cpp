#include <iostream>

using namespace std;

void Shell_sort(int a[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=a[i];
            for(j=i-gap;j>=0&&temp<a[j];j-=gap)   //Ö±½Ó²åÈëÅÅÐò
			{
				a[j+gap] = a[j];
			}
			a[j+gap] = temp;
        }
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
    Shell_sort(a,10);
    Print(a);
    return 0;
}
