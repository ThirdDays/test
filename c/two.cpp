#include<iostream>
#include <algorithm>
using namespace std;
#define maxNum 1000000
int arr[maxNum];
//�������� 
void input(int n,int arr[]) {
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
}

bool isAllSame(int n,int arr[]) {
	int sign = 0;				//���ڱ�� 
	for(int i=1;i<n;i++) {
		if(arr[0] != arr[i]) {
			sign = 1;				//�������ݶ���ȫ��� 
			break;
		}
	}
	if(sign == 0) {			//�������ݶ�ȫ���
		return true;
	}else {
		return false;
	}
}

int getMin(int n,int arr[]) {
	int min=arr[0];
	for(int i=1;i<n;i++) {
		if(arr[i]<min) {
			min = arr[i];
		}
	}
	return min;
}
int getMin2(int n,int arr[],int min) {
	int sec=arr[0];
	for(int i=0;i<n;i++) {
		if(arr[i] != min) {
			if(arr[i] < sec) {
				sec = arr[i];
//				cout<<sec<<endl;
			}
		}
	}
	return sec;
}
void finalResult(int n,int arr[]) {
//	sort(arr,arr+n);
	int min = getMin(n,arr);
//	cout<<"min="<<min<<endl;
	int second=getMin2(n,arr,min);
//	for(int i=0;i<n;i++) {
//		if(arr[i]>min) {
//			second=arr[i];
//			break;
//		}
//	}
	cout<<min<<" "<<second<<endl;
}
//������ս�� 
void output(int n,int arr[]){
	if(n<2) {		//�������ݲ�������
		cout<<"Invalid Input"<<endl;
	}else {
		if(isAllSame(n,arr)) {				//�������ݶ�ȫ���
			cout<<"There is no second smallest element"<<endl; 
		}else {
			finalResult(n,arr);				//ִ�к����߼� 
		}
	}
}
int main() {
	int n;
	cin>>n;
	input(n,arr);
	output(n,arr);
//	sort(arr,arr+n);
//	for(int i = 0;i<n;i++) {
//		cout<<arr[i]<<" "<<endl;
//	}
	return 0;
}
