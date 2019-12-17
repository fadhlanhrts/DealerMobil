#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN 30


struct mobil{
    char buat[LEN+1];
    char model[LEN+1];
    char warna[LEN+1];
    int tahun;
    int kota_mpg;
    int kilometer_mpg;
    int kuantitas;
    struct mobil *next;
};

struct mobil *append_to_list(struct mobil *list);

void cari_mobil(struct mobil *list);

void printList(struct mobil *list);

void clearList(struct mobil *list);

struct mobil *delete_from_list(struct mobil *list);

int read_line(char str[], int n);

void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void arrowHere(int posisiAsli,int posisiArrow){
	if(posisiAsli == posisiArrow){
		printf("--> -");
	} else{
		printf("     ");
	}
}

void printd(char* x, int y)
{
	int i;
	for(i=0;i<strlen(x);i++)
	{
		printf("%c",x[i]);
		Sleep(y);
	}
}

int main()
{
	int i;
	int position = 1;
	int keyPressed = 0;
	fullscreen ();
    system ("Color 06");
	system ("cls");
	printf("\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
		Sleep(25);
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t|\t\tDatabase Penjualan Mobil\t|\n\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
		Sleep(25);
	}

	while (keyPressed != 13){
	system ("cls");
    printf("\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t|\t\tDatabase Penjualan Mobil\t|\n\t\t\t\t\t\t\t\t\t\t");

	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\n");
	printf("Select\n");
	arrowHere(1,position); printf("1. Main Menu\n");
	arrowHere(2,position); printf("2. Exit\n");

	keyPressed = getch();
	if(keyPressed == 80 && position != 2){
		position++;
	} else if (keyPressed == 72 && position != 1){
		position--;
	}else{
		position = position;
	}
}
	switch(position){
		case 1:
			position == '1';
			main_menu();
			break;
		case 2:
			position == '2';
			Exit();
			break;
	}
}


	

