/**
* @file           SatirListesi.hpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef SatirListesi_h
#define SatirListesi_h
#include "Dugum.hpp"
using namespace std;
class SatirListesi // Düğümlerin Tutulduğu ve YöneticiDüğümlerin içerisinde Tutulan SatirListesi Sınıfı
{
public:
	SatirListesi(); // Kurucu Fonksiyon
	~SatirListesi(); // Yok Edici Fonksiyon
	void ekle(int veri); // SatırListesi İçerisine Düğüm Ekleme Fonksiyonu
	void DugumuSil(Dugum* silinecek); //SatirListesi içerisinden Düğüm Silme Fonksiyonu
	Dugum* ilk; // İlk Düğümün Adresini Tutacak Pointer.
	int Satirdugumsayisi;
private:
	

};

#endif