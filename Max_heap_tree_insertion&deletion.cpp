#include<iostream>
#include<cstdlib>
using namespace std;

void max_heap(int*a,int i,int n)//�ƧǥXMax Heap Tree
{
	int j, temp;
	temp = a[i];//�����Ȧs�btemp
	j = 2 * i; // j��i��m��left child
	while (j <= n)//�C�Ӥ����i��U�ӱ���P�_
	{
		if (j<n && a[j + 1]>a[j])//�Yright child�j��left child, �h��right child�h���U�����P�_
			j = j + 1;
		if (temp > a[j])//parent �� child �j�A�����մ�
			break;
		else if (temp <= a[j])//parent �� child �p�A�n�մ�
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}

void maxht_build(int*a, int n)//�إ�Max Heap Tree
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heap(a, i, n);//�I�s�Ƨ�Max Heap Tree���禡
	}
}
int main()
{
	int a[20];//�]�@�Ӥj�p��20���}�C�x�s��JHeap������
	int i,n;
	cout << "Input the number of elements: ";
	cin >> n; //��J�ҭn�ƧǪ������Ӽ�

	cout << "A sequence of unsorted numbers: ";
	for (i = 1; i <= n;i++)
		cin >> a[i];//��J�n�ƧǪ�����

	maxht_build(a, n);//�إ�Max Heap Tree
	cout << "The construction of max-heap tree: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	cout << "Input the insertion number: ";//Insertion
	cin >> a[n + 1];
	maxht_build(a, n+1); // �[�J�@�s��������A���s����إ�Max Heap Tree,�i�歫��
	for (i = 1; i <= n + 1; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "Input the insertion number: ";//�ĤG��Insertion
	cin >> a[n + 2];
	maxht_build(a, n + 2);
	for (i = 1; i <= n + 2; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	cout << "Deletion: " << endl;//Deletion
	for (i = 2; i <= n + 3; i++)//�q�ĤG�Ӷ}�l
	{
		a[i-1] = a[i];//��}�C�C�ӭȫ��w���쥻����@��m���ȡA�Ĥ@�Ӧ�m(�P�ɬ�Max Heap Tree���̤j��)�Y�Q����
	}
	maxht_build(a, n + 1);//������A����@���إ�M H T���B�J
	for (i = 1; i <= n + 1; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "Deletion: " << endl;//�ĤG��Deletion,�B�J�P�W�A����@��
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

	cout << "Deletion: " << endl;//�P�W
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






