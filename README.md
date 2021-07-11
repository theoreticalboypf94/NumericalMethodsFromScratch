# NumericalMethodsFromScratch
Численные методы для физиков-теоретиков

# студентам

sudo apt-get install vim-gtk
sudo apt install gcc
sudo apt install git gitk
sudo apt install mc
sudo apt install make cmake g++
sudo apt install nasm
sudo apt-get install telegram-desktop
sudo snap install skype --classic
sudo apt  install tmux

ssh-keygen

git config --global user.email  ваше 
git config --global user.name ваше

В общем - читаем книгу до момента с генераторами случайных чисел. Начинаем помогать мне в реализации. Детали будем обговаривать по ходу дела и по потребности с вашей стороны.

Пока какая картина, на мне архитектура программ и папки, плюс только я буду мерджить в мастера, создайте себе ветки и не сливайте в мастера.
## наша цель
Я хочу сделать хедер онли библиотеку с классами по каждому численному методу из книги, что я вам дал. Все классы-реализации должны быть шаблонными, те Шоб можно было и арифметику с произвольной точностью использовать и обычные double & long long double (или что даже интересно - арифметику ошибок и недостаточной точности - но это потом)

Есть побочная цель - сделать python интерфейс для нашей библиотеки - но это следующий шаг.

Из за ограничений на дебаг - лучше писать в обычном стиле а не хедер онли - в хедерах только декларируем.

## стек технологий
clion, gdb, кто хочет, может делать ассемблерные вставки (я скажу где надо), gitk, gnuplon (or mathplotlib), interprocess pipe communication (or another way you find)

## связь
Просто в телеге или по надобности в скайпе

## что я жду
1. написание тестов на google-test
2. освоение концепции конечного автомата
3. изучение моего прошлого опыта написания чисел с беск точностью  https://github.com/theoreticalboypf94/my_lib/tree/master/history/Number_2%20%D0%B7%D0%B0%D0%B5%D0%B1%D0%B0%D0%BB%D1%81%D1%8F%20%D0%BB%D1%83%D1%87%D1%88%D0%B5%20%D1%81%20%D0%BD%D1%83%D0%BB%D1%8F
4. я начну писать - буду говорить какие методы мне нужны
5. кто хочет идти вперед пусть под каждый метод пишет template class, чтобы не сидеть на числах с беск, точностью
