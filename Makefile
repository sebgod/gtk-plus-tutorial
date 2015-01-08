# Samples from: https://de.wikibooks.org/wiki/GTK_mit_Builder
GTK_FLAGS := $(shell pkg-config --cflags --libs gtk+-3.0 gmodule-2.0 || \
	pkg-config --cflags --libs gtk+-2.0 gmodule-2.0)

PROGS :=\
	hello_world              \
	stretch_manual           \
    stretch_combined         \
    table_layout_depr        \
	free_layout              \
    box_layout_vbox_depr     \
    box_layout_combined_depr \
	xml_manual_signal        \
	xml_automatic_singal     \
	xml_connection_mapper    \
	menubar                  \
	menu2_extern             \
	toolbar1_extern          \

.PHONY: all
all: $(PROGS) .gitignore

%: %.c
	$(CC) -o $@ -Wall $^ $(GTK_FLAGS)
	
%_extern: %_extern.c %.xml
	$(CC) -o $@ -Wall $< $(GTK_FLAGS)

.PHONY: clean
clean:
	rm -f .gitignore
	rm -f *.exe
	rm -f *.o
	rm -f *.obj
	$(foreach PROG,$(PROGS),rm -f $(PROG);)

.gitignore: .gitignore-tmpl
	cp -f $< $@
	@echo "">>$@
	@echo "# Unix executables">>$@
	@$(foreach PROG,$(PROGS),echo $(PROG) >>$@;)

