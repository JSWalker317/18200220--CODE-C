#include<stdio.h>
#include<conio.h>

/*
18200220 Phan Van Son
*/
void NhapMang(float a[], int n) {
	printf("\nNhap phan tu: \n");
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}

void XuatMang(float a[], int n) {
	for(int i = 0; i < n; ++i){
		printf("\na[%d] = %f", i, a[i]);
	}
	printf("\n");
}

int linearSearch(float a[], int n, float x) {
	int i = 0;
	a[n] = x;
	while(a[i] != x) {
		i++;
	}
	if(i == n) {
		return -1;
	} else {
		return i;
	}
}

int binarySearch(float a[], int n, float x){
	int left = 0; 
	int right = n - 1;
	int mid; 
	do {
		mid = (left + right)/2;
		if(a[mid] == x) return mid;
		else {
			if(x < a[mid]) right = mid - 1;
			else {
				left = mid + 1;
			}
		}
	} while(left <= right);
	return -1;
}

void swap(float &a, float &b) {
	float _swap = a;
	a = b;
	b = _swap;
}

void interchangeSort(float a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[j] < a[i]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void bubbleSort(float a[], int n) {
	int i, j;
    for (i = 0; i < n-1; i++){
        for (j = n-1; j>i; j--){
            if (a[j] < a[j-1]){
                swap(a[j], a[j-1]); 
            }
        }
     }   
}

void selectionSort(float a[], int n) {
	int  i, j,  min; 
	for (i = 0; i < n-1; i++){
		min = i;
		for (j = i+1; j < n; j++)
			if (a[j] < a[min]) 	
				min = j; 
    		swap(a[i], a[min]);
    }
}

void insertionSort(float a[], int n) {
	int i, j;
	float key;
   	for (i = 1; i < n; i++) {
       	key = a[i];
       	j = i-1;
 		while (j >= 0 && a[j] > key) {  //neu j chua ve dau day
           a[j+1] = a[j];  //don day
           j = j-1;
        }
       	a[j+1] = key; // chen vao
   }
}

void quickSort(float a[], int left, int right) {
	int  i, j;
	float x;
	int n = right + 1; //giu lai gia tri right cho lan chay khac
	x = a[(left + right)/2];
	i = left; j = right;
	do{
		while (a[i] < x) i++; // tang i toi khi gap so > x
		while (a[j] > x) j--;  // giam j toi khi gap so < x
		if(i <= j) { 	        
			swap(a[i], a[j]);  // doi
			i++; 
			j--;
		}
	}while (i<j);
	if (left < j) quickSort(a, left, j);
	if (i < right) quickSort(a, i, right);
}
void dispResult(int i, float x) {
	if(i == -1) {
		printf("Gia tri %d khong co trong mang!", x);
	} else {
		printf("Tim thay gia tri %f o vi tri thu %d trong mang!", x, i+1);
	}
}
void ganmang(float x[], float y[]){
	
	for(int i = 0; i<=sizeof(x); i++){
		y[i] = x[i];
	}
}
int main() {

	float arr[100],x, b[100];
	int n, left,right;
	int choice;
	do{
		printf("\n\n    ==================> LAB_2 <==================");
		printf("\n\t 1.Nhap mang \n\t 2.Xuat mang \n\t 3.LinearSearch \n\t 4.BinarySearch \n\t 5.InterchangeSort \n\t 6.BubbleSort \n\t 7.SelectionSort \n\t 8.InserttionSort \n\t 9.QuickSort \n\t 10.Lam moi mang \n\t 0.Thoat");
		printf("\nNhap so de chon : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap so luong phan tu nho hon 100:  ");
				do	{
					scanf("%d", &n);
					if(n <= 0 || n > 100) {
					printf("Vui long nhap lai so luong phan tu: ");
					}
				}while(n <= 0 || n > 100);	
				printf("\n----NHAP-MANG----\n");
				NhapMang(arr, n);
				ganmang(arr,b);
				break;
			case 2:
				printf("\n----XUAT-MANG----\n");
				printf("\nMang vua nhap:");
				XuatMang(b, n);
				break;
			case 3:
				float x;
					printf("Nhap so can tim: ");
					scanf("%f", &x);
					dispResult(linearSearch(arr, n, x), x);
				break;
			case 4:
					printf("Nhap so can tim: ");
					scanf("%f", &x);
				dispResult(binarySearch(arr, n, x), x);
				break;
			case 5:
				interchangeSort(b, n);
				printf("Done!!");
				break;
			case 6:
				bubbleSort(b, n);
				printf("Done!!");
				break;
			case 7:
				selectionSort(b, n);
				printf("Done!!");
				break;
			case 8:
				insertionSort(b, n);
				printf("Done!!");
				break;
			case 9:
				left = 0;
				right = n-1;
				quickSort(b, left, right);
				printf("Done!!");
				break;
			case 10:
				ganmang(arr,b);
				printf("Da lam moi lai mang");
				break;
			default:
				printf("Gia tri khong hop le, vui long nhap lai!");
				break;	
						}
	}while(choice!=0);

	printf("THANK YOU!");
	
} 

