#include <stdio.h>
#define MAX 100
int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bhyt[MAX];
    int n;
    int i;
    int k;
    int tong_doanh_thu = 0;
    int so_uu_tien = 0;
    // Nhap so luong benh nhan
    do {
        printf("Nhap so luong benh nhan (0 - 100): ");
        scanf("%d", &n);
        if (n < 0 || n > MAX) {
            printf("So luong khong hop le!\n");
        }

    } while (n < 0 || n > MAX);
    // Nhap thong tin benh nhan
    for (i = 0; i < n; i++) {
        printf("\n--- Benh nhan %d ---\n", i + 1);
        printf("Nhap ma so thu tu: ");
        scanf("%d", &ma_so[i]);
        // Nhap tuoi
        do {
            printf("Nhap tuoi (1 - 120): ");
            scanf("%d", &tuoi[i]);
            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi khong hop le!\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);
        // Nhap BHYT
        do {
            printf("Nhap BHYT (1: Co, 0: Khong): ");
            scanf("%d", &bhyt[i]);
            if (bhyt[i] != 0 && bhyt[i] != 1) {
                printf("Trang thai BHYT khong hop le!\n");
            }
        } while (bhyt[i] != 0 && bhyt[i] != 1);
    }
    // Tinh doanh thu va so benh nhan uu tien
    tong_doanh_thu = 0;
    so_uu_tien = 0;
    for (i = 0; i < n; i++) {
        if (bhyt[i] == 1) {
            tong_doanh_thu = tong_doanh_thu + 30000;
        } else {
            tong_doanh_thu = tong_doanh_thu + 150000;
        }
        if (tuoi[i] >= 70) {
            so_uu_tien++;
        }
    }
    // In danh sach ban dau
    printf("\n============================================\n");
    printf("        DANH SACH HANG CHO BAN DAU\n");
    printf("============================================\n");
    for (i = 0; i < n; i++) {
        printf("Vi tri %d: Ma so %d | Tuoi: %d | BHYT: %d",
               i, ma_so[i], tuoi[i], bhyt[i]);
        if (tuoi[i] >= 70) {
            printf(" | UU TIEN\n");
        } else {
            printf(" | THUONG\n");
        }
    }
    printf("Tong so benh nhan: %d\n", n);
    printf("Tong doanh thu du kien: %d VND\n", tong_doanh_thu);
    printf("So benh nhan uu tien: %d\n", so_uu_tien);
    // Nhap vi tri can huy
    if (n == 0) {
        printf("\nHang cho dang rong, khong co benh nhan de huy.\n");
        return 0;
    }
    printf("\nNhap vi tri K can huy (0 - %d): ", n - 1);
    scanf("%d", &k);
    if (k < 0 || k >= n) {
        printf("Vi tri huy khong hop le!\n");
        return 0;
    }
    // Huy benh nhan bang cach don mang sang trai
    for (i = k; i < n - 1; i++) {
        ma_so[i] = ma_so[i + 1];
        tuoi[i] = tuoi[i + 1];
        bhyt[i] = bhyt[i + 1];
    }
    n--;
    // Tinh lai doanh thu va so benh nhan uu tien
    tong_doanh_thu = 0;
    so_uu_tien = 0;
    for (i = 0; i < n; i++) {
        if (bhyt[i] == 1) {
            tong_doanh_thu = tong_doanh_thu + 30000;
        } else {
            tong_doanh_thu = tong_doanh_thu + 150000;
        }
        if (tuoi[i] >= 70) {
            so_uu_tien++;
        }
    }
    // In danh sach sau khi huy
    printf("\n============================================\n");
    printf("       DANH SACH HANG CHO SAU KHI HUY\n");
    printf("============================================\n");
    for (i = 0; i < n; i++) {
        printf("Vi tri %d: Ma so %d | Tuoi: %d | BHYT: %d",
               i, ma_so[i], tuoi[i], bhyt[i]);
        if (tuoi[i] >= 70) {
            printf(" | UU TIEN\n");
        } else {
            printf(" | THUONG\n");
        }
    }
    printf("Tong so benh nhan con lai: %d\n", n);
    printf("Tong doanh thu sau khi huy: %d VND\n", tong_doanh_thu);
    printf("So benh nhan uu tien: %d\n", so_uu_tien);
    return 0;
}
