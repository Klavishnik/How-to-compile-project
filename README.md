# Сборка мультифайловых проектов 
## Структура проекта

Допустим, мы имеет следующую структуру нашего классного проекта:

```tree
project

│   
└── src
    ├── lib
    │   ├── librow.c
    │   └── librow.h
    └── main.c
```

## 1. Компиляция всего в один исполняемый файл

Чтобы получить исполняемый файл нашей программы, необходимо сначала получить объектные файлы из исходных

```Makefile
gcc -c src/main.c -o main.o
gcc -c src/lib/librow.c -o librow.o
```

В директории появятся в данном случае два объектных файла. Соберём их в один исполняемый файл:

```Makefile
gcc -o bin main.o librow.o
```

или так

```Makefile
gcc -o bin *.o
```

## 2. Статическая библиотека

Для начала, всё так же получим объектные файлы:

```Makefile
gcc -c src/main.c -o main.o
gcc -c src/lib/librow.c -o librow.o
```

Теперь надо полученный объектный файл библиотеки упаковать:

```Makefile
ar rcs librow.a librow.o
```

Линкуем с главным исполняемым файлом:

```Makefile
gcc main.o -L. -lrow -o bin_static
```

## 3. Динамическая библиотека

Соберём объектные файлы для наших файлов, но с дополнительным флагом для библиотеки - `-fPIC`. Этот флаг означает Position-independent code. Наша библиотека может лежать в памяти где угодно и она не должна зависить от положения:

```Makefile
gcc -c src/main.c -o main.o
gcc -c -fPIC src/lib/librow.c -o librow.o
```

Собираем динамическую библиотеку:

```Makefile
gcc -shared librow.o -o librow.so
```

Линкуем с главным исполняемым файлом:

```Makefile
gcc main.o -L. -lrow -o bin_dynamic
```

Однако, в случае динамической библиотеки, просто запустить программу не получится, т.к. она не найдет библиотеку. Есть 2 способа заставить её работать:

1. Указать переменную окружения:

```bash
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH
```

2. Засунуть нашу библиотеку в стандартную папку для динамических библиотек и указать линковщику что она там:

```bash
sudo cp $(pwd)/librow.so /usr/lib
sudo chmod 0755 /usr/lib/librow.so
sudo ldconfig
```

## Полезные ссылки

1. <https://www.opennet.ru/man.shtml?topic=ar&category=1> - **man ar**
2. <https://www.opennet.ru/man.shtml?topic=gcc&category=1> - **man gcc**
