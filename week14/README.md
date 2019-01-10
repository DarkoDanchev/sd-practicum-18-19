## Зад. 1
Даден е сортиран във възходящ ред масив състоящ се от уникални цели числа. Да се намери и отпечата на стандартния изход елементът, който е равен на индекса, на който се намира в масива. Ако съществуват един или повече елементи в масива, които изпълняват това свойство, да се върне който и да е от тях. Ако не съществува елемент с посоченото свойство, да се отпечата -1 на стандартния изход.

### Примери:
#### 1)
#### Вход
8  
-2 -1 0 3 5 6 7 9

#### Изход
3

#### 2)
#### Вход
7  
0 1 2 3 4 5 6

#### Изход
5

## Зад. 2
В страната Водландия има n езера (номерирани от 1 до n) и m канала между тях,
като за всеки канал е известна ширината му в метри. Плаването по каналите може да се
извършва и в двете посоки. Известно е, че лодка с ширина 1 метър може да достигне
всяко езеро, тръгвайки от езеро с номер 1.
Напишете програма channels, която изчислява минималния брой канали,
които трябва да бъдат разширени, така че лодка с ширина k метра да може да направи
пътешествие между всеки две езера (лодката може да се придвижи от едно езеро до
друго, ако нейната ширина е по-малка или равна на ширината на канала, свързващ
езерата).

#### Вход
На първия ред са записани целите числа n и m (1 < n ≤ 1000, 1 < m ≤ 100000).
Следват m реда, на всеки от които са записани по три цели числа i, j и w,
показващи, че между езера i и j (1 ≤ i, j ≤ n) има канал с ширина w (1 ≤ w ≤ 200).
На последния ред на входа е записано цялото числото k (1 ≤ k ≤ 200).

#### Изход
На един ред на стандартния изход програмата трябва да изведе едно цяло число,
равно на най-малкия брой канали, които трябва да бъдат разширени.

### Пример
#### Вход
6 9  
1 6 1  
1 2 2  
1 4 3  
2 3 3  
2 5 2  
3 4 4  
3 6 2  
4 5 5  
5 6 4  
4

#### Изход
2

## Зад. 3
Дадени са ориентиран граф и два негови върха v1 и v2. Да се напише програма, която проверява дали съществува връх в графа, който е различен от върховете v1 и v2 и принадлежи на всеки път от v1 до v2. На първия ред от стандартния вход се въвеждат броят на върховете n и броят на ребрата m в графа. На следващия ред от стандартния вход се въвеждат v1 и v2 съответно. На всеки от следващите m реда е записано по едно ребро във формат: firstVertex secondVertex.

### Примери:
#### 1)
#### Вход
4 4  
1 4  
1 3  
1 2  
2 3  
3 4  

#### Изход
Vertex 3 belongs to every path from vertex 1 to vertex 4

#### 2)
#### Вход
4 5  
1 4  
1 3  
1 2  
2 3  
3 4  
2 4  

#### Изход
There is no vertex that belongs to every path from vertex 1 to vertex 4