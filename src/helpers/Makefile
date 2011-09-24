TARGETS := \
  gnome-shell \
  gnome2 \
  xfce-xfconf


.PHONY: all
all: $(TARGETS) ;

.PHONY: clean
clean:
	rm -f $(TARGETS)


gnome-shell: gnome-shell.c
	gcc -o $@ $(shell pkg-config --cflags --libs glib-2.0 dconf) $^

gnome2: gnome2.c
	gcc -o $@ $(shell pkg-config --cflags --libs glib-2.0 gconf-2.0) $^

xfce-xfconf: xfce-xfconf.c
	gcc -o $@ $(shell pkg-config --cflags --libs glib-2.0 libxfconf-0) $^
