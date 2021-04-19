/*
1. dem do trai cay
2. tim kiem 
3. thong ke 
4. soa
5. menu
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct TraiCay{
    char MaHang[30];
    char Ten[30];
    int SoLuong ;
    int Gia;
};
void Nhap(TraiCay *traicay);
void Xuat(TraiCay *traicay);
void Nhap (TraiCay *traicay,int &soluong);
void Xuat(TraiCay *traicay, int soluong);
void TimKiemMa(TraiCay *traicay, int soluong);
int TongKho(TraiCay *traicay,int soluong);
void SapXepSoLuong(TraiCay *traicay,int soluong);
void SapXepTen(TraiCay *traicay,int soluong);
void ThongKeSoLuong(TraiCay *Traicay,int soluong);
void ThongkeTen(TraiCay *traicay,int soluong);
void XoaDuLieu (TraiCay *traicay, int soluong,char id [10]);
 void menu(TraiCay *traicay,int soluong,char id[10]);
int main(){
    char id [10];
    int soluong;
    printf("\t\t\t\t==========================================CUA HANG TRAI CAY==========================================\n");
    printf("Nhap so Gio trai cay trung bay: ");
    scanf("%d",&soluong);
    TraiCay *traicay;
    traicay = (TraiCay*)malloc(sizeof(TraiCay));
    Nhap(traicay,soluong);
    menu(traicay,soluong,id);
    if(traicay != NULL)
    free(traicay);
    return 0;
}
void Nhap(TraiCay *traicay){
    fflush(stdin);
    printf("Nhap Ma: ");
    gets(traicay->MaHang);
    printf("Nhap Ten Trai Cay: ");
    gets(traicay->Ten);
    printf("Nhap So Luong : ");
    fflush(stdin);
    scanf("%d",&traicay->SoLuong);
    printf("Nhap Gia: ");
    scanf("%d",&traicay->Gia);
    printf("-------------------------------------------------------------------------------------------------------\n");
}
void Xuat(TraiCay *traicay){
    printf("\t\t\t\t\tMa:%-4s ||ten:%-5s ||So Luong: %-3d||Gia: %-6d\n",traicay->MaHang,traicay->Ten,traicay->SoLuong,traicay->Gia);
    printf("\t\t\t\t\t-----------------------------------------------\n");
}
void Nhap(TraiCay *traicay,int &soluong){
    printf("\n\t\t\t\t==========================================DANH SACH==========================================\n");
    for(int i = 0 ; i <soluong ; i ++){
        Nhap(traicay +i);
    }
}
void Xuat(TraiCay *traicay,int soluong){
    printf("So Gio TRAI CAY co trong trung bay la:\n");
    printf("\t\t\t\t\t-----------------------------------------------\n");
    for (int i = 0 ; i < soluong ; i++){
        Xuat(traicay +i);
    }
}
void TimKiemMa(TraiCay *traicay,int soluong){
    char name[30];
    int count= 0;
    printf(" Ma Trai Cay can tim: ");
    fflush(stdin);
    gets(name);
    for(int i = 0 ; i < soluong;i++){
        if(strcmp(name,(traicay+i)->MaHang)==0){
            printf("\t\t\t\t**\tMa: %-4s||Ten : %-5s||So Luong:%-3d||Gia: %-6d   **\n",(traicay + i)->MaHang,(traicay +i)->Ten,(traicay +i)->SoLuong,(traicay +i)->Gia);
            count ++;
        }
    }
    if(count == 0){
        printf("=>>KHONG CO TRAI CAY TRONG KHO.!");
    }
}
int  TongKho(TraiCay *traicay,int soluong){
    int sum = 0;
    for(int i = 0 ; i < soluong ; i++){
        sum = sum +((traicay + i)->SoLuong);
    }
    printf("\nTong so Trai Cay trong kho: %d\n",sum);
    return sum;
}
void SapXepSoLuong(TraiCay *traicay,int soluong){
    TraiCay temp ;
    for(int i = 0 ; i < soluong ; i ++){
        for (int j = i+1 ; j<soluong; j++){
            if((traicay +i)->SoLuong >(traicay+j)->SoLuong){
                    temp = *(traicay+i);
                    *(traicay +i) = *(traicay +j);
                    *(traicay +j) = temp;
            }
        }
    }
}
void SapXepTen(TraiCay *traicay,int soluong){
    TraiCay temp ;
    for(int i = 0 ; i < soluong ; i ++){
        for (int j = i+1 ; j<soluong; j++){
               if(strcmp((traicay +i)->Ten,(traicay+j)->Ten)>0){
                    temp = *(traicay+i);
                    *(traicay +i) = *(traicay +j);
                    *(traicay +j) = temp;
            }
        }
    }
}
void ThongKeSoLuong(TraiCay *traicay,int soluong){
    SapXepSoLuong(traicay,soluong);
    printf("\t\t\t\t-------------------------------------------------------------------------------------------------------\n");
    for(int i = 0 ; i < soluong ; i ++){
        printf("\t\t\t\tSo Luong:%-5d||Ma: %-4s||Ten : %-6s||Gia: %-10d\n",(traicay +i)->SoLuong,(traicay + i)->MaHang,(traicay +i)->Ten,(traicay +i)->Gia);
        printf("\t\t\t\t************************************************\n");
    }
}
void ThongkeTen(TraiCay *traicay,int soluong){
    SapXepTen(traicay,soluong);
    for(int i = 0 ; i <soluong; i ++){
        printf("\t\t\t\tTen : %-8s||Ma: %-4s||So Luong:%-3d||Gia: %-6d\n",(traicay+i)->Ten,(traicay + i)->MaHang,(traicay +i)->SoLuong,(traicay +i)->Gia);
        printf("\t\t\t\t************************************************\n");
    }
    printf("\t\t\t\t-------------------------------------------------------------------------------------------------------\n");
}
void XoaDuLieu (TraiCay *traicay, int soluong,char id [10]){
    bool check = false;
    printf("Nhap Ma can xoa: ");
    fflush(stdin);
    gets(id);
    for (int i=0; i< soluong; i++ ){
        if(strcmp(id,(traicay+i)->MaHang)==0){
            for(int j = i ; j <soluong -1;j++){
                *(traicay +j) = *(traicay +j+1);
                     check=true;
            }
             (traicay--);
        }
    }
    if(check){
        printf("\t\t\t\t XOA MA THANH CONG.\n");
    }
    else printf("\n\t\t\t\t MA KHONG TON TAI\n");
}
void menu(TraiCay *traicay,int soluong,char id[10]){
    int choise ;
    char k , c ;
    do{
        printf("\t\t\t\t\t\t |====================================| \n");
        printf("\t\t\t\t\t\t |1.Xuat Danh sach da nhap:           | \n");
        printf("\t\t\t\t\t\t |2. Tim kiem Ma trong kho:           | \n");
        printf("\t\t\t\t\t\t |3. Tong so sach trong kho:          | \n");
        printf("\t\t\t\t\t\t |4.Thong ke trai cay theo so luong:  | \n");
        printf("\t\t\t\t\t\t |5.thong ke trai cay theo ten:       | \n");
        printf("\t\t\t\t\t\t |6. Xoa theo ma trai cay da nhap:    | \n");
        printf("\t\t\t\t\t\t |====================================| \n");
        printf("\t\t\t\t\t\t              ban chon:");
        scanf("%d",&choise);
        switch(choise){
            case 1 :
                Xuat(traicay,soluong);
                break;
            case 2 :
                TimKiemMa(traicay , soluong);
                break;
            case 3 :
                TongKho(traicay, soluong);
                break;
            case 4 :
                ThongKeSoLuong(traicay,soluong);
                break;
            case 5 :
                ThongkeTen(traicay,soluong);
                break;
            case 6 :
                XoaDuLieu(traicay,soluong,id);
                Xuat(traicay,soluong);
                break;
            default :
                printf("KHONG HOP LE, vui long nhap lai!\n");
                break;
        }
        printf("ban muon THOAI khoi chuong trinh ?(esc)");
        k = getch();
        c = k ;
    }while(c!= 27);
}
