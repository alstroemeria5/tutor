#include <iostream>
#include <climits>
using namespace std;
int Merge(int arry[],int front,int mid,int rear);
int MergeSort(int arry[],int front,int rear);


int main(int argc,char *argv[]){
	int A[5]={5,4,3,2,1};
	MergeSort(A,0,4);
	for(int i=0;i<5;i++)
		cout<<A[i]<<' ';
	cout<<endl;
}
int MergeSort(int arry[],int front,int rear){
	if(front<rear){
		int mid=(front+rear)/2;
		MergeSort(arry,front,mid);
		MergeSort(arry,mid+1,rear);
		Merge(arry,front,mid,rear);
	}
}
int Merge(int arry[],int front,int mid,int rear){
	int nfront=mid-front+1;
	int nrear=rear-mid;
	int* L=new int[nfront+1];
	int* R=new int[nrear+1];
	for(int i=0;i<nfront;i++)
		L[i]=arry[front+i];
	for(int i=0;i<nrear;i++)
		R[i]=arry[mid+1+i];
	L[nfront]=INT_MAX;
	R[nrear]=INT_MAX;

	int i=0;int j=0;
	for(int k=front;k<=rear;k++)//using equate because we input end point not the whole number of element
	{
		if(L[i]<=L[j]){
			arry[k]=L[i];
			i++;
		}
		else
		{
			arry[k]=R[j];
			j++;
		}
		
	}
}