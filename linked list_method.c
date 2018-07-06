typedef struct Node{
    int val;
    struct Node* next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head;
    head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(head == NULL)
    {
        printf("Create head failed!");
        exit(1);
    }
    //head = NULL;
    head->val = NULL;
    head->next = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* cur = obj;    
    int count = 0;    
    while(cur != NULL)
    {
        if(count == index)
        {               
            printf("\n get val:%d\n",cur->val);
            return (cur->val);
        }
        count++;
        cur = cur->next;
    }
    return -1;
    
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
    MyLinkedList* new_node;
    new_node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    //MyLinkedList* head = obj;
    new_node->val = val;    
    new_node->next = obj;
    printf("obj val:%d\n",(obj->val));
    obj = new_node;
    printf("obj val:%d\n",(obj->val));
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* new_node = (MyLinkedList*)malloc(sizeof(MyLinkedList));     
    MyLinkedList* cur = NULL;
    cur = obj;
    new_node->val=val;
    new_node->next = NULL;
    if (obj == NULL){
        obj = new_node;
        return;
    }
    if(cur->next == NULL){        
        cur->next = new_node;
        return;
    }    
    while((cur->next)!=NULL){        
        cur = cur->next;
    }  
    cur->next = new_node;
    //printf("tail val:%d\n",(cur->next)->val);
    return;
    
    
    
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* new_node;    
    new_node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    MyLinkedList* cur = obj;
    new_node->val=val;
    int count = 0;
    while(cur != NULL){
        if(count == (index-1)){
            if(cur->next==NULL){
                cur->next = new_node;
                return;
            }
            new_node->next = cur->next;
            cur->next = new_node;
            //printf("index val:%d\n",(cur->next)->val);
            return;
        }
        count++;
        cur = cur->next;
    }
    
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
    if(obj == NULL){
        //printf("obj NULL");
        return;
    }
    MyLinkedList* cur = obj;
    if(index == 0){
        obj = cur->next;
        //free(cur);
        return;
    }    
    //int count = 0;
    for(int i = 0; cur != NULL && i < (index-1); i++){
        cur = cur->next;
    }
    if(cur == NULL|| cur->next == NULL){
        //printf("undelete");
        return;
    }
    MyLinkedList *next = cur->next->next;
    //printf("delete val:%d\n",(cur->next)->val);
    free(cur->next);
    cur->next = next;
    
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

void printList(MyLinkedList* obj){
    while(obj != NULL){
        printf("%d -> ",obj->val);
        obj = obj->next;
    }
    printf("\n");
}
/*int main(){
    struct MyLinkedList* obj = myLinkedListCreate();    
    //int param_1 = myLinkedListGet(obj, index);
    myLinkedListAddAtHead(obj, 5);
    myLinkedListGet(obj, 0);
    printList(obj);
    //printf("%d\n",myLinkedListGet(obj, 0));
    myLinkedListAddAtTail(obj, 3);
    printList(obj);
    myLinkedListAddAtIndex(obj, 1, 2);
    printList(obj);
    myLinkedListDeleteAtIndex(&obj, 0);
    printList(obj);
    myLinkedListFree(obj);
}*/
/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

