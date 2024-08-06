#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct KhachHang {
    string hoTen;
    string soDienThoai;
    int soVeNguoiLon;
    int soVeTreEm;
    string tenPhim;
    string phongChieu;
    string xuatChieu;
    int tienPhaiTra;
};

const int GIA_VE_NGUOI_LON = 40000;
const int GIA_VE_TRE_EM = 20000;

// Hàm tính ti?n ph?i tr? c?a khách hàng
void tinhTienPhaiTra(KhachHang &kh) {
    kh.tienPhaiTra = kh.soVeNguoiLon * GIA_VE_NGUOI_LON + kh.soVeTreEm * GIA_VE_TRE_EM;
}

// Hàm d?c danh sách khách hàng t? file
void docDanhSachKhachHang(const string &fileName, vector<KhachHang> &dskh) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Khong the mo file!" << endl;
        exit(1);
    }

    KhachHang kh;
    while (getline(file, kh.hoTen) &&
           getline(file, kh.soDienThoai) &&
           file >> kh.soVeNguoiLon &&
           file >> kh.soVeTreEm &&
           file.ignore() &&
           getline(file, kh.tenPhim) &&
           getline(file, kh.phongChieu) &&
           getline(file, kh.xuatChieu)) {
        tinhTienPhaiTra(kh);
        dskh.push_back(kh);
        file.ignore(); // Ð?c ký t? xu?ng dòng còn l?i
    }
}

// Hàm xu?t danh sách khách hàng
void xuatDanhSachKhachHang(const vector<KhachHang> &dskh) {
    for (const auto &kh : dskh) {
        cout << "Ho ten: " << kh.hoTen << endl;
        cout << "So dien thoai: " << kh.soDienThoai << endl;
        cout << "So ve nguoi lon: " << kh.soVeNguoiLon << endl;
        cout << "So ve tre em: " << kh.soVeTreEm << endl;
        cout << "Ten phim: " << kh.tenPhim << endl;
        cout << "Phong chieu: " << kh.phongChieu << endl;
        cout << "Xuat chieu: " << kh.xuatChieu << endl;
        cout << "Tien phai tra: " << kh.tienPhaiTra << " VND" << endl;
        cout << "------------------------------------" << endl;
    }
}

// Hàm tính t?ng doanh thu c?a r?p phim
int tinhTongDoanhThu(const vector<KhachHang> &dskh) {
    int tongDoanhThu = 0;
    for (const auto &kh : dskh) {
        tongDoanhThu += kh.tienPhaiTra;
    }
    return tongDoanhThu;
}

// Hàm tính t?ng doanh thu c?a t?ng phim
void tinhTongDoanhThuTheoPhim(const vector<KhachHang> &dskh) {
    map<string, int> doanhThuTheoPhim;
    for (const auto &kh : dskh) {
        doanhThuTheoPhim[kh.tenPhim] += kh.tienPhaiTra;
    }
    for (const auto &pair : doanhThuTheoPhim) {
        cout << "Phim: " << pair.first << ", Tong doanh thu: " << pair.second << " VND" << endl;
    }
}

// Hàm xu?t thông tin khách hàng theo phòng chi?u và xu?t chi?u
void xuatThongTinTheoPhongChieuXuatChieu(const vector<KhachHang> &dskh, const string &phongChieu, const string &xuatChieu) {
    for (const auto &kh : dskh) {
        if (kh.phongChieu == phongChieu && kh.xuatChieu == xuatChieu) {
            cout << "Ho ten: " << kh.hoTen << endl;
            cout << "So dien thoai: " << kh.soDienThoai << endl;
            cout << "So ve nguoi lon: " << kh.soVeNguoiLon << endl;
            cout << "So ve tre em: " << kh.soVeTreEm << endl;
            cout << "Ten phim: " << kh.tenPhim << endl;
            cout << "Phong chieu: " << kh.phongChieu << endl;
            cout << "Xuat chieu: " << kh.xuatChieu << endl;
            cout << "Tien phai tra: " << kh.tienPhaiTra << " VND" << endl;
            cout << "------------------------------------" << endl;
        }
    }
}

// Hàm s?p x?p danh sách khách hàng theo s? ti?n ph?i tr? tang d?n
void sapXepTheoTienPhaiTra(vector<KhachHang> &dskh) {
    sort(dskh.begin(), dskh.end(), [](const KhachHang &a, const KhachHang &b) {
        return a.tienPhaiTra < b.tienPhaiTra;
    });
}

// Hàm s?p x?p danh sách khách hàng theo h? tên (a -> z)
void sapXepTheoHoTen(vector<KhachHang> &dskh) {
    sort(dskh.begin(), dskh.end(), [](const KhachHang &a, const KhachHang &b) {
        return a.hoTen < b.hoTen;
    });
}

// Hàm tìm ki?m khách hàng theo tên b?ng thu?t toán Binary Search
int timKiemTheoHoTen(const vector<KhachHang> &dskh, const string &hoTen) {
    auto it = lower_bound(dskh.begin(), dskh.end(), hoTen, [](const KhachHang &kh, const string &name) {
        return kh.hoTen < name;
    });

    if (it != dskh.end() && it->hoTen == hoTen) {
        return distance(dskh.begin(), it);
    }
    return -1;
}

int main() {
    vector<KhachHang> dskh;
    string fileName;

    cout << "Nhap ten file txt: ";
    cin >> fileName;

    docDanhSachKhachHang(fileName, dskh);

    cout << "Danh sach khach hang:" << endl;
    xuatDanhSachKhachHang(dskh);

    cout << "Tong doanh thu cua rap phim: " << tinhTongDoanhThu(dskh) << " VND" << endl;

    cout << "Tong doanh thu theo tung phim:" << endl;
    tinhTongDoanhThuTheoPhim(dskh);

    string phongChieu, xuatChieu;
    cout << "Nhap phong chieu: ";
    cin >> phongChieu;
    cout << "Nhap xuat chieu: ";
    cin >> xuatChieu;
    cout << "Thong tin khach hang theo phong chieu " << phongChieu << " va xuat chieu " << xuatChieu << ":" << endl;
    xuatThongTinTheoPhongChieuXuatChieu(dskh, phongChieu, xuatChieu);

    sapXepTheoTienPhaiTra(dskh);
    cout << "Danh sach khach hang sau khi sap xep theo tien phai tra:" << endl;
    xuatDanhSachKhachHang(dskh);

    sapXepTheoHoTen(dskh);
    cout << "Danh sach khach hang sau khi sap xep theo ho ten:" << endl;
    xuatDanhSachKhachHang(dskh);

    string hoTen;
    cout << "Nhap ho ten khach hang de tim: ";
    cin.ignore(); // Xóa ký t? xu?ng dòng còn l?i
    getline(cin, hoTen);

    int index = timKiemTheoHoTen(dskh, hoTen);
    if (index != -1) {
        cout << "Khach hang " << hoTen << " nam o vi tri: " << index << endl;
    } else {
        cout << "Khong tim thay khach hang " << hoTen << endl;
    }

    return 0;
}

