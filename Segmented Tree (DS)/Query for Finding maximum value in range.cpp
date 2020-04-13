#include<bits/stdc++.h>
using namespace std;
#define sz 5
int tree[4*sz+5],a[]={2,3,1,4,6};
int l=0,r=4,summ=0;

void query(int at,int left,int right)
{
	//if(r<left||right<l)return 0;
	 if(l<=left&&right<=r)//[l,r] range
    summ=max(summ,a[left]);//Finding maximum value
	
     if(left==right)return;
   int mid =(left+right)/2;
   query(2*at,left,mid);
   query(2*at+1,mid+1,right);
  
}

void build(int at, int left ,int right){
	if(left==right){
		tree[at]=a[left];
		return ;
	}
	int mid=(left+right)/2;
	build(2*at,left,mid);
	build(2*at+1,mid+1,right);
	tree[at]=tree[2*at]+tree[2*at+1];
}


int main (){
	build(1,0,sz-1);
    query(1,0,sz-1);
	for(int i=1;i<sz*2+2;i++)
	cout<<"Tree["<<i<<"]"<<tree[i]<<endl;
    
    cout<<"Query result = "<<summ<<endl;
}
