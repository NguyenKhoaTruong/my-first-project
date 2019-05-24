#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
struct Node
{
	// Du lieu chua trong Node
	int Data; 
	struct Node *pLeft;
	struct Node *pRight;
};
typedef struct Node NODE;
typedef NODE* BinaryTree;
// khoi tao cay
void Init(BinaryTree &c)
{
	c = NULL;
}
// them mot phan tu vao cay
void InSert(BinaryTree &c, int a)
{
	// cay rong a la Node goc
	if(c == NULL)
	{
		NODE *q = new NODE;
		q ->Data = a;
		q ->pLeft = q ->pRight = NULL;
		c = q;
	}
	else
	{
		if(c ->Data > a)
		{
			InSert(c ->pLeft, a);
		}
		else if(c ->Data < a)
		{
			InSert(c ->pRight, a);
		}
	}
}
// Tao cay
void CreateBinaryTree(BinaryTree &c)
{
	 // khoi tao cay
	Init(c); 
	int Click;
	do{
		cout << "\n\t\t\t1. Nhap vao du lieu now.....";
		cout << "\n\t\t\t0. Ket thuc va chon muc khac....";

		cout << "\n\t\t\tNhap vao lua chon cua ban: ";
		cin >>Click;

		if(Click == 1)
		{
			int a;
			cout << "\n\t\tNhap du lieu can them vao: ";
			cin >> a;

			InSert(c, a); // them a voa cay
		}
	}while(Click != 0);
}
//Duyet theo thu tu truoc
void NLR(BinaryTree c)
{
	if(c != NULL)
	{
		cout << c ->Data << "   ";
		NLR(c ->pLeft);
		NLR(c->pRight);
	}
}
//Duyet theo thu tu giua
void LNR(BinaryTree c)
{
	if(c != NULL)
	{
		LNR(c ->pLeft);
		cout << c ->Data << "   ";
		LNR(c ->pRight);
	}
}
//Duyet theo thu tu sau
void LRN(BinaryTree c)
{
	if(c != NULL)
	{
		LRN(c ->pLeft);
		LRN(c ->pRight);
		cout << c->Data << "   ";
	}
}
// Tim kiem phan tu trong cay
NODE* Search(BinaryTree c, int a)
{
	if(c == NULL)
	{
		return NULL;
	}
	if(c ->Data > a)
	{
		Search(c->pLeft, a);
	}
	else if(c ->Data < a)
	{
		Search(c ->pRight, a);
	}
	else
	{
		return c;
	}
} 
void FindArrayPotentialElement(BinaryTree &p, BinaryTree &q)
{

	if(q ->pLeft != NULL)
	{
		FindArrayPotentialElement(p, q ->pLeft);
	}
	else 
	{
		p ->Data = q ->Data;
		p = q;
		q = q ->pRight;
	}
}
void DeleteNode(BinaryTree &c, int a)
{
	// Bat dau xoa  Node con va Node la
	if(c== NULL)
	{
		return;
	}
	if(c ->Data > a)
	{
		DeleteNode(c ->pLeft, a);
	}
	else if(c ->Data < a)
	{
		DeleteNode(c ->pRight, a);
	}
	else 
	{
		NODE *p = c;
		// xoa Node mot con va k co con
		if(c ->pLeft == NULL)
		{
			c = c ->pRight;
		}
		else if(c ->pRight == NULL)
		{
			c = c ->pLeft;
		}
		else
		{
			//Trai nhat cua cay con phai
			FindArrayPotentialElement(p, c ->pRight);

			//Phai nhat cua cay con trai
			FindArrayPotentialElement(p, c ->pLeft);
		}
		delete p;
	}
}
// tim tat ca cac node co trong cay nhi phan tim kiem...
int AllNodeForTREE(BinaryTree c)
{
	if(c==NULL) return 0;
	else return(AllNodeForTREE(c->pRight) + AllNodeForTREE(c->pLeft) )+1;
}

