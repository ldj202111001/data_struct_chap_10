/*
* ���α׷� ����: �� ���� ���α׷�
* �ǽ���¥: 2024 - 05 -22
* �й�: 202111001
* �̸�: �̵���
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_NODE 200

void error(const char str[])
{
    printf("%s\n", str);
    exit(1);
}

typedef int HNode; // ���� ������ �׸��� �ڷ���
#define Key(n) (n) // �� ��� n�� Ű��
HNode heap[MAX_HEAP_NODE]; // �迭�� �̿��� ������ ��(����� �迭)
int heap_size; // ���� ũ��
#define Parent(i) (heap[i/2]) // i�� �θ� ���
#define Left(i) (heap[i*2]) // i�� ���� �ڽ� ���
#define Right(i) (heap[i*2+1]) // i�� ������ �ڽ� ���
void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return (heap_size == MAX_HEAP_NODE - 1); }
HNode find_heap() { return heap[1]; }

void insert_heap(HNode n)
{
    int i;
    if (is_full_heap()) return;
    i = ++(heap_size);
    while (i != 1 && Key(n) > Key(Parent(i))) {
        heap[i] = Parent(i);
        i /= 2;
    }
    heap[i] = n;
}

HNode delete_heap()
{
    HNode hroot, last;
    int parent = 1, child = 2;
    if (is_empty_heap()) {
        hroot = heap[1];
        last = heap[heap_size--];
        while (child <= heap_size) {
            if (child < heap_size
                && Key(Left(parent)) < Key(Right(parent)))
                child++;
            if (Key(last) >= Key(heap[child])) break;
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = last;
        return hroot;
    }

}

void print_heap()
{
    int i, level;
    for (i = 1, level = 1; i <= heap_size; i++)
    {
        if (i == level)
        {
            printf("\n");
            level *= 2;
        }
        printf("%2d", Key(heap[i]));
    }
    printf("\n---------------");
}

void print_array(int a[], int n, const char* msg)
{
    int i;
    printf("%10s: ", msg);
    for (int i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n");
}

void main()
{
    int i, data[10];
    // ���� �迭 ����
    for (i = 0; i < 10; i++)
        data[i] = rand() % 100;
    print_array(data, 10, "���� ��");
    init_heap();
    for (i = 0; i < 10; i++)
        insert_heap(data[i]);
    for (i = 9; i >= 0; i--)
        data[i] = Key(delete_heap());
    print_array(data, 10, "���� ��");
}