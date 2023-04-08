/**
* @file           main.cpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/


#include <iostream>
#include<iomanip>
#include"YoneticiListesi.hpp"
#include<string>
#include<fstream>
#include<algorithm>
#include<fstream>
#include <sstream>
#include <vector>
using namespace std;



int main()
{
    srand((unsigned)time(NULL));
    ifstream file("./doc/veriler.txt"); //okunacak dosyanın tutulduğu yer.
    string line;
    YoneticiListesi* YoneticiListesi1 = new YoneticiListesi;  //heap den alan alarak boş bir YöneticiListesi oluşturuluyor.
    while (getline(file, line)) //dosyadaki sayıları okumak için getline komutu ile satır oldukça while içerisine girmeye devam ediyor.
    {   
        
        istringstream is(line);
        int numberOnLine;

        is >> numberOnLine;
        vector<int> myvec;  
        while (is)
        {
            myvec.push_back(numberOnLine);
            is >> numberOnLine;
        }

        for (int i = 0; i < myvec.size(); ++i) 
        {
            if (i == 0)
            {
                YoneticiListesi1->ekle(); //YoneticiListesi' ne YoneticiDugum u ekler. Ardından bu Dugume Bir SatirListesi Oluşturur.
                YoneticiListesi1->SatiRliste->ekle(myvec.at(i)); // Oluşturulan SatirListesine Dugum ekler.
            }
            else
            {
                YoneticiListesi1->SatiRliste->ekle(myvec.at(i)); // Oluşturulan SatirListesine Dugum ekler.
            }
            YoneticiListesi1->aritmetik(); // YoneticiListesindeki YoneticiDugumlerini Sıralar.
            
        }

        cout << endl;


    }
    YoneticiListesi1->Siralama(); // YoneticiListesindeki YoneticiDugumlerini Sıralar.
    
    string islem;
    
    
    do
    {   
        system("cls");
        cout <<* YoneticiListesi1; // Oluşturulan YöneticiListesini ekrana yazdırır.
        cin >> islem; // Kullanıcıdan yapmasını istediği işlem istenir.
        if (islem == "a" || islem == "A") // Eğer Yapılmak İstenen İşlem "a" veya "A" İse
        {
            
            if (YoneticiListesi1->secililiste > 7) // Eğer ilk sekizlide değilse buraya girer.
            {
                YoneticiListesi1->sekizli--; // sekizli sayısını 1 azaltır.
                YoneticiListesi1->secililiste = 0; 
                YoneticiListesi1->secililiste += 8 * YoneticiListesi1->sekizli; // SeciliListeyi ekrandaki sekizlinin ilk düğümüne atar. 
            }
            else
            {
                YoneticiListesi1->secililiste = 0;  // Eğer ilk sekizlide ise secililisteyi ilk düğüme atar.
            }
            
            
            system("cls");

        }
        if (islem == "d" || islem == "D") // Eğer Yapılmak İstenen İşlem "d" veya "D" İse
        {
            if (YoneticiListesi1->dugumsayisi > YoneticiListesi1->sekizli * 8 + 8) // Eğer sekizli son sekizlide değil ise buraya girer.
            {
                YoneticiListesi1->sekizli++; // sekizli sayısını 1 artırır.
                YoneticiListesi1->secililiste = 0;
                YoneticiListesi1->secililiste += 8*YoneticiListesi1->sekizli; // secililisteyi ekrandaki yeni sekizlinin ilk düğümüne atar.
            }
            else
            {
                YoneticiListesi1->secililiste = YoneticiListesi1->dugumsayisi -1; // Eğer ki son sekizlide ise secililisteyi son düğüme atar.
            }
            system("cls");
        }
        if (islem == "c" || islem == "C") // Eğer Yapılmak İstenen İşlem "C" veya "c" İse
        {   
            if (YoneticiListesi1->secililiste <((YoneticiListesi1->sekizli+1)*8)-1&& YoneticiListesi1->secililiste <YoneticiListesi1->dugumsayisi-1)
            // Toplam Düğüm Sayısı secili listeden fazlaysa ve secililiste ekrandaki sekizli içerisinde eğer ve sekizlinin son düğümünde değilse buraya girer. 
            {
                YoneticiListesi1->secililiste++; // secililiste yi 1 artırır.
            }
            else if (YoneticiListesi1->dugumsayisi > YoneticiListesi1->secililiste) // Toplam Düğüm sayısı secili listeden fazlaysa girer. 
            {
                if (YoneticiListesi1->dugumsayisi > YoneticiListesi1->sekizli * 8 + 8) // Ekrandaki Sekizlinin son düğümünden sonra düğüm varsa buraya girer.
                {
                    YoneticiListesi1->sekizli++; // sekizliyi artırır.
                    YoneticiListesi1->secililiste = 0;
                    YoneticiListesi1->secililiste += 8 * YoneticiListesi1->sekizli; // secililisteyi yeni sekizlinin ilk düğümüne atar.
                }
            }
            system("cls");
        }
        if (islem == "z" || islem == "Z")// Eğer Yapılmak İstenen İşlem "z" veya "Z" İse
        {
            if (YoneticiListesi1->secililiste >0 && YoneticiListesi1->secililiste % 8!=0) // secili liste ilk liste değil ve secili liste sekizlinin ilk düğümü değilse buraya girer.
            {
                YoneticiListesi1->secililiste --; // secili listeyi 1 azaltır.
            }
            else if (YoneticiListesi1->secililiste > 0) // secili liste ilk liste değilse buraya girer.
            {
                if (YoneticiListesi1->sekizli != 0) // sekizli ilk sekizliye eşit değilse buraya girer.
                {
                    YoneticiListesi1->sekizli--; // sekizliyi 1 azaltır.
                    YoneticiListesi1->secililiste = 7;
                    YoneticiListesi1->secililiste += 8 * YoneticiListesi1->sekizli; //secili listeyi ekrandaki sekizlinin en sağına atar. 
                }
                system("cls");
                cout <<* YoneticiListesi1; // Oluşturulan YöneticiListesini ekrana yazdırır.
            }
            system("cls");
        }
        if (islem == "k" || islem == "K") // Eğer Yapılmak İstenen İşlem "k" veya "K" İse
        {
            YoneticiListesi1->SeciliListeDugumSayisiBulma(); // Secili SatirListesinde kaç düğüm olduğunu bulur.
            int random = 1 + rand() % YoneticiListesi1->secililistededugumsayi ; // SatirListesindeki Sayı ve 0 arasında rastgele 1 sayı üretir.
            YoneticiListesi1->kacsilinsin = random-1; // kacsilinsin e random üretilen sayıyı atar.
            system("cls");
            cout <<* YoneticiListesi1; // Oluşturulan YöneticiListesini ekrana yazdırır.
            string islem2;
            cin >> islem2;

            if (islem2 == "k" || islem == "K") // Eğer Yapılmak İstenen İşlem "k" veya "K" İse  
            {
                YoneticiListesi1->YoneticiSeciliListebulma(); // YoneticiListesindeki secili lİSTEyi bulma Fonksiyonu
                bool kontrol = true;
                if (YoneticiListesi1->SeciliListe->sonraki == YoneticiListesi1->son) //Eğer ki seçili Düğüm sekizlinin son düğümüyse ve sekizliden sonra sadece 1 düğüm varsa girer
                {
                    kontrol = false;
                }
                YoneticiListesi1->RastgeleDugumSil(); // YoneticiListesindeki RastgeleDugumSil fonksiyonunu çağırır.
                if (YoneticiListesi1->dugumsayisi > 0) // Eğer düğüm sayısı 0 dan fazlaysa buraya girer.
                {
                    YoneticiListesi1->aritmetik(); // YoneticiListesindeki Aritmetik fonksiyonunu çağırır.
                    YoneticiListesi1->Siralama(); // YoneticiListesindeki Siralama fonksiyonunu çağırır.
                }
                
                if ( kontrol&&YoneticiListesi1->dugumsayisi % 8  == 0&& YoneticiListesi1->dugumsayisi == YoneticiListesi1->secililiste + 1 && YoneticiListesi1->son->sonraki == 0 &&YoneticiListesi1->secililistededugumsayi == 1 )
                //  seçili listedeki satır sayısı tek ve seçili liste ekrandaki sekizlinin ilk düğümü ise buraya girer.
                {
                    YoneticiListesi1->sekizli--; // sekizliyi 1 azaltır.
                   
                }
            }
            YoneticiListesi1->kacsilinsin = -1; // kaç ssilinsin i tekrardan -1 yapar.  
            system("cls");
            
        }
        if (islem == "p" || islem == "P") // Eğer Yapılmak İstenen İşlem "p" veya "P" İse
        {
            YoneticiListesi1->YoneticiSeciliListebulma(); // YoneticiListesindeki secili lİSTEyi bulma Fonksiyonu
            bool kontrol = true;
            if (YoneticiListesi1->SeciliListe->sonraki == YoneticiListesi1->son) //Eğer ki seçili Düğüm sekizlinin son düğümüyse ve sekizliden sonra sadece 1 düğüm varsa girer
            {
                kontrol = false;
            }
            YoneticiListesi1->SeciliListeDugumSayisiBulma(); // Secili SatirListesinde kaç düğüm olduğunu bulur.
            YoneticiListesi1->kacsilinsin = YoneticiListesi1->secililistededugumsayi - 1; // kaç silinsine Satırlistesindeki son düğümü atar.
            int kactane = YoneticiListesi1->secililistededugumsayi;  // SatırListesinde Kaç düğüm var bulur var kactane ye atar.
            
            for (int i = 0; i < kactane; i++) // Satır Listesinde ki düğüm kadar for döndürür.
            {
                YoneticiListesi1->secililistededugumsayi--; // Seçili Listedeki Düğüm Sayısını 1 azaltır.
                YoneticiListesi1->RastgeleDugumSil(); // Rastgele Düğüm Sil fonksiyonunu çağırır.
                YoneticiListesi1->kacsilinsin--; // Kaç silinsini 1 azaltır.
                
                
                
            }
            if (kontrol && YoneticiListesi1->dugumsayisi % 8 == 0 && YoneticiListesi1->dugumsayisi == YoneticiListesi1->secililiste + 1 && YoneticiListesi1->secililistededugumsayi == 0)
                // Silinen Düğüm ekrandaki sekizlinin ilk düğümü ise buraya girer.
            {
                YoneticiListesi1->sekizli--; // ekrandaki sekizli yi 1 azaltır.

            }
            if (YoneticiListesi1->dugumsayisi > 0) // Düğüm Sayısı 0 dan fazlaysa buraya girer.
            {
                YoneticiListesi1->aritmetik(); // YoneticiListesindeki Aritmetik fonksiyonunu çağırır.
                YoneticiListesi1->Siralama(); // YoneticiListesindeki Siralama fonksiyonunu çağırır.
            }
            
            
            YoneticiListesi1->kacsilinsin = -1; // kacsilinsini tekrardan -1 yapar.
        }
        if (YoneticiListesi1->dugumsayisi == 0) // Hiçbir Düğüm kalmadıysa buraya girer.
        {
            delete YoneticiListesi1; // oluşturulan YöneticiListesini Siler. Böylelikle Heap den alınan bütün alanlar serbest bırakılmış olur.
            system("cls");
            cout << "YoneticiListesinde Dugum Kalmadi!!!" << endl << "Olusturulan YoneticiListesi Silindi ve Heap den Alinan Butun Alanlar Serbest Birakildi."<<endl;
            break;
            
        }
        
       
    } while (true);
}