//  Xuat ra cac  node co hai  con  trong cay nhi phan
int TwoNodeChi(BinaryTree c)
{
	if(c!=NULL)
	{
		// Xu ly
			if(c->pLeft!=NULL && c->pRight!=NULL)
			{
				cout<<c->Data<<" ";
			}
			// duyet sang trai  cua node hien tai
			TwoNodeChi(c->pLeft); 
			// duyet sang phai cua node hien tai
			TwoNodeChi(c->pRight);
	}
}
// Tong chan trong cay nhi phan tim kiem...
int SplitTatol(BinaryTree c)
{
	if(c!=NULL) 
	{
		int h=SplitTatol(c->pLeft);
		int k=SplitTatol(c->pRight);
		if(c->Data%2==0)
		{
			return  c->Data+h+k;
		}
		else
		{
			return h+k;
		}
		return 0;
	}

}
// Tong le trong cay nhi phan tim kiem...
int RetailTotal(BinaryTree c)
{
		if(c!=NULL) 
	{
		int h=RetailTotal(c->pLeft);
		int k=RetailTotal(c->pRight);
		if(c->Data%2!=0)
		{
			return c->Data+h+k;
		}
		else
		{
			return h+k;
		}
		return 0;
	}
}
// Kiem tra so nguyen to trong cay...
bool CheckkPrimes(int a)
{ 
	if(a < 2)
	{
		return false;
	}
	else
	{
		if (a == 2)
		{
			return true;
		}
		else
		{
			if (a % 2 == 0)
			{
				return false;
			}
			else
			{
				for (int i = 2; i < a; i++)
				{
					if (a % i == 0)
					{
						return false;
					}
				}
			}	
		}
	}
	return true;
}
// Dem so nguyen to co trong cay nhi phan ....
void NumberCoutPrimes(BinaryTree c,int &Number)
{
	if(c!=NULL)
	{
		if(CheckkPrimes(c->Data)==true)
		{
			Number++;
		}
		// Duyet cac node ben trai..
		NumberCoutPrimes(c->pLeft, Number);
		// Duyet cac node ben phai...
		NumberCoutPrimes(c->pRight, Number);
			
	}
}
// Tinh tong cac so nguyen to da tim kiem
int SumNumberPrimes(BinaryTree c,int &Sum)
{
	
	if(c!=NULL)
	{
		int h=SumNumberPrimes(c->pLeft,Sum);
		int k=SumNumberPrimes(c->pRight,Sum);
		if(CheckkPrimes(c->Data)==true)
		{
			return Sum=c->Data+h+k;
			
		}
		else
		{
			return h+k;
		}
		return 0;
	}
	}
int main()
{
	// khai bao cay
	BinaryTree c;
	Init(c);
	CreateBinaryTree(c);
	cout<<"\n\t\t\t So phan tu hien co trong cay nhi phan la :"<<AllNodeForTREE(c)<<endl;
	cout<<"\n\t\t\t Node co hai con la:";
	TwoNodeChi(c);
	cout<<"\n\t\t\t Tong cac so chan trong cay la:"<<SplitTatol(c)<<endl;
	SplitTatol(c);
	cout<<"\n\t\t\t Tong cac so le trong cay la :"<<RetailTotal(c);
	RetailTotal(c);
	int Number=0;
	NumberCoutPrimes(c,Number);
	cout<<"\n\t\t\t So luong so nguyen to la :"<<Number;
	int Sum=0;
	SumNumberPrimes(c,Sum);
	cout<<"\n\t\t\t Tong cac so nguyen to la: "<<Sum;
	/*cout << "\n\t\t\t\tNLR\n\t\t\t";
	//xuat ra thu tu truoc
	NLR(c);
	cout << "\n\t\t\t\tLNR\n\t\t\t";
	//xuat ra thu tu giua
	LNR(c);
	cout << "\n\t\t\t\tLRN\n\t\t\t";
	//xuat ra thu tu sau
	LRN(c);
	int x;
	cout<< "\n\t\t\tNhap vao so ma ban can tim : ";
	cin>> x;
	NODE *q = Search(c, x);
	if(q == NULL)
	{
		cout<<"\n\t\t\tKhong tim thay phan tu trong du lieu cay !!!";
	}
	else
	{
		cout<<"\n\t\t\t Phan tu co ton tai trong cay !!!";
	}
	int b;
	cout<< "\n\t\t\tNhap vao so can xoa: ";
	cin>> b;
	DeleteNode(c, b);
	cout<< "\n\t\t\tCay sau khi xoa la: \n";
	cout<< "\n\t\t\t\tNLR\n\t\t\t";
	// Xuat ra cay tim kiem sau khi xoa
	NLR(c);
	system("pause");
	return 0;*/
}
