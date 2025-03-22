// TASK : Оптимізувати алгоритм лінійного пошуку на випадок впорядкованого масиву 

int LinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
        if (arr[i] > target) break;
    }
    return -1;
}
