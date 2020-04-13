#include<bits/stdc++.h>
using namespace std;
#define sz 5
int tree[4*sz+5],a[]={2,3,1,4,6};
int l=1,r=3,summ=0;

int query(int at,int left,int right){

  //If you can also use this:
	//if(r<left||right<l)return 0;
	 if(l<=left&&right<=r)return tree[at];
   else if(left==right)return 0;
   int mid =(left+right)/2;
   int x = query(2*at,left,mid);
   int y = query(2*at+1,mid+1,right);
  
	return x+y;
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
    int qres = query(1,0,sz-1);
	for(int i=1;i<sz*2+2;i++)
	cout<<"Tree["<<i<<"]"<<tree[i]<<endl;
    
    cout<<"Query result = "<<qres<<endl;
}
