#include<iostream>
#include<climits>
using namespace std;

//�������� �������� ������� ��� ����� ���� ����� �����
void swap(int* x, int* y);

//���� ��� ��������� ����(Min Heap)
class MinHeap
{
    int* harr; //�������� �� ����� �������� � ���
    int capacity; //����������� �������� ����� ��������� ����
    int heap_size; //������� ������� �������� � ���������� ���
public:
    //�� �����������
    MinHeap(int capacity);

    //��� ������������ �������� �� ���� � ������� �� ������� ��������
    void MinHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }

    //��� �������� ������ ����� ���������� �������� ����� � �������� i
    int left(int i) { return (2 * i + 1); }

    //��� �������� ������ ������� ���������� �������� ����� � �������� i
    int right(int i) { return (2 * i + 2); }

    //��� ������� �����, ���� � ���������� ���������
    int extractMin();

    //������ �������� ����� �� �������� i �� new_val
    void decreaseKey(int i, int new_val);

    //������� ���������� ���� (���� � ������) � ��������� ����
    int getMin() { return harr[0]; }

    //������� ����, �� ���������� �� �������� i
    void deleteKey(int i);

    //�������� ����� ����� 'k'
    void insertKey(int k);
};

//�����������: ���� ���� � ������ ������ a[] �������� ������
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

//������������ ����� ���� 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\n������������: �� ������� �������� ����\n";
        return;
    }

    //�/������� ���������� ����� ���� � �����
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    //����������� ���������� ��������� ����, ���� ���� ��������
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

//������ �������� ����� �� �������� 'i' �� new_val - �������������, ��
//new_val ����� ��� harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

//����� ��� ��������� ����������� �������� (��� ������) � ��������� ����
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return 2147483647;

    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    //����� �������� ��������� �������� �� ��������� ���� � ����
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}


//�� ������� ������� ���� �� �������� i. ���� �������� ������ �������� �� ����
//������������, � ���� ������� extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

//����������� ����� ��� ������������ �������� �� ���� � ������� �� ������� ��������
//��� ����� ���������, �� �������� ��� ����������� �� ����
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;

    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

//�������� ������� ��� ����� ���� ��������
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//������� �������� ��� ���������� �������������� �������
int main()
{
    MinHeap h(11);

    h.insertKey(3);

    h.insertKey(2);

    h.deleteKey(1);

    h.insertKey(15);

    h.insertKey(5);

    h.insertKey(4);

    h.insertKey(45);

    cout << h.extractMin() << " ";

    cout << h.getMin() << " ";

    h.decreaseKey(2, 1);

    cout << h.getMin();

    return 0;
}