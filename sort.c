#include <stdio.h>
#include <stdlib.h>

long long mc = 0, qc = 0;

void show(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if (i + 1 == n) printf("\n");
        else printf(" ");
    }
}

void merge(int a[], int t[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r) {
        mc++;
        if (a[i] <= a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    }

    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];

    for (i = l; i <= r; ++i) a[i] = t[i];
}

void mergeSort(int a[], int t[], int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSort(a, t, l, m);
    mergeSort(a, t, m + 1, r);
    merge(a, t, l, m, r);
}

int part(int a[], int l, int r) {
    int p = a[r], s = l - 1, x;

    for (int i = l; i < r; ++i) {
        qc++;
        if (a[i] <= p) {
            s++;
            x = a[s]; a[s] = a[i]; a[i] = x;
        }
    }

    x = a[s + 1]; a[s + 1] = a[r]; a[r] = x;
    return s + 1;
}

void quickSort(int a[], int l, int r) {
    if (l >= r) return;

    int p = part(a, l, r);

    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

void join(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }

    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}

int main(void) {
    FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("File not found\n");
        return 1;
    }

    int n, m;
    fscanf(f, "%d %d", &n, &m);

    int a[n + 1], q[n + 1], t[n + 1], b[m + 1], c[n + m + 1];

    for (int i = 0; i < n; ++i) {
        fscanf(f, "%d", &a[i]);
        q[i] = a[i];
    }
    for (int i = 0; i < m; ++i) fscanf(f, "%d", &b[i]);
    fclose(f);

    mergeSort(a, t, 0, n - 1);
    quickSort(q, 0, n - 1);

    printf("Merge Sort: ");
    show(a, n);
    printf("Quick Sort: ");
    show(q, n);
    printf("Merge Comparisons: %lld\n", mc);
    printf("Quick Comparisons: %lld\n", qc);

    join(a, n, b, m, c);
    printf("Updated Array: ");
    show(c, n + m);

    return 0;
}
