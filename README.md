# simple gtk2 app

build:

```bash
cc -c win `pkg-config --cflags --libs gtk+-2.0`
cc -o app app.c win.o `pkg-config --cflags --libs gtk+-2.0`
```
