TARGET = sm
all: clean
	gcc -o $(TARGET) client.c state_pause.c state_idle.c state_machine.c state_wait.c

clean:
	rm -rf $(TARGET)

distclean:
	rm -rf $(TARGET) GPATH GRTAGS GSYMS GTAGS gtags.files tags

gt:
	find . -name "*.[chCH]" > gtags.files
	gtags
	cat gtags.files | ctags --tag-relative=no --totals --recurse --extra="+qf" --fields="+i" -L -
