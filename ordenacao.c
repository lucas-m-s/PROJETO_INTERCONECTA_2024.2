#include <stdio.h>
#define abs(a) (a < 0 ? -a : a)

typedef struct{
  int x;
  double y;
} Point;

void merge(Point *arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  Point L[80000], R[80000];

  for(int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for(int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0;
  int k = left;

  while(i < n1 && j < n2) {
    if(L[i].y > R[j].y) {
      arr[k] = L[i];
      i++;
    } else if(L[i].y == R[j].y) {
      if(L[i].x <= R[j].x) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(Point *arr, int left, int right)
{
  if(left >= right) return;

  int mid = (right + left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}







void point_swap(Point *a, Point *b)
{
  Point temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(Point *arr, int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < n && arr[l].y < arr[largest].y)
    largest = l;

  if(r < n && arr[r].y < arr[largest].y)
    largest = r;

  if(largest != i) {
    point_swap(&arr[i], &arr[largest]);

    heapify(arr, n, largest);
  }
}

void heapsort(Point *arr, int n)
{
  for(int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for(int i = n - 1; i > 0; i--) {
    point_swap(&arr[0], &arr[i]);

    heapify(arr, i, 0);
  }
}

int main(void)
{
  Point a[] = {{1, 5.89}, {2, 1.3}, {3, 9.99}, {4, 5.90}, {5, 5.891}, {6, 7.12}, {7, 7.12}, {8, 123.09873}};

  heapsort(a, 8);

  for(int i = 0; i < 8; i++)
    printf("%d %lf\n", a[i].x, a[i].y);

  return 0;
}