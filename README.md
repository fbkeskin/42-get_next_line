# Get Next Line

![image](https://github.com/fbkeskin/42-get_next_line/assets/92950254/14635ae2-dcf6-4f88-9eef-f7445f1e2614) 
![image](https://github.com/fbkeskin/42-get_next_line/assets/92950254/14771bd6-a4dc-4873-b455-59aa12445aa7)



## Status
Bitirme Tarihi: 25/12/2023. Grade: 100/125.


## Introduction
Bu proje, belirtilen dosya tanımlayıcısından her çağrıldığında bir satır döndüren bir fonksiyon oluşturmayı hedefler.

Uygulanacak fonksiyona ``get_next_line`` adı verilir ve fonksiyon prototipi aşağıdaki gibidir:
```C
char *get_next_line(int fd);
```
* Input Parameters

Fonksiyon, yalnızca açık dosyanın integer ``fd`` değerini veya  ``fd = 0`` ise standart girdiyi alır.
* Return Values

Olası 2 return değeri vardır:

| Return Value | Description |
| :----------: | :---------: |
| char * | Fonksiyon tarafından okunan satırı içeren array |
| (null) | Bir hata veya EOF'ye(End Of File) ulaşılma durumu |

