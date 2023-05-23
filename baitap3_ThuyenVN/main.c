/****
bai 3
Xây dựng chương trình quản lý công ty đa cấp sử dụng cấu trúc m-ary tree. Mỗi nhân viên của công ty gồm các thông tin: id, tên, doanh số bán hàng. 
Công ty là nút gốc với id = 0, tên là tên công ty, doanh số bán = 0. Có tối đa 10 nhân viên cấp 1 là các nút con trực tiếp của công ty. 
Mỗi nhân viên có một hệ thống chân rết gồm tối đa 10 nhân viên cấp dưới. Chương trình có các tính năng sau:
1. Thêm nhân viên vào công ty bằng cách nhập id của nhân viên cấp trên và các thông tin của nhân viên cần thêm. 
2. Tính thu nhập của nhân viên theo id. Doanh số bán hàng của nhân viên cấp thấp nhất là doanh số trừ đi 30%. 
    Thu nhập của nhân viên cấp trên bằng 70% của (doanh số + tổng 30% thu nhập của nhân viên cấp dưới trực tiếp). 
    Ví dụ nhân viên A (doanh số 1000) quản lý 3 nhân viên cấp dưới cùng B, C, D đều có doanh số 1000. Thu nhập của B, C, D mỗi người là 700.
    Thu nhập của A = 70% x (1000 + 300 + 300 +300) = 1330 và A phải nộp lên trên là 570.
3. In thông tin của toàn bộ nhân viên trong công ty.
****/
#include "function.h"

 int main()
 {
    inf company = creat_company();
    action action;

    while(1)
    {
        action = 0;
        do{
        printf("Hanh dong muon thuc hien\n1 . Them nhan vien vao cong ty \n2. Tinh thua nhap cua nhan vien theo ID.\n3.In thong tin cua toan bo nhan vien\n");
        scanf("%d", &action);
        } while(action != 1 && action != 2 && action != 3);

        switch(action)
        {
            case add :
                printf("DangLHb DEBUG enter add\n");
                add_staff(company);
            break;
            case income:
                income_base_on_id(company);
            break;
            case print:
                print_tree(company,company);
            break;
            default:
            break;
        }
    }
    return 0;
 }