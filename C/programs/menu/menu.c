//Simple UI with menu options in C, using struct and link list
#include <stdio.h>
#include <string.h> //For string handling
#include <stdlib.h> //For malloc function

struct node{
    char fname[30];
    char lname[30];
    int age;
    char gender[20];
    char disease[20];
    int date;
    struct node *next;
};
struct node *head;
void add(char fname[30], char lname[30], int age, char gender[20], char disease[20], int date){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->fname, fname);
    strcpy(temp->lname, lname);
    temp->age = age;
    strcpy(temp->gender, gender);
    strcpy(temp->disease, disease);
    temp->date = date;
    if(head == NULL){
    head = temp;
    temp->next = NULL;
    }
    else{
    temp->next = head;
    head = temp;
    }
}
void display(){
    struct node *r;
    r = head;
    if(r == NULL){
        return;
    }

    printf("----------------------------------------------------------------------------------------------------------\n");
    while(r!=NULL){
    printf("Full case profile: %s | %s | %d | %s | %s | %d\n",r->fname, r->lname, r->age, r->gender, r->disease, r->date);
    r = r->next;
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
}
int count(){
    struct node *n;
    int cnt = 0;
    n = head;
    while(n != NULL){
        n = n->next;
        cnt++;
    }
    return cnt;
}
int main(){

int selection;
char fname[30], lname[30];
int age;
char gender[20];
char disease[20];
int date;

while(1){
    printf("Menu\n");
    printf("1.Add case\n");
    printf("2.Show number of cases\n");
    printf("3.Display full case profile\n");
    printf("4.Exit\n");
    printf("\nPlease, choose: ");
    scanf("%d",&selection);
    if(selection == 1){
        printf("Enter first name of case: ");
        scanf("%s",&fname);        
        printf("Enter last name of case: ");
        scanf("%s",&lname);
        printf("Enter age of case: ");
        scanf("%d",&age);
        printf("Enter gender of case: ");
        scanf("%s", &gender);        
        printf("Enter disease of case: ");
        scanf("%s",&disease);        
        printf("Enter record date: ");
        scanf("%d",&date);
        add(fname, lname, age, gender, disease, date);
    }
    else if(selection == 2){
        printf("%d\n",count());
    }
    else if(selection == 3){
        display();
    }
    else if(selection == 4){
        printf("You have exited successfully");
        return 0;
    }

}
return 0;
}