int main_menu(void)
{
    char code;
    int i;
    struct mobil *list_mobil = NULL;
    system("cls");
      printf("\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t|\t\tDatabase Penjualan Mobil\t|\n\t\t\t\t\t\t\t\t\t\t");

	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\n");
	printf("Select\n");
    printf("a. Tambah Ke List\n");
    printf("b. Mencari Mobil\n");
    printf("c. Menampilkan List Mobil\n");
    printf("d. Clear List\n");
    for (;;)
    {
        printf("\nMasukkan kode operasi: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   
            ;
        switch (code)
        {
            case 'a' : list_mobil = append_to_list(list_mobil);
                break;
            case 'b': cari_mobil(list_mobil);
                break;
            case 'c': printList(list_mobil);
                break;
            case 'd': clearList(list_mobil);
            case 'e': list_mobil = delete_from_list(list_mobil);
                break;
                
            default:  printf("Kode salah\n");
        }
        printf("\n");
    }
}


struct mobil *append_to_list(struct mobil *list)
{
    struct mobil *mobil_baru=NULL;           
    
    struct mobil *current=NULL;          
    
    struct mobil *previous=NULL;
    
    mobil_baru=malloc(sizeof(struct mobil));
    
    if(mobil_baru==NULL)
    {
        return list;
    }
    
    printf("Masukkan kode pembuatan: ");         
    read_line(mobil_baru->buat,31);
    
    printf("Model mobil: ");
    read_line(mobil_baru->model,31);
    
    printf("Warna mobil: ");
    read_line(mobil_baru->warna,31);
    
    printf("Tahun pembuatan: ");
    scanf("%d", &mobil_baru->tahun);
    
    printf("Jarak tempuh kota per galon: ");
    scanf("%d", &mobil_baru->kota_mpg);
    
    printf("Kilometer ditempuh per galon: ");
    scanf("%d", &mobil_baru->kilometer_mpg);
    
    printf("Jumlah mobil: ");
    scanf("%d", &mobil_baru->kuantitas);
    
    if(list==NULL)
    {
        return mobil_baru;
    }
    
    for(current=list;current!=NULL;current=current->next)               /*This for-loop will check if the car that the user entered already exists within the list.*/
    {
        previous=current;
        if(strcmp(current->buat,mobil_baru->buat)==0 && strcmp(current->model,mobil_baru->model)==0 && strcmp(current->warna,mobil_baru->warna)==0 && (current->tahun==mobil_baru->tahun))
        {
            printf("Mobil tersebut sudah ada.");
            return list;
        }
        
        
        
    }
    
    
    
    for(previous=NULL, current=list;current!=NULL;previous=current,current=current->next){
        if(previous==NULL && strcmp(current->buat,mobil_baru->buat)>0){
            previous->next=mobil_baru;
            mobil_baru->next=current;
            return list;
        }
        else if(strcmp(current->buat, mobil_baru->buat)>0 && strcmp(previous->buat,mobil_baru->buat)<0){
            previous->next=mobil_baru;
            mobil_baru->next=current;
            return list;
        }
        else if(strcmp(current->buat,mobil_baru->buat)==0 && strcmp(previous->buat, mobil_baru->buat)<0){
            if(strcmp(current->model, mobil_baru->model)>0){
                previous->next=mobil_baru;
                mobil_baru->next=current;
                return list;
            }
        }
    }
    if(strcmp(previous->buat, mobil_baru->buat)<0 && current==NULL){
        previous->next=mobil_baru;
        mobil_baru->next=NULL;
        return list;
    }
    
    
    
}


void cari_mobil(struct mobil * list)
{
    struct mobil *current;
    
    char buat[31];              /*Declaring character arrays to store the strings of make and model*/
    char model[31];
    
    int length=0;
    
    printf("Masukkan kode pembuatan: ");
    read_line(buat,31);
    
    printf("Model mobil: ");
    read_line(model,31);
    
    
    
    for(current=list;current!=NULL;current=current->next)           /*This for-loop will check through each of the nodes in the linked list to see if the make and model are the same using the string compare function*/
    {
        if(strcmp(current->buat, buat)==0 && strcmp(current->model, model)==0)
        {
            printf("Warna: %s, Tahun: %d, Jarak tempuh kota: %d, Kilometer: %d, Jumlah: %d", current->warna, current->tahun, current->kota_mpg, current->kilometer_mpg, current->kuantitas);
            length++;
        }
        return list;
    }
    
    if(length==0)
    {
        printf("Mobil tidak ditemukan.");
    }
    
}
void printList(struct mobil *list){
    
    struct mobil *current=NULL;
    
    
    
    for(current=list;current!=NULL;current=current->next)      /*The for-loop will go through each of the nodes in the list and display all the information in the nodes.*/
    {
        printf("Kode pembuatan: %s, \tModel: %s, \tWarna: %s, \tTahun pembuatan: %d, \tJarak tempuh kota: %d, \tKilometer: %d, \tJumlah: %d", current->buat, current->model, current->warna, current->tahun, current->kota_mpg, current->kilometer_mpg, current->kuantitas);
        printf("\n");
        return list;
    }
    
    
    
}
void clearList(struct mobil *list)
{
    struct mobil *current=NULL;
    struct mobil *previous=NULL;
    
    for(current=list;current!=NULL; )          /*In the for-loop, I am assigning the previous pointer to the current pointer before I iterate to the next node using current->next.*/
    {
        previous=current;                      /*This way, I do not delete the null at the end of the list when deleting everything.*/
        current=current->next;
        free(previous);
        return list;
    }
  
    
}

struct mobil *delete_from_list(struct mobil *list){
    struct mobil *mobil_baru=NULL;
    struct mobil *current=NULL;
    
    char buat[31];
    char model[31];
    char warna[31];
    int tahun;
    
    mobil_baru=malloc(sizeof(struct mobil));
    
    if(mobil_baru==NULL)
    {
        return list;
    }
    
    printf("Masukkan kode pembuatan: ");
    read_line(buat,31);
    
    printf("Model mobil : ");
    read_line(model,31);
    
    printf("Warna mobil: ");
    read_line(warna,31);
    
    printf("Tahun pembuatan: ");
    scanf("%d", &tahun);
    
    for(current=list; current!=NULL;current=current->next){
        if(strcmp(current->buat, buat)==0 && strcmp(current->model, model)==0 && strcmp(current->warna,warna)==0 && current->tahun==tahun){
            free(current);
        }
    }
    return list;
}



int read_line(char str[], int n)
{
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ;
    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
int Exit(){
	system("cls");
	int p;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t");
	for(p=0;p<33;p++)
	{
		printf("=");
		Sleep(20);
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t\tSee U Next Time\n\t\t\t\t\t\t\t\t\t\t");
	for(p=0;p<33;p++)
	{
		printf("=");
		Sleep(20);
	}
	return 0;
}
