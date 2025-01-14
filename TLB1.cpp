#include<bits/stdc++.h>
using namespace std;

int a[100],ok;
void createL(int a[],int n){
	for(int i=1;i<=n;i++){
		a[i]=0; 
	}
}
void sinh(int n){
	while(n>=1 && a[n]==1){
		a[n] = 0;
		--n;
	}
	if(n==0){
		ok = 0;
	}
	else{
		a[n] = 1;
	}
} 
int main(){
	int n ;
	cin>>n;
	ok=1;
	createL(a,n);
	while(ok){
		for(int i = 1; i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh(n);
	} 
}
