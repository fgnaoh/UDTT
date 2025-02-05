#include<bits/stdc++.h>
using namespace std;

struct Fan{
	char name[20];
	char color[20];
	int quantity;
	double price;
};
void display(Fan *fans, int n) {
	for(int i = 0 ; i < n ; i ++){
		cout<<setw(10)<<left<<fans[i].name;
		cout<<setw(10)<<left<<fans[i].color;
		cout<<setw(10)<<left<<fans[i].quantity;
		cout<<setw(10)<<left<<fans[i].price<<endl;
	}
}
double totalPrice(Fan * fans, int n, int i) {
	if(i == n) return 0;
	return fans[i].quantity * fans[i].price + totalPrice(fans,n,i + 1);
}
int count(Fan * fans, int left, int right) {
	if(left > right) return 0;
	if(left == right) return strcmp(fans[left].color, "Red") == 0 ? 1 : 0;
	
	int mid = (left + right)/2;
	return count(fans,left, mid) + count(fans,mid + 1,right);
}
void quaylui(int result[], Fan *fans, int pos, int d[]) {
	int count = 0;
	if(pos == 5) {
		for(int i = 0; i < 5 ; i ++) {
			cout<<i + 1;
			int m = result[i];
			cout<<setw(10)<<left<<fans[m].name;
			cout<<setw(10)<<left<<fans[m].price;
		}
		cout<<endl;
		return;
	}
	for(int i = 0 ; i < 5 ; i++) {
		if(d[i] == 0) {
			d[i] = 1;
			result[pos] = i;
			quaylui(result,fans,pos + 1,d);
			d[i] = 0;
		}
	}
}
int main() {
	int n = 6;
	Fan fans[] = {
		{"Toshiba","Black",3,1},
		{"Panasonic","Black",4,1},
		{"Shenko","Black",6,1},
		{"Tojo","Red",2,1},
		{"Medie","While",5,1},
		{"Sharp","Blue",7,1},
	};
	display(fans,n);
	int i = 0;
	double money = totalPrice(fans,n,i);
	cout<<money<<endl;
	int q = count(fans,0,n-1);
	cout<<q<<endl;
	int result[5];
	int d[6];
	for(int i = 0; i < 6; i++) {
		d[i] = 0;
	}
	quaylui(result,fans,0,d);
	
	return 0; 
}
