#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
//Nguyen Khoa Truong S20-K59TH MSSV:1751061333
struct SV
{
    char tensv[30];
    char mssv[20];
    char tenmh[30];
    int dmh;
};
// Khai bao cau truc du lieu danh sach lien ket
struct NODE
{
    SV Info;
    struct NODE* next;
};
struct LIST
{
    NODE *head;
    NODE *tail;
};
//Tao NODE sinh vien trong danh sach
NODE* CreateNode (SV x)
{
	//Cap phat 1 NODE
    NODE *p;
    p=new NODE;
    if(p==NULL) 
	{
		exit(1);
	} 
    p->Info=x; //Luu X vao Info
    p->next=NULL;
    return p;
}
void Init(LIST &L)
{
	L.head=L.tail=NULL;
}
void AddHead(LIST &L,NODE *p)
{
	if(L.head==NULL)
	{
		L.head=L.tail=p;
	}
	else
	{
		p->next=L.head;
		L.head=p;
	}
}
int Quantity(LIST L) {
 int temp = 0;
 for (NODE *p=L.head;p!=NULL;p=p->next)
  {
  	temp++;
  }
}
void Input (SV &x)
{
	printf("\n\tNhap Ten Sinh Vien:");
	fflush(stdin);
	scanf("%s",&x.tensv);
    printf("\n\tNhap MSSV: "); 
	fflush(stdin);
	gets(x.mssv);
    printf("\n\tNhap Ten Mon Hoc: "); 
	fflush(stdin);
	gets(x.tenmh);   
    printf("\n\tNhap Diem Mon Hoc: "); 
	scanf("%d", &x.dmh);
}
void AddLast (LIST &L, NODE *p)
{
    if(L.head==NULL) 
	{
		L.head=L.tail=p;	
	} 
    else
    {
        L.tail->next=p;
        L.tail=p;
    }
}
void Nhap (LIST &L)
{
    SV x;
    char kt;   
    printf("\n\tNhan Mot Phim Bat Ky De Tiep Tuc...\n");
    do
    {
        kt=getch();
        if(kt=='0')  break;
        Input(x);
        NODE *p=CreateNode(x);
        AddLast(L,p);
    } while (1);
}
void Output (SV x)
{
    printf("\n\t%s    %s		%s      %d",x.tensv,x.mssv,x.tenmh,x.dmh);
}
void Xuat (LIST L)
{
    NODE *p;
    p=L.head;
    while(p!=NULL)
    {
        Output(p->Info);
        p=p->next;
    }
}
// Ham tim danh sach sinh vien co diem mon hoc thap nhat::
void Mindmh(LIST L)
{
 NODE *p,*min;
    int dem;
    p=L.head;
    min=p;
    while (p!=NULL)
    {
        if(p->Info.dmh<min->Info.dmh)
		  {
		   min=p;
		   dem=0; 
		  }
        if(p->Info.dmh==min->Info.dmh)
		 {
		  	min=p;
		    dem++; 
		 }
        p=p->next;
    }
    printf("\n\tSinh Vien Co Diem Mon Hoc Thap Nhat La: \n");
    if(dem==0) 
	{
		Output(min->Info);
	 } 
    else
    {
        NODE *q=L.head;
        while (q!=NULL)
        {
            if(q->Info.dmh==min->Info.dmh)
			{
			Output(q->Info);	
			}
            q=q->next;
        }
    }	
}
//Ham tim danh sach sinh vien co diem mon hoc cao nhat::
void Maxdmh (LIST L)
{
    NODE *p,*max;
    int dem;
    p=L.head;
    max=p;
    while (p!=NULL)
    {
        if(p->Info.dmh>max->Info.dmh) 
		 { 
			max=p;
			dem=0; 
		 }
        if(p->Info.dmh==max->Info.dmh)
		 { 
		 	max=p;
		    dem++; 
		 }
        p=p->next;
    }
    printf("\nSinh Vien Co Diem Mon Hoc Cao Nhat La: \n");
    if(dem==0) 
	{
		Output(max->Info);
	} 
    else
    {
        NODE *q=L.head;
        while (q!=NULL)
        {
            if(q->Info.dmh==max->Info.dmh)
			{
				Output(q->Info);
			} 
            q=q->next;
        }
    }
}
// ham chon truc tiep Selection Sort.....
void SelectionSort (LIST &L)
{
    NODE *p,*q,*min;
    p=L.head;
    SV temp;
    while (p!=L.tail)
    {
        min=p;
        q=p->next;
        while (q!=NULL)
        {
            if(q->Info.dmh<min->Info.dmh)  min=q;
            q=q->next;
        }
        temp=p->Info;
        p->Info=min->Info;
        min->Info=temp;
        p=p->next;
    }
}
// thuat toan QuickSort.......
void QuickSort(LIST &L )
{
 	LIST l1, l2;
 	NODE *tag, *p;
 	if(L.head == L.tail )
 		{
 			 return;
 		}
 	Init(l1);
 	Init(l2);
 	tag = L.head;
 	L.head = L.head->next; // cap nhat lai L.head
 	tag->next= NULL;// co lap tag
 	while( L.head!= NULL )
 		{
  			p = L.head;
  			L.head = L.head->next;
  			p->next= NULL;
  			if(p->next<= tag->next) 
  				{
  					AddHead(l1,p->next);
  				}
  			else 
  				{
  					AddHead(l2,p->next);
  				}
 		}
  // goi de qui sap xep l1, l2
 	QuickSort(l1); 
 	QuickSort(l2);
 	if(l1.head != NULL )// l1 rong
 	{ 
 // lay head cua l1 gan cho head cua l;
  	L.head = l1.head; 
  	l1.tail->next= tag;
 	} 
 	else
 	{
 		L.head = tag;
 		tag->next= l2.head;	
 	} 
 	if(l2.head!= NULL ) 
 		{
 			L.tail = l2.tail;
 		}
 	else
 		{
 			 L.tail = tag;	
 		}	 
}
void CreateList (LIST &L)
{
    L.head=L.tail=NULL;
}
// tao menu chon nhap,xuat,tim sinh vien co diem cao nhat,thap nhat va sap xep danh sach theo thuat toan SelectionSort,QuickSort.....
void Menu()
{
    LIST L;
    NODE *p,*q,*moi;
    SV x;
    char Click;
    CreateList(L);
    do
    {
      
        printf("\n\t\t1. Nhap Danh Sach...");
        printf("\n\t\t2. In Danh Sach...");
        printf("\n\t\t3. Danh Sach Sinh Vien Co Diem Mon Hoc Cao Nhat...");
        printf("\n\t\t4. Danh Sach Sinh Vien Co Diem Mon Hoc Thap Nhat...");
        printf("\n\t\t5. Sap Xep Danh Sach Tang Dan...theo SelectionSort");
        printf("\n\t\t6. Thuat toan QuickSort...");
        Click=getch();
        switch(Click)
        {
            case '1': { Nhap(L);
			 break;}
            case '2': { Xuat(L); 
			break;}
            case '3': { Maxdmh(L);
			 break;}
            case '4':  {Mindmh(L);
				break;
			}
            case '5': { SelectionSort(L);printf("\nDanh Sach Sinh Vien Sau Khi Sap Xep: "); Xuat(L);
			 break;}
			case '6':{ QuickSort(L);printf("QuickSork::"); Xuat(L);
				break;
			}
        }
    } while (Click!='0');
}
// xu ly
int main()
{
    while(1)
    {
        Menu();
        getch();
    }
}
