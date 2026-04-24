//4.24
//l2-006 树的遍历 
//利用后序和中序建立二叉树
//将二叉树层序输出 
#include<bits/stdc++.h>
using namespace std;
typedef struct tree{
	int data;
	struct tree *lc;
	struct tree *rc;
}tree,*etree;
int n,h[31],z[31];
etree chuang(int hl,int hr,int zl,int zr){
	int pos;
	if(zl>zr||hl>hr) return NULL;
	etree r=new tree;
	r->data=h[hr];
	for(int i=zl;i<=zr;i++){
		if(z[i]==r->data) {
			pos=i;
			break;
		}
	}
	int lefts=pos-zl;
	r->lc=chuang(hl,hl+lefts-1,zl,pos-1);
	r->rc=chuang(hl+lefts,hr-1,pos+1,zr);
	return r;
}
void cengxu(etree t){
	if(!t) return;
	queue<etree>q;
	q.push(t);
	int count=0;
	while(!q.empty()){
		etree c=q.front();
		count++;
		cout<<c->data;
		if(count<n) cout<<" "; 
		q.pop();
		if(c->lc) q.push(c->lc);
		if(c->rc) q.push(c->rc);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cin>>z[i];
	etree t=chuang(0,n-1,0,n-1);
	cengxu(t);	
	return 0;
} 

