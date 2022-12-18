#include<stdio.h>
#include <stdlib.h>
//tao nut co truong key bang x
struct node{
	int x; //truong key
	node *left, *right; //2 nhanh cua cay
};
//typedef node* Tree;
//tao nut moi
node* newNode(int x)
{
    node* temp = new node;
    temp->x = x;
    temp->left = temp->right = NULL;
    return temp;
}
//them 1 node vao cay nhi phan tim kiem
void insert(node* &tree, int key)
{
    if(tree==NULL){		//neu cay rong
    	tree = newNode(key);	//node moi chinh la node goc
	}					//neu co phan tu trong cay
	else{
		if(tree->x > key){		//neu phan tu them vao nho hon node goc => them vao ben trai cua cay
			insert(tree->left,key);
		}
		else if(tree->x < key){	//neu phan tu them vao ma lon hon node goc => them vao ben phai cua cay
			insert(tree->right,key);
		}
	}
}
//duyet cay nhi phan
void Print_treeNLR(node* tree){
	//duyet het cay NLR
	if(tree != NULL){
		printf("%d\t",tree->x);
		Print_treeNLR(tree->left);
		Print_treeNLR(tree->right);
	}
}
//ham dung phan tu the mang
node* minValueNode(node* &tree)
{
    node* current = new node;
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
//xoa node co truong key bang x
node* deleteNode(node* &tree, int key)
{
	if (tree == NULL)
        return tree;
    if (key < tree->x)
        tree->left = deleteNode(tree->left, key);
	else if (key > tree->x)
        tree->right = deleteNode(tree->right, key);
	else {
		if (tree->left == NULL) {
            node* temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL) {
            node* temp = tree->left;
            free(tree);
            return temp;
        }
	node* temp = minValueNode(tree->right);
    tree->x = temp->x;
	tree->right = deleteNode(tree->right, temp->x);
    }
    return tree;
}
//Tim 1 phan tu co key bang x
node* SearchNode(node* &tree, int key)
{
    if (tree == NULL)
        return NULL;
	node* p = tree;
	while (p != NULL)
	{
		if (p->x == key)
		{
		return p;
		}
		else if (p->x > key)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
}
int main(){
	//Khoi tao cay
	node* tree = NULL;
	int key, n, deleteX, findX;
	printf("Nhap so phan tu cua cay :");
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		printf("Phan tu thu %d ",i+1);
		scanf("%d",&key);
		insert(tree,key);
	}
	Print_treeNLR(tree);
	//xoa phan tu co key bang x
	printf("\nNhap x can xoa trong cay :");
	scanf("%d",&deleteX);
	tree = deleteNode(tree,deleteX);
	Print_treeNLR(tree);
	//tìm 1 phan tu co key bang x
	printf("\nNhap phan tu muon tim trong cay : ");
	scanf("%d",&findX);
	node *p = SearchNode(tree,findX);
	if (p==NULL){
		printf("Phan tu %d khong ton tai trong cay ",findX);
	}
	else{
		printf("Phan tu %d co ton tai trong cay,Vi tri : %x ",findX,p);
	}
}


