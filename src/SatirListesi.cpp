/**
* @file           SatirListesi.cpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"


SatirListesi::SatirListesi()
{
	Satirdugumsayisi = 0;
	ilk = 0;

}
SatirListesi::~SatirListesi()
{
    
}
void SatirListesi::ekle(int veri)
{
    Satirdugumsayisi = Satirdugumsayisi + 1; // SatirListesindeki Düğüm lerin Sayısını 1 Artırır.
    Dugum* yeniDugum = new Dugum(veri); // Heap de Dugum Sınıfında veri oluşturur. 
    if (ilk == 0) // Oluşturulan Düğüm İlk Düğümse buraya girer.
    {
        ilk = yeniDugum; // ilk düğümü gösteren pointer a atar.

    }
    else
    {
        Dugum* gec = ilk; 
        while (gec->sonraki != 0) // son düğümü bulana kadar ilerler.
        {
            gec = gec->sonraki;
        }       
        yeniDugum->onceki = gec; // oluşturulan yeni düğümü sona ekler ve önceki ve sonrakini ayarlar.
        gec->sonraki = yeniDugum;
    }

}

void SatirListesi::DugumuSil(Dugum* silinecek)
{
    Dugum* gec = silinecek; // gecici pointer oluşturur.
    if (gec->sonraki == 0) // eğer silinecek düğüm son düğümse girer.
    {
        if (gec->onceki == 0 ) //eğer silinecek düğüm ilk düğümse girer.
        {
            delete gec; // bu komut ile secili dugum silinerek heapden alınan alan serbest bırakılıyor.
        }
        else
        {
            gec->onceki->sonraki = 0; // silinecek düğümün öncekinin sonrakine 0 atar.
            delete gec; // bu komut ile secili dugum silinerek heapden alınan alan serbest bırakılıyor..

        }
    }
    else if (gec->onceki == 0) // eğer silinecek düğüm ilk düğümse girer.
    {
        
        gec->sonraki->onceki = 0; // silinecek düğümün sonraki düğümünün öncesine 0 atar.
        delete gec; // bu komut ile secili dugum silinerek heapden alınan alan serbest bırakılıyor..
        
    }
    else
    {
        gec->onceki->sonraki = gec->sonraki; // silinecek düğümün öncekinin sonrakine silinecek düğümün sonrakini atar.
        gec->sonraki->onceki = gec->onceki;  // silinecek düğümün sonrakinin öncekine silinecek düğümün öncekini atar.
        delete gec; // bu komut ile secili dugum silinerek heapden alınan alan serbest bırakılıyor..
    }
}
