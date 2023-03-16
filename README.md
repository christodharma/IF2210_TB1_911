# Kompetisi Kartu ala Kerajaan Permen
> Tugas Besar 1 Kompetisi Kartu
ala Kerajaan Permen - IF2210 Pemrograman Berorientasi Objek (kelompok 911 - ninuninu)


## Table of Contents
* [About the program](#about-the-program)
* [Program Structure](#program-structure)
* [Features](#features)
* [Technology used](#technology-used)
* [Setup](#setup)
* [How to run program](#how-to-run-program)
* [Authors](#authors)


## About the program
Pada program ini, Permainan Kartu ala Kerajaan Permen menerapkan konsep OOP. Konsep OOP yang digunakan dalam program ini, yaitu:
- Inheritance
- Polymorphism
- Method/Operator Overloading
- Template & Generic Classes
- Exception
- C++ Standard Template Library
- Abstract Base Class


## Program Structure
```
IF2210_TB1_911                   
├─ bin                           
│  ├─ driver                     
│  │  ├─ driver_Card.cpp         
│  │  ├─ driver_Combination.cpp  
│  │  ├─ driver_Combination.exe  
│  │  ├─ driver_Deck.cpp         
│  │  ├─ driver_Exception.cpp    
│  │  ├─ driver_Inventory.cpp    
│  │  ├─ driver_MapCard.cpp      
│  │  └─ driver_Player.cpp       
│  └─ main.cpp                   
├─ src                           
│  ├─ Ability.cpp                
│  ├─ Ability.hpp                
│  ├─ Card.cpp                   
│  ├─ Card.hpp                   
│  ├─ Combination.cpp            
│  ├─ Combination.hpp            
│  ├─ Deck.cpp                   
│  ├─ Deck.hpp                   
│  ├─ Exception.hpp              
│  ├─ Flush.cpp                  
│  ├─ Flush.hpp                  
│  ├─ FourOfAKind.cpp            
│  ├─ FourOfAKind.hpp            
│  ├─ FullHouse.cpp              
│  ├─ FullHouse.hpp              
│  ├─ GameManager.cpp            
│  ├─ GameManager.hpp            
│  ├─ GameState.cpp              
│  ├─ GameState.hpp              
│  ├─ Generics.cpp               
│  ├─ Generics.hpp               
│  ├─ HighCard.cpp               
│  ├─ HighCard.hpp               
│  ├─ InventoryHolder.cpp        
│  ├─ InventoryHolder.hpp        
│  ├─ Pair.cpp                   
│  ├─ Pair.hpp                   
│  ├─ Player.cpp                 
│  ├─ Player.hpp                 
│  ├─ splashScreen.hpp           
│  ├─ Straight.cpp               
│  ├─ Straight.hpp               
│  ├─ StraightFlush.cpp          
│  ├─ StraightFlush.hpp          
│  ├─ Table.cpp                  
│  ├─ Table.hpp                  
│  ├─ ThreeOfAKind.cpp           
│  ├─ ThreeOfAKind.hpp           
│  ├─ TwoPair.cpp                
│  ├─ TwoPair.hpp                
│  ├─ Valueable.cpp              
│  └─ Valueable.hpp              
└─ README.md                                       

```


## Features
Fitur (Command) yang terdapat dalam program ini:

- NEXT -> Perintah yang memiliki arti pemain tidak melakukan apa-apa (tidak Half, tidak
Double, dan tidak mengeluarkan kartu ability)
- RE-ROLL -> Perintah yang memiliki arti pemain membuang kedua kartu yang ada di
tangannya dan mengambil ulang dua kartu baru.
- DOUBLE/QUADRUPLE -> Perintah yang memiliki arti pemain akan menaikkan total poin hadiah pada
permainan menjadi dua kali lipat atau empat kali lipat.
- HALF/QUARTER -> Perintah yang memiliki arti pemain akan menurunkan total poin hadiah pada
permainan menjadi setengah atau seperempat nilai awal.
- REVERSE -> Perintah yang memiliki arti untuk memutar arah giliran eksekusi perintah oleh
pemain.
- SWAPCARD -> Perintah yang memiliki arti menukar satu kartu pemain lain dengan satu kartu
pemain yang lain. 
- SWITCH -> Perintah yang memiliki arti pemain akan menukar kartu main deck miliknya
dengan kartu main deck milik pemain lain. 
- ABILITYLESS -> Perintah yang memiliki arti pemain akan mematikan kemampuan kartu lawan.


## Technology Used
- C++ 17


## How to run program
Untuk menjalankan permainan dibutuhkan:
- g++
- Linux

Untuk menggunakan program diperlukan _compile_ terhadap program dengan cara:
- _Copy_/_Download_ repository ini dan pastikan sudah menggunakan Linux (boleh WSL) dan sudah ter-_install_ g++ pada Linux.
- Jika belum mempunyai _g++_ bisa _install_ dengan mengetik _command_ pada terminal
```
sudo apt install g++
```
- Ubah directory ke lokasi repositori yang sudah di-clone dan ketik 
```
cd bin
````
```
g++ -o kompetisiKartu main.cpp ../src/*.cpp ; if ($?) {./kompetisiKartu}
```


## Authors
| NIM | Name | 
| :---: | :---: |
| 13521009 | [Christophorus Dharma Winata](https://github.com/christodharma) |
| 13521018 | [Syarifa Dwi Purnamasari](https://github.com/syrifaa) |
| 13521027 | [Agsha Athalla Nurkareem](https://github.com/agshaathalla) |
| 13521029 | [M Malik I Baharsyah](https://github.com/malikbaharsyah) |
| 13521030 | [Jauza Lathifah Annassalafi](https://github.com/listgirrlll) |