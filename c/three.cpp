//������ 
#include<iostream>
using namespace std;
struct res{
	int size;			//��Ʒ�Ĵ�С 
	int location;		//��Ʒ��λ�� 
};
int arr3[100][100];	
void input(int n,res goods[]) {
	for(int i=0;i<n;i++) {
		goods[i].location=-1;			//��ʼ����Ʒ��λ�� 
		cin>>goods[i].size;
	}
}
//��ʼ����������
void init(int n,int arr[]) {
	for(int i=0;i<n;i++) {
		arr[i] = 0;
	}
}
int boxNum(int n,int arr[]) {		//��ȡ�����������д����Ʒ�ĸ��� 
	int size=0;				//��¼�������Ч���� 
	for(int i=0;i<n;i++) {
		if(arr[i] > 0) {
			size++;
		}
	}
	return size;
}
//����Ʒ���������� 
void depositGoods(int n,res goods[],int arr[]) {
	for(int i=0;i<n;i++) {				//������Ʒ 
		for(int j=0;j<n;j++) {			//������������ 
			if(goods[i].size <= ( 100-arr[j] )) {		//�����Ʒ�Ĵ�СС�ڵ������ӵ�ʣ������ 
				arr[j] += goods[i].size;					//����Ʒ���������� 
				goods[i].location = j;					//��¼���ӵ�λ�� 
				break;									
			}	
		}
	}
}
//������ս�� 
void output(int n,res goods[],int arr[]) {
	for(int i=0;i<n;i++) {
		cout<<goods[i].size<<" "<<++goods[i].location<<endl;
	}
	int size = boxNum(n,arr);
	cout<<size<<endl;
}
int main() {
	int n;
	cin>>n;
	res goods[n]; 			//���ڴ洢�ͼ�¼��Ʒ 
	int arr[n];
	init(n,arr);				//��ʼ���������� 
	input(n,goods); 
	depositGoods(n,goods,arr);
	output(n,goods,arr);
//	int arr3[n][n];			//��¼��������װ�����Ʒ,�ñ������ʾ��Ʒ 
//	cin>>n;
//	input(n,arr);
//	cout<<arr.size<<endl;
	
	return 0;
}
