# compilador
comp = gcc

# flags
stdlibs = -lm -lpthread
sdl = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
flagsChatas = -Wall -pedantic -ansi
outros= -D_GNU_SOURCE=1 -D_REENTRANT

# caminhos
lib = lib/*.c lib/*/*.c
srcDir = src
source = $(srcDir)/*.c $(srcDir)/*/*.c
bin = exe
executavel = out
dev = dev
testes = $(dev)/testes

# resultado
comandos = $(comp) -o $(bin).$(executavel) $(lib) $(source) $(stdlibs) $(sdl)

# regras
exec: compilar
	./$(bin).$(executavel)
	@make cleanSimples --no-print-directory
	@echo

repetir: cleanSimples
	@$(comp) -o $(dev)/repetir.$(executavel) $(dev)/repetir.c
	@./$(dev)/repetir.$(executavel)
	@make cleanSimples --no-print-directory
	@echo

compilar:
	@echo
	$(comandos)
	@echo

chato:
	$(comandos) $(flagsChatas)

# limpezas
cleanSimples:
	@echo
	rm -rf `find -name '*.o'; find -name '$(bin)'; find -name '*.$(executavel)'`

clean: cleanSimples
	rm -rf `find  -name '*~'; find -name 'core'; find -name 'a.out'`
	@echo

cleanCompleto:
	@echo
	rm -rf `find -name '*.o' -o -name '*.exe' -o -name '*.bak' -o -name '*.c~' -o -name 'core' -o -name 'a.out' -o -name '$(bin)' -o -name 'repetir'`
	@echo

limpa: clean
	@

limpar: clean
	@
	
#testar (testes/[nome].c)
%:
	@echo
	rm -rf $@
	@echo
	$(comp) -o $(testes)/$@.$(executavel) lib/terminal.c $(testes)/$@.c
	@echo
	./$(testes)/$@.$(executavel)
	@echo

