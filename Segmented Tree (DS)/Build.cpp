#include<bits/stdc++.h>
using namespace std;
#define sz 5
int tree[4*sz+5],a[]={2,3,1,4,6};

/*We have to memorize that, we should initialize at least
  "4*size" memories in tree array.*/
 
void build(int at, int left ,int right){
	if(left==right){
		tree[at]=a[left];
		return ;
	}
	int mid=(left+right)/2;

	build(2*at,left,mid);//Left side of root
	build(2*at+1,mid+1,right);//Right side of root

        //Storing sum of childs to their parent node

	tree[at]=tree[2*at]+tree[2*at+1];
}
 
 
int main (){
	build(1,0,sz-1);
 
	for(int i=1;i<sz*2+2;i++)
	cout<<"Tree["<<i<<"]"<<tree[i]<<endl;
 
}
