void FixHeap (int a[], int n, int pos)
{
    int temp, son;
    if(n <= 1)
        return;

    temp = a[pos];

    for (; pos*2+1 < n; pos = son)
    {
        son = 2*pos+1;
        if (son < n-1 && a[son] < a[son+1])
            son++;

        if (a[son] > temp)
            a[pos] = a[son];
        else
            break;
    }
    a[pos] = temp;
}

void buildheap(Item a[], int n){
  int i;
  for (i = n/2-1; i>=0; i--)
    FixHeap (a, n, i);
}

void heapsort(Item a[], int n) {
  int i = n-1;
  buildheap(a,n);
  while (i > 0) {
    exch(a[i], a[0]);
    FixHeap (a, i, 0);
    i--;
  }
}


void FixHeap (int a[], int n, int pos)
{
    int temp, son;
    if(n <= 1)
        return;

    temp = a[pos];

    for (; pos*2+1 < n; pos = son)
    {
        son = 2*pos+1;
        if (son < n-1 && a[son] < a[son+1])
            son++;

        if (a[son] > temp)
            a[pos] = a[son];
        else
            break;
    }
    a[pos] = temp;
}

void buildheap(Item a[], int n){
  int i;
  for (i = n/2-1; i>=0; i--)
    FixHeap (a, n, i);
}

void heapsort(Item a[], int n) {
  int i = n-1;
  buildheap(a,n);
  while (i > 0) {
    exch(a[i], a[0]);
    FixHeap (a, i, 0);
    i--;
  }
}