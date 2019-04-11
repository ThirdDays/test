//µÚÒ»Ìâ 
#include<iostream>
using namespace std;
void input(int n,int arr[]) {
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
}
bool isAllNegative(int n,int arr[]) {
	int sign=1;
	for(int i=0;i<n;i++) {
		if(arr[i]<0) {
			sign = 0;
			break;
		}
	}
	if(sign==1) {
		return true;
	}else {
		return false;
	}
}

int core(int n,int arr[]) {
	int max=0;
	for(int i=0;i<n;i++) {			
		int temp=0;	
		for(int j=i;j<n;j++) {
			temp+=arr[j];
			if(temp>max) {
				max=temp;
			}
		}
	}
	return max;	
}
void output(int n,int arr[]) {
	if(isAllNegative(n,arr)) {
		cout<<0<<endl;
	}else {
		int result=core(n,arr);
		cout<<result<<endl;
	}
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	input(n,arr);
	output(n,arr);
	return 0;
}
