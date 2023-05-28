Node *rev(Node *Start){
Node *prev = NULL;
Node *current = NULL;
Node *move = Start;
while(move!=NULL){
current = move->next;
move->next = prev;
prev = move;
move = current;
}
Start = prev;
return Start;
}
void pallindrome(){
for(Node *move = L ; move!=NULL ; move=move->next){
insert3(move->data);
}
Node *rev = rev(head);
print(L);
print(rev);
bool palindrome = true;
Node *move2 = rev;
for(Node *move =L ;move!=NULL ;move=move->next ){
if(move->data!=move2->data){
palindrome=false;

}
move2=move2->next;

}
if(palindrome){
cout<<"The link list is Pallindrome"<<endl;
}
else{
cout<<"The link list is Not Pallindrome"<<endl;
}

}