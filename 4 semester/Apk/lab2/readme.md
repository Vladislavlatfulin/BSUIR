## Архитектура персонального компьютера №2 "Программирование контроллера прерываний"

___

### Вариант 14
Написать резидентную программу выполняющую перенос всех векторов аппаратных
прерываний ведущего и ведомого контроллера на пользовательские прерывания. При этом
необходимо написать обработчики аппаратных прерываний, которые будут установлены на
используемые пользовательские прерывания и будут выполнять следующие функции:
1. Выводить на экран в двоичной форме следующие регистры контроллеров
прерывания (как ведущего, так и ведомого):
регистр запросов на прерывания;
регистр обслуживаемых прерываний;
регистр масок.
При этом значения регистров должны выводиться всегда в одно и то же место экрана.
2. Осуществлять переход на стандартные обработчики аппаратных прерываний, для
обеспечения нормальной работы компьютера.
3. Базовый вектор: C8H/08h
