#include <iostream>

using namespace std;

int main()
{
    int n=0,x=0,y=0;
    /*int a[n];*/
    int i,j,temp;
    /*cin>>n;*/
    int a[10]={0,11,22,33,55,66,77,99,88,44};
    /*for(i=0;i<=n-1;i++)
    {
        cin>>a[i];
    }
    */
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }
    /*
    for(i=0;i<n;i++)
    {
        while(a[i]<60)
        {
            if(a[i]<a[i+1])
            {
                x=a[i+1];
            }
        }
    }


    for(i=n-1;i>=0;i--)
    {
        while(a[i]>60)
        {
            if(a[i]<a[i+1])
            {
                y=a[i+1];
            }
        }
    }

    if(x!=0)
    {
        cout<<x;
    }
    else cout<<"worth case";

    if(y!=0)
    {
        cout<<y;
    }
    else cout<<"worth case";
    */
}