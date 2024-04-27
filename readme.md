# 在 Linux 上部署服务器

首先，您需要在 Linux 上部署一个服务器。在本例中，我们使用 SQLite 作为数据库。然后，您可以使用 Qt Creator 打开程序并运行。

```bash
# 切换到 C 盘
loveday@blingbling:~$ cd /mnt
loveday@blingbling:/mnt$ cd c

# 进入代码目录
loveday@blingbling:/mnt/c$ cd Users/Bling/Desktop/SHomeSystem/server/src

# 编译代码
loveday@blingbling:/mnt/c/Users/Bling/Desktop/SHomeSystem/server/src$ 

# 编译 util.c 文件
gcc -c util.c -o util.o -I/usr/include/cjson

# 编译 db.c 文件
gcc -c db.c -o db.o -I/usr/include/cjson

# 编译主文件 main.o
gcc api.o db.o main.o server.o util.o -o k_program -lmicrohttpd -lcurl -lcjson -lsqlite3

# 运行程序
loveday@blingbling:/mnt/c/Users/Bling/Desktop/SHomeSystem/server/src$ ./k_program
```

