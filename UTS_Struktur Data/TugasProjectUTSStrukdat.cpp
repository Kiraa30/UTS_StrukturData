#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;
int nr,isi,ch;
struct node
{
        int norek;
        string nama;
        string alamat;
        int saldo;
        struct node *next;
}*front=NULL,*rear,*temp;

void ins()
{
    temp=new node;
    string alamat;
    string n;
    cout <<" Input NIM\t: ";
    cin >> nr;
    cin.ignore(1,'\n');
    cout <<" Input Nama\t: ";
    getline(cin,n);
    cout << " Input Alamat\t: ";
    getline(cin, alamat);
    cout << " Input Saldo\t: ";
    cin>>isi;
    temp->norek=nr;
    temp->nama=n;
    temp->saldo=isi;
    temp->alamat=alamat;
    temp->next=NULL;

    if(front==NULL)
        front=rear=temp;
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void del()
{
    if(front==NULL)
    {
        cout << " Belum ada mahasiswa\n";
        cout << "Tekan enter untuk kembali ";
        cin.get();
        getch();
    }
    else
    {
        temp=front;
        front=front->next;
        cout << " No.Nim " <<temp->norek << " dihapus beserta datanya\n";
        delete(temp);
        getch();
        cin.get();
    }
}

void dis()
{
    if(front==NULL)
    {
        cout << " Belum ada mahasiswa\n";
        cout << "Tekan enter untuk kembali";
        cin.get();
        getch();
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            cout << "No.NIM\t: " << temp->norek << endl;
            cout << "Nama\t: " << temp->nama << endl;
            cout << "Saldo\t: " << temp->saldo << endl;
            cout << "Alamat\t: " << temp->alamat << endl;
            cout << " ------------------------------- " << endl;
            cout << "Tekan enter untuk kembali ";
            temp=temp->next;
        }
        getch();
        cin.get();
    }
}

void cari()
{
    node *temp;
    temp = front;
    int caridata;
    int ketemu=0;
    if(front!=NULL)
    {
        cout << "\n Input no.NIM yang dicari\t: ";
        cin >> caridata;
        while(temp!=NULL)
        {
            temp->norek;
            if(caridata==temp->norek)
            {
                cout << "\n\n>>> Data Yang Anda Cari Ditemukan <<<" << endl;
                cout << " Nama\t: " << temp->nama << endl;
                cout << " Saldo\t: " << temp->saldo << endl;
                cout << " ----------------------------------" << endl;
                cout << "Tekan enter untuk kembali";
                cout << "\n\n";
                ketemu=1;
            }
            temp=temp->next;
        }
        if(ketemu==0)
        {
            cout << "Data tidak ditemukan\n";
        }
    }
    else
    cout <<" Belum ada mahasiswa\n";
    cout <<"Tekan enter untuk kembali";
    cin.get();
    getch();
}

void cek()
{
    node *temp;
    temp=front;
    int ketemu=0;
    if(front!=NULL)
    {
        cout << "n Input no NIM\t ";
        cin>>nr;
        while(temp!=NULL)
        {
            temp->norek;
            if(nr==temp->norek)
            {
                cout << "--------------------------------------" << endl;
                cout << "Sisa saldo saat ini\t: " << temp->saldo << endl;
                cout << "--------------------------------------" << endl;
                ketemu=1;
            }
            temp=temp->next;
        }
        if(ketemu==0)
        {
            cout << "Data tidak ditemukan";
        }
    }
    else cout <<" Belum ada mahasiswa\n";
    cout <<"Tekan enter untuk kembali ";
    cin.get();
    getch();
}

int main()
{
    int nr,isi,ch;
    do
    {
        cout <<"\n===============================================================";
        cout <<"\n        Program Beasiswa Universitas Karawang New Era          ";
        cout <<"\n===============================================================";
        cout <<"\n                            Menu                               ";
        cout <<"\n===============================================================";
        cout <<"\n 1. Input Data Mahasiswa ";
        cout <<"\n 2. Hapus Data Maahsiswa ";
        cout <<"\n 3. Cek Saldo Mahasiswa ";
        cout <<"\n 4. Tampilkan Daftar Mahasiswa ";
        cout <<"\n 5. Cari Data Mahasiswa ";
        cout <<"\n 6. Keluar ";
        cout <<"\n\n Masukkan Pilihan (1-6): ";
        cin >> ch;
        cout << "\n___________________________________________________________";
        cout << "\n";
        switch (ch)
        {
            case 1:
                ins();
                break;
            case 2:
                del();
                break;
            case 3:
                dis();
                break;
            case 4:
                cari();
                break;
            case 5:
                cek();
                break;
            case 6:
                cout << "-----------EXIT-----------";
                cout << "Made by : 2310631170027 - M. Ilham Syahputra 2C";
                break;
            default :
                cout << "Pilihan tidak valid!";
                break;
        }
    } while(ch != 6);
    return 0;
}
