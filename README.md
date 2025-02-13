# s21_string+

Реализация библиотеки `string.h` с дополнениями, включая функции `sprintf`, `sscanf` и специальные функции обработки строк, вдохновленные классом `String` в языке C#.

## Содержание

1. [Введение](#введение)
2. [Установка и сборка](#установка-и-сборка)
3. [Использование](#использование)
   - [Функции библиотеки string.h](#функции-библиотеки-stringh)
   - [Функция sprintf](#функция-sprintf)
   - [Функция sscanf](#функция-sscanf)
   - [Специальные функции обработки строк](#специальные-функции-обработки-строк)
4. [Тестирование](#тестирование)
5. [Требования к коду](#требования-к-коду)
6. [Дополнительные задания](#дополнительные-задания)
7. [Лицензия](#лицензия)

## Введение

Проект представляет собой реализацию библиотеки `string.h` на языке C с дополнительными функциями, такими как `sprintf`, `sscanf` и специальные функции обработки строк. Основная цель проекта — изучить работу со строками и форматированным вводом/выводом, а также отработать навыки структурного программирования.

## Установка и сборка

Для сборки проекта выполните следующие шаги:

1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/yourusername/s21_stringplus.git
   cd s21_stringplus
   ```

2. Соберите проект с помощью Makefile:
   ```bash
   make
   ```

   Это создаст статическую библиотеку `s21_string.a` и исполняемые файлы для тестирования.

3. Для запуска тестов выполните:
   ```bash
   make test
   ```

4. Для очистки проекта выполните:
   ```bash
   make clean
   ```

## Использование

### Функции библиотеки string.h

Библиотека включает в себя все стандартные функции `string.h`, такие как `memcpy`, `memcmp`, `strlen`, `strcat`, `strcmp`, `strcpy`, `strchr`, `strstr`, `strtok` и другие. Каждая функция имеет префикс `s21_`, например, `s21_memcpy`, `s21_strlen`.

Пример использования:
```c
#include "s21_string.h"

int main() {
    char src[] = "Hello, World!";
    char dest[20];
    s21_strcpy(dest, src);
    printf("%s\n", dest);  // Вывод: Hello, World!
    return 0;
}
```

### Функция sprintf

Функция `s21_sprintf` поддерживает следующие спецификаторы:
- `c`, `d`, `f`, `s`, `u`, `%`
- Флаги: `-`, `+`, ` ` (пробел)
- Ширина: `(число)`
- Точность: `.(число)`
- Длина: `h`, `l`

Пример использования:
```c
#include "s21_string.h"

int main() {
    char buffer[100];
    s21_sprintf(buffer, "Hello, %s! You are %d years old.", "Alice", 25);
    printf("%s\n", buffer);  // Вывод: Hello, Alice! You are 25 years old.
    return 0;
}
```

### Функция sscanf

Функция `s21_sscanf` поддерживает полное форматирование, включая флаги, ширину, точность и модификаторы.

Пример использования:
```c
#include "s21_string.h"

int main() {
    char input[] = "25 3.14 Alice";
    int age;
    float pi;
    char name[20];
    s21_sscanf(input, "%d %f %s", &age, &pi, name);
    printf("Age: %d, Pi: %.2f, Name: %s\n", age, pi, name);  // Вывод: Age: 25, Pi: 3.14, Name: Alice
    return 0;
}
```

### Специальные функции обработки строк

Библиотека также включает в себя дополнительные функции обработки строк, вдохновленные классом `String` в языке C#:

- `s21_to_upper`: Преобразует строку в верхний регистр.
- `s21_to_lower`: Преобразует строку в нижний регистр.
- `s21_insert`: Вставляет строку в указанную позицию.
- `s21_trim`: Удаляет начальные и конечные вхождения заданных символов.

Пример использования:
```c
#include "s21_string.h"

int main() {
    char str[] = "  Hello, World!  ";
    char *trimmed = s21_trim(str, " ");
    printf("%s\n", trimmed);  // Вывод: Hello, World!
    free(trimmed);
    return 0;
}
```

## Тестирование

Для проверки корректности работы библиотеки используются unit-тесты с помощью библиотеки `Check`. Тесты покрывают не менее 80% каждой функции.

Для запуска тестов выполните:
```bash
make test
```

Для генерации отчета о покрытии кода тестами выполните:
```bash
make gcov_report
```

## Требования к коду

- Код написан на языке C стандарта C11.
- Используется компилятор gcc.
- Код соответствует стилю Google C++ Style Guide.
- Библиотека оформлена как статическая библиотека `s21_string.a`.
- Исключено дублирование кода, общие модули вынесены в отдельные файлы.
- Подготовлено полное покрытие unit-тестами с использованием библиотеки `Check`.
- Запрещено использование стандартной библиотеки `string.h` и других библиотек обработки строк, кроме unit-тестов.

## Дополнительные задания

### Реализация дополнительных модификаторов для sprintf

- Поддержка спецификаторов: `g`, `G`, `e`, `E`, `x`, `X`, `o`, `p`.
- Поддержка флагов: `#`, `0`.
- Поддержка ширины: `*`.
- Поддержка точности: `.*`.
- Поддержка длины: `L`.

### Реализация функции sscanf

- Полная поддержка форматирования, включая флаги, ширину, точность и модификаторы.

### Реализация специальных функций обработки строк

- Функции `to_upper`, `to_lower`, `insert`, `trim`.

## Лицензия

Проект распространяется под лицензией MIT. Подробности смотрите в файле [LICENSE](LICENSE).

---

Проект разработан в рамках учебного задания.
