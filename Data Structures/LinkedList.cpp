********************Singly LinkedList Implementation**************************
class Node
{
    public:
    int key;
    Node* next;
};
void add(Node** head, int key)//O(1)
{
    Node* new_ = new Node;
    new_->key = key;
    new_->next = *head;
    *head = new_;
}
void append(Node** head, int key)//O(n)
{
    Node* nw_ = new Node();
    nw_->key = key;
    nw_->next = nullptr;
    Node* tmp = *head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = nw_;
}
void trv(Node* head)//O(n)
{
    Node* tmp = head;
    while(tmp != nullptr)
    {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
void solvethetestcase()
{
    Node* head = nullptr;
    FOR(i, 1, 11) add(&head, i);
    trv(head);
    append(&head, 12);
    trv(head);
    trv(head);
}


*******************Doubly LinkedList Implementation*********************
class Node
{
    public :
    int key;
    Node *next, *prev;
};
Node *tail = nullptr;
void add(Node **head, int key)
{
    Node *new_node = new Node();
    new_node->key = key;
    new_node->next = *head;
    new_node->prev = nullptr;
    if(*head == nullptr) tail = new_node;
    else (*head)->prev = new_node;
    *head = new_node;
}
void trvl2r(Node* node)
{
    Node *tmp = node;
    while(tmp != nullptr)
    {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
void trvr2l()
{
    Node *tmp = tail;
    while(tmp != nullptr)
    {
        cout << tmp->key << " ";
        tmp = tmp->prev;
    }
    cout << "\n";
}
void delByVal(Node *head, Node **head_ref, int key)
{
    Node *tmp = head;
    if(tmp->key == key)//if key at head
    {
        *head_ref = tmp->next;
        delete tmp;//deletes pointer created with new(operator)
        return;
    }
    while(tmp->key != key)
    {
        tmp = tmp->next;
        if(tmp == nullptr) return;
    }
    if(tmp->next == nullptr) tmp->prev->next = nullptr;//if key at tail
    else
    {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;//deletes pointer created with new(operator)
    }
}
void solvethetestcase()
{
    Node* head = nullptr;
    FOR(i, 1, 11) add(&head, i);
    trvl2r(head);
    delByVal(head, &head, 10);
    trvl2r(head);

}
