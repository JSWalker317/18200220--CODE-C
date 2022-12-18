//-----------------------------------------//
//-----------------------------------------//
//NOI DUNG HAMMING CODES:
 //data : D1 D2 D3 D4
 //Parity: P1 P2 P3 -->(the same: V1 V2 V4) 
	 // P1 = (D1 xor D2 xor D4)
	 // P2 = (D1 xor D3 xor D4)
	 // P3 = (D2 xor D3 xor D4)
 //Data_Encode : P1 P2 D1 P3 D2 D3 D4 
 //-->(the same: V1 V2 V3 V4 V5 V6 V7)
 //Data_Decode : 
 // C1 = (P1 xor D1 xor D2 xor D4)
 // C2 = (P2 xor D1 xor D3 xor D4)
 // C3 = (P3 xor D2 xor D3 xor D4)
 // C = C1 C2 C3 convert to Decimal = 1*C1 + 2*C2 +4*C3
 // Position Error is C, if C = 0 no Error.
 //------------------------------------------//
#include<stdio.h>
int main() {
    int data[10]; 
    int dataatrec[10],c,c1,c2,c3,i;
 
    printf("Enter 4 bits of data one by one\n");  //Nhap 4 bit theo tung bit mot
    scanf("%d",&data[3]);    	//nhap bit D1
    scanf("%d",&data[5]);		//nhap bit D2
    scanf("%d",&data[6]);		//nhap bit D3
    scanf("%d",&data[7]);		//nhap bit D4 tuong duong V7 trong ma hoa nen gan data[7]
 
    //Calculation of even parity
    data[1]=data[3]^data[5]^data[7];     //khi ma hoa P1 (V1) = D1 xor D2 xor D4 (the same V3 xor V5 xor V7: check 1 bit skip 1 bit)
	data[2]=data[3]^data[6]^data[7];	//khi ma hoa P2 (V2) = D1 xor D3 xor D4  (the same V3 xor V6 xor V7: check 2 bit skip 2 bit)
	data[4]=data[5]^data[6]^data[7];	//khi ma hoa P3 (V4)= D2 xor D3 xor D4   (the same V5 xor V6 xor V7: check 3 bit skip 3 bit)
 
	printf("\nEncoded data is\n");
	for(i=1;i<=7;i++)       //cho i chay tu 0 den 6 tuong duong voi 7 bit ma hoa da sap xep o tren
        printf("%d",data[i]);  // xuat 7bit da ma hoa
 
    printf("\n\nEnter received data bits one by one\n"); //nhap du lieu 7 bit nhan
    for(i=1 ;i<=7 ;i++)   
        scanf("%d",&dataatrec[i]);  //nhap tung bit nhan
 // tinh toan giai ma

    c1=dataatrec[1]^dataatrec[3]^dataatrec[5]^dataatrec[7]; //tinh C1 = V1 xor V3 xor V5 xor V7
	c2=dataatrec[2]^dataatrec[3]^dataatrec[6]^dataatrec[7]; //tinh C2 = V2 xor V3 xor V6 xor V7
	c3=dataatrec[4]^dataatrec[5]^dataatrec[6]^dataatrec[7]; //tinh C3 = V4 xor V5 xor V6 xor V7
	c=c3*4+c2*2+c1 ; 	// C = C1 C2 C3 chuyen sang he thap phan = 1*C1 + 2*C2 +4*C3
 
    if(c==0) {
		printf("\nNo error while transmission of data\n");
    }  	// Neu C = 0 khong co loi.
	else {
		printf("\nError on position %d",c);  // Vi tri bit loi la: C
		printf("\nData sent : ");
        for(i=1;i<=7;i++)
        	printf("%d",data[i]);	//xuat du lieu bit gui
        	
		printf("\nData received : ");   	
        for(i=1;i<=7;i++)
        	printf("%d",dataatrec[i]);	// xuat du lieu bit nhan
    
		printf("\nCorrect message is\n\t\t");
 
//if errorneous bit is 0 we complement it else vice versa
		if(dataatrec[c]==0)	//Neu bit sai la 0
			dataatrec[c]=1;  //Doi lai thanh 1
	    else
			dataatrec[c]=0;  // nguoc lai doi bit 1 thanh bit 0
		for (i=1;i<=7;i++) {
			printf("%d",dataatrec[i]);  //xuat du lieu bit da sua sai
		}
	}
}
