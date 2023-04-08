/**
* @file           YoneticiDugum.cpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include"Dugum.hpp"
#include"SatirListesi.hpp"
#include"YoneticiDugum.hpp"
YoneticiDugum::YoneticiDugum( SatirListesi* baglanacakSatirListesi)
{
	onceki = sonraki = 0; // önceki ve sonrakine 0 atar.
	aritm = 0; // aritm e 0 atar.
	this->bagliSatirListesi = baglanacakSatirListesi; // kurucu fonksiyon ile gelen pointer ı baglıSatirListesi ne atar.
}
YoneticiDugum::~YoneticiDugum()
{

}