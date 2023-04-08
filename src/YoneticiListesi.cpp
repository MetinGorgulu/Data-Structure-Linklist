/**
* @file           YoneticiListesi.cpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"
#include <iomanip>
#include <iostream>



YoneticiListesi::YoneticiListesi()
{
    // başlangıçta kurucu fonksiyonla gerekli atamalar yapılıyor.
	dugumsayisi = 0;
	ilk = 0;
    sekizli = 0;
    secililiste =0;
    kacsilinsin = -1;
}
YoneticiListesi::~YoneticiListesi()
{
    
}
void YoneticiListesi::ekle()
{	
    SatirListesi* SatirListesi1= new SatirListesi; // Heap den SatırListesi İçin Alan Alınıyor.
    SatiRliste = SatirListesi1; // SatiRliste Pointer ına Alınan Alanın Adresi Atanıyor.
    dugumsayisi ++; // dügüm sayısını belirten int 1 artırılıyor.
    YoneticiDugum* yeniDugum = new YoneticiDugum(SatirListesi1); // Heap den YoneticiDugumu İçin Alan Alınıyor.
    if (ilk == 0) // Eğer İlk YoneticiDüğümü İse Girer.
    {
        ilk = yeniDugum; // ilk e atar bu YöneticiDüğümünü.
        son = yeniDugum; // son a atar bu YöneticiDüğümünü.
        
    }
    else
    {
        YoneticiDugum* sonDugumuBul = ilk; // Son düğümü bulmak için pointer oluşturulur.
        while (sonDugumuBul->sonraki != 0) //son düğüm bulunana kadar girer.
        {
            sonDugumuBul = sonDugumuBul->sonraki;
        }
        yeniDugum->onceki = sonDugumuBul; //yeni düğümün öncesine sondügümü atar.
        sonDugumuBul->sonraki = yeniDugum; // son düğümün sonrasına yeni düğüme atar.
        son = yeniDugum; // son a Yeni Düğümü atar.
        

    }
    yeniDugum->bagliSatirListesi->ilk = SatiRliste->ilk; // oluşturulan yeni düğümün bağlı satır listesindeki ilk düğüme Satır Listesinin İlk düğümü atanır.
   
}
void YoneticiListesi::aritmetik()
{
    YoneticiDugum* yoneticiDugumgec = ilk; // ilk YöneticiDüğümü Gösteren Pointer Oluşturulur.
    do
    {
        int kacdugum = 1;
        float toplam = 0;
        Dugum* gecDugum = yoneticiDugumgec->bagliSatirListesi->ilk; // Yönetici Düğümün SatırListesindeki İlk düğüm için Düğüm tipinde Pointer Oluşturulur.
        while (gecDugum->sonraki!=0) // düğüm ün en sonuncusuna gidene kadar devam eder.
        {
            gecDugum = gecDugum->sonraki;
            kacdugum++; // düğüm sayısını artırır.
        }
        gecDugum = yoneticiDugumgec->bagliSatirListesi->ilk; // tekrardan düğümü SatırListesinin İlkine Atar.
        for (int i = 0; i < kacdugum; i++) // Kaç tane Düğüm varsa O kadar for Döndürür.
        {
            toplam += gecDugum->veri; // toplam verisine düğüm içindeki veriyi ekler. 
            if (gecDugum->sonraki == 0) // eğer düğüm son düğümse girer.
                break;
            gecDugum = gecDugum->sonraki;

        }
        toplam = toplam / kacdugum; // toplam sayısını kaç tane düğüm varsa böler.
        yoneticiDugumgec->aritm = toplam; // bölüm sonucu çıkan sayıyı Yönetici Düğümün aritm verisine atar.
        if (yoneticiDugumgec->sonraki == 0) // Yönetici Düğüm son düğüm ise girer.
            break;
        yoneticiDugumgec = yoneticiDugumgec->sonraki;
    } while (true);
}
void YoneticiListesi::Siralama()
{
    YoneticiDugum* sirala = ilk; // YöneticiDüğümün ilk i için pointer oluşturulur.
    bool kontrol = true;
    while (kontrol) // kontrol true oldukça devam eder.
    {   
        sirala = ilk; // sirala YöneticiDüğümü tipindeki pointer a ilk düğümün adresini atar.
        while (sirala->sonraki != 0) // sirala pointerı son Yonetici Düğümünü Gösterene kadar Devam eder.
        {   
            if (sirala->aritm > sirala->sonraki->aritm) // sirala YöneticiDüğümü içindeki aritm siralanın Sonrakindeki aritm den fazlaysa girer.
            {
                YoneticiDugum* yedeksonraki = sirala->sonraki; //siralanin sonraki için yedek pointer oluşturur.
                YoneticiDugum* yedekonceki = sirala->onceki; //siralanin önceki için yedek pointer oluşturur.
                
                sirala->onceki = sirala->sonraki;  // sirala nin öncekine siralanın sonrakini atar.
                sirala->sonraki = sirala->sonraki->sonraki; // siralanın sonrakine siralanın sonrakinin sonrakini atat.
                yedeksonraki->onceki = yedekonceki; // yedeksonraki nin öncekine yedekönceki atanır. 
                yedeksonraki->sonraki = sirala; // yedeksonraki nin sonrakine sıralayı atar. 
                if (yedekonceki != 0) // Eğer yedekonceki 0 değilse girer.
                {
                    yedekonceki->sonraki = yedeksonraki; // yedekoncekinin sonrakine yedeksonrakiyi atar. 
                }
                if (sirala->sonraki != 0)  // sirala nin sonraki 0 değilse girer
                {
                    sirala->sonraki->onceki = sirala; // sirala nın  sonraki nin önceki ne siralayı atar.
                }
                while (sirala->onceki != 0) // sıralanın önceki 0 a eşit olana kadar dönmeye devam eder. 
                {

                    sirala = sirala->onceki; 
                    ilk = sirala; // ilk YöneticiDüğümüne Sıralayı atar.

                }
                while (sirala->sonraki != 0) // sıralanın sonraki 0 a eşit olana kadar dönmeye devam eder. 
                {

                    sirala = sirala->sonraki;
                    son = sirala; // son YöneticiDüğümüne Sıralayı atar.

                }
                sirala = ilk; // sıralayı ilk e atar tekrardan.
            }
            else
            {
                sirala = sirala->sonraki;
            }
            
            
        }
        sirala = ilk;
        while (true) // break komutu görene kadar sürekli döner.
        {   
            if (sirala->sonraki == 0) //siralanın sonraki 0 a eşit ise girer.
            {
                kontrol = false;
                break;
            }
            if (sirala->aritm < sirala->sonraki->aritm) // sırala nın aritm verisi sırala dan sonraki aritm verisinden küçükse girer.
            {
                kontrol = true;
                if (sirala->sonraki == 0) //sirala nın sonraki 0 a eşitse girer.
                {
                    kontrol = false;
                    break;
                }
                
            }
            sirala = sirala->sonraki;
          
        }
        
    }
}
void YoneticiListesi::SeciliListeDugumSayisiBulma() 
{
    secililistededugumsayi = 1; // seçili Listedeki Düğüm sayısını tutan int değerini 1 yapar.
    int secililistekac = secililiste; 
    YoneticiDugum* seciliYoneticiDugum = ilk; // İlk YöneticiDüğümünü Gösteren Pointer Oluşturulur.
    for (int i = 0; i < secililistekac; i++) // Seçili liste kaç ise  o kadar döndürür.
    {
        seciliYoneticiDugum = seciliYoneticiDugum->sonraki;
    }
    Dugum* listeDugum = seciliYoneticiDugum->bagliSatirListesi->ilk; // Seçili Yönetici Düğümün SatırListesindeki İlk Düğümü Gösteren Pointer Oluşturulur.
    while (listeDugum->sonraki!=0) // ilk düğümü gösteren pointer ın sonraki 0 olana kadar girer
    {
        secililistededugumsayi++; // seçili listedeki düğüm sayısını gösteren değeri 1 artırır
        listeDugum = listeDugum->sonraki;
    }
    
}
void YoneticiListesi::YoneticiListesiniSil(int silinecekliste)
{
    int secililistekac = silinecekliste; 
    YoneticiDugum* seciliYoneticiDugum = ilk; // İlk YöneticiDüğümü Gösteren Pointer Atar.
    for (int i = 0; i < secililistekac; i++) // seçilistekaç ise o kadar döndürür.
    {
        seciliYoneticiDugum = seciliYoneticiDugum->sonraki;
    }
    Dugum* silDugum = seciliYoneticiDugum->bagliSatirListesi->ilk; // Seçili Yöneticiği düğümdeki Satır Listesinin İlk Düğümünü Gösteren Pointer.
    bool dugumbitti;

    do
    {
        dugumbitti = false;
        Dugum* sahtesil = silDugum; // Yedek bir Düğüm pointer ı oluşturur.
        if (silDugum->sonraki != 0) // düğümün sonraki 0 değilse girer.
        {
            silDugum = silDugum->sonraki;
            dugumbitti = true;
        }
        seciliYoneticiDugum->bagliSatirListesi->DugumuSil(sahtesil); // düğüm silme fonksiyonunu çağırır.

    } while (dugumbitti); // dugumbitti bool u false olana kadar dönmeye devam eder.
    if (seciliYoneticiDugum->sonraki ==0 ) // eğer seçili yönetici düğümünün sonraki 0 ise girer.
    {
        if (seciliYoneticiDugum->onceki == 0)  // eğer seçili yönetici düğümünün önceki de 0 ise girer.
        {
            delete seciliYoneticiDugum->bagliSatirListesi; // önce Yönetici Düğüme BAĞLI satır listesini Silme Fonksiyonunu çağırır.
            delete seciliYoneticiDugum; // Sonra da YoneticiDüğümü Silme Fonksiyonunu çağırır.
            dugumsayisi--; // YoneticiDüğüm Sayısını 1 azaltır.
            secililiste--; // secililisteyi de 1 azaltır.
        }
        else
        {
            seciliYoneticiDugum->onceki->sonraki = 0; // Secili YoneticiDüğümün önceki ve sonraki ni 0 yapar.
            delete seciliYoneticiDugum->bagliSatirListesi; // önce Yönetici Düğüme BAĞLI satır listesini Silme Fonksiyonunu çağırır.
            delete seciliYoneticiDugum; // Sonra da YoneticiDüğümü Silme Fonksiyonunu çağırır.
            dugumsayisi--; // YoneticiDüğüm Sayısını 1 azaltır.
            secililiste--; // secililisteyi de 1 azaltır.
            

        }
        
    }
    else if(seciliYoneticiDugum->onceki==0) // eğer ki secili yonetici düğüm önceki 0 a eşitse girer.
    {
        
        
        ilk = seciliYoneticiDugum->sonraki; // ilk i secili yöneticidüğümün sonraki yapar.
        seciliYoneticiDugum->sonraki->onceki = 0; // secili yonetici düğümünün sonrakini öncekini de 0 yapar.
        delete seciliYoneticiDugum->bagliSatirListesi; // önce Yönetici Düğüme BAĞLI satır listesini Silme Fonksiyonunu çağırır.
        delete seciliYoneticiDugum; // Sonra da YoneticiDüğümü Silme Fonksiyonunu çağırır.
        dugumsayisi--; // YoneticiDüğüm Sayısını 1 azaltır.
            
        
    }
    else
    {
        seciliYoneticiDugum->onceki->sonraki = seciliYoneticiDugum->sonraki; // Secili Yonetici Düğümün Öncekinin sonrakini Seçili Yönetici Düğümün sonrakine eşitler.
        seciliYoneticiDugum->sonraki->onceki = seciliYoneticiDugum->onceki; // secili Yöenrici Düğümün Sonrakinin Öncekine Seçili Yonetici Düğümün Öncekini atar.
        delete seciliYoneticiDugum->bagliSatirListesi; // önce Yönetici Düğüme BAĞLI satır listesini Silme Fonksiyonunu çağırır.
        delete seciliYoneticiDugum; // Sonra da YoneticiDüğümü Silme Fonksiyonunu çağırır.
        dugumsayisi--; // YoneticiDüğüm Sayısını 1 azaltır.
    }
    seciliYoneticiDugum = ilk;
    if (dugumsayisi > 0) // eğer düğüm sayısı 0 dan fazla ise girer değilse YöneticiDüğüm Kalmamış Demektir.
    {
        while (seciliYoneticiDugum->sonraki != 0) // Seçili Yönetici Düğümün Sonraki 0 a eşit olmadıkça döner. son düğüm bulmak için yazılmıştır.
        {
            seciliYoneticiDugum = seciliYoneticiDugum->sonraki;
            son = seciliYoneticiDugum; 
        }
    }
}
void YoneticiListesi::YoneticiSeciliListebulma()
{
    int secililistekac = secililiste;
    YoneticiDugum* seciliYoneticiDugum = ilk; // Seçili Yönetici Düğümü Bulmak İçin Pointer
    for (int i = 0; i < secililistekac; i++) //Seçili Liste kadar for döndürür.
    {
        seciliYoneticiDugum = seciliYoneticiDugum->sonraki;
    }
    SeciliListe = seciliYoneticiDugum;
}
void YoneticiListesi::RastgeleDugumSil()
{
    int secililistekac = secililiste;  
    YoneticiDugum* seciliYoneticiDugum = ilk; // Seçili Yönetici Düğümü Bulmak İçin Pointer
    for (int i = 0; i < secililistekac;i++) //Seçili Liste kadar for döndürür.
    {
        seciliYoneticiDugum = seciliYoneticiDugum->sonraki;
    }
    Dugum* sil = seciliYoneticiDugum->bagliSatirListesi->ilk; // Yönetici Düğüm İçindeki SatırListesinin İlk Düğümünü Gösteren Pointer.
    for (int i = 0; i < kacsilinsin; i++) // Kaçsilinsin kadar döner.
    {
        sil = sil->sonraki;
    }
    if (kacsilinsin == 0) // kaçsilinsin 0 a eşitse girer.
    {
        if (sil->sonraki != 0) //sil in sonraki 0 a eşit değilse girer.
        {
            seciliYoneticiDugum->bagliSatirListesi->ilk = sil->sonraki; // Seçili Yönetici Düğümün Bağlı Satır Listesi nin ilk i ne Sil in Sonrakini atar.
            seciliYoneticiDugum->bagliSatirListesi->DugumuSil(sil); // Seçili Yönetici Düğümün Bağlı Satır Listesi nin DUĞUM SİLME Fonksiyonu sik pointer ı ile çağırılır.
        }
        else
        {
            YoneticiListesiniSil(secililistekac); // YoneticiListesiniSil fonksiyonu secililistekaç ile çağırılır.
        }
       
    }
    else
    {

        seciliYoneticiDugum->bagliSatirListesi->DugumuSil(sil); // Seçili Yönetici Düğümün Bağlı Satır Listesi nin DUĞUM SİLME Fonksiyonu sik pointer ı ile çağırılır.
    }





}
ostream& operator<<(ostream& os, const YoneticiListesi& YoneticiListesi)
{
    using namespace std;
    YoneticiDugum* ekrandakiIlkDugum = YoneticiListesi.ilk; // Ekrandaki İlk YöneticiDüğümü Bulmak İçin Pointer
    YoneticiDugum* ekrandakiSonDugum = ekrandakiIlkDugum; // Ekrandaki Son YöneticiDüğümü Bulmak İçin Pointer
    os << endl;
    int sekizli = YoneticiListesi.sekizli;
    int ekrandakiDugumSayisi = 0;
    int secililiste = YoneticiListesi.secililiste;
    
    
    if (ekrandakiSonDugum->sonraki != 0) //yeni atadığımız pointer ın sonraki sıfır değilse girer. 
    {
        for (int i = 0; i < (sekizli * 8) + 7; i++) //Ekrandaki Son Düğüm Pointer ını sekizli nin son düğümünü bulana kadar döndürür 
        {
            ekrandakiSonDugum = ekrandakiSonDugum->sonraki;
            if (ekrandakiSonDugum->sonraki == 0) // eğer ki sonraki 0 sa break yapmak için girer.
            {
                break;
            }
        }
    } 
    for (int i = 0; i < sekizli * 8; i++) // Yeni atadğımız Pointer ın Ekrandaki İlk Düğüm Olana kadar döner.
    {
        if (ekrandakiIlkDugum->sonraki == 0)// sonraki adres 0 sa break yaptırır.
            break;
        ekrandakiIlkDugum = ekrandakiIlkDugum->sonraki;
    }
YoneticiDugum* gecIlkDugum = ekrandakiIlkDugum; //ekrandaki ilk düğüm için gecici pointer oluşturur.
    for (int i = 0; i < 8; i++) // ekrandaki düğüm sayısını bulmak için döner.
    {

        if (gecIlkDugum == ekrandakiSonDugum || gecIlkDugum->sonraki == 0)// eğer ekrandaki son düğüme eşitse bu geçici düğüm veya sonraki adresi 0 sa girer
        {
            ekrandakiDugumSayisi++;
            break;
        }

        gecIlkDugum = gecIlkDugum->sonraki; 
        if (ekrandakiDugumSayisi == 8)// ekrandaki düğüm sayısı 8 se girer ve break yapar.
            break;
        ekrandakiDugumSayisi++;
    }
    if (ekrandakiSonDugum->sonraki == 0 &&  ekrandakiDugumSayisi% 8 == 0 && YoneticiListesi.dugumsayisi == ekrandakiDugumSayisi*sekizli)
    {// ekrandakison düğümün sonraki 0 ve eekrandaki düğüm sayısı 8 in katı ve düğüm sayısı ekrandaki düğüm sayısı ile sekizli çarpımına eşitse girer.
        sekizli--;
    }
  
    
    
    if (ekrandakiIlkDugum->onceki == 0) //ekrandaki düğüm ilk düğümse girer.
    {
        os << "ilk";
      
    }
    else
    {
        os << "<---";
    }

    if (ekrandakiDugumSayisi > 1) //ekrandaki düğüm sayısı 1 den fazlaysa girer
    {
        if (ekrandakiDugumSayisi < 8) // ekrandaki düğüm sayısı 8 den azsa girer.
        {
            os << setw(ekrandakiDugumSayisi * 14 - 8) <<right<< "son";
        }
        else if (ekrandakiDugumSayisi ==8 && ekrandakiSonDugum == YoneticiListesi.son) // ekrandaki düğüm sayısı 8 e eşit ve son düğümse girer.
        {

            os << setw(ekrandakiDugumSayisi * 14 - 8) <<right<< "son";
        }
        else 
        {
            os << setw(ekrandakiDugumSayisi * 13) <<right<< "--->";
        }
    }
    os << endl << "";
    gecIlkDugum = ekrandakiIlkDugum;
    for (int i=0;i< ekrandakiDugumSayisi;i++) //ekrandaki düğüm sayısı kadar döner
    {

        os <<setw(10)<<right<< gecIlkDugum<<setw(4)<<"";
        if (gecIlkDugum->sonraki == 0) //eğer sonraki adres 0 sa girer ve break olur.
            break;
        gecIlkDugum = gecIlkDugum->sonraki;
    }
    os << endl;
    for (int i = 0; i < ekrandakiDugumSayisi; i++) //ekrandaki düğüm sayısı kadar döner
    {

        os << setw(14) << left << "-----------";
    }

    os << endl;
    gecIlkDugum = ekrandakiIlkDugum;
    for (int i = 0; i < ekrandakiDugumSayisi; i++) //ekrandaki düğüm sayısı kadar döner
    {

        os << "|"<<setw(9)<<right<< gecIlkDugum->onceki <<"|"<< setw(4)<<right;
        if (gecIlkDugum->sonraki == 0) //eğer sonraki adres 0 sa girer ve break olur.
            break;
        gecIlkDugum = gecIlkDugum->sonraki;
    }
    os << endl;
    for (int i = 0; i < ekrandakiDugumSayisi; i++)//ekrandaki düğüm sayısı kadar döner
    {

        os << setw(14) << left << "-----------";
    }
    os << endl;
    gecIlkDugum = ekrandakiIlkDugum;
    for (int i = 0; i < ekrandakiDugumSayisi; i++)//ekrandaki düğüm sayısı kadar döner
    {

        os << "|" << setw(9) << right <<setprecision(3)<< gecIlkDugum->aritm << "|" << setw(4) << right;
        if (gecIlkDugum->sonraki == 0)//eğer sonraki adres 0 sa girer ve break olur.
            break;
        gecIlkDugum = gecIlkDugum->sonraki;
    }
    os << endl;
    for (int i = 0; i < ekrandakiDugumSayisi; i++)//ekrandaki düğüm sayısı kadar döner
    {

        os << setw(14) << left << "-----------";
    }
    os << endl;
    gecIlkDugum = ekrandakiIlkDugum;
    for (int i = 0; i < ekrandakiDugumSayisi; i++)//ekrandaki düğüm sayısı kadar döner
    {

        os << "|"<< setw(9)<<right<< gecIlkDugum->sonraki << "|" << setw(4) << right;
        if (gecIlkDugum->sonraki == 0)//eğer sonraki adres 0 sa girer ve break olur.
            break;
        gecIlkDugum = gecIlkDugum->sonraki;
    }
    os << endl;
    for (int i = 0; i < ekrandakiDugumSayisi; i++)//ekrandaki düğüm sayısı kadar döner
    {

        os << setw(14) << left << "-----------";
    }
    os << endl;
    for (int i = 0; i < secililiste - sekizli * 8; i++)//ekrandaki düğüm sayısı kadar döner
    {
        os << setw(14) << " ";
    }
    os << left << setw(14) << "^^^^^^^^^^^" << endl;
    YoneticiDugum* listebulucu = 0;
    Dugum* listeyial = 0;
    listebulucu = YoneticiListesi.ilk; // oluşturulan listebulucu Düğümüne YöneticiListesinin İlk Düğümünü Atar.
    for (int i = 0; i < secililiste; i++) //secililisteyi bulana kadar döner.
    {
        listebulucu = listebulucu->sonraki;
    }
    listeyial = listebulucu->bagliSatirListesi->ilk; // oluşturulan listeyial Düğümü Listebulucunun Bağlı Satır Listesinin İlk Düğümüne Eşitlenir.
    int kactanedugum = 0;
    if (listeyial->sonraki != 0) // listeyial Düğümünün sonraki 0 değilse girer.
    {
        do
        {
            kactanedugum++; // kaçtane düğüm var int değerini artırır.
            listeyial = listeyial->sonraki;

        } while (listeyial->sonraki != 0); // listeyial sonraki 0 olmadığı sürece döner. kaç tane düğüm olduğunu buluruz.
    }
    listeyial = listebulucu->bagliSatirListesi->ilk; // oluşturulan listeyial Düğümü Listebulucunun Bağlı Satır Listesinin İlk Düğümüne Eşitlenir.
    for (int i = 0; i <= kactanedugum; i++) //kaçtane düğüm varsa o kadar döner.
    {
        for (int i = 0; i < secililiste - sekizli * 8; i++) // ekrandaki seçili liste kadar döndürür.
        {
            os << setw(14) << " ";
        }
        os <<setw(10) <<right<< listeyial << endl;
        for (int i = 0; i < secililiste - sekizli * 8; i++)// ekrandaki seçili liste kadar döndürür.
        {
            os << setw(14) << " ";
        }
        os << setw(11) << left << "-----------" << endl;
        for (int i = 0; i < secililiste - sekizli * 8; i++)// ekrandaki seçili liste kadar döndürür.
        {
            os << setw(14) << " ";
        }
        os << "|" << setw(6) << right << listeyial->veri << setw(4) << right << "|" << endl;
        for (int i = 0; i < secililiste - sekizli * 8; i++)// ekrandaki seçili liste kadar döndürür.
        {
            os << setw(14) << " ";
        }
        os << setw(11) << left << "-----------";
        if (YoneticiListesi.kacsilinsin ==i)// Eğer ki kaçsilinsin i ye eşitse girer.
        {
            os << setw(27) << right << "<---- Silinecek Secili " << endl;
        }
        else
        {
            os << endl;
        }
        for (int i = 0; i < secililiste - sekizli * 8; i++)// ekrandaki seçili liste kadar döndürür.
        {
            os << setw(14) << " ";
        }
        os << "|" << setw(9)<<right << listeyial->sonraki << "|" << endl << endl;
        listeyial = listeyial->sonraki;
    } 

    return os;
}
