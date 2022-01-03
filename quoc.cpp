#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapMang(int n, int a[])
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void xuatMang(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int timPhanTuAmLonNhat(int n, int a[])
{
    int i, max = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            max = a[i];
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] < 0 && a[i] > max)
            max = a[i];
    }
    return max;
}
float trungBinhCongPhanTuAm(int n, int a[])
{
    int s = 0, dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
        {
            dem++;
            s += a[i];
        }
    if (dem == 0)
        return dem;
    return s / (float)dem;
}
int kiemTraSoNguyenTo(int t)
{
    if (t < 2)
        return 0;
    if (t == 2)
        return 1;
    int count = 0;
    for (int j = 2; j <= sqrt(t); j++)
    {
        if (t % j == 0)
            count++;
    }
    if (count == 0)
        return 1;
    return 0;
}
int demSoLuongSNT(int n, int a[])
{
    int demSNT = 0;
    for (int i = 0; i < n; i++)
        if (kiemTraSoNguyenTo(a[i]) == 1)
            demSNT++;
    return demSNT;
}
int kiemTraSoHoanHao(int n, int a[])
{

    for (int i = 0; i < n; i++)
    {
        int tongUoc = 0;
        for (int j = 1; j < a[i]; j++)
            tongUoc += j;
        if (tongUoc == a[i])
            return a[i];
    }
    return 0;
}
void chenPhanTu(int n, int a[], int b[], int phanTuCanChen)
{
    for (int i = 0; i <= n; i++)
        b[i] = a[i];
    for (int i = n + 1; i >= 1; i--)
        b[i] = b[i - 1];
    b[0] = phanTuCanChen;
    for (int i = 0; i <= n; i++)
        printf("%d ", b[i]);
}
void daoNguocMang(int n, int a[], int c[])
{
    for (int i = n - 1; i >= 0; i--)
        c[n - 1 - i] = a[i];
    xuatMang(n, c);
}
void sapXep(int n, int a[])
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
}
void xoaPhanTuAm(int &n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            i--;n--;
        }
       
    }
    xuatMang(n, a);
}
int main()
{
    int n, a[103], b[103], c[103], d[103];
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    printf("Nhap mang: \n");
    nhapMang(n, a);
    printf("Xuat mang: \n");
    xuatMang(n, a);
    if (timPhanTuAmLonNhat(n, a) == 0)
        printf("\nKhong co phan tu am\n");
    else
        printf("\nPhan tu am lon nhat la: %d\n", timPhanTuAmLonNhat(n, a));
    if (trungBinhCongPhanTuAm(n, a) == 0)
        printf("Khong co phan tu am \n");
    else
        printf("TBC phan tu am: %10.2f\n", trungBinhCongPhanTuAm(n, a));
    printf("So luong so nguyen to la: %d\n", demSoLuongSNT(n, a));
    if (kiemTraSoHoanHao(n, a) == 0)
        printf("Khong co so hoan hao \n");
    else
        printf("So hoan hao la: %d \n", kiemTraSoHoanHao(n, a));
    int phanTuCanChen;
    printf("Nhap phan tu can chen: ");
    scanf("%d", &phanTuCanChen);
    chenPhanTu(n, a, b, phanTuCanChen);
    printf("\n");
    daoNguocMang(n, a, c);
    printf("\n");
    sapXep(n, a);
    xuatMang(n, a);
    printf("\n");
    xoaPhanTuAm(n, a);
}

/*Bài 1 (số lẻ). Viết chương trình thực hiện các công việc sau bằng hàm:
a)	Nhập vào một số nguyên dương (0 < n ≤ 102)
b)	Nhập mảng số nguyên gồm n phần tử.
c)	Xuất mảng số nguyên vừa nhập.
d)	Tìm phần tử âm lớn nhất trong mảng.
e)	Tính trung bình cộng các phần tử âm trong mảng.
f)	Đếm số phần tử là số nguyên tố trong mảng.
g)	Tìm phần tử là số hoàn thiện đầu tiên trong mảng.
h)	Nhập thêm một phần tử và chèn vào đầu mảng.
i)	Đảo ngược mảng.
j)	Sắp xếp mảng theo thứ tự tăng dần.
k)	Xóa tất cả phần tử âm trong mảng.*/