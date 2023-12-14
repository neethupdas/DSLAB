#include<stdio.h>
#include<stdlib.h>
struct bstnode
{
	
	struct bstnode *lchild;
	int key;
	struct bstnode *rchild;
};
struct bstnode *root=NULL;

void insert(int item)
{
	struct bstnode *newnode,*ptr,*ptr1;
	ptr=root;
	ptr1=NULL;
	int flag=0;
	newnode=(struct bstnode *)malloc(sizeof(struct bstnode));
	newnode->lchild=NULL;
	newnode->key=item;
	newnode->rchild=NULL;
	
	while((ptr!=NULL)&&(flag==0))
	{
		if(item<ptr->key)
		{
			ptr1=ptr;
			ptr=ptr->lchild;
		}
		else
		{
			if(item>ptr->key)
			{
				ptr1=ptr;
				ptr=ptr->rchild;
			}
			else
			{
				if(item==ptr->key)
				{
					flag=1;
					printf("failed.\n");
				}
			}
		}
		
	}
	
	if(root==NULL)
	          root=newnode;
	else
	{
	          if(flag!=1)
	          {
	                    if(item<ptr1->key)
	                              ptr1->lchild=newnode;
	                    else
	                              ptr1->rchild=newnode;
	          }
	}
	
	
}

void inorder(struct bstnode *ptr)
{
          if(ptr!=NULL)
          {
                    inorder(ptr->lchild);
                    printf("%d\n",ptr->key);
                    inorder(ptr->rchild);
          }
          
}
void preorder(struct bstnode *ptr)
{
          if(ptr!=NULL)
          {
		    printf("%d\n",ptr->key);
                    preorder(ptr->lchild);
                    preorder(ptr->rchild);
          }
          
}
void postorder(struct bstnode *ptr)
{
          if(ptr!=NULL)
          {
		    
                    postorder(ptr->lchild);
                    postorder(ptr->rchild);
		    printf("%d\n",ptr->key);
          }
          
}

void search(int item)
{
        struct bstnode*ptr=root;
          int flag=0;
        
        while((ptr!=NULL)&&(flag==0))
        {
		if(item<ptr->key)
		
	
			ptr=ptr->lchild;
		else
		{
			if(item>ptr->key)
			
				ptr=ptr->rchild;
			else
			{
				if(item==ptr->key)
				{
					flag=1;
					
				}
			}
		}
          }
          if(flag==1)
                    printf("key found.\n");
          else
                    printf("key not found.\n");
                    
}
struct bstnode*minimum(struct bstnode*ptr)
{
	while(ptr->lchild!=NULL)
		ptr=ptr->lchild;
	return(ptr);
}
struct bstnode*successor(struct bstnode*ptr)
{
	if(ptr->rchild!=NULL)
		return (minimum(ptr->rchild));
	return(ptr);
}
void delete(int item)
{
          struct bstnode*ptr=root,*ptr1;
	int flag=0;
          
          while((ptr!=NULL && flag==0))
	{
		if(item<ptr->key)
		{
			ptr1=ptr;
			ptr=ptr->lchild;
		}
		else
		{
			if(item>ptr->key)
			{
				ptr1=ptr;
				ptr=ptr->rchild;
			}
			else
			{
				if(item==ptr->key)
				flag=1;
				
				
			}
		}
		
	}
	//case 1:No child nodes
	if((ptr->lchild==NULL)&&(ptr->rchild==NULL))
	{
	          if(ptr==ptr1->lchild)
	                   ptr1->lchild=NULL;
	          else
	                   ptr1->lchild=NULL;
	                   free(ptr);
	}
	else
	{
	//case2:if both child nodes exists
		if((ptr->lchild!=NULL) && (ptr->rchild!=NULL))
		{
			int temp;
			struct bstnode*succr;
			succr=successor(ptr);
			temp=succr->key;
			delete(temp);
			ptr->key=temp;
		}
		else
		{	
			int temp;
			if(ptr->rchild!=NULL)
			{
				temp=ptr->rchild->key;
				delete(temp);
				ptr->key=temp;
			}
			else
			{
				temp=ptr->lchild->key;
				delete(temp);
				ptr->key=temp;			
			}
		}

	}


}

int main()
{
	  int ch;
	  printf("***********MENU*************");
	  printf("1.insert \n2.delete\n3.search\n4.inorder\n5.preorder\n5.postorder\n");
	  printf("enter choice:");
	  scanf("%d",&ch);
	  while(1)
	  {
	  	switch(ch)
		{
			case
	  insert(5);
          insert(4);
          insert(7);
          insert(6);
          insert(8);
          search(5);
          search(10);
	  inorder(root);
	  struct bstnode*succr=successor(root);
	  printf("successor of root is %d\t \n",succr->key);
          delete(5);
	  preorder(root);
	 
}

