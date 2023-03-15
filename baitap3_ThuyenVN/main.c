/*
bai 3

Xây dựng chương trình quản lý công ty đa cấp sử dụng cấu trúc m-ary tree. Mỗi nhân viên của công ty gồm các thông tin: id, tên, doanh số bán hàng. Công ty là nút gốc với id = 0, tên là tên công ty, doanh số bán = 0. Có tối đa 10 nhân viên cấp 1 là các nút con trực tiếp của công ty. Mỗi nhân viên có một hệ thống chân rết gồm tối đa 10 nhân viên cấp dưới. Chương trình có các tính năng sau:
1. Thêm nhân viên vào công ty bằng cách nhập id của nhân viên cấp trên và các thông tin của nhân viên cần thêm. 
2. Tính thu nhập của nhân viên theo id. Doanh số bán hàng của nhân viên cấp thấp nhất là doanh số trừ đi 30%. Thu nhập của nhân viên cấp trên bằng 70% của (doanh số + tổng 30% thu nhập của nhân viên cấp dưới trực tiếp). Ví dụ nhân viên A (doanh số 1000) quản lý 3 nhân viên cấp dưới cùng B, C, D đều có doanh số 1000. Thu nhập của B, C, D mỗi người là 700. Thu nhập của A = 70% x (1000 + 300 + 300 +300) = 1330 và A phải nộp lên trên là 570.
3. In thông tin của toàn bộ nhân viên trong công ty.
*/
 

 int main()
 {
 	return 0;
 }