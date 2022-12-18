#include<stdio.h>
#include <stdlib.h>
int HoanVi(int &a,int &b)
{
	int temp;
		temp = a;
		a = b;
		b = temp;
}
//Cau truc cua 1 dslk
struct Info{
	int n;
};
struct node{
	Info data;	//truong info bang x //Chu y thay data thanh x 
	node *next; // dia chi tiep theo
};
struct LIST{
	node *head;
	node *tail;
};
//Khoi tao danh sach NULL
void InitListNULL(LIST &L){
	L.head = NULL;
	L.tail = NULL;
}
//Khoi tao node moi
node* CreateNode(Info data) {
	node *p = new node;
	if ( p==NULL) return NULL;  //neu nhu bo nho k cap phat duoc nua
	p->data = data; 
	p->next = NULL;
	return p; 
}
//tao node co truong info bang x
node* CreateNode(int x){
	Info data = {x};
	node* p = CreateNode(data);
}
//kiem tra list rong
bool IsEmpty(LIST &L){
	if (L.head==NULL){
		return true;
	}
	return false;
}
//Them 1 phan tu vào dau list
void AddHead(LIST &l, node* p)
{
		if (IsEmpty(l))  //neu list rong
		{ 
			l.head = l.tail = p; 
		}
		else	//nguoc lai
		{ 
			p->next = l.head; //gán next theo vi tri dau
  			l.head = p; 	//gan phan tu vào dau
		}
}
//Them vao dau list
void Addhead(LIST &l, int x){
	node* p = CreateNode(x);
	AddHead(l,p);
}
void AddTail(LIST &l,node* p){
	
	if (IsEmpty(l))  //neu list rong
		{ 
			l.head = l.tail = p; //vi tri dau va cuoi deu la node p
		}
		else	//nguoc lai
		{ 
			l.tail->next = p;
			l.tail = p ;	//
		}
}
//Them vao cuoi list
void Addtail(LIST &l,int n){
	node *p = CreateNode(n);
	AddTail(l,p);
}
void AddQ(LIST &l, node *p, node *q)
{	
	for(node *k = l.head; k != NULL; k = k ->next)
	{
		if(k->data.n == q->data.n) // Tim thay Node
		{
			node *g = k ->next;
			k ->next = p;
			p ->next = g;
			return; 
		}
	}	
}

//Them data sao sau vi tri q
void Addq(LIST &l,int dataAdd, int Q){
	node *p = CreateNode(dataAdd);
	node *q = CreateNode(Q);
	AddQ(l,p,q);
}
//Tìm 1 phan tu co info bang x
node *Search(LIST l, int x) 
{	
	node *p;
	p = l.head;
	while((p!=NULL)&&(p->data.n!=x)) 
		p = p->next;
	return p;
}
//Huy phan tu trong danh sach
int RemoveHead(LIST &l){	
	node *p;
	if(l.head!=NULL)
	{	
		p=l.head; 
		l.head=l.head->next;
		delete p;
		if(l.head==NULL)
			l.tail=NULL;
		return 1;
	}
	return 0;
}
void RemoveTail(LIST &l)
{
	node *p;
	for(node *k = l.head; k != NULL; k = k ->next)
	{
		if(k == l.tail)
		{
			l.tail = p;
			l.tail -> next = NULL;
			delete k;
			return;
		}
		p = k;
	}
}
void RemoveQ(LIST &l, node *q)
{
	node *g; // Node nam sau q
	for(node *k = l.head; k != NULL; k = k ->next)
	{
		// tim q
		if(k ->data.n == q ->data.n) // q bay gio chinh la k
		{
			g = k ->next;
			k ->next = g ->next;
			delete g;
			return;
		}
	}
}
//Xoa data bat ki trong danh sach
void Delete(LIST &l, int data)
{
	if(l.head->data.n == data)
	{
		RemoveHead(l);
		return;
	}
	if(l.tail->data.n == data)
	{
		RemoveTail(l);
		return;
	}
	node *q;
	// Neu Node can xoa khong phai dau hoac cuoi 
	for(node *g = l.head; g != NULL; g = g -> next) //tao g là phan tu dau, chay den cuoi list, tang theo *next
	{
		if(g->data.n == data)
		{
			RemoveQ(l, q);
			return;
		}
		q = g;
	}	
}
//xuat danh sach || duyet danh sach
void Print_List(LIST &l){
	printf("\nPhan tu trong mang la : ");
	if(IsEmpty(l)) {
		printf("List is empty");
	}
	else{
		node* temp = l.head; //gan node bang head là phan tu dau tien
		while(temp != NULL){	//chay cho toi khi den phan tu cuoi cung cua mang temp = null
			printf("%d\t",temp->data.n);
			temp = temp->next;
		}
	}
}
//Sap xep danh sach
void Sort(LIST &l){
	for(node *p = l.head; p != l.tail; p = p ->next)
	{
	    for(node *q = p ->next; q != NULL; q = q ->next)
		{
			if(p->data.n > q->data.n)
			{
				HoanVi(p->data.n, q->data.n);
			}
		 }
	}
	printf("\nMang sau khi sap xep la : ");
	Print_List(l);
}		
int main(){
	LIST L;
	InitListNULL(L);
	int x, n;
	int dataAdd, key, findX, dataDelete;
	printf("Nhap so phan tu trong mang ");
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		printf("Nhap phan tu thu %d:  ",i);
		scanf("%d",&x);
		Addtail(L,x);
	}
	//Tìm 1 phan tu co info bang x 
	printf("\nNhap phan tu co info bang x de tim : ");
	scanf("\n%d",&findX);
	node *c = Search(L,findX);
	printf("\ngia tri cua info la : %d",c->data);
	printf("\nVi tri cua info la : %d",c);
	//Thêm mot phan tu có khóa x vào danh sách
	printf("\nNhap vi tri can them vao : ");
	scanf("%d",&key);
	printf("\nGia tri cua phan tu de them vao vi tri %d la : ",key);
	scanf("%d",&dataAdd);
	if(key==0){
		Addhead(L,dataAdd);
	}
	else if(key==n-1){
		Addtail(L,dataAdd);
	}
	else{
		Addq(L,dataAdd,key);
	}
	Print_List(L);
	//Huy phan tu trong danh sach
	printf("\nNhap gia tri phan tu muon xoa : ");
	scanf("%d",&dataDelete);
	Delete(L,dataDelete);
	//duyet danh sach
	Print_List(L);
	//Sap xep danh sach
	Sort(L);
}

