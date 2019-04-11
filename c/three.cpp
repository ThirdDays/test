//第三题 
#include<iostream>
using namespace std;
struct res{
	int size;			//物品的大小 
	int location;		//物品的位置 
};
int arr3[100][100];	
void input(int n,res goods[]) {
	for(int i=0;i<n;i++) {
		goods[i].location=-1;			//初始化物品的位置 
		cin>>goods[i].size;
	}
}
//初始化箱子数组
void init(int n,int arr[]) {
	for(int i=0;i<n;i++) {
		arr[i] = 0;
	}
}
int boxNum(int n,int arr[]) {		//获取箱子数组中有存放物品的个数 
	int size=0;				//记录数组的有效长度 
	for(int i=0;i<n;i++) {
		if(arr[i] > 0) {
			size++;
		}
	}
	return size;
}
//将物品存入箱子中 
void depositGoods(int n,res goods[],int arr[]) {
	for(int i=0;i<n;i++) {				//遍历物品 
		for(int j=0;j<n;j++) {			//遍历箱子数组 
			if(goods[i].size <= ( 100-arr[j] )) {		//如果物品的大小小于等于箱子的剩余容量 
				arr[j] += goods[i].size;					//将物品存入箱子中 
				goods[i].location = j;					//记录箱子的位置 
				break;									
			}	
		}
	}
}
//输出最终结果 
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
	res goods[n]; 			//用于存储和记录物品 
	int arr[n];
	init(n,arr);				//初始化箱子数组 
	input(n,goods); 
	depositGoods(n,goods,arr);
	output(n,goods,arr);
//	int arr3[n][n];			//记录箱子中所装入的物品,用编号来表示物品 
//	cin>>n;
//	input(n,arr);
//	cout<<arr.size<<endl;
	
	return 0;
}
