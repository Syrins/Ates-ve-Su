
## API Kullanımı

#### Tüm öğeleri getir

```http
  GET /api/items
```

| Parametre | Tip     | Açıklama                |
| :-------- | :------- | :------------------------- |
| `api_key` | `string` | **Gerekli**. API anahtarınız. |

#### Öğeyi getir

```http
  GET /api/items/${id}
```

| Parametre | Tip     | Açıklama                       |
| :-------- | :------- | :-------------------------------- |
| `id`      | `string` | **Gerekli**. Çağrılacak öğenin anahtar değeri |

#### add(num1, num2)

İki sayı alır ve toplamı döndürür.

  

# Ateş ve Su

Ateş ve Su oyunu online oynayabilirsiniz. 
Artık yan yana olmanıza gerek yok.


## Bölüm Editor

#### LevelGeneration Açınız

```text
  Bu kısımdan kendi bölümlerinizi yapabilirsiniz
```

| Parametre | Açıklama                |
| :-------- | :------------------------- |
| `G`  |kapı düğmesi ekler |
| `B`  |köprü düğmesi ekler |
| `M`  |orta blok ekler |
| `L`  |sol blok ekler |
| `R`  |sağ blok ekler |
| `W`  |küçük su ekler |
| `F`  |küçük lav ekler |
| `f`  |sol lav ekler |
| `i`  |orta lav ekler |
| `r`  |sağ lav ekler |
| `w`  |sol su ekler|
| `a`  |orta su ekler|
| `t`  |Sağ su ekler|



#### Örnek

```text
  1. Level Tasarımı
```

                        "                ",
                        "                ",
                        "         LMMMMMM",
                        "                ",
                        "GR       LMMGMMM",
                        "    LMBR        ",
                        "           LBR  ",
                        "    LfirR       ",
                        "                ",

Bu şekilde sizde kendi bölümlerinizi yapabilirsiniz.
