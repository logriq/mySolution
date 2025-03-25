def quick_sort(arr) :
    //������� ������ �������� �������� ����������(QuickSort).
    //������� ���� : ������� ������� �������(pivot), ������� ����� �� �� ������� :
//1) ��������, �� ����� �� �������,
//2) ��������, �� ����� ��� ���� ��������.
//���� ���������� ����������� ������ ���������� �� ��� ���� ������.

//������ ���������� ��������� :
//-�������� �� ��������� ������� : O(n log n)
//- �������� �������(���� ��������� ��������� ��� ��������� �������) : O(n?)

//���������� ���������� : O(n) � ������� ������������ ������ Python ����� ��������� ����� ������.

//������� ������� : ���� ������� ������ ����� ��� ������� 1, �� ��� ������������

if len(arr) <= 1 :
    return arr

//���� �������� ��������(pivot) - ��� �������� �������� ������� ������

    pivot = arr[len(arr)2]  

//�������� ������ :
// �� ��������, ����� �� pivot, ����������� � left

left = [x for x in arr if x < pivot]
    # �� ��������, ���� pivot, ����������� � middle
    middle = [x for x in arr if x == pivot]
    # �� ��������, ����� �� pivot, ����������� � right
    right = [x for x in arr if x > pivot]

//���������� ���������� �������� �� ��'������� ����������

    return quick_sort(left) + middle + quick_sort(right)

//������� ������������ �������� ����������
    
arr = [3, 6, 8, 10, 1, 2, 1, 5, 7, 4, 9]
    sorted_arr = quick_sort(arr)
    print("������� �����:", arr)
    print("³����������� �����:", sorted_arr)  # ������ ������������ �����
