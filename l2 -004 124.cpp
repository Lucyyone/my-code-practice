//4.23
//l2-004 124
//给出该树的前序 
//检查是否为二叉搜索树或是二叉搜索树的镜像 
//进行镜像处理 
//是的话进行后序遍历输出
//需要：
//利用前序和bst的性质/镜像规则先建立二叉树
//检查是否是二叉搜索树或是其镜像树
//后序遍历输出 
#include<bits/stdc++.h>
using namespace std;
int n,postindex;
vector<int>t;
vector<int>h; 
bool built(int l,int r,bool mirror){
	if(l>r) return 1;
	int root=t[l];
	int pos=l+1;
	if(!mirror){
		while(pos<=r&&t[pos]<root){
			pos++;
		}
		for(int i=pos;i<=r;i++){
			if(t[i]<root) return 0;
		}
	}
	else{
		while(pos<=r&&t[pos]>=root){
			pos++;
		}
		for(int i=pos;i<=r;i++){
			if(t[i]>=root) return 0;
		}
	}
	bool left=built(l+1,pos-1,mirror);
	bool right=built(pos,r,mirror);
	if(left&&right){
		h[postindex++]=root;
		return 1;
	}
	return 0;
}
int main(){
	cin>>n;
	t.resize(n);
	h.resize(n);
	for(int i=0;i<n;i++) cin>>t[i];
	postindex=0;
	if(built(0,n-1,1)){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) {
			if(i!=n-1) cout<<h[i]<<" ";
			else cout<<h[i];
		}
		return 0;
	}
	//postindex=0;
	else if(built(0,n-1,0)){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) {
			if(i!=n-1) cout<<h[i]<<" ";
			else cout<<h[i];
		}
		return 0;
	}
	cout<<"NO";
	return 0;
}
 


