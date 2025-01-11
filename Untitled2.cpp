#include<bits/stdc++.h>
using namespace std;

struct Student{
	char firstname[30];
	char lastname[30];
	int year;
	char address[50];
};

void display(Student *students, int n){
	for(int i = 0; i<n ; i++){
		cout<<setw(10)<<left<<students[i].firstname;
		cout<<setw(15)<<left<<students[i].lastname;
		cout<<setw(10)<<left<<students[i].year;
		cout<<setw(10)<<left<<students[i].address<<endl;
	}
}
// dat ten du lieu phai co tinh thuc tien vd hang xe lambo, suv ... khong dat len kieu abc neu sai - nua diem

void Sort(Student *students,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		   if(strcmp(students[i].firstname,students[j].firstname) == 1)
		  {
			Student temp=students[i];
            students[i]=students[j];
            students[j]= temp;
		  }
		}
	} 
}

int Find(Student *students, int n, char *x){
	int left = 0;
	int right = n-1;
	while(left <= right){
		int mid = left +(right - left)/2;
		int cmp = strcmp(students[mid].firstname,x);
		if(cmp == 0){
			return mid;
		}else if(cmp<0){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	return -1;
}

void displayFindingStudent(Student *students, char *x){
	int position = 	Find(students,4,x);
	if(position != 1){
		cout<<"\n---------------------------------------------"<<endl;
		cout<<"Student number: "<<position+1<<" in my list of student"<<endl;
		cout<<setw(10)<<left<<students[position].firstname;
		cout<<setw(15)<<left<<students[position].lastname;
		cout<<setw(10)<<left<<students[position].year;
		cout<<setw(10)<<left<<students[position].address<<endl;
		cout<<"\n---------------------------------------------"<<endl;
	}else{
		cout<<"\n---------------------------------------------"<<endl;
		cout<<"404 NOT FOUND"<<endl;
		cout<<"\n---------------------------------------------"<<endl;
	}
}
int main(){
	Student students[]={
		{"Hoang","Nguyen Viet",2004,"Thai Binh"},
		{"Huy","Le Tran",2004,"Nghe An"},
		{"Duc","Ngo Van",2004,"Hai Phong"},
		{"Dinh","Pham Duc",2004,"Hai Duong"},
	};
	Sort(students,4);
	display(students,4);
	char x[30];
	cout<<"\n---------------------------------------------"<<endl;
	cout<<"\nEnter the name that you want to find:";
	cin>>x;
	cout<<"\n---------------------------------------------"<<endl;
	displayFindingStudent(students,x);
	
    return 0;
}
