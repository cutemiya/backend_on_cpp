# Backend-приложение на С++ c использованием CrowCpp и sqlite3 + sqlite_modern_cpp

## Основная информация
### Зависимости
```Crow``` [Crow — это C++-фреймворк для создания веб-сервисов HTTP или Websocket](https://github.com/CrowCpp/Crow?ysclid=ljvxagftpm538458674)

```sqlite3``` [SQLite — это внутрипроцессная библиотека, реализующая автономное бессерверное ядро транзакционной базы данных SQL с нулевой конфигурацией](https://www.sqlite.org/cintro.html)

```sqlite_modern_cpp``` [Обертка над sqlite3 для более удобной работы с базой данных](https://github.com/SqliteModernCpp/sqlite_modern_cpp?ysclid=ljvxwj5gsk449900577)

```Ubuntu 20.04``` [Ubuntu — дистрибутив GNU/Linux, основанный на Debian GNU/Linux](https://ubuntu.com/)

```boost::asio``` [Boost.Asio — кроссплатформенная C++ библиотека для сетевого и низкоуровневого программирования ввода-вывода который предоставляет разработчикам согласованную асинхронную модель, использующую современную Подход C++ (Crow работает на основе boost::asio, являясь некой оберткой над данным фреймворком)](https://www.boost.org/doc/libs/master/doc/html/boost_asio.html)

## Backend

### Routes

```/catalog``` - получить информацию о всех животных в базе данных

```/cat```, ```/dog```, ```/fish```, ```/cow``` - добавить животное в базу данных 

body:
```
    kind  - вид
    genus - род
    info  - информация о животном
    url   - ссылка на фотографию 
```

```catalog/delete``` - очистить базу данных
