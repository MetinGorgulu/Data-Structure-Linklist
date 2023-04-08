/**
* @file           YoneticiDugum.hpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef YoneticiDugum_h
#define YoneticiDugum_h
#include "SatirListesi.hpp"
#include <iostream>
using namespace std;



class YoneticiDugum // YoneticiListesi İçeriisinde Bulunan ve İçerisinde SatırListesi Bulunduran YöneticiDüğümlerin Sınıfı
{
public:

	YoneticiDugum(SatirListesi* baglanacakSatirListesi); // SatirListesi Pointer ı ile Gelen Kurucu Fonksiyon.
	~YoneticiDugum();
	float aritm;
	YoneticiDugum* onceki; // sonraki
	YoneticiDugum* sonraki; // önceki
	SatirListesi* bagliSatirListesi; // SatırListesi pointer ı ile bağlı olan SatirListesinin tutar.
};







#endif