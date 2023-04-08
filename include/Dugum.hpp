/**
* @file           Dugum.hpp
* @description    Programım Veri.txt dosyasından okuduğu 2 basamaklı Sayıları Heapden alan alarak listeleme yapar. 
* @course         1.öğretim C grubu
* @assignment     1.ödev
* @date           15.11.2022 - 25.11.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Dugum_h
#define Dugum_h

class Dugum // SatırListesinde Oluşturulacak Olan Düğüm Sınıfı
{
public:
	Dugum(int veri); // int alan kurucu fonksiyon.
	~Dugum(); // Yok edici fonksiyon.
	int veri; 
	Dugum* sonraki; //sonraki pointer ı 
	Dugum* onceki; // önceki pointer ı
private:

};


#endif