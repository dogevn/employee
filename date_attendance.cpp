#include "date_attendance.h"
#include "employee.h"

int format_tt(string tt)    // check format diem danh
{
    if (tt == "DL" || tt == "DLNN" || tt == "N" || tt == "NP")
        return 1;
    else return 0;
}
void getDatacsv(string file)
{
    ofstream myfile(file, ios::in);
    if (myfile.is_open())
    {
        string id, tt;
        cout << "Nhap ma nhan vien \n";
        getline(cin, id);
        while (testId(file, id))
        {
            cout << "Ma so nhan vien khong khong ton tai\n";
            cout << "Moi nhap lai ma nhan vien: ";
            getline(cin, id);
        }
        int n;
        Employee e = searchEmployee(file, id);
        print(e);
        cout << "===Diem Danh====\n";
        cout << "So ngay diem danh \n";

        cin >> n;

        cin.ignore();

        for (int i = 0; i < n; i++)          //
        {
            cout << "Nhap ngay thang diem danh ";
            getline(cin, e.Date[i].Date);
            while (valiDate(e.Date[i].Date) == 0)
            {
                cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
                cout << "Nhap ngay thang diem danh: ";
                getline(cin, e.Date[i].Date);
            }
            cout << "1.DL: Di lam \n2.DLNN: di lam nua ngay \n3.N: nghi\n4.NP: nghi phep \n";
            getline(cin, e.Date[i].Trang_thai);
            string tt = e.Date[i].Trang_thai;
            while (format_tt(tt) == 0)
            {
                cout << "Ban chua nhap dung dinh dang , VD: NL\n";
                getline(cin, e.Date[i].Trang_thai);
                tt = e.Date[i].Trang_thai;
            }
            //
            //Check xem co bi Diem danh trung ngay khong
            //
             // check trong qua trinh nhap
            for (int x = 0; x < i - 1; x++)
                for (int y = x + 1; y < i; y++)
                {
                    if (e.Date[x].Date == e.Date[y].Date)
                    {
                        cout << e.Date[y].Date << " Da duoc diem danh, ban co muon ghi de len khong ?\n";
                        int k;
                        bool key = true;
                        cout << "1. Co\n2. Khong\nNhap 1 hoac 2";
                        cin >> k;
                        while (key)
                        {
                            if (k == 1)key = false;
                            if (k == 2)
                            {
                                getline(cin, e.Date[y].Trang_thai);
                                int temp = x;
                                x = temp;
                                key = false;
                            }
                        }

                    }
                }
            //check trong file(Chua code)

        }
        myfile << e.id << "," << e.name << "," << e.birthday << "," << e.adress << "," << e.team;
        for (int i = 0; i < n; i++)
        {
            myfile << ',' << e.Date[i].Date << ':' << e.Date[i].Trang_thai;
            if (i == n - 1)myfile << endl;
        }                                                                                                  // iN RA CO DANG mAC,Nguyen Tien Dat,20 01 2001,42,admin10 02 2020:N,12 8 2020:DL
    }
    else cout << "Mo file that bai. TIP: Kiem tra duong dan hoac Chay chuong trinh voi quyen admin\n";

}