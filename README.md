# 7-Segment-Display
1.Proje Özeti
Pic16f877, 7 Seg-BCD, 1 adet LED ve 4 adet button kullanarak saat-dakika-saniye gösteren ve ayarlanabilen bir saat sistemi yapıp çalıştırdık.
2.Yazılım Tasarımı
Bu projenin geliştirilmesinde kullanılan araçlar; 
•	CCS C Compilerda C dili ile kodlayıp,
•	Proteus 8.9 üzerinden devre çizimini ve simülasyonunu gerçekleştirdik.
Devremizde yer alan malzemeler;
•	Pic16f877
•	7 adet 7Seg-BCD
•	1 adet LED
•	4 adet button
1.	Buton saati/alarmı göstermek/ayarlamak için 
2.	Buton değiştirilecek haneyi seçmek için 
3.	Buton seçili hanenin sayı değerini bir artırmak için 
4.	Buton seçili hanenin sayı değerini bir azaltmak için kullanılacaktır.  
3.Projenin Çalışma Mantığı
Öncelikle milisecondcounter, secondcounter, minutecounter, hourcounter olarak değişkenlerimizi tanımladık. Ayrıca secondcounter, minutecounter ve hourcounter onlar ve birler basamağından oluştuğu için 2 tane 7Seg-BCD kullandık. Bundan dolayı secondcounter1+secondcounter2, minutecounter1+minutecounter2 ve hourcounter1+hourcounter2 olmak üzere birler ve onlar basamağını temsilen değişken tanımladık.
İlk olarak 7seg-BCD kullanarak öncelikle sayı sayma işlemini gerçekleştirmeye çalıştım. Bunun için digital olarak maksimum 23:59:59:9 şeklinde bir değer görebileceğimizden dolayı buna uygun değer atamalarını #int_timer1 üzerinde gerçekleştirdik. timer1()’i seçme nedenimiz16 bit timer/counter olmasıdır.
Set_tris_x(): port pinlerinin hangisinin giriş pini hangisinin çıkış pini olacağını belirtir. (x:işlem yapılacak portun adı, parantez içine de hexadecimal olarak 8 bitlik değer girilir.)
Output_low(): İstenen portun istenen biti lojik-0(0v) yapılır. İstenen ucun çıkışı 0 yapılır.
Output_high(): İstenen portun istenen biri lojik-1(5V) yapılır. İstenen ucun çıkışı 1 yapılır.
void main (): Projenin ana fonksiyonunda ise başta verilen buttonStop komutunun doğruluğu halinde, switch case yapısı kullanarak buttonların belirtilen digit seçme, seçilen digitin değerini arttırma, seçilen digitin değerini azaltma gibi komutlara yer verdim. Ayrıca eğer ayarlanan saat ve buttona basıldıktan sonra gelinen saat eğer eştise led ışığımızda yanmaktadır.
4.Projede Karşılaşılan Sorunlar 
Proteus’tan kaynaklı olarak mikroişlemcinin A4 girişinde var olan problemden dolayı LED’in yanmasında çeşitli problemler bazen yaşanmaktadır. Proje demosu yaparken de bu sorun ortaya çıkmıştır.
Bunlara ek olarak da bu yazılımların indirdiğimiz yerlerden kaynaklı ödevi yaparken sürekli kodları tekrar yazma, devreyi yeniden çizme gibi problemlerle karşılaştım ve bu da süreci biraz yavaşlattı.
5.Sonuç
İstenen kriterlere göre dijital saatimiz ve alarm sistemimiz başarılı bir şekilde gerçekleştirilmiştir.	
