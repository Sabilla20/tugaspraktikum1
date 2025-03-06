#include <iostream>
using namespace std;

void inputData();
void tampilkanData();
void bubbleSort();
// void quickSort();
void sequentialSearch();

struct kendaraan{
    int plat;
    string jenis;
    string merk;
    string model;
    string nama;
    int tahun;
};
kendaraan kdr[100];
int jumlahkdr =0;

void inputData(){
    int jumlah;
    cout<<"Masukkan Jumlah Data yang Ingin Diinputkan: ";
    cin>>jumlah;

    if (jumlahkdr + jumlah >100){
        cout<<"Data yang diinputkan melebihi kapasitas"<<endl;
        return;
    }
    for (int i=0; i<jumlah; i++){
        cout<<"Masukkan nomor plat kendaraan ke-"<<(jumlahkdr+1)<<": ";
        cin>>kdr[jumlahkdr].plat;
        cout<<"Masukkan jenis kendaraan ke-"<<(jumlahkdr+1)<<": ";
        cin>>kdr[jumlahkdr].jenis;
        cout<<"Masukkan merk kendaraan ke-"<<(jumlahkdr+1)<<": ";
        cin>>kdr[jumlahkdr].merk;
        cout<<"Masukkan model kendaraan ke-"<<(jumlahkdr+1)<<": ";
        cin>>kdr[jumlahkdr].model;
        cout<<"Masukkan nama pemilik kendaraan ke-"<<(jumlahkdr+1)<<": ";
        cin>>kdr[jumlahkdr].nama;
        cout<<"Masukkan tahun produksi kendaraan ke-"<<(jumlahkdr+1)<<": ";
        cin>>kdr[jumlahkdr].tahun;
        jumlahkdr++;
        cout<<"\n";
    }
    cout<<"--- Data Kendaraan Telah Berhasil Ditambahkan. ---"<<endl;
}

void tampilkanData(){
    if (jumlahkdr == 0){
        cout <<"Belum ada data yang ditambahkan."<<endl;
    }else {
        cout<<"=== Data Kendaraan === "<<endl;
        for(int i=0; i<jumlahkdr; i++){
            cout<<"Data Kendaraan ke- "<<i+1<<":"<<endl;
            cout<<"Nomor Plat Kendaraan: "<<kdr[i].plat <<endl;
            cout<<"Jenis Kendaraan: "<<kdr[i].jenis <<endl;
            cout<<"Merk Kendaraan: "<<kdr[i].merk <<endl;
            cout<<"Model Kendaraan: "<<kdr[i].model <<endl;
            cout<<"Nama Pemilik Kendaraan: "<<kdr[i].nama <<endl;
            cout<<"Tahun Produksi Kendaraan: "<<kdr[i].tahun<<endl;
            cout<<"============================================"<<endl;
        }
    }
}

void bubbleSort(){
        for (int i = 0; i < jumlahkdr - 1; i++) {
            for (int j = 0; j < jumlahkdr - i - 1; j++) {
                if (kdr[j].tahun > kdr[j + 1].tahun) {
                    swap(kdr[j], kdr[j + 1]);
                }
            }
        }
        cout << "--- Data Kendaraan Telah Diurutkan Berdasarkan Tahun Produksi ---\n";
        tampilkanData();
    }
    
// void quickSort(){
//     int partition (int low, int high){
//         int pivot = kdr[high].tahun;
//         int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (kdr[j].tahun < pivot) {
//             i++;
//             swap(kdr[i], kdr[j]);
//         }
//     }
//     swap(kdr[i + 1], kdr[high]);
//     return i + 1;
// }

// void quickSort(int low, int high) {
//     if (low < high) {
//         int pi = partition(low, high);
//         quickSort(low, pi - 1);
//         quickSort(pi + 1, high);
//     }
//     }
// }

void sequentialSearch(){
    string cariNama;
    bool found = false;
    cout<<"Masukkan Nama Pemilik Kendaraan yang Ingin Anda Cari: ";
    cin>>cariNama;

    for(int i=0; i<jumlahkdr; i++){
        if (kdr[i].nama==cariNama){
            cout<<"==============="<<endl;
            cout<<"Nama Pemilik Kendaraan Telah Ditemukan"<<endl;
            cout<<"==============="<<endl;
            cout<<"Nomor Plat Kendaraan: "<<kdr[i].plat<<endl;
            cout<<"Jenis Kendaraan: "<<kdr[i].jenis<<endl;
            cout<<"Merk Kendaraan: "<<kdr[i].merk<<endl;
            cout<<"Model Kendaraan: "<<kdr[i].model;
            cout<<"Nama Pemilik Kendaraan: "<<kdr[i].nama<<endl;
            cout<<"Tahun Keluaran Kendaraan: "<<kdr[i].tahun<<endl;
            cout<<"\n";
            found=true;
            break;
        }
    }
    if (!found){
        cout<<"Data dengan Nama Pemilik: "<<cariNama<<"Tidak Ditemukan!"<<endl;
    }
}

int main(){

    int pilihan;
    do {
        cout << "=== Menu ===" << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Tampilkan Seluruh Data Kendaraan" << endl;
        cout << "3. Urutkan Data Kendaraan (Bubble Sort)" << endl;
        cout << "4. Urutkan Data Kendaraan (Quick Sort)" << endl;
        cout<< "5. Cari Data Kendaraan (Sequential Search)"<<endl;
        cout<<"6. Keluar"<<endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                bubbleSort();
                break;
            // case 4:
            //     quickSort();
            //      break;
            case 5:
                sequentialSearch();
                break;
            case 6:
                cout << "Keluar " << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silahkan coba lagi" << endl;
        }
    } while (pilihan != 5);

    return 0;
}