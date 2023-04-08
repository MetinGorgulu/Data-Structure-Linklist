/**
* @file           YoneticiListesi.hpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef YoneticiListesi_h
#define YoneticiListesi_h
#include "SatirListesi.hpp"
#include "YoneticiDugum.hpp"
#include <iostream>
using namespace std;

class YoneticiListesi // İçerisinde Yonetici Düğümlerini Tutan YoneticiListesi Sınıfı
{
public:
	YoneticiListesi();  // YoneticiListesi Kurucu Fonksiyonu.
	~YoneticiListesi(); // Yok edici Fonksiyonu.
	void ekle(); // YoneticiDüğümü Ekleme Fonksiyonu.
	void aritmetik(); // Düğümlerin Aritmetiğini Alan Fonksiyon.
	void Siralama(); // YöneticiDüğümlerini İçerisindeki Sayıların Aritmetiğine Göre Sıralayan Fonksiyon.
	void YoneticiListesiniSil(int silinecekliste); // YöneticiDüğümünü Silen Fonksiyon
	void RastgeleDugumSil(); // Rastgele Düğüm Silme Fonksiyonu.
	void YoneticiSeciliListebulma();
	void SeciliListeDugumSayisiBulma(); // Seçili SatırListesindeki Düğüm Sayısını Bulan Fonksiyon.
	YoneticiDugum* son; // son pointer ı
	YoneticiDugum* ilk; // il pointer ı
	YoneticiDugum* SeciliListe; // seciliListe Pointer ı
	SatirListesi* SatiRliste; // SatirListesi pointer ı
	int sekizli;
	int dugumsayisi;
	int secililiste;
	int secililistededugumsayi;
	int kacsilinsin;
	friend ostream& operator<<(ostream& os, const YoneticiListesi& YoneticiListesi);// nesneyi yazdırmak için.
	

private:

	

};


#endif