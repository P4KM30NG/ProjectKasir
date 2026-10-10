#include <stdio.h>
#include <ctype.h>

int idBarang[]=
{
    101,
    102,
    103,
};

char barang[][50] = 
{
    "Barang 1",
    "Barang 2",
    "Barang 3",
};

int hargaBarang[] =
{
    10000,
    20000,
    30000,
};

int keranjang[10] =
{
    0
};

int jumlahItem_keranjang[10] = 
{
    0
};

void list_barang(int ukuranArray_list) // ukuran array & nampilin listnya
{
    int i;
    printf("ID | NAMA BARANG | HARGA\n");
    while (i < ukuranArray_list)
    {
        printf("%d | %s | %d\n",idBarang[i], barang[i], hargaBarang[i]);
        i++;
    }
}
int jumlahKeranjang = 0;
void tambah_keranjang(int idBarang_input, int jumlahBarang_input)
{
    int i=0;
    while (i < jumlahKeranjang)
    {
        if (keranjang[i] == idBarang_input)
        {
            jumlahItem_keranjang[i] += jumlahBarang_input;
            
            return;
         
        }
        i++;
    }
    if(jumlahKeranjang >= 10)
    {
        printf("Keranjang sudah penuh!\n");
        return;
    }
        keranjang[jumlahKeranjang] = idBarang_input;
        jumlahItem_keranjang[jumlahKeranjang] = jumlahBarang_input;
        jumlahKeranjang++;
    
}

void list_kranjang(int ukuranArray_kranjang, int ukuranArray_list) //ukuran array & nampilin keranjang
{
    int i = 0;
    printf("ID | NAMA BARANG | JUMLAH | HARGA\n");
    while (i < ukuranArray_kranjang)
    {
        int j = 0;
        int k = 0;
        while(j < ukuranArray_list)
        {
            if (keranjang[i] == idBarang[j])
            {
                printf("%d | %s | %d | %d\n",idBarang[j], barang[j], jumlahItem_keranjang[i], hargaBarang[j]);
                k = 1;
                break;
            }
            j++;
        } 
        if (!k) {
            printf("%d | ID Tidak Ditemukan | %d | - | -\n", 
                   keranjang[i], 
                   jumlahItem_keranjang[i]);
            }
        
        i++;
    }
}

void hapusIsi_kranjang(int ukuranArray_kranjang, int ukuranArray_list)
{
    int idBarang_Hapus;
    int i = 0;

    list_kranjang(ukuranArray_kranjang, ukuranArray_list);
    printf("Masukkan ID Barang yang mau dihapus: ");
    scanf("%d", &idBarang_Hapus);

    while (i < jumlahKeranjang)
    {
        if (keranjang[i] == idBarang_Hapus)
        {
            int j = i;
            while (j < jumlahKeranjang - 1)
            {
                keranjang[j] = keranjang[j + 1];
                jumlahItem_keranjang[j] = jumlahItem_keranjang[j + 1];
                j++;
            }
            jumlahKeranjang--;
            keranjang[jumlahKeranjang] = 0;
            jumlahItem_keranjang[jumlahKeranjang] = 0;
            
            list_kranjang(jumlahKeranjang, ukuranArray_list);
            return;
        }
        i++;
    }

    printf("ID barang tidak ditemukan di keranjang.\n");
}

void edit_kranjang(int ukuranArray_kranjang, int ukuranArray_list)
{
    int i = 0;
    int idBarang_ubah;
    int s;
    list_kranjang(ukuranArray_kranjang, ukuranArray_list);
    printf("Masukkan ID Barang yang mau diubah/diedit: ");
    scanf("%d", &idBarang_ubah);

    while(i < jumlahKeranjang)
    {
        if (keranjang[i] == idBarang_ubah)
        {
            printf("Apa yang mau diubah?\n1. Tambah jumlah Barang\n2. Hapus Barang\nPilih Menu: ");
            scanf("%d", &s);
            do {
                switch (s) 
                {
                    case 1 : 
                    int jumlahBarang_input;
                    printf("Masukkan jumlah yang baru: "); scanf("%d", &jumlahBarang_input );
                        jumlahItem_keranjang[i] = jumlahBarang_input;
                    break;

                    case 2:
                    hapusIsi_kranjang();
                    break;

                    default: 
                        printf("Error, tidak sesuai input");
                        brak;
                }
            } while (!= 0)
        }
    }
}

