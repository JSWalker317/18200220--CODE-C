#include <stdio.h>
#include <conio.h>
/*Noi dung co ban cua ma hoa CRC
	Cho chuoi bit thong tin ---CRC--> Chuoi bit duoc ma hoa
	Vd : Chuoi bit thong tin 1 0 1 0 0 0 1 0, da thuc sinh 1 0 0 1 1 
	Sau do ta can them 4 bit 0 0 0 0 vào sau 4 bit thong tin
	Tien hanh chia chuoi bit thong tin cho da thuc sinh, ket qua tra ve chinh la phan du cua phep chia
	XOR ket qua tra ve voi chuoi bit thong tin ta duoc chuoi bit da duoc ma hoa CRC
	---------------------------------------
	Kiem tra nguoc lai :
	Lay chuoi bit thong tin duoc ma hoa, ta dem chia lai cho da thuc sinh o tren
	Neu : Ket qua tra ve bang 0 ----> chuoi bit kiem tra dung
		  Ket qua tra ve khac 0 ----> chuoi bit kiem tra bi loi
*/
void division(int temp[],int gen[],int n,int r) //ham chia nhi phan
{
 for(int i=0;i<n;i++)	
 {
     if (gen[0]==temp[i])	//neu bit dau cua tu ma bang voi 
     {
         for(int j=0,k=i;j<r+1;j++,k++)	
             if(!(temp[k]^gen[j]))	//xor tung bit cua chuoi thong tin voi tu ma
                 temp[k]=0;	//neu thoa thi bang 0
             else
                 temp[k]=1;	//nguoc lai
     } }}
int main()
{
int n,r,message[50],gen[50],temp[50];
 printf("Tai Noi Gui\n\n");
 printf("Nhap So Bit Truyen : ");	
 scanf("%d",&n);	//Nhap so bit can truyen di de giai ma
 printf("Nhap So Bit Cua Tu Ma : ");
 scanf("%d",&r);	//nhap so bit cua tu ma 
 printf("Nhap Chuoi Bit Thong tin : ");
 for(int i=0;i<n;i++){
 	printf("Bit Thu %d : ",i);
     scanf("%d",&message[i]);	//nhap tung bit cua chuoi thong tin
 }
     
 printf("Nhap Tu Ma\n");
 for(int i=0;i<r;i++){
 	printf("Bit Thu %d : ",i);
 	scanf("%d",&gen[i]);	//nhap tung bit cua tu ma
 }    
 r--;
 for(int i=0;i<r;i++)
     message[n+i] = 0;	//them r bit 0 vao sau chuoi bit
 for(int i=0;i<n+r;i++)
     temp[i] = message[i];	//tao mot chuoi bit temp de dua vao bo chia
 division(temp,gen,n,r);	//dua vao bo chia
 printf("Tu Ma CRC : ");
 for(int i=0;i<r;i++)		//xuat ra tu ma crc sau khi qua bo chia
 {
     printf("%d",temp[n+i]);
     message[n+i] = temp[n+i];	//temp s? tra ve chuoi ket qua cua ham chia ve
 }
 printf("\nChuoi Bit Truyen Di Sau Khi Ma Hoa : ");
 for(int i=0;i<n+r;i++)
     printf("%d ",message[i]);	//xuat ra chuoi bit sau khi ma hoa
 printf("\n\nTai Noi Nhan :\n");
 printf("Nhap Chuoi Thong Tin Kiem Tra : \n");
 for(int i=0;i<n+r;i++){
 	printf("Bit Thu %d : ",i);
 	scanf("%d",&message[i]);	//nhap chuoi bit thong tin can kiem tra
 }
     
 for(int i=0;i<n+r;i++)
     temp[i] = message[i];	//luu chuoi bit thong tin vao temp de dua vao ham chia kiem tra	
 division(temp,gen,n,r);	//dua chuoi bit vao kiem tra bang bo chia 
 for(int i=0;i<r;i++)
 {
     if(temp[n+i])	//neu ket qua co gia tri khac 0, chuoi bit kiem tra co xuat hien loi
     {
         printf("Phat Hien Loi Cua Thong Tin Kiem Tra");
         return 0;
     } }
 printf("Khong Co Loi\nMa Nhan La : ");	//nguoc lai bang 0, chuoi bit kiem tra khong có loi
 for(int i=0;i<n;i++)
     printf("%d ",message[i]);	//xuat chuoi bit thong tin
 return 0;
}
