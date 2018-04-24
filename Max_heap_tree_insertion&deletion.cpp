#include<iostream>
#include<cstdlib>
using namespace std;

void max_heap(int*a,int i,int n)//排序出Max Heap Tree
{
	int j, temp;
	temp = a[i];//元素暫存在temp
	j = 2 * i; // j為i位置的left child
	while (j <= n)//每個元素進行各個條件判斷
	{
		if (j<n && a[j + 1]>a[j])//若right child大於left child, 則讓right child去做下面的判斷
			j = j + 1;
		if (temp > a[j])//parent 比 child 大，不必調換
			break;
		else if (temp <= a[j])//parent 比 child 小，要調換
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}

void maxht_build(int*a, int n)//建立Max Heap Tree
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heap(a, i, n);//呼叫排序Max Heap Tree的函式
	}
}
int main()
{
	int a[20];//設一個大小為20的陣列儲存輸入Heap的元素
	int i,n;
	cout << "Input the number of elements: ";
	cin >> n; //輸入所要排序的元素個數

	cout << "A sequence of unsorted numbers: ";
	for (i = 1; i <= n;i++)
		cin >> a[i];//輸入要排序的元素

	maxht_build(a, n);//建立Max Heap Tree
	cout << "The construction of max-heap tree: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	cout << "Input the insertion number: ";//Insertion
	cin >> a[n + 1];
	maxht_build(a, n+1); // 加入一新的元素後再重新執行建立Max Heap Tree,進行重排
	for (i = 1; i <= n + 1; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "Input the insertion number: ";//第二個Insertion
	cin >> a[n + 2];
	maxht_build(a, n + 2);
	for (i = 1; i <= n + 2; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	cout << "Deletion: " << endl;//Deletion
	for (i = 2; i <= n + 3; i++)//從第二個開始
	{
		a[i-1] = a[i];//把陣列每個值指定為原本的後一位置的值，第一個位置(同時為Max Heap Tree的最大值)即被移除
	}
	maxht_build(a, n + 1);//移除後再執行一次建立M H T的步驟
	for (i = 1; i <= n + 1; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "Deletion: " << endl;//第二個Deletion,步驟同上再執行一輪
	for (i = 2; i <= n + 2; i++)
	{
		a[i - 1] = a[i];
	}
	maxht_build(a, n);
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "Deletion: " << endl;//同上
	for (i = 2; i <= n + 1; i++)
	{
		a[i - 1] = a[i];
	}
	maxht_build(a, n-1);
	for (i = 1; i <= n-1; i++)
	{
		cout << a[i] << " ";
	}

	system("pause");
	return 0;
}






