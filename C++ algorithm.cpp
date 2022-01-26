//#include "qSortMT.hpp" 
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string>
#include<queue>

using namespace std;

template <class T>
class TreeNode{
	public:
		T data;
  		TreeNode <T> *leftChild=NULL;
  		TreeNode <T> *rightChild=NULL;
};




template <class T>
class sort{
	friend class TreeNode<T>;
	public:
		void setheap(int number);
		void set(int number);
		void output(int number);
		void output2(int number);
		void Heapsort(int number);
		void BuildMaxHeap(int number);
		void Max_Heapify(int number,int heap_size);
		void Quicksort(int p, int number);
		int Partition(int p, int number);
		void mergesort(int first,int last);
		void merge(int first,int last,int mid);
		void binary_tree(int number);
		void inorder_traversal(TreeNode<T> *parent, int i);
		TreeNode <T>*tree;
		T *A;	
};


int main(void){
	srand(time(0));
	
	int number, change, go =0;
	double start, stop, count =0;
	sort<string> data;
	cout << "quentity = ";
	cin >> number;
	
	cout<<endl;
	
	for(number=1;number<=5;number+=1){
	
	cout<<endl;
	cout<<number<<endl;
	data.setheap(number);
	
	start = clock();
	data.Heapsort(number);
	stop = clock();
//	data.output2(number);
	cout << "\nheapsort cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout<<endl;
	
	data.set(number);
	start = clock();
	data.Quicksort(0,number-1);
	
	stop = clock();
//	data.output(number);
	cout << "\nquicksort cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout<<endl;
	
	
	
	data.set(number);
	start = clock();
	data.mergesort(0,number-1);
	stop = clock();
	
//	data.output(number);
	cout << "\nmergesort cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout<<endl;

	data.set(number);
	start = clock();
//	data.binary_tree(number);
//	data.inorder_traversal(data.tree,0);
	stop = clock();
	
	
//	cout << "\nbinary search tree cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
}
	return 0;
}

template <class T>
void sort<T>::set(int number){
	char aph;
	A = new T[number];
	for(int i=0;i<number;i++){
		for(int k=0;k<6;k++){
			aph=(rand()%26)+97;
			A[i]=A[i]+aph;
		}
		//A[i]=(rand()%1000000);//int¶Ã¼Æ 
		//A[i]=(T)(rand()/(RAND_MAX+1.0))+1;//double 
	}
		
}


template <class T>
void sort<T>::setheap(int number){
	char aph;
	A = new T[number+1];
	for(int i=1;i<=number;i++){
		for(int k=0;k<6;k++){
			aph=(rand()%26)+97;
			A[i]=A[i]+aph;
		}
		//A[i]=(rand()%1000000);//int¶Ã¼Æ 
		//A[i]=(T)(rand()/(RAND_MAX+1.0))+1;//double 
	}
		
}

template <class T>
void sort<T>::output(int number){
	for(int i=0;i<number;i++){
		cout << A[i] << " ";
	}
	cout<<endl;
}
template <class T>
void sort<T>::output2(int number){
	for(int i=1;i<=number;i++){
		cout << A[i] << " ";
	}
	cout<<endl;
}




template <class T>
void sort<T>::Max_Heapify(int number,int heap_size){
	int largest=0;
	int le = 2*number;
	int rt = 2*number+1;
	if(le<=heap_size && A[le]>A[number])
		largest = le;
	else largest = number;
	if(rt<=heap_size && A[rt]>A[largest])
	largest = rt;
	if(largest!=number){	
		swap(A[number],A[largest]);
		Max_Heapify(largest,heap_size);
	}
	
	
	
}

template <class T>
void sort<T>::Heapsort(int number){
	int length=number;
	int heap_size=number;
	for(int i=(length/2);i>=1;i--)
		Max_Heapify(i,heap_size);
	for(int j=length;j>=2;j--){
		swap(A[1],A[j]);
		heap_size=heap_size-1;
		Max_Heapify(1,heap_size);
	}
}

template <class T>
void sort<T>::Quicksort(int p, int number){
	int q;
	if(p<number){
		q = Partition(p,number);
		Quicksort(p,q-1);
		Quicksort(q+1,number);
	}
}

template <class T>
int sort<T>::Partition(int p, int number){
	int i;
	T x;
	x = A[number];
	i = p-1;
	for(int j=p;j<=number-1;j++){
		if(A[j]<=x){
		i++;
		swap(A[i],A[j]);}
	}
	swap(A[i+1],A[number]);
	return i+1;
}

template<class T>
void sort<T>::binary_tree(int number){
	tree=new TreeNode<T>;
	tree->data=A[0];
	
	TreeNode <T>*y;
	TreeNode <T>*x=tree;
	
	for(int i=1;i<number;i++){
		while(x!=NULL){
			y=x;
			if(A[i]>x->data){
				x=x->rightChild;
			}
			else if(A[i]<x->data){
				x=x->leftChild;
			}
			else if(A[i]==x->data)break;
		}
		if(A[i]<y->data){
			y->leftChild=new TreeNode<T>;
			y->leftChild->data=A[i];
		}
		else if(A[i]>y->data){
			y->rightChild=new TreeNode<T>;
			y->rightChild->data=A[i];;
		}
		x=tree;
		y=NULL;
	}
}


template <class T>
void sort<T>::inorder_traversal(TreeNode<T>*parent,int i){
	if(parent!= NULL){
		inorder_traversal(parent->leftChild,i);
		A[i]=parent->data;
	//	cout << A[i] << " ";
		i++;
		inorder_traversal(parent->rightChild,i);
	}
}

template <class T>
void sort<T>::mergesort(int first,int last){
	if(first<last){
		int mid = (first+last)/2;
		mergesort(first,mid);
		mergesort(mid+1,last);
		merge(first,last,mid);
	}
}

template <class T>
void sort<T>::merge(int first,int last,int mid){
	int sizeA=mid-first+1,sizeB=last-mid;
	int right=0,left=0;
	
	T *L= new T[sizeA];
	T *R= new T[sizeB];
	
	for(int i=0;i<sizeA;i++){
		L[i]=A[i+first];
	}
	
	for(int i=0;i<sizeB;i++){
		R[i]=A[i+mid+1];
	}
	
	
	for(int i=first;i<=last;i++){
		if(sizeB==right){
			for(int j=i;j<=last;j++){
				A[j]=L[left];
				left++;
			}
			break;
		}	
		if(sizeA==left){
			for(int j=i;j<=last;j++){
				A[j]=R[right];
				right++;
			}
			break;
		}	
		if(L[left]<=R[right]){
			A[i]=L[left];
			left++;
		}
		else{
			A[i]=R[right];
			right++;
		} 
		
	}
	delete []R;
	delete []L;
}