int main()
{
    int pilihanMenu;
 
    while(pilihanMenu != 0){
        printf("=== PROGRAM KASIR SEDERHANA ===\n          Select Menu          \n");
        printf("1. Preview List Barang\n2. Tambah ke Keranjang\n3. Hapus barang di Keranjang\n4. Edit Keranjang\n5. Lihat Keranjang\n6. Checkout\n7. Print Struk\n0. Exit Program\nMenu Ke-");
        scanf("%d", &pilihanMenu);

        switch(pilihanMenu){
            case 0:
                if(pilihanMenu == 0)
                {
                    printf("Terimakasih telah Berbelanja bersama kami!");
                    break;
                }
            case 1:
                char pilihanList;
                int arrayLen_barang = sizeof(idBarang)/sizeof(idBarang[0]);
                list_barang(arrayLen_barang);
                printf("\nKembali ke menu? (Y/N): "); scanf(" %c", &pilihanList);
                pilihanList = tolower(pilihanList);
                    if(pilihanList == 'n'){
                        printf("Terimakasih telah Berbelanja bersama kami!\n");
                        break; 
                    } else {
                        printf("\n");
                        continue;
                    }
                
            case 2:
                int x, y;
                char pilihanTambah;
                while(1){
                    printf("Masukkan ID Barang:"); scanf(" %d", &x);
                    printf("Masukkan Jumlah Barang:"); scanf(" %d", &y);
                    tambah_keranjang(x,y);
                    printf("Tambah Lagi?(Y/N):"); scanf(" %c", &pilihanTambah);
                    pilihanTambah = tolower(pilihanTambah);
                    if(pilihanTambah == 'n')
                    {
                        printf("\n");
                        break;
                    } printf("\n");
                } 
            break;

            case 3:
            char pilihanList_kranjang;
                hapusIsi_kranjang(jumlahKeranjang, sizeof(idBarang)/sizeof(idBarang[0]));
                printf("Barang Berhasil dihapus")
                printf("\nKembali ke menu? (Y/N): "); scanf(" %c", &pilihanList_kranjang);
                pilihanList_kranjang = tolower(pilihanList_kranjang);
                    if(pilihanList_kranjang == 'n'){
                        printf("Terimakasih telah Berbelanja bersama kami!\n");
                        break; 
                    } else {
                        printf("\n");
                        continue;
                    }

            case 4:
            char pilihanList_kranjang;
                edit_kranjang(jumlahKeranjang, sizeof(idBarang)/sizeof(idBarang[0]));
                printf("Barang Berhasil diubah")
                printf("\nKembali ke menu? (Y/N): "); scanf(" %c", &pilihanList_kranjang);
                pilihanList_kranjang = tolower(pilihanList_kranjang);
                    if(pilihanList_kranjang == 'n'){
                        printf("Terimakasih telah Berbelanja bersama kami!\n");
                        break; 
                    } else {
                        printf("\n");
                        continue;
                    }

            case 5:
            int arrayLen_kranjang = sizeof(keranjang)/sizeof(keranjang[0]);
            char pilihanList_kranjang;
            list_kranjang(jumlahKeranjang, arrayLen_barang);
            printf("\nKembali ke menu? (Y/N): "); scanf(" %c", &pilihanList_kranjang);
                pilihanList_kranjang = tolower(pilihanList_kranjang);
                    if(pilihanList_kranjang == 'n'){
                        printf("Terimakasih telah Berbelanja bersama kami!\n");
                        break; 
                    } else {
                        printf("\n");
                        continue;
                    }
            case 6:
            case 7:
            default:
            printf("Salah pilih menu!\n");
            continue;
    }
    }

 
}