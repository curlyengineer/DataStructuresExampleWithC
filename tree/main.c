#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *createNode(int item){
	struct tree *yeni=(struct tree*)malloc (sizeof(struct tree));
	yeni->data=item;
	yeni->left=yeni->right=NULL;
	return yeni;
}
void inOrder(struct tree *root){
	if(root==NULL)
	return;
	inOrder(root->left);
	printf("%d\t",root->data);
	inOrder(root->right);
}
void postOrder(struct tree *root){
	if(root==NULL) return ;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d \t", root->data);
}
void preOrder(struct tree *root){
	if(root==NULL) return ;
	printf("%d \t", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
struct tree *insert(struct tree *root, int item){
	if(root==NULL)return createNode(item);
	if(item<root->data)
	root->left=insert(root->left,item);
	else if(item>root->data)
	root->right=insert(root->right,item);
	return root ;
}
// for  Binary Search Tree
int theBiggestBinary(struct tree *root){
	if(root==NULL) return 0;
	while(root->right!=NULL){
		root=root->right;
	}
	int sonuc=root->data;
	return sonuc;
} 
// for other tree
int theBiggest(struct tree *root){
	if(root==NULL)return 0;
	int max=root->data;
	int lVal=theBiggest(root->left);
	int rVal=theBiggest(root->right);
	if(lVal>rVal)
	max=lVal;
	if(rVal>lVal)
	max=rVal;
	return max;
}
int main(int argc, char *argv[]) {
	struct tree *root=NULL;
	root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->right->right=createNode(4);
	root->left->right->left=createNode(5);
	root->left->right->right=createNode(6);
	insert(root,6);
	inOrder(root);
	printf("\n");
//	preOrder(root);
	printf("\n");
//	postOrder(root);
	printf("\n");
	printf("En buyuk Yaprak %d",theBiggestBinary(root));
	return 0;
}
