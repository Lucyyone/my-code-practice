//根据后序建立完全二叉树
//再用层序输出该完全二叉树的每一个节点
#include<bits/stdc++.h>
using namespace std;
typedef struct tree{
	int data;
	struct tree *lc;
	struct tree *rc;
}tree,*etree;
int a[31];
int n;
int zuozishu(int n){
	if(n<=1) return 0;
	int h=(int)log2(n+1);
	int lasts=n-((1<<(h))-1);
	int szs=(1<<(h-1))-1;//上一层左子树的节点总数 
	int zlef;
	if(lasts<(1<<(h-1)))  zlef=lasts+szs;
	else  zlef=szs+(1<<(h-1));
	return zlef;
}
etree houxuchuang(int a[],int s,int e){
	if(s>e) return NULL;
	//etree r=(etree)malloc(sizeof(struct tree));
	etree r=new tree;
	r->data=a[e];
	int n=e-s+1;
	if(n==1) {
		r->lc=r->rc=NULL;
		return r;
	}
	int ls=zuozishu(n);
	int rs=n-ls-1;
	r->lc=houxuchuang(a,s,s+ls-1);
	r->rc=houxuchuang(a,s+ls,s+ls+rs-1);
	return r;
}
void cengxushuchu(etree r){
	if(r==NULL) return ;
	queue<etree>q;
	q.push(r);
	int count=0;
	while(!q.empty()){
		etree c=q.front();
		q.pop();
		count++;
		cout<<c->data;
		if(count<n)cout<<" ";
		if(c->lc) q.push(c->lc);
		if(c->rc) q.push(c->rc);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	etree r=houxuchuang(a,0,n-1);
	cengxushuchu(r);
	return 0;
}










 
