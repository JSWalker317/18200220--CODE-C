#include<conio.h>
#include<stdio.h>
#define MAX 100

// tinh giai thua de quy
int GiaiThua (int n){
	if (n==0)	return 1;
	else 		return n*GiaiThua(n-1);
}

void TinhGiaiThua(int n){
	printf("---De Quy tinh n giai thua ");
	printf("\nNhap vao gia tri n (n<=19): ");
	scanf("%d",&n);
	printf("%d!= %d ",n,GiaiThua(n));
}

//
void NhapKichThuoc (int& n)
{
	printf("\nNhap vao kich thuoc mang: ");
	scanf("%d", &n);
}

void NhapMang(int a[], int& n)
{
	for (int i=0; i<n; i++){
		printf ("a[%d]= ", i);
		scanf ("%d", &a[i]);
	}
}

void XuatMang(int a[], int n)
{
	printf ("Mang nhap vao: ");
	for (int i=0; i<n; i++){
		printf("%d \t",a[i]);
	}
}

void HoanVi(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
// sap xep de tim kiem nhi phan
void interchange(int a[], int n)
{
	for (int i = 0; i<n-1; i++)
		for (int j = i+1; j<n; j++)
			if (a[j] < a[i]) 
			HoanVi(a[i], a[j]);
	
	printf ("\nMang da sap xep: ");
	for (int k=0; k<n; k++)
	{
		printf(" %d \t", a[k]);
	}	
}

//De Quy binary search
int TimKiemNP(int a[], int x, int left, int right) {
	
	
    while (left <= right) {	
    	int mid = (left + right) / 2;
    	
    	if (x == a[mid])	return mid;

    	if (x < a[mid])		return TimKiemNP(a, x, left, mid - 1);

    	return TimKiemNP(a, x, mid + 1, right);
    }
    return -1;
  }
  
void BinarySearch (int a[], int n, int x){
	
	NhapKichThuoc(n);
	NhapMang(a,n);
	XuatMang(a,n);
	
	printf("\n---De Quy tim kiem nhi phan");
	printf("\nNhap so can tim: ");
	scanf("%d", &x);
	interchange(a,n);
	int t = TimKiemNP(a,x,0,n-1);
	if (t == -1)  printf("\nKhong tim thay");
	else printf ("\nSo can tim o vi tri thu: %d", t);	
}


//sap xep bang pp quicksort de quy
void QuickSort(int a[], int left, int right) {
	
	int  i, j, x;
	x = a[(left + right)/2];
	i = left; j = right;
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i<=j) { 	
			HoanVi(a[i], a[j]);
			i++; 
			j--;
		}
	} while (i < j);
	if (left < j)	QuickSort(a, left, j);
	if (i < right)	QuickSort(a, i, right);
}

void PrintQuickSort(int a[], int n) {
	
	NhapKichThuoc(n);
	NhapMang(a,n);
	XuatMang(a,n);
	
	QuickSort(a,0,n-1);
	
	printf ("\nMang da sap xep: ");
	for (int k=0; k<n; k++)
	{
		printf(" %d \t", a[k]);
	}
}


int main() {
	
	int n,a[MAX],b,c,x,left,right;
	int in;
	
	while(true) {
		
		printf("\n\nLAB_3: \n1.Tinh giai thua \n2.Tim kiem nhi phan \n3.Sap xep bang phuong phap Quick sort \n0.Exit\n");
		printf("\nLua chon: ");
		scanf("%d", &in);
		
		switch(in) {
			case 0: return 0;
			case 1: TinhGiaiThua(n); break;
			case 2: BinarySearch(a,n,x); break;
			case 3: PrintQuickSort(a,n); break;
		}
	}
	
}
