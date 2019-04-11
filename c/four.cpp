#include<iostream>
using namespace std;
void input(int n,int q,int c[],int table[][2]) {
	for(int i=0;i<n-1;i++) {
		cin>>c[i];
	}
//	cout<<"start"<<endl;
	for(int i=0;i<q;i++) {
		for(int j=0;j<2;j++) {
			cin>>table[i][j];
		}
	}	
//	cout<<"end"<<endl;
}
//计算两地之间可运输的最大货物重量 
int maxWeightBetweenTwoDot(int left,int right,int c[]) {
	int min=c[left];
	for(int i=left;i<=right-1;i++) {
		if(c[i]<min) {
			min=c[i];
		}
	}
	return min;
}

//交换数据的位置
void swap(int q,int table[][2]) {
	for(int i=0;i<q;i++) {
		if(table[i][0]>table[i][1]) {		//如果起始点在大于终点 
			int temp=table[i][0];
			table[i][0]=table[i][1];
			table[i][1]=temp;
		}
	}
}

void output(int q,int c[],int table[][2]) {
	
	//核心算法 
	int max=0;
	for(int i=0;i<q;i++) {
		int w = maxWeightBetweenTwoDot(table[i][0],table[i][1],c);
		for(int j=0;j<q;j++) {
			if(table[i][1]<=table[j][0]) {
				int temp = maxWeightBetweenTwoDot(table[j][0],table[j][1],c);
				w+=temp;
			}
		}
		if(max<w) {
			max=w;
		}
	}
	cout<<max<<endl;
}
int main() {
	int n,q;
	cin>>n>>q;
	int c[n-1];
	int table[q][2];
	input(n,q,c,table);
	swap(q,table);
//	int num = maxWeightBetweenTwoDot(2,4,c);
//	cout<<num<<endl;
	output(q,c,table);
	return 0;
}
