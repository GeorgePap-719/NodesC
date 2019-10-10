#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//initialize global the file
FILE *fp;
//initialize node
typedef struct Node{
	int id;
	struct Node *next;
}Node;

void Delete(Node *head);
void Search(Node *head);
void InsertBottom(Node *head);
void Display(Node *head);
Node* CreateNode(void);
Node* ReadFromFile(FILE *fp);
void SaveToFile(FILE *fp,Node *head);
Node* CreateFirstNode(int first_node);
void queue (Node *head);
void stack (Node *head);


int main(int argc, int *argv[]){
	fp=fopen("test.txt","r");
	srand(time(NULL));
	Node *head, *current;
	current=head;
	current = (Node*)malloc(sizeof( Node));
	//head = CreateNode();
	current = ReadFromFile(fp);fclose(fp);//the fp-fopen and fclose (for the read)
	//must be outside the function
	head = current;
		
	
	InsertBottom(head);
	Display(head);
	Delete(head);
	Display(head);
	Search(head);
	queue(head);
	Display(head);
	stack(head);
	Display(head);

	fp = fopen("test.txt","w");
	SaveToFile(fp,head);
	fclose(fp);
}

void InsertBottom(Node *head){
		Node *current;
		Node *newNode=( Node*)malloc(sizeof(Node));//create new node
		current = head;	
		
	if(current==NULL){printf("node is empty");exit(1);}
	if(newNode == NULL){
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1);
    }
	 newNode->next = NULL;  // Change 1	
	 newNode->id = rand() % 100-0;
	
        // loop through the list and find the last
        //node, insert next to it
        
		while(current->next!=NULL){
			current = current->next;
		}
          current->next = newNode;
}
    

void Display(Node *head){
	//normal display function
	struct Node *current;
	current=head;
	//check if node is empty
	while(current!=NULL){
	printf("ID:%d\n",current->id);
    current=current->next;
		printf("\n");
	}
	free(current);//free the useless node
}
void Delete(Node *head){
	Node *previous;
	Node *current;
	current=head;
	int ID;
	//deletes random nuber in the linked list
	//check if node is empty
	if(head!= NULL){
	ID=rand() %100-0;
	printf("Id i want to delete is:%d \n",ID);	
	while(current->id!=ID){
		if(current->next == NULL){
			
			printf("\nNo match has been found\n");break;	
			
	}
		previous =current; 
		current=current->next;
}	//we are at the first node so we need a bit diffrent code from normal deletion node
	if(current==head){
	Node *temp;		// save old head for freeing.
	temp=head->next;
	*head=*temp;
	free(temp);
	} else if(current->id==ID) {
		previous->next= current->next;	
		free(current);//free the useless node
	}

} else printf("the node is empty!!");


}
void Search(Node *head){
	Node *current;
	current=head;
	int ID;
 
	if(head!= NULL){
		//search random numbers in the node
	ID=rand() %100-0;
	printf("Item i want to search  is:%d",ID);	
	while(current->id!=ID){
		if(current->next == NULL){
			printf("\nNo match has been found\n");break;	
	}
		current=current->next;
}	
	 if(current->id==ID) {
		printf("\nthe item has been found ");
		
	}

} else printf("the node is empty!!");
	
	//free(current);//free the useless node
	}

Node* CreateNode(void){
	//creates the first node 
	Node *start;
	start = (Node*)malloc(sizeof( Node));
	//check if malloc is succesfull
	if(start==NULL){
	fprintf(stderr,"LINE: %d, malloc() failed\n",__LINE__);	
		return NULL;
	}
	else{
		
	start->id = rand() % 100-0;
	start->next=NULL;
	
    return start;	
	}
	
}
Node* ReadFromFile(FILE *fp){	
	
	Node *i = malloc(sizeof(Node));
	int fid;
	int fileRead;
	fileRead = fscanf(fp,"%d",&fid);
	
	if(fileRead == 0){
		return NULL;
	}
	 // Check to make sure we allocated space.
	if(fileRead > 0 ){
	i->id=fid;
	i->next = ReadFromFile(fp);
	}else {
	//  your object is invalid so release and
    // set i to NULL so it becomes the last one.
	free(i);
	i=NULL;
	}
	
	return i;	
}
void SaveToFile(FILE *fp,Node *head){
	
	//check if the list is emprty
	if(head == NULL)fprintf(stderr,"LINE: %d, list is empty\n",__LINE__);	
					  
	while(head != NULL){
	fprintf(fp,"%d\n",head->id);
	head=head->next;	
	}
	    				
				   
	//free(current);//free the memory

	
}
void queue (Node *head){
	//fifo
	printf("queue list active\n");
	Node *temp;
	if(head==NULL){
		printf("this list is emprty");
		exit(1);
	}
	temp=head->next;
	*head=*temp;
	free(temp);
	
}
void stack (Node *head){
	//stack lifo
	Node *current,*prev;
	current=head;
	printf("stack list is active");
	if(head!=NULL){
		while(current->next!=NULL){
			printf("im here1");
			prev=current;
			printf("im here2");
			current=current->next;
			printf("im here3");
		}
		prev->next=NULL;
	}else printf("list is empty");
}






























	
