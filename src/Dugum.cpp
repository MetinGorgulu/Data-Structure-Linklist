/**
* @file           Dugum.cpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include"Dugum.hpp"
Dugum::Dugum(int veri) 
{
	this->veri = veri; // bu düğümün veri int'ine kuruccu fonksiyonlar gelen veriyi atar.
	onceki = sonraki = 0; // önceki ve sonraki pointerlara 0 atar.

};
Dugum::~Dugum()
{

}

